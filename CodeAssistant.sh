#! /usr/bin/env zsh

ctags -R .

if [ -f "cscope.out" ]; then
  rm cscope.*
fi
find . -name "*.h" -o -name "*.c" -o -name "*.cpp" > cscope.files
cscope -bkq -i cscope.files

