#!/bin/bash

find src/ -name '*.cc' -o -name '*.h'|while read i; do cat license-header.txt > $i.lic && cat $i >> $i.lic && mv $i.lic $i; done
