#include <libft.h>
#include <main.h>
#include <stdio.h>

int		valid_cell(int pos, char c)
{
	if (pos % 5 && c != '\n')
		return (1);
	else if (c != '.' && c != '*' && pos > 0)
		return (1);
	return (0);
}

int		check_tetr(int fd)
{
	int		pos;
	char	buf;

	pos = 0;
	while (read(fd, &buf, BUFSIZE))
	{
		printf("POS (%d) : %c\n", pos, buf);
		if (valid_cell(pos, buf))
			return (1);
		if (!(pos % 22))
			pos++;
	}
	return (0);
}
