#!/bin/bash

if [ -e bonjour.txt ]
then
  echo "Le fichier existe déjà"
else
  touch bonjour.txt
  echo "Bonjour le monde" >> bonjour.txt
fi