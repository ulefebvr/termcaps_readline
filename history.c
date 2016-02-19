/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 23:57:22 by zipo              #+#    #+#             */
/*   Updated: 2016/02/19 00:51:52 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

#include <stdlib.h>

void           history_move_elem(t_info *info)
{
    int i;

    i = 0;
    while (i < (HISTORY_SIZE - 1))
    {
        info->history[i] = info->history[++i];
    }
}

static int     history_size(char **history)
{
    int i;

    i = 0;
    while (history[i] && i < HISTORY_SIZE)
        i++;
    return (i);
}

void           history_free(char **history)
{
    int i;

    i = history_size(history);
    while (i > 0)
        free(history[--i]);
    free(history);
}

void            add_history(t_info *info, char *cmd)
{
    int size;

    if ((size = history_size(info->history)) == HISTORY_SIZE)
    {
        free(info->history[0]);
        history_move_elem(info);
    }
    info->history[size == HISTORY_SIZE ? size - 1 : size] = ft_strdup(cmd);
}
