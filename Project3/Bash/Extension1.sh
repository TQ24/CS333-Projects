#!/bin/Bash
# Extension1

HELLO=Hello
Mix=T9
function helloworld {
  local HELLO=World
  VAR=GlobalOrLocal
  echo $HELLO
}

echo $HELLO
helloworld
echo $Mix
echo $VAR
