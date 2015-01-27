/*
** list.h for list in /home/amstut_a/rendu/malloc
** 
** Made by Arthur Amstutz
** Login   <amstut_a@epitech.net>
** 
** Started on  Tue Jan 27 12:37:12 2015 Arthur Amstutz
** Last update Tue Jan 27 12:41:36 2015 Arthur Amstutz
*/

#ifndef LIST_H_
# define LIST_H_

typedef enum	bool
  {
    false,
    true
  }		bool;

typedef struct	s_list
{
  bool		isFree;
  void		*ptr_begin;
  void		*ptr_end;
  struct s_list	*next;
}		t_list;

void	add_to_list_end();

#endif /* !LIST_H_  */
