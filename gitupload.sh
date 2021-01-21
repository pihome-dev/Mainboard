#!/bin/bash

repourl="https://github.com/pihome-dev/Mainboard"

git init

rm *~ >> /dev/null

git add .

echo "Please enter a commit:"

read commitname
git commit -m "${commitname}"

git remote add origin ${repourl}

git push origin master
