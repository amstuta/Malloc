##
## Makefile for malloc in /home/elkaim_r/projects/malloc
## 
## Made by raphael elkaim
## Login   <elkaim_r@epitech.net>
## 
## Started on  Tue Jan 27 12:11:45 2015 raphael elkaim
## Last update Thu Feb  5 14:29:45 2015 raphael elkaim
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wextra -Wall -Werror -fPIC -lpthread

NAME	=	libmy_malloc_$(HOSTTYPE).so

LDFLAGS	=	-shared -Wl,-soname,$(NAME)

SRCS	=	malloc.c \
		align.c \
		list.c \
		free.c \
		merge.c \
		realloc.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS)  $(LDFLAGS) -o $(NAME) && ln -sf $(NAME) libmy_malloc.so

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) libmy_malloc.so

re:	fclean all

.PHONY:	all clean fclean re
