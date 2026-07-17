#!/usr/bin/env bash
# Build the GDExtension and refresh compile_commands.json for the IDE.
# Run from the project root (same folder as SConstruct).
#
# Usage:
#   ./build.sh              -> debug build (default, use during development)
#   ./build.sh release      -> release build (use before exporting the game)

set -e  # stop on first error

PLATFORM="macos"
TARGET="template_debug"

if [ "$1" == "release" ]; then
    TARGET="template_release"
fi

echo "Building ($TARGET)..."
scons platform="$PLATFORM" target="$TARGET" compiledb=yes

echo "Done. compile_commands.json refreshed."