/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:43:54 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/13 12:44:17 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sol;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	sol = (char *)malloc(sizeof(*sol) * (ft_strlen(s1) \
				+ ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	while (s1[i])
		sol[j++] = s1[i++];
	i = 0;
	while (s2[i])
		sol[j++] = s2[i++];
	sol[j] = '\0';
	free(s1);
	return (sol);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*sc;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	sc = (char *)malloc(sizeof(char) * (i + 2));
	if (!sc)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		sc[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		sc[i] = str[i];
		i++;
	}
	sc[i] = '\0';
	return (sc);
}

char	*ft_switch_line(char *str)
{
	int		i;
	int		j;
	char	*sc;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	sc = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!sc)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		sc[j++] = str[i++];
	sc[j] = '\0';
	free(str);
	return (sc);
}