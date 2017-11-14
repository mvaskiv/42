/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbuy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:32:15 by dbuy              #+#    #+#             */
/*   Updated: 2017/10/31 15:23:40 by dbuy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

void	f1(char *a)
{
	*a = *a + 1;
}

void	ft_test_tocase(void)
{
	puts("\nTESTING TOCHAR...\n");
	int i;
	int flag = 0;

	i = -200;
	while (i < 500)
	{
		if (toupper((char)i) != ft_toupper((char)i))
		{
			printf("DIFFupper %d\n", i);
			flag++;
			break ;
		}
		if (tolower((char)i) != ft_tolower((char)i))
		{
			printf("DIFFlower %d\n", i);
			flag++;
			break ;
		}
		i++;
	}
	if (flag == 0)
		puts("ALL OK!");
}

void	ft_test_char(void)
{
	puts("\nTESTING ISCHAR...\n");
	int i = -200;
	int	flag;

	flag = 0;
	while (i < 500)
	{
		if (isdigit(i) != ft_isdigit(i))
		{
			flag = 1;
			printf("DIFFdigit%d\t", i);
		}
		if (isalpha(i) != ft_isalpha(i))
		{
			flag = 1;
			printf("DIFFalpha%d\t", i);
		}
		if (isalnum(i) != ft_isalnum(i))
		{
			flag = 1;
			printf("DIFFalnum%d\t", i);
		}
		if (isascii(i) != ft_isascii(i))
		{
			flag = 1;
			printf("DIFFascii%d\t", i);
		}
		if (isprint(i) != ft_isprint(i))
		{
			flag = 1;
			printf("DIFFprint%d\t", i);
		}
		i++;
	}
	if (flag == 0)
		puts("All OK!");
}

void	ft_test_atoi(void)
{
	puts("\nTESTING ATOI...\n");
	char **a;
	a = (char**)malloc(sizeof(char*) * 10);
	a[0] = "\t\n\r\v\f-2147483647";
	a[1] = "\t\n\r\v\f00000";
	a[2] = "\t\n\r\v\f-00001+";
	a[3] = "\t\n\r\v\f000001-";
	a[4] = "+\t\n\r\v\f+21+-";
	a[5] = "+-20";
	a[6] = "-+20";
	int i = 0;
	while (i < 7)
	{
		if (atoi(a[i]) == ft_atoi(a[i]))
			printf("OK!%d\t", i);
		else
			printf("DIFF!%d\t", i);
		i++;
	}
	puts("");
}

void	ft_test_strcmp(void)
{
	int i;
	char *a;
	int flag;

	a = (char*)malloc(5);
	i = -200;
	flag = 0;
	while (i < 500)
	{
		a[0] = (unsigned char)i;
		if (strcmp("\200hello!", a) != ft_strcmp("\200hello!", a))
		{
			printf("DIFFcmp at i = %d", i);
			flag = 1;
			break ;
		}
		if (strncmp("\200hello!", a, 2) != ft_strncmp("\200hello!", a, 2))
		{
			printf("DIFFncmp at i = %d", i);
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		puts("OK!cmp");
}

void	ft_test_strlcat(void)
{
	char *dest1;
	char *dest2;
	char *dest3;
	char *dest4;

	dest1 = (char*)malloc(20);
	dest1 = memset(dest1, 'G', 2);
	dest2 = (char*)malloc(20);
	dest2 = memset(dest2, 'G', 2);
	dest3 = (char*)malloc(20);
	dest3 = memset(dest3, 'G', 2);
	dest4 = (char*)malloc(20);
	dest4 = memset(dest4, 'G', 2);

	if (strlcat(dest1, "test", 0) == ft_strlcat(dest2, "test", 0))
		puts("OK!lcat1");
	else
		puts("DIFFlcat1");
	if (memcmp(dest1, dest2, 20) == 0)
		puts("OK!lcat2");
	else
		puts("DIFFlcat2");
	if (strlcat(dest1, "test", 15) == ft_strlcat(dest2, "test", 15))
//	printf("%d\n", (int)strlcat(dest1, "test", 15));
//	printf("%d\n", (int)ft_strlcat(dest2, "test", 15));
		puts("OK!lcat3");
	else
		puts("DIFFlcat3");
	if (memcmp(dest1, dest2, 20) == 0)
		puts("OK!lcat4");
	else
		puts("DIFFlcat4");
	char h[10] = "HELLO!";
	if (memcmp(strchr(h, 'L'), ft_strchr(h, 'L'), 10) == 0)
		puts("OK!chr1");
	else
		puts("DIFF1chr");
	if (memcmp(strchr(h, '\0'), ft_strchr(h, '\0'), 10) == 0)
		puts("OK!chr2");
	else
		puts("DIFF2chr");
	if (memcmp(strrchr(h, 'L'), ft_strrchr(h, 'L'), 10) == 0)
		puts("OK!chrr1");
	else
		puts("DIFF1chrr");
	if (memcmp(strrchr(h, '\0'), ft_strrchr(h, '\0'), 10) == 0)
		puts("OK!chrr2");
	else
	{
		printf("%s$\n", strrchr(h, '\0'));
		printf("%s$\n", ft_strrchr(h, '\0'));
		puts("DIFF2chrr");
	}
}

void	ft_test_str(void)
{
	int i;
	char *a;
	char **c;
//	char c1[30] =
	char *b;
	char *e;
	char *f;

	i = -1;
	c = (char**)malloc(sizeof(char*) * 10);

	while (++i < 10)
		c[i] = (char*)malloc(30);


	c[0] = "test!";
	c[1] = "\0\0\0\0";
	c[2] = "\n\t\r\v   test2   \v\r\t\n";
	c[3] = "test3\0";
	c[4] = "tes";
	c[5] = "tes\200t5";
	c[6] = "\0";
	a = (char*)malloc(10);
	b = (char*)malloc(10);
	e = (char*)malloc(10);
	f = (char*)malloc(10);


	i = -1;
	while(++i < 7)
	{
		ft_putstr("testing string ");
		ft_putstr(ft_itoa(i));

		if (ft_strcmp(ft_strdup(c[i]), strdup(c[i])) != strcmp(ft_strdup(c[i]), strdup(c[i])))
		{
			write(1, "DIFF!dup\n", 7);
			write(1, strdup(c[i]), strlen(c[i]));
		}
		else
			ft_putstr("\tOK!dup");
//		if (ft_strlen(c[i]) == strlen(c[i]))
//			ft_putstr("\tOK!len");
//		else
//			ft_putstr ("\tDIFFlen\n");
		if (strcmp(ft_strcpy(a, c[i]), strcpy(b, c[i])) == 0)
		{
//			printf("\n%s\n", strcpy(a, c[i]));
			ft_putstr("\tOK!cpy");
		}
		else
			ft_putstr("\tDIFF!cpy\n");

		if (strcmp(strcat(a, c[i]), ft_strcat(b, c[i])) == 0)
			ft_putstr("\tOK!cat\n");
		else
		{
//			printf("!%s!\n", strcat(a, c[i]));
//			printf("!%s!\n", ft_strcat(b, c[i]));
			puts("\tDIFFcat!\n");
		}
		if (strlcat(e, c[i], 10) == ft_strlcat(f, c[i], 10))
			ft_putstr("\tOK!lcat\n");
		else
		{
//			printf("%d\n", (int)strlcat(a, c[i], 10));
//			printf("%s\n", a);
//			printf("%d\n", (int)ft_strlcat(b, c[i], 10));
//			printf("%s\n", b);
			ft_putstr("\tDIFFlcat!\n");
		}
		if (strcmp(strncpy(a, c[i], 10), ft_strncpy(b, c[i], 10)) == 0)
			ft_putstr("\tOK!cpy\n");
		else
			ft_putstr("\tDIFFncpy!\n");
		if (strcmp(strncat(a, c[i], 10), ft_strncat(b, c[i], 10)) == 0)
			ft_putstr("\tOK!ncat\n");
		else
			ft_putstr("\tDIFFncat!\n");
	}
		if (strcmp(strstr("HELLO!", "\0"), ft_strstr("HELLO!", "\0")) == 0)
			ft_putstr("OK!str1\n");
		else
			ft_putstr("\nDIFF1str1\n");
		if (strcmp(strstr("HELLO!", "LO"), ft_strstr("HELLO!", "LO")) == 0)
			ft_putstr("OK!str1\n");
		else
			ft_putstr("\nDIFF2str2\n");
		if (strcmp(strnstr("HELLO!", "LO", 5), ft_strnstr("HELLO!", "LO", 5)) == 0)
			ft_putstr("OK!nstr1\n");
		else
			ft_putstr("\nDIFF1nstr1\n");
		if (ft_strnstr("HELLO!", "LO", 4) == NULL)
			ft_putstr("OK!nstr2\n");
		else
			ft_putstr("\nDIFF2nstr2\n");


// STRLCAT
		ft_test_strlcat();
// STRCMP + STRNCMP
		ft_test_strcmp();
// ATOI
		ft_test_atoi();
// ISCHAR
		ft_test_char();
// TOCASE
		ft_test_tocase();

}

void	ft_memmove_test(void)
{
	char a[40] = "123456789abcdefgh";
	char *b;
	char *c;
	char *e;
	char *f;

	b = a + 5;
	c = a + 5;
	e = b - 5;
	f = b - 5;
	if (memcmp(memmove(b, a, 10), ft_memmove(c, a, 10), 15) == 0)
		puts("OK!move1");
	else
		puts("DIFF1move");
	if (memcmp (memmove(b, a, 0), ft_memmove(c, a, 0), 15) == 0)
		puts("OK!move2");
	else
		puts("DIFF2move");
	if (memcmp(memmove(e, b, 10), ft_memmove(e, b, 10), 15) == 0)
		puts("OK!move3");
	else
		puts("DIFF3move");

//	printf("%s\n", memmove(b, a, 3));
}

void	ft_test_mem(void)
{
	char **c;
	char *a;
	char *b;
	char *g;
	char *h;
	char *buff;
	int	i;

	i = -1;
	a = (char*)malloc(60);
	b = (char*)malloc(60);
	buff = (char*)malloc(60);
	buff = memset(buff, 'c', 10);
	c = (char**)malloc(sizeof(char*) * 10);
	while (++i < 10)
	{
		c[i] = (char*)malloc(30);
		i++;
	}
	c[1] = "test_str1";
//	write(1, " 2 ", 3);
	if (memcmp(memset(a, 'c', 10), ft_memset(b, 'c', 10), 10) == 0)
		write(1, "OK!set\n", 4);
	else
		write(1, "DIFF1set!\n", 9);
//	a = ft_memset(a, 'c', 10);
//	b = memset(b, 'c', 10);
//	write(1, " 3 ", 3);
//	printf("%s\n", a);
//	printf("%s\n", b);
	bzero(a, 2);
	ft_bzero(b, 2);
	if (memcmp(a, b, 10) == 0)
		puts("OK!zero");
	else
		puts("DIFFbzero\n");
	a = memset(a, 'c', 10);
	b = memset(b, 'c', 10);
	buff = memset(buff, 'a', 3);
	if (memcmp(memcpy(a, buff, 5), ft_memcpy(b, buff, 5), 10) == 0)
		puts("OK!cpy");
	else
		puts("\nDIFFcpy");
// MEMCCPY
	g = (char*)malloc(60);
	h = (char*)malloc(60);
	g = memset(g, 'a', 10);
	h = memset(h, 'a', 10);
//	printf("%s\n", ft_memccpy(a, "123456", '4', 5));
//	printf("%s\n", a);

	if (memcmp(memccpy(g, "123456", '4', 5), ft_memccpy(h, "123456", '4', 5), 29) == 0)
		puts("OK!ccpy1");
	else
	{
		puts("\nDIFF1ccpy");
		printf("%s\n", g);
		printf("%s\n", h);
	}
	if (memcmp(g, h, 30) == 0)
		puts("OK!ccpy2");
	else
		puts("DIFF2ccpy");
	if (memccpy(g, "HELL", 'Z', 4) == NULL)
		puts("OK!ccpy3");
	else
		puts("DIFF3ccpy");
// MEMMOVE
	ft_memmove_test();
// MEMCHR
	char mchr[40] = "HELLO_WOR\0LD";
	if (memchr(mchr, '_', 6) == ft_memchr(mchr, '_', 6))
		puts("OK!chr1");
	else
		puts("DIFF!chr1");
	if (ft_memchr(mchr, 'f', 10) == NULL)
		puts("OK!chr2");
	else
		puts("DIFFchr1");
	if (memchr(mchr, '\0', 15) == ft_memchr(mchr, '\0', 15))
		puts("OK!chr3");
	else
		puts("DIFFchr3");

}

void	ft_test_striter(void)
{
	puts("\nTESTING STRITER...\n");

	int i;
	char *a;

	i = 0;
	int flag = 0;
	a = (char*)malloc(20);
	a = memset(a, 'A', 20);
	ft_striter(a, f1);
	while (i < 20)
	{
		if (a[i] != 'B')
		{
			printf("ERRiter, char = %c on index %d\n", a[i], i);
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
		puts ("OK!striter");
}

void 	f2(unsigned int i, char *a)
{
	*a = *a + i;
}

void	ft_test_striteri(void)
{
	puts("\nTESTING STRITERI...\n");
	char *a;
	char *b;

	a = (char*)malloc(10);
	a = ft_memset(a, 'Y', 9);
	a[0] = 'A';
	ft_striteri(a, f2);

	b = (char*)malloc(10);
	b = memset(b, 'Y', 9);
	b[0] = 'A';
	ft_striteri(b, f2);

	if (memcmp(a, b, 10) == 0)
		puts("OK!striteri");
	else
		puts("DIFF1striteri");
	if (a[0] != 'A')
		puts("DIFF2striteri");
	if (a[1] != 'Z')
		puts("DIFF3striteri");
}

char	f3(char a)
{
	if (a >= 'a' && a <= 'z')
		return (a - 32);
	else
		return (a);
}

void	ft_test_strmap(void)
{
	puts("\nTESTING STRMAP...\n");
	char *in;
	char *out;

	in = "Hello World!";
	out = ft_strmap(in, f3);
	if (strcmp(out, "HELLO WORLD!") != 0)
		puts("DIFF1strmap");
	else
		puts("OK!strmap");
}

char	f4(unsigned int i, char a)
{
	if (a >= 'a' && a <= 'z' && i < 3)
		return (a - 32);
	else
		return (a);
}

void	ft_test_strmapi(void)
{
	puts("\nTESTING STRMAPI...\n");
	char *in;
	char *out;

	in = "Hello World!";
	out = ft_strmapi(in, f4);
	if (strcmp(out, "HELlo World!") != 0)
		puts("DIFF1strmapi");
	else
		puts("OK!strmapi");
}

void	ft_test_strequ(void)
{
	puts("\nTESTING STREQU...\n");
	if (ft_strequ("Hello", "Hello World") == 1)
		puts("DIFF1strequ");
	else
		puts("OK!strequ 1");
	if (ft_strequ("Hello", "Hello") != 1)
		puts("DIFF2strequ");
	else
		puts("OK!strequ 2");
}

void	ft_test_strnequ(void)
{
	puts("\nTESTING STRNEQU...\n");
	if (ft_strnequ("Hello_", "Hello World", 6) == 1)
		puts("DIFF1strnequ");
	else
		puts("OK!strnequ 1");
	if (ft_strnequ("Hello", "Hello World", 5) != 1)
		puts("DIFF2strnequ");
	else
		puts("OK!strnequ 2");
}

void	ft_test_strsub(void)
{
	puts("\nTESTING STRSUB...\n");
	if (strcmp(ft_strsub("Hello World", 0, 2), "He") == 0)
		puts("OK!strnequ 1");
	else
		puts("DIFFstrnequ 1");
	if (strcmp(ft_strsub("Hello World", 1, 3), "ell") == 0)
		puts("OK!strnequ 2");
	else
		puts("DIFFstrnequ 2");
}

void	ft_test_strjoin(void)
{
	puts("\nTESTING STRJOIN...\n");
	if (strcmp(ft_strjoin("Hello_", "WORLD"), "Hello_WORLD") == 0)
		puts("OK!strjoin 1");
	else
		puts("DIFFstrjoin 1");
	if (strcmp(ft_strjoin("\0\0\0", "ell\0\0\0"), "ell") == 0)
		puts("OK!strjoin 2");
	else
		puts("DIFFstrjoin 2");
}

void	ft_test_strtrim(void)
{
	puts("\nTESTING STRTRIM...\n");
	if (strcmp(ft_strtrim("\t \n \t Hello \n\t\n "), "Hello")  == 0)
		puts("OK!strtrim 1");
	else
		puts("DIFFstrtrim 1");
}

void	ft_test_strsplit(void)
{

	if (strcmp(ft_strsplit("   Test    this!    ", ' ')[0], "Test") == 0)
		puts("OK!strsplit 1");
	else
		puts("DIFFstrsplit 1");
	if (strcmp(ft_strsplit("   Test    this!    ", ' ')[1], "this!") == 0)
		puts("OK!strsplit 2");
	else
		puts("DIFFstrsplit 2");
	printf("1\n");
	if (strcmp(ft_strsplit("   Test    this!    ", ' ')[1], "this!") == 0)
		puts("OK!strsplit 3");
	else
		puts("DIFFstrsplit 3");
	ft_strsplit("\0", ' ');
	printf("13\n");
	// if (strcmp(ft_strsplit("\0", ' ')[0], "") == 0)
	// 	puts("OK!strsplit 4");
	// else
	// 	puts("DIFFstrsplit 4");
	if (strcmp(ft_strsplit("Test    this!", ' ')[0], "Test") == 0)
		puts("OK!strsplit 5");
	else
		puts("DIFFstrsplit 5");
	if (strcmp(ft_strsplit("Test    this!", ' ')[1], "this!") == 0)
		puts("OK!strsplit 6");
	else
		puts("DIFFstrsplit 6");
}

void	ft_test_itoa(void)
{
	puts("\nTESTING ITOA...\n");
	if (strcmp(ft_itoa(-2147483648), "-2147483648") == 0)
		puts("OK!itoa 1");
	else
		puts("DIFFitoa 1");
	if (strcmp(ft_itoa(-10000100), "-10000100") == 0)
		puts("OK!itoa 2");
	else
		puts("DIFFitoa 2");
	if (strcmp(ft_itoa(-2147483648), "-2147483648") == 0)
		puts("OK!itoa 3");
	else
		puts("DIFFitoa 3");

}

void	ft_test_fd(void)
{
	int fd;
	int r;
	char *buff;

	buff = (char*)malloc(100);
	fd = open("txt", O_RDWR);
	ft_putchar_fd('C', fd);
	close(fd);
	fd = open("txt", O_RDWR);
	r = read(fd, buff, 1);
	if (buff[0] == 'C')
		puts("OK!char_fd");
	else
		puts("DIFFchar_fd");
	ft_putstr_fd("HELLO" ,fd);
	close(fd);
	fd = open("txt", O_RDWR);
	r = read(fd, buff, 10);
	if (strcmp(buff, "CHELLO") == 0)
		puts("OK!str_fd");
	else
		puts("DIFFstr_fd");
	ft_putendl_fd("_world" ,fd);
	close(fd);
	fd = open("txt", O_RDWR);
	r = read(fd, buff, 20);
	if (strcmp(buff, "CHELLO_world\n") == 0)
		puts("OK!endl_fd");
	else
		puts("DIFFendl_fd");
	ft_putnbr_fd(-214000, fd);
	close(fd);
	fd = open("txt", O_RDWR);
	r = read(fd, buff, 20);
	if (strcmp(buff, "CHELLO_world\n-214000") == 0)
		puts("OK!nbr_fd");
	else
		puts("DIFFnbr_fd");
}

void	ft_test_add(void)
{
	puts("\nTESTING ADD FUNC...\n");
	int i;
	char *a;
	char *b;
	int flag;

	i = 10000;
	flag = 0;
	a = ft_memalloc(i);
	a[0] = 'L';
	if (a[0] != 'L')
		puts("ERRmemalloc");
	while (i > 2)
	{
		if (a[i - 1] != 0)
		{
			printf("ERRmemalloc %d\n", i);
			flag = 1;
		}
		i--;
	}
	if (flag == 0)
		puts("OK!memalloc");
	ft_memdel((void **)&a);
	if (!a)
		puts("OK!memdel");
	else
		puts("ERRmemdel");
	b = ft_strnew(1000);
	b[0] = 'G';
	i = 1000;
	if (b[0] != 'G')
		puts("ERRstrnew");
	while (i > 2)
	{
		if (b[i - 1] != '\0')
		{
			printf("ERRnewstr %d\n", i);
			flag = 1;
		}
		i--;
	}
	if (flag == 0)
		puts("OK!strnew");
	ft_strdel(&a);
	if (!a)
		puts("OK!strdel");
	else
		puts("ERRstrdel");
	char *d;
	d = (char*)malloc(100);
	d = memset(b, 'D', 100);
	i = 99;
	ft_strclr(d);
	while (i >= 0)
	{
		if (d[i] != '\0')
		{
			puts("ERRstrclr");
			flag = 1;
		}
		i--;
	}
	if (flag == 0)
		puts("OK!strclr");
// STRITER
	ft_test_striter();
// STRITERI
	ft_test_striteri();
// STRMAP
	ft_test_strmap();
// STRMAPI
	ft_test_strmapi();
// STREQU
	ft_test_strequ();
// STRNEQU
	ft_test_strnequ();
// STRSUB
	ft_test_strsub();
// STRJOIN
	ft_test_strjoin();
// STRTRIM
	ft_test_strtrim();
// STRSPLIT
	ft_test_strsplit();
// ITOA
	ft_test_itoa();
	puts("\nTESTING PUTNBR...\n");
	puts("1000000:");
	ft_putnbr(1000000);
	puts("\n-2147483648:");
	ft_putnbr(-2147483648);
	puts("\n0:");
	ft_putnbr(0);
	puts("\n6006:");
	ft_putnbr(6006);
	puts("");
// TESTING FDs...
	ft_test_fd();
}

void	del(void *a, size_t s)
{
	if (a && s)
		puts("del work");
}

void	ft_liter(t_list *elem)
{
	printf("%s\n", elem->content);
}

char	ft_strcap(char a)
{
		if (a >= 'a' && a <= 'z')
			a = a - 32;
	return (a);
}





int		main(int argc,  char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error argc. Use parameters \"mem\", \"str\", \"mem\", or \"add\"\n");
		return (0);
	}
	if (ft_strcmp(argv[1], "str") == 0)
		ft_test_str();
	if (ft_strcmp(argv[1], "mem") == 0)
		ft_test_mem();
	if (ft_strcmp(argv[1], "add") == 0)
		ft_test_add();
	return (0);
}
