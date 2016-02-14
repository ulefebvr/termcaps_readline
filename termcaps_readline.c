/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:16:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/14 17:58:34 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "command_line_termcaps.h"

#include <unistd.h>

char        *getnextline(int fd, t_info *info)
{
    char    *line;
    int     ret;

    line = NULL;
    (void)info;
    ret = get_next_line(fd, &line);
    return (ret ? line : NULL);
}

char        *termcaps_readline(t_info *info)
{
    int     term;

    if (isatty(0))
    {
        termcaps_save(1);
        term = termcaps_activation(info->term->is_term);
        // ft_putstr(info->term->prompt);
        ft_putstr("?> ");
        return (return_char(info, term));
    }
    else
    {
        return (getnextline(0, info));
    }
    return (NULL);
}
