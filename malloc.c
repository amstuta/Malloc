/*
** malloc.c for malloc in /home/amstut_a/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 11:00:26 2015 Arthur Amstutz
** Last update Tue Jan 27 12:27:30 2015 raphael elkaim
*/

#include <stddef.h>
#include <stdio.h>

void *malloc(size_t size)
{
  putchar('a');
  (void)size;
  return (0);
}

void free(void *ptr)
{
  (void)ptr;
}

void *realloc(void *ptr, size_t size)
{
  (void)size;
  return (ptr);
}
