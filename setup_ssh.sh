#!/bin/bash
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
echo "✅ SSH key added. You can now use GitHub via SSH."

