# WORKSPACE

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

## Fetch the doctest testing framework from GitHub
#http_archive(
#    name = "doctest",
#    sha256 = "165d27809680373df9e6113b24f5a01340a631165a2283e33a1e1273873d623b",
#    strip_prefix = "doctest-2.4.12",
#    urls = ["https://github.com/doctest/doctest/archive/refs/tags/2.4.12.zip"],
#    # Create a BUILD file for doctest on the fly so Bazel knows how to use it
#    build_file_content = """
#load("@rules_cc//cc:defs.bzl", "cc_library")
#
#cc_library(
#    name = "doctest",
#    hdrs = ["doctest/doctest.h"],
#    includes = ["."],
#    visibility = ["//visibility:public"],
#)
#""",
#)