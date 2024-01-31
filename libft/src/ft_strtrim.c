/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:41:33 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 15:42:17 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		last;
	char	*trimmed_string;

	start = 0;
	last = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (0);
	while (start <= last && ft_strchr(set, s1[start]))
		start++;
	if (last < start)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[last]) && last >= 0)
		last--;
	trimmed_string = (char *) malloc((last - start + 2) * sizeof(char));
	if (!trimmed_string)
		return (0);
	ft_strlcpy(trimmed_string, &s1[start], last - start + 2);
	return (trimmed_string);
}
