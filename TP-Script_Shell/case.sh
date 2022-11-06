#!/bin/bash

case $# in
  0) echo "Veuillez vous identifier de la manière suivante : ./case.sh user password";;
  1) echo "Bonjour $1, il vous manque le mot de passe pour accéder à votre répertoire.";;
  2) echo "Bonjour $1, nous téléversons votre profile du serveur."
    echo "Création de votre dossier."
    mkdir $1 && mkdir $1/Documents && mkdir $1/Images && mkdir $1/Desktop && mkdir $1/Downloads && mkdir $1/Media && mkdir $1/Projects && mkdir $1/Professional && mkdir $1/Confidential
    touch $1/Documents/identities.txt
    echo "Nom d'utilisateur : $1@localhost" >> $1/Documents/identities.txt
    echo "Mot de passe : $2" >> $1/Documents/identities.txt
    echo "Votre identité a bien été créée.";;
  *) echo "VOUS NE RESPECTEZ PAS LA SYNTAXE";;
esac