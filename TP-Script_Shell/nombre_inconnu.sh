#!/bin/bash
compteur=0
nombre=$(((RANDOM%100)+1))
gagne=false

while [ gagne=false ]
do
  echo "Veuillez choisir un nombre entre 1 et 100 :"
  read nombre_a_tester

  if [ $nombre_a_tester -eq $nombre ]
  then
    gagne=true
    compteur=$((compteur+1))
    echo "Vous avez gagné au bout de la $compteur ème tentative !"
    exit 0
  elif [ $nombre_a_tester -lt $nombre ]
  then
    compteur=$((compteur+1))
    echo "Plus grand"
  elif [ $nombre_a_tester -gt $nombre ]
  then
    compteur=$((compteur+1))
    echo "Plus petit"
  fi
done