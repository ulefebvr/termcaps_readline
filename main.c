/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:57:22 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/19 00:40:20 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <termcap.h>

void print_history(char **history)
{
    int i;

    i = 0;
    while (history[i] && i < HISTORY_SIZE)
    {
        ft_print("-> %s\n", history[i++]);
    }
}

int init_history(t_info *info)
{
    int i;

    i = 0;
    if (info->history = ft_memalloc(HISTORY_SIZE))
    {
        while (i < HISTORY_SIZE)
            info->history[i++] = NULL;
        return (1);
    }
    return (0);
}

int termcap_available(void)
{
    int     ret;
    char    *term;

    ret = 0;
    if ((term = ft_getenv("TERM")))
    {
        if ((tgetent(NULL, term) > 0))
            ++ret;
        free(term);
    }
    return (ret);
}

int main(void) {
    t_info info;
    t_termcaps term;

    ft_bzero(&info, sizeof(info));
    ft_bzero(&term, sizeof(term));

    info.term = &term;
    info.term->is_term = termcap_available();
    info.term->capa = termcap_capainit();
    info.term->cmd = ft_memalloc(BUFFER_SIZE);
    init_history(&info);
    // info.term->prompt = NULL;

    char *command;
    while ((command = termcaps_readline(&info)))
    {
        ft_print("%s\n", command);
        if (info.term->is_term)
            ft_bzero(info.term->cmd, BUFFER_SIZE);
        else
            free(command);
        info.term->pos_c = 0;
        print_history(info.history);
    }
    return 0;
}
