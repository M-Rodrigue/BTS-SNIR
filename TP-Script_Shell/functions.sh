#!/bin/bash

function calculate {
  local a=$1
  local b=$2
  local c=$3

  if [ -z $a ] || [ -z $b ] || [ -z $c ]
  then
    echo "Veuillez spécifier les paramètres comme ceci (premier chiffre, le signe puis le deuxième chiffre) : 10 * 2 ou 9 + 4"
    exit 1;
  else
    result=$(($a$b$c))
  fi
}

calculate $1 $2 $3
echo $result