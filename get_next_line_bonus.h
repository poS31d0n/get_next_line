#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_new_line(char *str);
char	*ft_new_str(char *str);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_n(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#endif