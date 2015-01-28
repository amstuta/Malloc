/*
** my_malloc.h for malloc in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 16:12:18 2015 raphael elkaim
** Last update Wed Jan 28 12:39:00 2015 Arthur Amstutz
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

#include "list.h"

extern void	*g_startheap;
extern t_list	*g_mem;

void *align(void *ptr);

#endif /* !MY_MALLOC_H_ */
