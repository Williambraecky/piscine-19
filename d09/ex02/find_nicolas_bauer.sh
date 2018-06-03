#!/bin/sh
cat annuaire.txt | grep -i "nicolas\tbauer" | grep -v -i "bomber" | tr '\t' '\n' |  grep -i "-"
