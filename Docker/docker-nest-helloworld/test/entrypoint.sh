#!/bin/bash
set -e

# Run npm test
npm run test

# Run npm e2e tests
npm run test:e2e
