#!/bin/bash

echo "===== BORN2BEROOT SELF-TEST ====="

echo
echo "[1] System Target"
systemctl get-default

echo
echo "[2] Hostname"
hostnamectl | grep "Static hostname"

echo
echo "[3] Firewall"
if command -v ufw &>/dev/null; then
    sudo ufw status
else
    sudo firewall-cmd --list-all
fi

echo
echo "[4] SSH Port"
sudo ss -tulpn | grep ssh

echo
echo "[5] Root SSH Login"
sudo grep -i PermitRootLogin /etc/ssh/sshd_config

echo
echo "[6] Users in Groups"
id "$USER"

echo
echo "[7] Password Aging"
chage -l "$USER"

echo
echo "[8] PW Quality"
grep -v '^#' /etc/security/pwquality.conf

echo
echo "[9] Login.defs"
grep PASS_ /etc/login.defs

echo
echo "[10] Sudoers"
sudo grep -E "passwd_tries|badpass_message|requiretty|secure_path|logfile" /etc/sudoers /etc/sudoers.d/* 2>/dev/null

echo
echo "[11] LVM + Encryption"
lsblk
sudo lvscan

echo
echo "[12] Networking"
ip a | grep -E "inet |ether"

echo
echo "[13] Sudo Log Count"
sudo grep -c "" /var/log/sudo/sudo.log 2>/dev/null

echo
echo "[14] Cron Jobs"
sudo crontab -l

echo
echo "===== DONE ====="
