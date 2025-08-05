#include "gtest/gtest.h"
#include "main.hpp"

// Test suite for the complex_decision function
class MCDC_Test : public ::testing::Test {
protected:
    // You can add setup/teardown logic here if needed
};

// To satisfy MCDC for (A && B) || C, we need a minimal set of tests
// that shows each condition (A, B, C) can independently affect the outcome.
//
// Our chosen set of tests:
// 1. (T, T, F) -> True  |
// 2. (F, T, F) -> False | Pair for A: Changes A, outcome flips.
// ------------------------
// 1. (T, T, F) -> True  |
// 3. (T, F, F) -> False | Pair for B: Changes B, outcome flips.
// ------------------------
// 2. (F, T, F) -> False |
// 4. (F, T, T) -> True  | Pair for C: Changes C, outcome flips.
//
// This set of 4 tests satisfies MCDC.

TEST_F(MCDC_Test, TestCase1_TTF_ResultsInTrue) {
    // Base case for our pairs. (true && true) || false -> true
    EXPECT_EQ(complex_decision(true, true, false), 100);
}

TEST_F(MCDC_Test, TestCase2_FTF_ResultsInFalse_PairForA) {
    // Paired with TestCase1 to show 'a' independently affects the outcome.
    // (false && true) || false -> false
    EXPECT_EQ(complex_decision(false, true, false), 200);
}

TEST_F(MCDC_Test, TestCase3_TFF_ResultsInFalse_PairForB) {
    // Paired with TestCase1 to show 'b' independently affects the outcome.
    // (true && false) || false -> false
    EXPECT_EQ(complex_decision(true, false, false), 200);
}

TEST_F(MCDC_Test, TestCase4_FTT_ResultsInTrue_PairForC) {
    // Paired with TestCase2 to show 'c' independently affects the outcome.
    // (false && true) || true -> true
    EXPECT_EQ(complex_decision(false, true, true), 100);
}

// Standard gtest main function
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}