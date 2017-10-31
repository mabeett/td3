#!/bin/bash

# Indent para reorganizar el código conforme a un estilo de programación

OPTS="\
-nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 \
-cli0 -d0 -di1 -nfc1 -i4 -ip0 -l80 -lp -npcs -nprs -npsl -sai \
--no-tabs \
-saf -saw -ncs -nsc -sob -cp33 -ss -ts8 -il1 "
# -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1 "

dos2unix -q "${1}"
indent ${OPTS} "${1}"
