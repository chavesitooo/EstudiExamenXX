#!/bin/bash

function finish {
    set +e
    killall exam > /dev/null 2>&1
    killall exam-tester-a > /dev/null 2>&1
    echo "TEST FAILED"
}

trap finish EXIT

# Killing exam and exam-tester-a just in case it was already running...

killall exam > /dev/null 2>&1 && { echo "Exam binary was still running... killing it. You may want to wait for a few seconds for the port to be available again"; }
killall exam-tester-a > /dev/null 2>&1 && { echo "Exam tester binary was still running... killing it. You may want to wait for a few seconds for the port to be available again"; }

set -e

# Starting test server listening at port 2345

echo "Starting bin/exam-tester-a (listening at port 2345)"

bin/exam-tester-a&

sleep .2

# Starting your server

echo "Starting bin/exam"

bin/exam&

# Starting test client connecting to localhost:1234

sleep .2

echo "Starting bin/exam-tester-b (connecting to localhost:1234)"

bin/exam-tester-b

sleep .2

killall exam > /dev/null 2>&1 && { echo "Exam binary still running when should have stopped!" ; exit 1; }
killall exam-tester-a > /dev/null 2>&1 && { echo "Exam tester binary still running when should have stopped!" ; exit 1; }

trap - EXIT
