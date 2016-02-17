/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 22:59:17 by zipo              #+#    #+#             */
/*   Updated: 2016/02/16 23:02:27 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

int         ft_fquote(int *b)
{
    return (b[0] || b[1] || b[2]);
}

int         ft_fbracket(int *b)
{
    return (b[3] || b[4] || b[5]);
}

int         ft_isquote(char c)
{
    return (c == '\'' || c == '"' || c == '`');
}

int         ft_isbracket(char c)
{
    return (c == '{' || c == '[' || c == '(');
}
