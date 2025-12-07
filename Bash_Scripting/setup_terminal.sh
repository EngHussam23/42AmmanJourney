#!/bin/bash

echo "🔧 Starting Terminal Setup..."

# 1. Install Powerline + Fonts
echo "📦 Installing Powerline..."
sudo apt update -y
sudo apt install -y powerline fonts-powerline

# 2. Create ~/.bash_aliases
echo "⚙️ Setting up aliases..."
cat << 'EOF' > ~/.bash_aliases
alias gp='git push'
alias gs='git status'
alias gl='git log --oneline --graph --decorate'
alias ga='git add .'
alias gc='git commit -m'
EOF

# 3. Patch ~/.bashrc with Powerline + Alias loading
echo "📝 Updating ~/.bashrc..."

# Remove old duplicates if exist
sed -i '/powerline/d' ~/.bashrc
sed -i '/bash_aliases/d' ~/.bashrc

# Append clean block
cat << 'EOF' >> ~/.bashrc

# ===== Custom Terminal Setup (Hussam) =====
# Enable Powerline
if [ -f /usr/share/powerline/bindings/bash/powerline.sh ]; then
    source /usr/share/powerline/bindings/bash/powerline.sh
fi

# Load Aliases
if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi
# ==========================================
EOF

# 4. Reload Bash
echo "🔄 Reloading Bash..."
source ~/.bashrc

echo "✅ Setup Complete!"
echo "🎨 Make sure to select the same Nerd Font in Terminal → Preferences → Text."
