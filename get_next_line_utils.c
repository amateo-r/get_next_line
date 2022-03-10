/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:45:57 by amateo-r          #+#    #+#             */
/*   Updated: 2022/03/10 12:39:48 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] != (char)c)
		if (s[i] == '\0')
			return (NULL);
	return ((char *) s + i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	dst = (char *)malloc (sizeof(char) * ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		dst[i] = s1[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (NULL);
	if (*s == '\0' || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start + 1 > len + 1)
		dst = (char *)malloc(sizeof(char) * (len + 1));
	else
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!dst)
		return (0);
	while (s[start] && i < len)
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		s[i + j] = s2[j];
	s[i + j] = '\0';
	free(s1);
	return (s);
}
