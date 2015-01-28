/*
** main.c for  in /home/elkaim_r/projects/malloc
** 
** Made by raphael elkaim
** Login   <elkaim_r@epitech.net>
** 
** Started on  Tue Jan 27 12:59:04 2015 raphael elkaim
** Last update Wed Jan 28 16:55:50 2015 raphael elkaim
*/

void show_alloc_mem();

int main()
{
  int i = 0;
  int b = 0;
  char *test;
  srandom(time(0));
  malloc(0);
  test = malloc(120);
  malloc(4);
  free(test);
  calloc(10, 1);
  malloc(20);
  /*  for (i = 0;i < 10;i++)
    {
      test = malloc(7);
      strcpy(test, "salut!");
      test[6] = 0;
      printf("%s\n", test);
      //      free(test);
      }*/
  show_alloc_mem();
}
