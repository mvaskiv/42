#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char		*input;
	t_tminos	*game;

	if (argc != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	input = ft_copy_input(fd);
	close(fd);
	if (!validation_for_each(input))
	{
		ft_putendl("error");
		return (0);
	}
	game = ft_get_minos(input);
	ft_play_the(game, input);
	free(input);
	free(game);
	return (0);
}
