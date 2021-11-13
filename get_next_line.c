#include "get_next_line.h"

void	save_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

int	s_buff_check(char **save_buffer, char **s_word, char **tmp)
{
	*s_word = ft_strchr(*save_buffer, '\n');
	if (s_word)
	{
		*tmp = ft_strlcpy_gnl(*save_buffer);
		s_word++;
		*save_buffer = ft_strdup(*s_word);
		return (1);
	}
	else
		*tmp = ft_strdup(*save_buffer);
	return (0);
}

char	*new_buff(char *save_buffer, char *s_word)
{
	save_free(&save_buffer);
	save_buffer = ft_strdup(s_word);
	return (save_buffer);
}

char	*get_next_line(int fd)
{
	static char	*save_buffer = NULL;
	char		buff[BUFFER_SIZE + 1];
	char		*s_word;
	char		*tmp;
	int			nom;

	if (!fd || BUFFER_SIZE < 1 || !buff)
		return (NULL);
	tmp = NULL;
	nom = read(fd, buff, BUFFER_SIZE);
	if (!(s_buff_check(&save_buffer, &s_word, &tmp)))
	{
		while (nom > 0 && !s_word)
		{
			buff[nom] = '\0';
			s_word = ft_strchr(buff, '\n');
			if (s_word++)
				save_buffer = new_buff(save_buffer, s_word);
			tmp = ft_strjoin(tmp, buff);
			nom = read(fd, buff, BUFFER_SIZE);
		}
	}
	return (tmp);
}
