#!/bin/bash

# Le compteur commence à un
i=1

### Donner la table de multiplication avec un argument
while [ $i -le 10 ]
do
  echo "$1*$i = "$(($1*$i))
  i=$((i+1))
done