#! /bin/bash

run () {
  echo "$*"           # echo the command
  if $*               # execute it and test result
  then echo 'success'
  else echo 'error'
  fi
}

run ./mean_length <<EOF
Hello how are u 
EOF
echo '-----------------------------------'

exit 0
