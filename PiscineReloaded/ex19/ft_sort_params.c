void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] || s2[i])
  {
    if (s1[i] > s2[i])
      return (1);
    if (s2[i] > s1[i])
      return (-1);
    i++;
  }
  return (0);
}

void	ft_swap(char **a, char **b)
{
  char	*c;

  c = *a;
  *a = *b;
  *b = c;
}

void	ft_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ft_putchar(str[i++]);
}

int main(int argc, char *argv[])
{
  int i;

  i = 1;
  while (i < argc - 1)
  {
    if (ft_strcmp(argv[i], argv[i + 1]) > 0)
    {
      ft_swap(&argv[i], argv[i + 1]);
      i = 1;
    }
    else
      i++;
  }
  i = 1;
  while (i < argc)
  {
    ft_putstr(argv[i]);
    ft_putchar('\n');
    i++;
  }
  return (0);
}
