#include  "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_line()
{
}

int	ft_save_file(int fd, char **buffer, char **buffer_save, char **l)
{
}

char	*get_next_line(int fd)
{
	static char	*buffer_save;
	char		*buffer;
	char		*l;
	int			i;

	buffer_save = NULL;
	if (ft < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer_save)
		buffer_save = ft_strdup("");
	i = ft_save_file(fd, &buffer, &buffer_save, &l);
	if (i == 0 && !l)
		return (NULL);
	return (l);
}
