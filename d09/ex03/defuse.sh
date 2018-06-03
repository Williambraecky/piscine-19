#!/bin/sh
touch -A -000001 bomb.txt
stat -s bomb.txt | tr ' ' '\n' | grep 'st_atime' | cut -d = -f 2
