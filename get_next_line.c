#include  "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_next_l(char **buffer_save, char **l)
{
	char	*new;
	int		i;

	i = 0;
	while ((*(*buffer_save + i) != '\n') && (*(buffer_save + i) != '\0'))
		i++;
	if (*(*buffer_save + i) == '\0')
	{
		i++;
		*line = ft_substr(buffer_save, 0, i);
		new = ft_strdup(*buffer_save + i);
	}
	else
		*l = ft_strdup(*buffer_save);
	free(*buffer_save);
	*buffer_save = NULL;
	return (new);
}

int	ft_save_file(int fd, char **buff, char **buffer_save, char **l)
{
	char	*tmp;
	int		i;

	i = 1;
	while (!ft_strchr(*buffer_save, '\n') && i)
	{
		i = read(fd, *buff, BUFFER_SIZE);
		(*buff)[i] = '\0';
		tmp = *buffer_save;
		buffer_save = ft_strjoin(tmp, *buff);
		free(tmp);
	}
	free(*buff);
	*buff = NULL;
	buffer_save = ft_next_l(buffer_save, l);
	if (*line == '\0')
	{
		free(*l);
		*l = (NULL);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer_save;
	char		*buff;
	char		*l;
	int			i;

	buffer_save = NULL;
	if (ft < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	if (buffer_save)
		buffer_save = ft_strdup("");
	i = ft_save_file(fd, &buff, &buffer_save, &l);
	if (i == 0 && !l)
		return (NULL);
	return (l);
}
