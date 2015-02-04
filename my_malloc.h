/*
** my_malloc.h for malloc in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 16:12:18 2015 raphael elkaim
** Last update Wed Jan 28 15:31:57 2015 raphael elkaim
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

#include "list.h"

extern pthread_mutex_t g_mut;
extern void	*g_startheap;
extern t_list	*g_mem;

void		*align(void *ptr);
void		*safe_malloc(size_t size);
void		*safe_free(void *ptr);
void		*change_mem_size(t_list *, size_t);
void		fake_free(void *ptr);


#endif /* !MY_MALLOC_H_ */
