#!/bin/bash

# Le compteur commence à un
i=1

while [ $i -le 8 ]
do
  if [ $i = 1 -o $i = 3 ]
  then
    echo "non"
  elif [ $i = 2 -o $i = 4 -o $i = 6 ]
  then
    echo "grr"
  elif [ $i = 5 ]
  then
    echo "toto"
  elif [ $i = 7 ]
  then
    echo "oui"
  elif [ $i = 8 ]
  then
    echo "merci !"
  fi
  i=$(($i+1))
done