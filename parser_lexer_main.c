/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:47:57 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/15 18:04:46 by ulefebvr         ###   ########.fr       */
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
		ft_bzero(ret, size);
		ft_strncpy(ret, str, size);
	}
	return (ret);
}

int main(void)
{
	char *tmp = "ls -l ' echo '";
	char *tmp2;
	char *tmp3;
	int i = 0;

	ft_print("%s\n", tmp);
	while ((tmp2 = ft_strchr(tmp, '\'')))
	{
		tmp3 = ft_strndup(tmp, (tmp2 - tmp) ? tmp2 - tmp : 1);
		ft_print("%s\n", tmp3);
		tmp = (tmp2 - tmp) ? tmp2 : ++tmp2;
		if (++i > 10)
			break;
	}
}
