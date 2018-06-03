#!/bin/sh
echo obase=13';'ibase=5';'$FT_NBR1+$FT_NBR2 | tr \'\\\\\"\?\! '01234' | tr 'mrdoc' '01234' | sed 's/3base/obase/g' | bc | tr '0123456789ABC' 'gtaio luSnemf'