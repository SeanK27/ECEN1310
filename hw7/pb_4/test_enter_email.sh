#! /bin/bash

run () {
  echo "$*"           # echo the command
  if $*               # execute it and test result
  then echo 'success'
  else echo 'error'
  fi
}

run ./email <<EOF
example@google.com
EOF
echo '-----------------------------------'

run ./email <<EOF
examplegoogle.com
EOF
echo '-----------------------------------'

exit 0
