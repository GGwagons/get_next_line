/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:13:34 by miturk            #+#    #+#             */
/*   Updated: 2023/10/10 09:54:51 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s++ == (char)c)
			return ((char *)--s);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str3;
	int		i;
	int		j;
	int		k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	str3 = (char *)malloc(i + j + 1);
	if (str3 == NULL)
		return (NULL);
	while (k < i)
	{
		str3[k] = s1[k];
		k++;
	}
	while (k < (i + j))
	{
		str3[k] = s2[k - i];
		k++;
	}
	str3[k] = '\0';
	return (str3);
}

char	*ft_strdup(const char *s)
{
	const char	*org;
	char		*dup;
	int			orglen;
	int			i;

	i = 0;
	orglen = ft_strlen(s);
	dup = (char *)malloc(sizeof (char) * orglen + 1);
	if (!dup)
		return (0);
	org = s;
	while (org[i] != '\0')
	{
		dup[i] = org[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char const		*str;
	char			*sub;

	str = s;
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}