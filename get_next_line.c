#include "get_next_line.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		nom;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nom = 1;
	while ((!ft_check_n(str)) && nom)
	{
		nom = read(fd, buff, BUFFER_SIZE);
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
	static char	*str;
	char		*line;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_new_line(str);
	str = ft_new_str(str);
	return (line);
}
