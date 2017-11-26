#include "h.h"

int	main(int argc, char *argv[])
{
  int fd;
  int ret;
  char buf[BUF_SIZE + 1];

  if (argc == 1)
  {
    ft_putstr("File name missing.\n");
    return (0);
  }
  if (argc > 2)
  {
    ft_putstr("Too many arguments.\n");
    return (0);
  }
  fd = open(argv[1], O_RDONLY);
  while ((ret = read(fd, buf, BUF_SIZE)))
  {
    buf[ret] = '\0';
    ft_putstr(buf);
  }
  close(fd);
  return (0);
}
