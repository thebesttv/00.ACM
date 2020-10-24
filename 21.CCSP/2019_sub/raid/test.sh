#!/bin/bash

for i in {1..10}; do
  cd data/$i
  echo $i
  ../../a.out < $i.in > out
  diff out $i.ans
  cd ../../
done
