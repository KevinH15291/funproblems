#!/bin/bash


for ((i = 0 ; i < 2 ; i++)); do
  for ((j = 0 ; j < 2 ; j++)); do
  a=$(mktemp)
  b=$(mktemp)
  (echo "$i $j"  | ./powersof2test) > ${a}
  
  (echo "$i $j" | ./powersof2) > ${b}
  echo "$i $j" 
  diff $a $b
  done
done