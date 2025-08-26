#!/bin/bash

if [[ ! -z "${BUILDBUDDY_ORG_API_KEY}" ]]; then
  BAZEL_REMOTE_CONFIG=(
    --config=remote
    --remote_header=x-buildbuddy-api-key="${BUILDBUDDY_ORG_API_KEY}"
  )
fi
bazel --bazelrc=$GITHUB_WORKSPACE/.github/workflows/ci.bazelrc --bazelrc=.bazelrc \
  build "${BAZEL_REMOTE_CONFIG[@]}" //... "$@"
