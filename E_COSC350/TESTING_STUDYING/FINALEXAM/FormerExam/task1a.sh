#!/bin/bash

for i in *; do

	if [ -d $i ]; then
		ls $i
	fi

done
