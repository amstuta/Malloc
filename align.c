/*
** align.c for malloc in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 13:59:23 2015 raphael elkaim
** Last update Tue Jan 27 16:11:20 2015 raphael elkaim
*/

static long	on_16(long ptr)
{
  long		i;

  i = 0;
  while ((ptr + i) % 16)
    ++i;
  return (i);
}

void	*align(void *ptr)
{
  return ((void*)on_16((long)ptr));
}
