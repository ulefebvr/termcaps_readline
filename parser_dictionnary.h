/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dictionnary.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:02:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/17 17:11:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DICTIONNARY_H
# define PARSER_DICTIONNARY_H

# define TOKENS			"\'><\\|&:012$\"{}()[]``"

# define CMD			{0, ""}
# define STRING			{1, "'"}

# define BSLH			10
# define CHR			11
# define SQTE			12
# define DQTE			13

typedef struct			s_parse
{
	int					key;
	char				*value;
	struct s_parse		*next;
}						t_parse;

t_parse		*ft_lexer(char *str);
void		free_list(t_parse *begin);
t_parse		*group_nodes(t_parse *list, char *key, int value);
t_parse		*lexer_group(t_parse **cmd, char *skey, char *ekey, int value);
t_parse		*rules_backslash(t_parse	*node);
void		parser_attr_keys(t_parse *list, t_parse *func(t_parse *));
t_parse		*rules_quotes(t_parse *node);

#endif
