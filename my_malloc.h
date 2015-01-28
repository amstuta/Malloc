/*
** my_malloc.h for malloc in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 16:12:18 2015 raphael elkaim
** Last update Tue Jan 27 17:03:42 2015 raphael elkaim
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

extern void	*g_startheap;
extern t_list	*g_mem;

void *align(void *ptr);

#endif /* !MY_MALLOC_H_ */
