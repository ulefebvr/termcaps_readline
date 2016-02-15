/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_check_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:57:47 by zipo              #+#    #+#             */
/*   Updated: 2016/02/14 23:45:27 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command_line_termcaps.h"

typedef struct s_bracket
{
    int f_quote;
    int f_dquote;
    int f_mquote;
    int parenthese;
    int bracket;
    int cbracket;
}               t_bracket;

/**
*   int *b
*
*   [0] quote
*   [1] dquote
*   [2] mquote
*   [3] parenthese
*   [4] bracket
*   [5] cbracket
**/

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

int         ft_getflag(char c, int *b)
{
    if (c == '\'')
        b[0] = 1;
    else if (c == '"')
        b[1] = 1;
    else if (c == '`')
        b[2] = 1;
    else if (c == '(')
        b[3] = 1;
    else if (c == '[')
        b[4] = 1;
    else if (c == '{')
        b[5] = 1;
    return (1);
}

int         ft_isclose(char c, int *b, char type, int *fqb)
{
    int i;

    i = -1;
    if (type == 'q')
    {
        if (b[0] && c == '\'' && (i = 0))
            *fqb -= 1;
        if (b[1] && c == '"' && (i = 1))
            *fqb -= 1;
        if (b[2] && c == '`' && (i = 2))
            *fqb -= 1;
    }
    else
    {
        if (b[3] && c == ')' && (i = 3))
            *fqb -= 1;
        if (b[4] && c == ']' && (i = 4))
            *fqb -= 1;
        if (b[5] && c == '}' && (i = 5))
            *fqb -= 1;
    }
    b[i] = 0;
    return (0);
}

int         check_cmd(char *cmd)
{
    int       i;
    int       f_quote;
    int       f_bracket;
    int       b[6];

    i = 0;
    f_quote = 0;
    f_bracket = 0;
    ft_bzero(b, (sizeof(int) * 6));
    while (cmd[i])
    {
        if (ft_fquote(b) && !ft_isclose(cmd[i], b, 'q', &f_quote))
        {
            i++;
            continue;
        }
        else if (ft_fbracket(b) && !ft_isclose(cmd[i], b, 'b', &f_bracket))
        {
            i++;
            continue;
        }
        if (ft_isquote(cmd[i]) && ft_getflag(cmd[i], b))
            f_quote++;
        else if (ft_isbracket(cmd[i]) && ft_getflag(cmd[i], b))
            f_bracket++;
        i++;
    }
    return ((f_bracket || f_quote) ? 0 : 1);
}

char        *return_char(t_info *info)
{
    char            *ret;
    char            *tmp;
    t_termcaps      *term;
    static int      level;

    term = info->term;
    ret = term->cmd;
    tmp = NULL;
    if (!level)
    {
        while (!check_cmd(ret))
        {
            tmp = ft_strdup(ret);
            if (level)
                free(ret);
            ft_bzero(term->cmd, BUFFER_SIZE);
            term->pos_c = 0;
            ++level;
            ret = ft_strjoin(tmp, termcaps_loop(info));
            free(tmp);
        }
        level = 0;
    }
    return (ret);
}
