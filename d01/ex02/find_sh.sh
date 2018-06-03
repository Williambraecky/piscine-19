#!/bin/sh
find . -name '*.sh' | sed 's/\.sh//g; s/.\///g'
