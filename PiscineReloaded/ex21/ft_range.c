#include <stdlib.h>

int *ft_range(int min, int max)
{
  int *arr;
  int i;
  int c;

  i = 0;
  if (max <= min)
    return(0);
  c = max - min;
  arr = malloc(sizeof(int) * c + 1);
  while (min < max)
  {
    arr[i] = min;
    i++;
    min++;
  }
  arr[i] = '\0';
  return (arr);
}
