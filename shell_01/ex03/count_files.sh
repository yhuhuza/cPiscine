#!/bin/bash
#find . | wc -l | tr -d ' '
find $PWD \( -type f -or -type d \) -name ".*" -prune -o -print | wc -l | tr -d ' '
