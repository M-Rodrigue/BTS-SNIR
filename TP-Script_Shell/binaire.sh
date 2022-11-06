#!/bin/bash

MaxBits=8

pow ()
{
  value2=1
  for (( k=1 ; k<$i ; k ++ ))
  do
    let value2=$value2*2
  done
}

if [ $# -eq 0 ]
then
  echo "Saisir une valeur décimale"
  read value
else
  value=$1
fi

declare -a bin
j=0

for (( i=$MaxBits ; i>=0 ; i-- ))
do

  pow
  if [ $value -ge $value2 ]
  then
    bin[j]="1"
    let value=$value-$value2
  else
    bin[j]="0"
  fi
  let j=$j+1
done

printf "La valeur binaire est de : "

for (( i=0 ; i<=($MaxBits-1) ; i++ ))
do
    printf ${bin[i]}
done

echo ""