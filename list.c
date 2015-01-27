/*
** list.c for list in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 12:50:52 2015 Arthur Amstutz
** Last update Tue Jan 27 14:18:15 2015 Arthur Amstutz
*/

#include <stdio.h>
#include <stddef.h>
#include "list.h"

void		show_alloc_mem(t_list **mem)
{
  int		size;
  t_list	*tmp;

  tmp = *mem;
  if (tmp == NULL)
    return;
  printf("break : %p\n", g_startheap);
  while (tmp != NULL)
    {
      size = tmp->end - tmp->begin;
      printf("%p - %p : %d octets\n", tmp->ptr_begin, tmp->ptr_end, size);
      tmp = tmp->next;
    }
}

void		delete_at_back(t_list **mem)
{
  t_list	*tmp;

  tmp = *mem;
  if (tmp == NULL)
    return;
  if (tmp->next == NULL)
    tmp->ifFree = true;
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  tmp->next->isFree = true;
}

t_bool		insert(t_list **mem, void *begin, void *end)
{
  int		size;
  t_list	*tmp;
  t_list	*new;

  tmp = *mem;
  size = end - begin;
  while (tmp != NULL)
    {
      if ((tmp->ptr_end - tmp->ptr_begin) >= (size + sizeof(t_list)) \
	  && tmp->isFree == true)
	{
	  new = end + 1;
	  new->ptr_begin = end + 1 + sizeof(t_list);
	  new->ptr_end = tmp->end;
	  new->isFree = true;
	  new->next = tmp->next;
	  tmp->ptr_begin = begin;
	  tmp->ptr_end = end;
	  tmp->isFree = false;
	  tmp->next = new;
	  return (true);
	}
      tmp = tmp->next;
    }
  return (false);
}

t_bool		add_to_list_end(t_list **mem, int size)
{
  t_list	*tmp;
  t_list	*new;

  tmp = *mem;
  if (tmp == NULL)
    return (false);
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (tmp->isFree == true &&\
      (tmp->ptr_end - tmp->ptr_begin) >= (end - begin + sizeof(t_list)))
    {
      tmp->ptr_end = tmp->ptr_begin + size;
      tmp->isFree = true;
    }
  else
    {
      new = tmp->ptr_end + 1;
      new->ptr_begin = tmp->ptr_end + 1 + sizeof(t_list);
      new->ptr_end = new->ptr_begin + size;
      new->isFree = false;
      new->next = NULL;
    }
  return (true);
}
