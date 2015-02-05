/*
** merge.c for malloc in /home/faraday/projects/malloc
**
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
**
** Started on  Thu Feb  5 13:58:07 2015 raphael elkaim
** Last update Thu Feb  5 14:29:25 2015 raphael elkaim
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "my_malloc.h"
#include "list.h"

t_list		*find_mem_to_free(void *ptr)
{
  t_list	*tmp;

  tmp = g_mem;
  while (tmp && tmp->next != NULL)
    {
      if (tmp->next->ptr_begin == ptr)
	{
	  tmp->next->isFree = true;
	  break ;
	}
      else if (tmp == g_mem && tmp->ptr_begin == ptr)
	{
	  tmp->isFree = true;
	  break ;
	}
      tmp = tmp->next;
    }
  return (tmp);
}

void		merge_memory(t_list *tmp)
{
  if (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->isFree && tmp->next->isFree)
	{
	  tmp->ptr_end = tmp->next->ptr_end;
	  tmp->next = tmp->next->next;
	  if (tmp->isFree && tmp->next && tmp->next->isFree)
	    {
	      tmp->ptr_end = tmp->next->ptr_end;
	      tmp->next = tmp->next->next;
	    }
	}
      else if (tmp->next && tmp->next->isFree && tmp->next->next && tmp->next->next->isFree)
	{
	  tmp->next->ptr_end = tmp->next->next->ptr_end;
	  tmp->next->next = tmp->next->next->next;
	}
    }
}
