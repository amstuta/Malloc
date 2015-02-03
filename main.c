/*
** main.c for  in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 12:59:04 2015 raphael elkaim
** Last update Thu Jan 29 17:06:44 2015 Arthur Amstutz
*/

void show_alloc_mem();

#include <string.h>

int main()
{
  int d = 0;
  int i = 0;
  //int b = 0;
  char *test;

  
  srandom(time(0));
  //malloc(0);
  //test = malloc(120);
  //malloc(4);
  //free(test);
  //calloc(10, 1);
  //malloc(40000);*/
    for (i = 0;i < 100;i++)
    {
      test = malloc(100);
      if ((unsigned long)test % 16 == 0)
	++d;
      free(test);
      //      free(test);
    }
    printf("aligned %d/100 times!\n", d);

  
  char *a = "tameresucepourdesbananes";
  char *b = strdup(a);
  show_alloc_mem();
  b = realloc(b, 3);
  printf("%s\n", b);
  show_alloc_mem();
  //printf("b: %s\n", b);
}
