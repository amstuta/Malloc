/*
** malloc.c for malloc in /home/amstut_a/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 11:00:26 2015 Arthur Amstutz
** Last update Thu Feb  5 13:19:11 2015 raphael elkaim
*/

#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <pthread.h>
#include "my_malloc.h"
#include "list.h"

pthread_mutex_t	g_mut = PTHREAD_MUTEX_INITIALIZER;
void		*g_startheap = 0;
t_list		*g_mem = 0;

void		*malloc(size_t size)
{
  void		*res;

  if ((long)size <= 0)
    return (0);
  pthread_mutex_lock(&g_mut);
  if ((long long)g_startheap <= 0)
    {
      g_startheap = sbrk(0);
      if ((long long)g_startheap <= 0)
	{
	  pthread_mutex_unlock(&g_mut);
	  return (NULL);
	}
    }
  while ((res = insert(size)) == 0)
    {
      if (add_memory_end() == false)
	{
	  pthread_mutex_unlock(&g_mut);
	  return (0);
	}
    }
  pthread_mutex_unlock(&g_mut);
  return (res);
}

void		*fake_malloc(size_t size)
{
  void		*res;
  
  if ((long)size <= 0)
    return (0);
  if (!g_startheap || (long long)g_startheap <= 0)
    {
      g_startheap = sbrk(0);
      if ((long long)g_startheap <= 0)
	return  (NULL);
    }
  while ((res = insert(size)) == 0)
    {
      if (add_memory_end() == false)
	return (0);
    }
  return (res);
}

void		*calloc(size_t size, size_t size2)
{
  void		*ptr;

  if ((long long)(size * size2) <= 0)
    return (0);
  pthread_mutex_lock(&g_mut);
  ptr = fake_malloc(size * size2);
  if (ptr && ptr != g_startheap)
    ptr = memset(ptr, 0, size * size2);
  pthread_mutex_unlock(&g_mut);
  return (ptr);
}
