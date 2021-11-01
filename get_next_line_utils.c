#include "get_next_line.h"

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

char	*ft_substr(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		gglen;

	i = 0;
	if (!s)
		return (NULL);
	gglen = ft_strlen(s);
	if (start > gglen)
		return (ft_strdup(""));
	gglen -= start;
	if (len >= gglen)
		len = gglen;
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*r;

	size = 0;
	while (src[size])
		size++;
	r = (char *)malloc(size + 1);
	if (!r)
		return (NULL);
	size = -1;
	while (src[++size])
		r[size] = src[size];
	r[size] = '\0';
	return (r);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
