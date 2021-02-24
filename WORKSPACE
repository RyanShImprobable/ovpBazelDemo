load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

http_archive(
    name = "com_google_protobuf",
    patches = [
        # This patch ensures that protobuf compiles with -DHAVE_ZLIB on Windows.
        #"@third_party//com_google_protobuf/patches:zlib-msvc.patch",
        #"@third_party//com_google_protobuf/patches:protoc_m_alias.patch",
    ],
    sha256 = "bf0e5070b4b99240183b29df78155eee335885e53a8af8683964579c214ad301",
    strip_prefix = "protobuf-3.14.0",
    url = "https://github.com/google/protobuf/archive/v3.14.0.zip",
)

http_archive(
    name = "abseil",
    sha256 = "19f6f094b1b6d8260f048c91f3ff10d59ad9811083e519a3b9f6b0328e301ea4",
    strip_prefix = "abseil-cpp-b2dcbba18341d75f3fef486b717585cefda0195d",
    urls = ["https://github.com/abseil/abseil-cpp/archive/b2dcbba18341d75f3fef486b717585cefda0195d.zip"],
)

http_archive(
    name = "com_github_grpc_grpc",
    repo_mapping = {"@com_google_absl": "@abseil"},
    #sha256 = "58eaee5c0f1bd0b92ebe1fa0606ec8f14798500620e7444726afcaf65041cb63",
    strip_prefix = "grpc-1.33.1",
    url = "https://github.com/grpc/grpc/archive/1.33.1.tar.gz",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()

# NOTE(fabian): We make third_party/ its own bazel workspace because it allows to run `bazel build ...` without
# having all targets defined in third-party BUILD files in that directory buildable.
local_repository(
    name = "third_party",
    path = "third_party",
)

# Everything repo dependencies.
http_archive(
    name = "nlohmann_json",
    build_file = "@third_party//nlohmann_json:BUILD",
    sha256 = "87b5884741427220d3a33df1363ae0e8b898099fbc59f1c451113f6732891014",
    strip_prefix = "include",
    url = "https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip",
)

# Everything repo dependencies.
http_archive(
    name = "jwt-cpp",
    build_file = "@third_party//jwt-cpp:BUILD",
    strip_prefix = "jwt-cpp-0.5.0/include",
    url = "https://github.com/Thalhammer/jwt-cpp/archive/v0.5.0.zip",
)

