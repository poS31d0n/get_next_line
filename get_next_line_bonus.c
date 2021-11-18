#include "get_next_line_bonus.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		nom;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nom = 1;
	while (!ft_check_n(str) && nom)
	{
		nom = read(fd, buff, 1);
		if (nom == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[nom] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[5000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_new_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
