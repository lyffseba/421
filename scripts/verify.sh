#!/bin/sh
# Exit 0 if repository trees are complete.
set -e
cd "$(dirname "$0")/.."
make verify
