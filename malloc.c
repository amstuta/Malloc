/*
** malloc.c for malloc in /home/amstut_a/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 11:00:26 2015 Arthur Amstutz
** Last update Wed Jan 28 16:13:35 2015 raphael elkaim
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
//#include "align.h"
#include "my_malloc.h"
#include "list.h"

void	*g_startheap = 0;
t_list	*g_mem = 0;

void	*malloc(size_t size)
{
  void *res;

  if (!g_startheap)
    g_startheap = sbrk(0);
  //  printf("REACH FOR THE SKIES\n");
  while ((res = insert(size)) == 0)
    {
      if (add_memory_end() == false)
	return (0);
    }
  return (res);
}

void		*fake_malloc(size_t size)
{
 void		*res;

  if (!g_startheap)
    g_startheap = sbrk(0);
  while ((res = insert(size)) == 0)
    {
      if (add_memory_end() == false)
	return (0);
    }
  return (res);
}

void		*realloc(void *ptr, size_t size)
{
  t_list	*tmp;
  void		*nptr;

  tmp = g_mem;
  if (!ptr)
    return (fake_malloc(size));
  if (!size)
    {
      fake_free(ptr);
      return (0);
    }
  while (tmp)
    {
      if (tmp->ptr_begin == ptr)
	{
	  nptr = fake_malloc(size);
	  nptr = memcpy(nptr, tmp->ptr_begin, size);
	  fake_free(ptr);
	  break ;
	}
      tmp = tmp->next;
    }
  return (nptr);
}
