/*
** malloc.c for malloc in /home/amstut_a/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 11:00:26 2015 Arthur Amstutz
** Last update Tue Jan 27 17:25:23 2015 raphael elkaim
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
//#include "my_malloc.h"
#include "list.h"

void	*g_startheap = 0;
t_list	*g_mem = 0;

void	*malloc(size_t size)
{
  void *res;

  if (!g_startheap)
    g_startheap = sbrk(0);
      printf("REACH FOR THE SKIES\n");
  while ((res = insert(size)) == 0)
    {
      //      printf("YOHOHO\n");
      if (add_memory_end() == false)
	return (0);
    }
  return (res);
}

void	free(void *ptr)
{
  (void)ptr;
}

void	*realloc(void *ptr, size_t size)
{
  (void)size;
  return (ptr);
}
