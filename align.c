/*
** align.c for malloc in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 13:59:23 2015 raphael elkaim
** Last update Wed Feb  4 13:23:35 2015 raphael elkaim
*/

static long long	on_16(long long ptr)
{
  long long		i;

  i = 0;
  while ((ptr + i) % 16)
    ++i;
  return (i);
}

void	*align(void *ptr)
{
  return ((void*)on_16((long long)ptr));
}
