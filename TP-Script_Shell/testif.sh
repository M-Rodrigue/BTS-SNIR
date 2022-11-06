#!/bin/bash

# Récupère le nom de l'utilisateur
echo -n "votre prenom en minuscule svp:"
read nom

# Vérification du nom
if [ "$nom" = "rodrigue" ]
then
	echo "Bonjour Rodrigue !"
else
	echo "Vous n'êtes pas enregistré dans le système"

fi
