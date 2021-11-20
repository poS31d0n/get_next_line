#include "get_next_line_bonus.h"

char	*ft_new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_str(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free (str);
	return (line);
}

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
