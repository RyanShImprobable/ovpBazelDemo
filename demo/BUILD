load("@rules_cc//cc:defs.bzl", "cc_library")

cc_binary(
    name = "ovp_demo",
    srcs = glob(["*.cpp"]),
	copts = ["-Ilib"],
	deps = [
        "//lib:proto_gen_cpp",
		"@nlohmann_json",
    ],
	visibility = ["//visibility:public"],
	
)
