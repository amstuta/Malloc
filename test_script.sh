#!/bin/sh
## test_script.sh for script in /home/elkaim_r/projects/malloc
## 
## Made by raphael elkaim
## Login   <elkaim_r@epitech.net>
## 
## Started on  Tue Jan 27 12:34:34 2015 raphael elkaim
## Last update Tue Jan 27 17:44:33 2015 raphael elkaim
##

export LD_PRELOAD=./libmy_malloc.so
./moul_malloc_stud
unset LD_PRELOAD
