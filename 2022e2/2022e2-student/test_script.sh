#!/bin/bash

function finish {
    set +e
    killall exam > /dev/null 2>&1
    echo "TEST FAILED"
}

trap finish EXIT

# Killing exam just in case it was already running...

killall exam > /dev/null 2>&1 && { echo "Exam binary was still running... killing it. You may want to wait for a few seconds for the port to be available again"; }

set -e

# Starting your server

bin/exam&

# Starting test client

sleep .2

bin/exam-tester

killall exam > /dev/null 2>&1 && { echo "Exam binary still running when should have stopped!" ; exit 1; }

trap - EXIT
