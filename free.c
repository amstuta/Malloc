/*
** free.c for free in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Wed Jan 28 12:26:26 2015 Arthur Amstutz
** Last update Wed Jan 28 12:37:55 2015 Arthur Amstutz
*/

#include <stddef.h>
#include "my_malloc.h"
#include "list.h"

void		free(void *ptr)
{
  t_list	*tmp;

  tmp = g_mem;
  while (tmp != NULL)
    {
      if (tmp->ptr_begin == ptr)
	{
	  tmp->isFree = true;
	  break;
	}
      tmp = tmp->next;
    }
  tmp = g_mem;
  while (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->isFree && tmp->next->isFree)
	{
	  tmp->ptr_end = tmp->next->ptr_end;
	  tmp->next = tmp->next->next;
	}
      tmp = tmp->next;
    }
}
