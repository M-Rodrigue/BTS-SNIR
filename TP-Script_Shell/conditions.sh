#!/bin/bash

while [ -z $new_password ]
do
	echo "Enter your new password"
	read new_password
	if [ -z $new_password ]
	then
		echo "You have doesn't write any password"
	fi
done

echo "Enter the password to confirm the modification : "
read confirm_password

# Vérification du mot de passe avec des conditions
if [ "$new_password" = "$confirm_password" ]
then
	echo "The password as fully changed !"
elif [ "$new_password" != "$confirm_password" ]
then
	echo "The password doesn't match"
fi
