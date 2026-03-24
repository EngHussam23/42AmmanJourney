#!/bin/bash

# install curl:
echo "sudo is attempting to install curl for you 👨‍💻:"
sudo apt install curl

# install brave's security key:
echo "installing brave security key:"
sudo curl -fsSLo /usr/share/keyrings/brave-browser-archive-keyring.gpg https://brave-browser-apt-release.s3.brave.com/brave-browser-archive-keyring.gpg

# add brave repository
echo "Adding brave repository 🚚💨:"
echo "deb [signed-by=/usr/share/keyrings/brave-browser-archive-keyring.gpg] https://brave-browser-apt-release.s3.brave.com/ stable main"|sudo tee /etc/apt/sources.list.d/brave-browser-release.list

# Update:
echo "The usual update 🙂:"
sudo apt update && sudo apt upgrade
echo "Installing Brave 🤩:"
sudo apt install brave-browser

