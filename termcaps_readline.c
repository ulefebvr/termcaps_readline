/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:16:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/12 23:51:01 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "command_line_termcaps.h"

#include <unistd.h>

typedef struct s_bracket
{
    int f_quote;
    int f_dquote;
    int f_mquote;
    int parenthese;
    int bracket;
    int cbracket;
}               t_bracket;

int         ft_fquote(t_bracket *b)
{
    return (b->f_quote || b->f_dquote || b->f_mquote);
}

int         ft_fbracket(t_bracket *b)
{
    return (b->parenthese || b->bracket || b->cbracket);
}

int         ft_isquote(char c)
{
    return (c == '\'' || c == '"' || c == '`');
}

int         ft_isbracket(char c)
{
    return (c == '{' || c == '[' || c == '(');
}

int         ft_getflag(char c, t_bracket *b)
{
    if (c == '\'')
        b->f_quote = 1;
    else if (c == '"')
        b->f_dquote = 1;
    else if (c == '`')
        b->f_mquote = 1;
    else if (c == '(')
        b->parenthese = 1;
    else if (c == '[')
        b->bracket = 1;
    else if (c == '{')
        b->cbracket = 1;
    return (1);
}

int         ft_isclose(char c, t_bracket *b, char type, int *fqb)
{
        if (type == 'q')
        {
            if (b->f_quote && c == '\'')
            {
                *fqb -= 2;
                return (b->f_quote = 0, 1);
            }
            if (b->f_dquote && c == '"')
                return (1);
            if (b->f_mquote && c == '`')
                return (1);
        }
        else
        {
            if (b->parenthese && c == ')')
                return (1);
            if (b->bracket && c == ']')
                return (1);
            if (b->cbracket && c == '}')
                return (1);
        }
        return (0);
}

int         check_cmd(char *cmd)
{
    int       i;
    int       f_quote;
    int       f_bracket;
    t_bracket b;

    i = 0;
    f_quote = 0;
    f_bracket = 0;
    b.f_quote = 0;
    b.f_dquote = 0;
    b.f_mquote = 0;
    b.parenthese = 0;
    b.bracket = 0;
    b.cbracket = 0;
    while (cmd[i])
    {
        if (ft_fquote(&b) && !ft_isclose(cmd[i], &b, 'q', &f_quote))
        {
            i++;
            continue;
        }
        else if (ft_fbracket(&b) && !ft_isclose(cmd[i], &b, 'b', &f_bracket))
        {
            i++;
            f_bracket--;
            continue;
        }
        if (ft_isquote(cmd[i]) && ft_getflag(cmd[i], &b))
            f_quote++;
        else if (ft_isbracket(cmd[i]) && ft_getflag(cmd[i], &b))
            f_bracket++;
        i++;
    }
    return ((f_bracket || f_quote) ? 0 : 1);
}

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
        ft_putstr(info->term->prompt);
        return ((term) ? termcaps_loop(info) : getnextline(0, info));
    }
    else
    {
        return (getnextline(0, info));
    }
    return (NULL);
}
