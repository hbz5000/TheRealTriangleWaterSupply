#!/bin/sh

COLS=`head -n1 $1 | sed 's/,/\n/g' | wc -l`
ROWS=`wc -l $1 | cut -f1 -d' '`

echo -e "$1: $ROWS x $COLS"