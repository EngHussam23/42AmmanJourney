#!/bin/bash

read -p "Enter your Git username: " GIT_USERNAME
git config --global user.name $GIT_USERNAME

read -p "Enter your Git email: " GIT_EMAIL
git config --global user.email $GIT_EMAIL