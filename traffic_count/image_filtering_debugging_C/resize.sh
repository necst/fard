#!/bin/bash
read -p "Scaling output percentage: " PERCENTAGE

for f in *.bmp;
do
	convert "$f" -scale "$PERCENTAGE%" "r$f";
done