/*
** free.c for free in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Wed Jan 28 12:26:26 2015 Arthur Amstutz
** Last update Wed Feb  4 13:23:02 2015 raphael elkaim
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "my_malloc.h"
#include "list.h"

void		suppress_mem(t_list *elem)
{
  while ((elem->ptr_end - elem->ptr_begin) > 8192 && elem->isFree)
    {
      sbrk(-8192);
      elem->ptr_end = elem->ptr_end - 8192;
    }
  if (elem == g_mem && (unsigned long)(elem->ptr_end - elem->ptr_begin) == 8192 - (unsigned long)align(g_startheap) - sizeof(t_list))
    {
      brk(g_startheap);
      g_mem = NULL;
    }
}

void		free(void *ptr)
{
  t_list	*tmp;

  tmp = g_mem;
  pthread_mutex_lock(&g_mut);  
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
  if (tmp && !tmp->next)
    suppress_mem(tmp);
  else if (tmp && tmp->next && !tmp->next->next)
    suppress_mem(tmp->next);
  pthread_mutex_unlock(&g_mut);
}

void		fake_free(void *ptr)
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
  if (tmp && !tmp->next)
    suppress_mem(tmp);
  else if (tmp && tmp->next && !tmp->next->next)
    suppress_mem(tmp->next);
}
