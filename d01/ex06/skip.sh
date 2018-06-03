#!/bin/sh
ls -l | grep -e '\-' -e 'd' | sed 'n; d'
