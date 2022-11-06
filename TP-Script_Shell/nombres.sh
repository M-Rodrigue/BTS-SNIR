#!/bin/bash

echo "How old are you ?"
read age

if [ $age -eq "18" ]
then
  echo "You have 18 years"
elif [ $age -ge 666 ]
then
  echo "Are you Lucifer !?"
elif [ $age -le 1 ]
then
  echo "It's look like a binary"
elif [ $age -lt 18 ]
then
  echo "You are child"
elif [ $age -gt 18 ]
then
  echo "You are adult"
else
  echo "Have you entered a number ?"
fi