load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "proto_gen_cpp",
    srcs = glob(["**/*.cc"]),
	copts = ["-Ilib"],
	hdrs = glob(["**/*.h"]),
	deps = [
		"@com_github_grpc_grpc//:grpc++",		
	],
	visibility = ["//visibility:public"],
)
