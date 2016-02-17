/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_ccp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 23:32:36 by zipo              #+#    #+#             */
/*   Updated: 2016/02/17 10:42:09 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

void    cut_line(t_info *info)
{
    if (info->term->save_cmd)
        free(info->term->save_cmd);
    info->term->save_cmd = ft_strdup(info->term->cmd);
    info->term->pos_c = ft_strlen(info->term->cmd);
    keyboard_clear_line(info);
}

void    copy_line(t_info *info)
{
    if (info->term->save_cmd)
        free(info->term->save_cmd);
    info->term->save_cmd = ft_strdup(info->term->cmd);
}

void    paste_line(t_info *info)
{
    int len;
    int slen;
    int pos_c;
    int plen;

    pos_c = info->term->pos_c;
    if (info->term->save_cmd)
    {
        len = ft_strlen(info->term->cmd);
        plen = ft_strlen(info->term->prompt);
        slen = ft_strlen(info->term->save_cmd);
        if ((len + slen) < BUFFER_SIZE)
        {
            ft_memcpy(&info->term->cmd[pos_c + slen], &info->term->cmd[pos_c], (len - pos_c) + 1);
            ft_memcpy(&info->term->cmd[pos_c], info->term->save_cmd, slen);
            move_cursor(info->term->capa, pos_c , plen, 0);
            info->term->pos_c = ft_strlen(info->term->cmd);
            ft_putstr(info->term->cmd);
        }
    }
}
