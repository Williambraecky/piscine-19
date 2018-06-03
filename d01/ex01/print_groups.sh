#!/bin/sh
id -Gn $FT_USER | sed 's/ /,/g'
