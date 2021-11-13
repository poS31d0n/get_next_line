#include "get_next_line.h"

char	*ft_read_str(int fd, char str)
{
	char	buff[BUFFER_SIZE + 1];
	int		nom;

	if (!buff)
		return (NULL);
	nom = 1;
	while ((!ft_strchr(str, '\n')) && nom != 0)
	{
		nom = read(fd, buff, BUFFER_SIZE);
		if (nom == -1)
		{
			free(buff);
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
	char		line;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_new_line(str);
	str = ft_new_str(str);
	return (line);
}