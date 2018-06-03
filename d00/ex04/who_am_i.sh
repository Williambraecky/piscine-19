#!/bin/sh
ldapwhoami -Q | cut -d : -f 2
