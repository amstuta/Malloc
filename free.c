/*
** free.c for free in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Wed Jan 28 12:26:26 2015 Arthur Amstutz
** Last update Thu Jan 29 17:02:03 2015 Arthur Amstutz
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "my_malloc.h"
#include "list.h"

void		suppress_mem()
{
  t_list	*tmp;

  tmp = g_mem;
  while (tmp->next)
    {
      tmp = tmp->next;
    }
  while ((tmp->ptr_begin - tmp->ptr_end) > 8192 && tmp->isFree && tmp != g_mem)
    {
      sbrk(-8192);
      tmp->ptr_end = tmp->ptr_end - 8192;
    }
  /*  if (tmp == g_mem && tmp->isFree)
    {

    }*/
}

void		free(void *ptr)
{
  t_list	*tmp;

  tmp = g_mem;
  while (tmp->next != NULL)
    {
      if (tmp->next->ptr_begin == ptr)
	{
	  tmp->next->isFree = true;
	  break ;
	}
      tmp = tmp->next;
    }
  if (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->isFree && tmp->next->isFree)
	{
	  tmp->ptr_end = tmp->next->ptr_end;
	  tmp->next = tmp->next->next;
	}
      if (tmp->isFree && tmp->next->isFree)
	{
	  tmp->ptr_end = tmp->next->ptr_end;
	  tmp->next = tmp->next->next;
	}
      else if (tmp->next->isFree && tmp->next->next && tmp->next->next->isFree)
	{
	  tmp->ptr_end = tmp->next->ptr_end;
	  tmp->next = tmp->next->next;
	}
    }
  //suppress_mem();
}

void		fake_free(void *ptr)
{
  t_list	*tmp;

  tmp = g_mem;
  while (tmp != NULL)
    {
      if (tmp->ptr_begin == ptr)
	{
	  tmp->isFree = true;
	  break ;
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
  suppress_mem();
}
