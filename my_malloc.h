/*
** my_malloc.h for malloc in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 16:12:18 2015 raphael elkaim
** Last update Thu Feb  5 14:30:28 2015 raphael elkaim
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

#include <pthread.h>
#include "list.h"

extern pthread_mutex_t g_mut;
extern void	*g_startheap;
extern t_list	*g_mem;

t_list		*find_mem_to_free(void *ptr);
void		*align(void *ptr);
void		*fake_malloc(size_t size);
void		*safe_malloc(size_t size);
void		*safe_free(void *ptr);
void		*change_mem_size(t_list *, size_t);
void		fake_free(void *ptr);
void		merge_memory(t_list *tmp);


#endif /* !MY_MALLOC_H_ */
