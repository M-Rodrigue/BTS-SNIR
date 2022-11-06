#!/bin/bash

# Vérification du prénom par le paramètre
if [ "$1" = "rodrigue" ]
then
	echo "Bonjour Rodrigue, comment allez-vous ?"
else
	echo "Votre identification n'est pas dans le système"
fi
