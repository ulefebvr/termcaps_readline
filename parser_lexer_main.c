/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:47:57 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/17 00:39:53 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_dictionnary.h"

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

t_parse		*lexer_syntax_highlight(char *str, char *token)
{
	char	*tmp;
	t_parse	*node;

	node = NULL;
	if (str && *str)
	{
		node = (t_parse *)malloc(sizeof(t_parse));
		ft_bzero(node, sizeof(t_parse));
		if (tmp = ft_strchrtab(str, TOKENS))
		{
			node->value = ft_strndup(str, (tmp - str) ? tmp - str : 1);
			node->next = lexer_syntax_highlight((tmp - str) ? tmp : ++tmp, token);
		}
		else
		{
			node->value = ft_strdup(str);
			node->next = lexer_syntax_highlight(NULL, token);
		}
	}
	return (node);
}

t_parse		*ft_lexer(char *str)
{
	t_parse	*cmd;

	cmd = lexer_syntax_highlight(str, TOKENS);
	cmd = lexer_group(&cmd, "'", "'", 5);
	cmd = lexer_group(&cmd, "\"", "\"", 6);
	cmd = lexer_group(&cmd, "(", ")", 7);
	cmd = lexer_group(&cmd, "{", "}", 8);
	cmd = lexer_group(&cmd, "[", "]", 9);
	cmd = lexer_group(&cmd, "`", "`", 10);
	return (cmd);
}

void		free_list(t_parse *begin)
{
	if (begin)
	{
		free_list(begin->next);
		free(begin->value);
		free(begin);
	}
}

// int main(void)
// {
// 	char *tmp1 = "ls -l \' ec:\"ho while \' fo\"uwe >\\<ouh |while test 1 | && jjd";
//
// 	ft_print("%s\n", tmp1);
//
// 	t_parse *begin = ft_lexer(tmp1, TOKENS);
// 	t_parse *tmp = begin;
// 	while (tmp)
// 	{
// 		ft_print("[%s]\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	free_list(begin);
// }
