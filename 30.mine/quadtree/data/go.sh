#!/bin/bash

g++ ../gen1.cpp -o gen1.out -O3
g++ ../gen2.cpp -o gen2.out -O3
g++ ../gen3.cpp -o gen3.out -O3
g++ ../gen4.cpp -o gen4.out -O3

g++ ../ori.c -o ori.out -O3
g++ ../std.cpp -o std.out
g++ judge.cpp -o judge.out

for i in {1..7};
do
  ./gen1.out 50 10 40 > "${i}.in"
  echo "generated data set ${i}"
done

for i in {8..10};
do
  ./gen2.out > "${i}.in"
  echo "generated data set ${i}"
done

for i in {11..13};
do
  ./gen3.out > "${i}.in"
  echo "generated data set ${i}"
done

for i in {14..14};
do
  ./gen4.out > "${i}.in"
  echo "generated data set ${i}"
done

for i in {15..18};
do
  ./gen1.out 20 1 79 > "${i}.in"
  echo "generated data set ${i}"
done

for i in {19..20};
do
  ./gen1.out 40 40 20 > "${i}.in"
  echo "generated data set ${i}"
done

for i in {1..20};
do
  echo "testing data set ${i}"
  for s in {"add","remove","query"};
  do
    echo "  ${s}: $(fgrep $s "${i}.in" | wc -l)"
  done
  time ./ori.out < "${i}.in" > "${i}.out.test"
  time ./std.out < "${i}.in" > "${i}.out"
  ./judge.out ./std.out 1500 250880 "${i}.in" "${i}.out.ori"
  diff "${i}.out.test" "${i}.out"
done

rm *.out.test *.out.ori
