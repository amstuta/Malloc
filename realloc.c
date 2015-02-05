/*
** realloc.c for malloc in /home/faraday/projects/malloc
**
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
**
** Started on  Tue Feb  3 15:40:13 2015 raphael elkaim
** Last update Thu Feb  5 13:31:31 2015 raphael elkaim
*/

#include <string.h>
#include <pthread.h>
#include "my_malloc.h"
#include "list.h"

void		*realloc(void *ptr, size_t size)
{
  t_list	*tmp;
  void		*nptr;

  tmp = g_mem;
  if (!ptr && size)
    return (safe_malloc(size));
  if ((long)size <= 0 && ptr)
    return (safe_free(ptr));
  pthread_mutex_lock(&g_mut);  
  while (tmp)
    {
      if (tmp->ptr_begin == ptr)
	{
	  nptr = change_mem_size(tmp, size);
	  break ;
	}
      tmp = tmp->next;
    }
  pthread_mutex_unlock(&g_mut);  
  return (nptr);
}

void		*safe_malloc(size_t size)
{
  void		*nptr;
  
  pthread_mutex_lock(&g_mut);
  nptr = fake_malloc(size);
  pthread_mutex_unlock(&g_mut);
  return (nptr);
}

void		*safe_free(void *ptr)
{  
  pthread_mutex_lock(&g_mut);
  fake_free(ptr);
  pthread_mutex_unlock(&g_mut);
  return (0);
}

void		*change_mem_size(t_list *tmp, size_t size)
{
  void		*nptr;

  nptr = fake_malloc(size);
  if (size >= (unsigned long)(tmp->ptr_end - tmp->ptr_begin) && nptr)
    memcpy(nptr, tmp->ptr_begin, (tmp->ptr_end - tmp->ptr_begin));
  else if (nptr)
    memcpy(nptr, tmp->ptr_begin, size);
  fake_free(tmp->ptr_begin);
  return (nptr);
}

