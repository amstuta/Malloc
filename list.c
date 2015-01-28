/*
** list.c for list in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 12:50:52 2015 Arthur Amstutz
** Last update Wed Jan 28 14:12:24 2015 raphael elkaim
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
      if ((unsigned long)(tmp->ptr_end - tmp->ptr_begin) > (size + sizeof(t_list)) \
	  && tmp->isFree == true)
	{
	  //	  printf("heya\n");
	  new = tmp->ptr_begin + size /*+ 1*/;
	  //printf("size:%ld\nsize needed:%ld", (tmp->ptr_end - tmp->ptr_begin) / 32, (size + sizeof(t_list)));
	  new->ptr_begin = tmp->ptr_begin + size  + sizeof(t_list);
	  //printf("yohoho\n");
	  new->ptr_end = tmp->ptr_end;
	  //	  printf("new size:%ld\nnew size needed:%ld\n", (new->ptr_end - new->ptr_begin), (size + sizeof(t_list)));
	  //printf("ptr begin:%p\nptr end:%p\n", new->ptr_begin,new->ptr_end);
	  new->isFree = true;
	  new->next = tmp->next;
	  //printf("gotta boom!\n");
	  tmp->ptr_end = new->ptr_begin - sizeof(t_list);
	  tmp->isFree = false;
	  tmp->next = new;
	  //printf("old size:%ld\nold size needed:%ld\n", (tmp->ptr_end - tmp->ptr_begin), (size + sizeof(t_list)));
	  //printf("yolo\n");
	  //printf("size:%ld\nsize needed:%ld", (tmp->ptr_end - tmp->ptr_begin) / 32, (size + sizeof(t_list)));
	  return (tmp->ptr_begin);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_bool		add_memory_end()
{
  t_list	*tmp;
  void *ret;

  //  printf("salut\n");
  //  printf("JE RETIRE MES LUNETTES\n");
  if ((ret = sbrk(4096)) == (void *)-1)
    return (false);
  //printf("JE RETIRE MES LUNETTES\n");
  tmp = g_mem;
  if (g_mem == NULL)
    {
      //      brk(g_startheap + 4096);
      g_mem = g_startheap;
      g_mem->ptr_begin = g_startheap + sizeof(t_list);
      g_mem->ptr_end = g_startheap + 4096;
      g_mem->isFree = true;
      g_mem->next = 0;
      //printf("size:%ld\n", g_mem->ptr_end - g_mem->ptr_begin);
      return (true);
    }
  //printf("hello\n");
  while (tmp->next != NULL)
    tmp = tmp->next;
  //printf("hello\n");
  //brk(tmp->ptr_end + 4096);
  tmp->ptr_end = tmp->ptr_end + 4096;
  return (true);
}
