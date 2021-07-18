/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:01:41 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/15 20:12:02 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strncpy(char *src, char *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_include(char value, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (value == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	wl(char *str, char *charset)
{
	int	i;

	i = 0;
	while ((ft_include(str[i], charset) == 0) && (str[i] != '\0'))
		i ++;
	return (i);
}

int	get_wordn(char *str, char *charset)
{
	int	i;
	int	number_word;
	int	new_word;

	number_word = 0;
	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		while (ft_include(str[i], charset) == 1)
		{
			i++;
			new_word = 1;
		}
		if (str[i] == '\0')
			return (number_word);
		if (new_word == 1)
		{
			number_word++;
			new_word = 0;
		}
		i++;
	}
	return (number_word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		a_wr;

	result = malloc(sizeof(result) * (get_wordn(str, charset) + 1));
	result[get_wordn(str, charset)] = NULL;
	i = 0;
	a_wr = 0;
	while (str[i] != '\0')
	{
		while (ft_include(str[i], charset) == 1)
		{
			i++;
		}
		if (str[i] == '\0')
			return (result);
		if (str[i] != '\0')
		{
			result[a_wr] = malloc(sizeof(result) * (wl(&str[i], charset) + 1));
			ft_strncpy(&str[i], result[a_wr], wl(&str[i], charset));
			a_wr++;
			i += wl(&str[i], charset);
		}
	}
	return (result);
}
