#!/bin/bash

function finish {
    set +e
    killall exam-tester > /dev/null 2>&1
    echo "TEST FAILED"
}

trap finish EXIT

# Killing exam just in case it was already running...

killall exam-tester > /dev/null 2>&1 && { echo "Exam test binary was still running... killing it. You may want to wait for a few seconds for the port to be available again"; }

set -e

# Starting test server

bin/exam-tester&

# Starting your client

sleep .2

bin/exam

killall exam-tester > /dev/null 2>&1 && { echo "Exam test binary still running when should have stopped!" ; exit 1; }

trap - EXIT
