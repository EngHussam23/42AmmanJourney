#!/bin/bash
# Script to automate SSH key generation for GitHub

read -p "Enter your GitHub email: " email
keyfile="$HOME/.ssh/id_ed25519"

# Generate SSH key
ssh-keygen -t ed25519 -C "$email" -f "$keyfile"

# Show public key
echo "\nYour public key is:"
cat "$keyfile.pub"

echo "\nCopy the above key and add it to your GitHub account:"
echo "  https://github.com/settings/keys"

echo "Done!"
