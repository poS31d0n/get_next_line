#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strdup(char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*ft_strlcpy_gnl(char *dst);

int		ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#endif