#!/bin/bash

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./phonenumber <<EOF
(999) 999-9999
EOF
echo '-----------------------------------'

run ./phonenumber <<EOF
888-888-8888
EOF
echo '-----------------------------------'

run ./phonenumber <<EOF
(hah) hah-haha
EOF
echo '-----------------------------------'

run ./phonenumber <<EOF
hah-hah-haha
EOF
echo '-----------------------------------'

run ./phonenumber <<EOF
9999999999
EOF
echo '-----------------------------------'

run ./phonenumber <<EOF
EOF

exit 0