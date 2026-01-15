#!/bin/bash
read -p "enter you commit message" COMMIT_MSG

if (!$COMMIT_MSG)
	$COMMIT_MSG="Pushing into remote..."

git add .
git commit -m $COMMIT_MSG
git push
