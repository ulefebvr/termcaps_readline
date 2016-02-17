/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dictionnary.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:02:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/17 00:35:45 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DICTIONNARY_H
# define PARSER_DICTIONNARY_H

# define TOKENS			"\'><\\|&:012$\"{}()[]``"

# define CMD			{0, ""}
# define STRING			{1, "'"}



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


#endif
