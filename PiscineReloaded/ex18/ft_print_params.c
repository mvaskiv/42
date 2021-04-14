#include "ft_putchar.c"

int main(int argc, char *argv[])
{
  int i;
  int j;

  i = 0;
  j = 1;
  while (j < argc)
  {
    while (argv[j][i])
      ft_putchar(argv[j][i++]);
    j++;
    i = 0;
    ft_putchar('\n');
  }
}
