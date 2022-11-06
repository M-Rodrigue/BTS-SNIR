#!/bin/bash

TestUser ()
{
    if grep "^$util:" /etc/passwd > /dev/null
    then
        echo $ligne
    fi
}

if [ $# -eq 0 ]
then
    echo "Chemin et nom du fichier :"
    read fichier
else
    fichier=$1
fi

if [ -e $fichier ]
then
    cat $fichier | while true
    do
        read ligne
        if [ "$ligne" = "" ]
        then
            exit
        else
            set -- $ligne
            util=$1
            TestUser
        fi
    done
else
    echo "Le fichier $fichier n'existe pas ..."
fi