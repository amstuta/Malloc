/*
** list.h for list in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 12:37:12 2015 Arthur Amstutz
** Last update Thu Feb  5 12:46:24 2015 raphael elkaim
*/

#ifndef LIST_H_
# define LIST_H_

typedef enum	e_bool
  {
    false,
    true
  }		t_bool;

typedef struct	s_list
{
  t_bool	isFree;
  void		*ptr_begin;
  void		*ptr_end;
  struct s_list	*next;
}		t_list;

void   	show_alloc_mem();
void 	*insert(size_t size);
t_bool	add_memory_end();

#endif /* !LIST_H_  */
