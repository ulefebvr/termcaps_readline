/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:15:59 by zipo              #+#    #+#             */
/*   Updated: 2016/02/19 01:16:43 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

char **get_history(history)
{
    char **cpy;
    int  i;

    cpy = ft_memalloc(HISTORY_SIZE + 1);
    i = 1;
    cpy[0] = NULL;
    while (history[i - 1] && i <= HISTORY_SIZE)
    {
        cpy[i] = ft_strdup(history[i - 1]);
        i++;
    }
    return (cpy);
}

char *history_gestion(char **history, int case, char *cmd)
{
    static int pos;
    static char **history_cpy;

    if (!case)
        history_cpy = get_history(history);
    else if (case == 1 || case == -1)
    {
        if (cmd && history_cpy[pos])
            free(history_cpy[pos]);
        history_cpy[pos] = ft_strdup(cmd);
        if (pos < HISTORY_SIZE && pos > 0)
            pos += case;
        return (history_cpy[pos]);
    }
    else
    {
        history_free(history_cpy);
        pos = 0;
    }
    return (NULL);
}
