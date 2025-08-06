#!/bin/bash
set -e

# Step 1: Get the Bazel workspace path
WORKSPACE_DIR=$(bazel info workspace)

# Step 2: Trim the last 17 characters
TRIMMED_DIR="${WORKSPACE_DIR:0:-17}"

# Step 3: Find all .gcno and .gcda files under the trimmed path
COVERAGE_FILES=$(find "$TRIMMED_DIR" -name "*.gcno" -o -name "*.gcda")

# Step 4: Copy them to coverage_report/
mkdir -p coverage_report
for file in $COVERAGE_FILES; do
    cp "$file" coverage_report/
done

echo "Capturing..."
lcov    --capture \
        --directory coverage_report \
        --output-file coverage_report/coverage.unfiltered.info \
        --gcov-tool "/usr/bin/gcov-14" \
        --mcdc-coverage \
        --rc lcov_branch_coverage=1 \
        --ignore-errors path,source


echo "Filtering..."
lcov    --extract "coverage_report/coverage.unfiltered.info" \
        "${WORKSPACE_DIR}" \
        --output-file coverage_report/coverage.info

echo "Generating report..."
genhtml coverage_report/coverage_info \
        --output-directory coverage_report \
        --title "Bazel Code Coverage Proof of Concept" \
        --mcdc-coverage \
        --rc genhtml_branch_coverage=1 \
        --frames \
        --legend