#!/bin/bash
# Script to automate SSH key generation for GitHub (Ubuntu/Linux/WSL)

read -p "Enter your GitHub email: " email
keyfile="$HOME/.ssh/id_ed25519"

# Create .ssh directory if it doesn't exist
mkdir -p "$HOME/.ssh"
chmod 700 "$HOME/.ssh"

# Generate SSH key
ssh-keygen -t ed25519 -C "$email" -f "$keyfile" -N ""

# Start ssh-agent and add key
eval "$(ssh-agent -s)"
ssh-add "$keyfile"

# Show public key
echo -e "\nYour public key is:"
cat "$keyfile.pub"

echo -e "\nCopy the above key and add it to your GitHub account:"
echo "  https://github.com/settings/keys"

echo -e "\nDone! SSH key generated and added to ssh-agent."
