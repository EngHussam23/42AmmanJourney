# PowerShell script to automate SSH key generation for GitHub (Windows)

# Get GitHub email from user
$email = Read-Host "Enter your GitHub email"
$sshDir = "$env:USERPROFILE\.ssh"
$keyfile = "$sshDir\id_ed25519"

# Create .ssh directory if it doesn't exist
if (-not (Test-Path $sshDir)) {
    New-Item -ItemType Directory -Path $sshDir -Force | Out-Null
    Write-Host ".ssh directory created"
}

# Generate SSH key (empty passphrase)
Write-Host "`nGenerating SSH key..."
ssh-keygen -t ed25519 -C $email -f $keyfile -N '""'

# Start ssh-agent and add key
Write-Host "`nStarting ssh-agent..."
Start-Service ssh-agent
ssh-add $keyfile

# Show public key
Write-Host "`nYour public key is:" -ForegroundColor Green
Get-Content "$keyfile.pub"

# Copy to clipboard (optional)
Get-Content "$keyfile.pub" | Set-Clipboard
Write-Host "`n Public key copied to clipboard!" -ForegroundColor Cyan

Write-Host "`nCopy the above key and add it to your GitHub account:" -ForegroundColor Yellow
Write-Host "  https://github.com/settings/keys" -ForegroundColor Yellow

Write-Host "`nDone! SSH key generated and added to ssh-agent." -ForegroundColor Green
