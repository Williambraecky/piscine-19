#!/bin/sh
ldapsearch -Q -LLL -s sub "uid=z*" cn | grep  '^cn:' | sort -f -r | cut -c 5-


