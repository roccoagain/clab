#!/bin/bash

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./mean_length <<EOF
To sleep, perchance to dream. 
EOF
echo '-----------------------------------'

run ./mean_length <<EOF
aaaa aaaa aaaa aaaa
EOF
echo '-----------------------------------'

run ./mean_length <<EOF
a
EOF
echo '-----------------------------------'

run ./mean_length <<EOF
EOF

exit 0