/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dictionnary.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:02:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/15 16:35:18 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DICTIONNARY_H
# define PARSER_DICTIONNARY_H

# define CMD			{0, ""}
# define SQUOTE_OP		{1, "'"}

typedef struct			s_parse
{
	int					key;
	char				*value;
	t_parse				*next;
}						t_parse;

#endif
