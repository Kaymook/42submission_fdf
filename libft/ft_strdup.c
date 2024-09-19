/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:34:24 by kmoshker          #+#    #+#             */
/*   Updated: 2024/05/01 16:33:07 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	count;
	size_t	i;

	count = ft_strlen(src);
	i = 0;
	while (count > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*new;

	if (!s1)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + 1) * (sizeof(char)));
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
