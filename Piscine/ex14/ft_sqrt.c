int ft_sqrt(int nb);
{
  int r;

  r = 1;
  if (nb <= 0)
    return (0);
  while (r < 46342 || r != nb)
  {
    if ((r * r) == nb)
      return(r);
    r++:
  }
  return (0);
}
