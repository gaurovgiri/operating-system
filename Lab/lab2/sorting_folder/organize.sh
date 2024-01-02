#!/bin/bash

mkdir documents images videos audios scripts 2>/dev/null

mv *.jpg *.jpeg *.png images/ 2>/dev/null
mv *.doc *.docx *.pdf documents/ 2>/dev/null
mv *.mov *.mpeg *.mp4 videos/ 2>/dev/null
mv *.mp3 *.wav audios/ 2>/dev/null
mv *.sh *.py scripts/ 2>/dev/null
mv scripts/organize.sh ./ 2>/dev/null

echo "### DIRECTORY SORTED ###"
