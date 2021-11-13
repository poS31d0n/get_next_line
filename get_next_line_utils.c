#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char )c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char )c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		str[ft_strlen(s1) + i] = ft_strlen(s2);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
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
	free(str);
	return (NULL);
}
