/*
** list.c for list in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 12:50:52 2015 Arthur Amstutz
** Last update Tue Jan 27 17:26:52 2015 raphael elkaim
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "list.h"
#include "my_malloc.h"

void		show_alloc_mem()
{
  int		size;
  t_list	*tmp;

  tmp = g_mem;
  if (tmp == NULL)
    return ;
  printf("break : %p\n", g_startheap);
  while (tmp != NULL)
    {
      if (!tmp->isFree)
	{
	  size = tmp->ptr_end - tmp->ptr_begin;
	  printf("%p - %p : %d octets\n", tmp->ptr_begin, tmp->ptr_end, size);
	}
      tmp = tmp->next;
    }
}

void		delete_at_back()
{
  t_list	*tmp;

  tmp = g_mem;
  if (tmp == NULL)
    return ;
  if (tmp->next == NULL)
    tmp->isFree = true;
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  tmp->next->isFree = true;
}

void		*insert(size_t size)
{
  t_list	*tmp;
  t_list	*new;

  tmp = g_mem;
  while (tmp != NULL)
    {
      if ((size_t)(tmp->ptr_end - tmp->ptr_begin) >= (size + sizeof(t_list))\
	  && tmp->isFree == true)
	{
	  new = tmp->ptr_begin + 1 + size;
	  new->ptr_begin = tmp->ptr_begin + 1 + size + sizeof(t_list);
	  new->ptr_end = new->ptr_begin + size;
	  new->isFree = true;
	  new->next = tmp->next;
	  tmp->ptr_end = new->ptr_begin - 1 - sizeof(t_list);
	  tmp->isFree = false;
	  tmp->next = new;
	  return (tmp->ptr_begin);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_bool		add_memory_end()
{
  t_list	*tmp;

  if (sbrk(4096) == (void *)-1)
    return (false);
  tmp = g_mem = g_startheap;
  if (g_mem == g_startheap)
    {
      g_mem->ptr_begin = g_mem + sizeof(t_list);
      g_mem->ptr_end = g_mem + 4096;
      g_mem->isFree = true;
      g_mem->next = 0;
      return (true);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->ptr_end += 4096;
  return (true);
}
