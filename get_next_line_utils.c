/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:41:48 by abdennac          #+#    #+#             */
/*   Updated: 2024/01/09 18:07:02 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*p;
	int		i;

	if (!ptr)
		return (NULL);
	p = ptr;
	i = 0;
	while (n > (size_t)i)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t number, size_t size)
{
	size_t	*new;
	size_t	num;

	num = number * size;
	if (size != 0 && number != num / size)
		return (NULL);
	new = malloc(number * size);
	if (new)
	{
		ft_memset(new, 0, number * size);
		return (new);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	i = 0;
	cc = c;
	if (!s)
		return (NULL);
	while (s[i] || cc == '\0')
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s1 && s2)
	{

		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*sourc;

	if (src == NULL && dst == NULL)
		return (NULL);
	dest = dst;
	sourc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;
	size_t	strsize;
	size_t	to_allocate;

	if (!(s))
		return (NULL);
	strsize = ft_strlen(s);
	to_allocate = len;
	if (start >= strsize || !*s)
		return (ft_strdup(""));
	if (to_allocate > (strsize - start))
		to_allocate = strsize - start;
	sub = (char *)malloc((to_allocate + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	j = 0;
	while (j < to_allocate)
	{
		sub[j] = s[start];
		j++;
		start++;
	}
	sub[j] = '\0';
	return (sub);
}