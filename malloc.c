/*
** malloc.c for malloc in /home/amstut_a/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 11:00:26 2015 Arthur Amstutz
** Last update Wed Feb  4 17:23:46 2015 raphael elkaim
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
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
	  return  (NULL);
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

void		*realloc(void *ptr, size_t size)
{
  t_list	*tmp;
  void		*nptr;

  tmp = g_mem;
  if (!ptr && size)
    {
      pthread_mutex_lock(&g_mut);
      nptr = fake_malloc(size);
      pthread_mutex_unlock(&g_mut);
      return (nptr);
    }
  if ((long)size <= 0 && ptr)
    {
      pthread_mutex_lock(&g_mut);
      fake_free(ptr);
      pthread_mutex_unlock(&g_mut);
      return (0);
    }
  pthread_mutex_lock(&g_mut);  
  while (tmp)
    {
      if (tmp->ptr_begin == ptr)
	{
	  nptr = fake_malloc(size);
	  if (size >= (unsigned long)(tmp->ptr_end - tmp->ptr_begin) && nptr)
	    memcpy(nptr, tmp->ptr_begin, (tmp->ptr_end - tmp->ptr_begin));
	  else if (nptr)
	    nptr = memcpy(nptr, tmp->ptr_begin, size);
	  fake_free(ptr);
	  break ;
	}
      tmp = tmp->next;
    }
  pthread_mutex_unlock(&g_mut);  
  return (nptr);
}

/*void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off)
{
  (void)addr;
  (void)len;
  (void)prot;
  (void)flags;
  (void)fildes;
  (void)off;
  printf("HOLY SHIT IT WAS THIS ALL ALONG\n");
  return (fake_malloc(len));
x  }*/
