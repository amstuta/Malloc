#!/bin/sh
## test_script.sh for script in /home/elkaim_r/projects/malloc
## 
## Made by raphael elkaim
## Login   <elkaim_r@epitech.net>
## 
## Started on  Tue Jan 27 12:34:34 2015 raphael elkaim
## Last update Tue Feb  3 16:16:44 2015 raphael elkaim
##

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
echo "${green}recompiling the project${reset}"
make && echo "${green}succesfully recompiled the project${reset}" || (echo "${red}compilation failed :(${reset}";exit 1)
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:./malloc/" && echo "${green}setting up the library path${reset}"
echo "${green}recompiling the test main${reset}"
(gcc main.c -lmy_malloc -L./ && echo "${green}done!${reset}") || (echo "failed :(" && exit 1)
echo "${green}and everything shall use our malloc!${reset}"
export LD_PRELOAD=./libmy_malloc.so
echo "${green}testing basic malloc/free interactions:${reset}"
./a.out
#exit 0
echo "${green}testing the mighty moulinette:${reset}"
./moul_malloc_stud
echo "${green}some more basic tests:${reset}\n creating file \"your mom\""
touch yourmom
rm -v yourmom
echo "${green}running a new bash command shell!:${reset}"
bash
echo "${green}when shit starts going down:testing emacs:${reset}"
emacs -nw randomfilewedontcareaboutbutitbetterwork || echo "${red}fuck it >:(${reset}"
echo "${green}setting everything back to normal!${reset}"
unset LD_PRELOAD
