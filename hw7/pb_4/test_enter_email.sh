
run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./enter_email <<EOF
adam@example.com
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
asdf@asdf.com
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
blahblahblah@blahblahblah.com
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
1l1k1?sd;fkk@a;lksjdf;alksjdf.com
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
@example.com
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
asdf@
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
adam@@example.com
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
a@example
EOF
echo '-----------------------------------'

run ./enter_email <<EOF
EOF

exit 0