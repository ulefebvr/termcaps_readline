/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:47:57 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/15 18:39:12 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "parser_dictionnary.h"

char		*ft_strndup(char *str, size_t size)
{
	char	*ret;

	ret = NULL;
	if (size && str && (ret = (char *)malloc(sizeof(char) * size + 1)))
	{
		ft_bzero(ret, size + 1);
		ft_strncpy(ret, str, size);
	}
	return (ret);
}

char		*ft_strchrtab(char *str, char *delim)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(delim, str[i]))
			return (&str[i]);
		++i;
	}
	return (NULL);
}

int main(void)
{
	char *tmp = "ls -l ' echo ' fouwe >\\<ouh ";
	char *tmp2;
	char *tmp3;
	int i = 0;

	ft_print("%s\n", tmp);
	// while ((tmp2 = ft_strchr(tmp, '\'')))
	while ((tmp2 = ft_strchrtab(tmp, "\'><\\")))
	{
		tmp3 = ft_strndup(tmp, (tmp2 - tmp) ? tmp2 - tmp : 1);
		ft_print("%s\n", tmp3);
		free(tmp3);
		tmp = (tmp2 - tmp) ? tmp2 : ++tmp2;
		if (++i > 10)
			break;
	}
	ft_print("%s\n", tmp);
}
