/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pathfinding.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 14:32:20 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 14:06:18 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lem_in.h"

void    find_path(t_info *info)
{
    int i;
    int path_id;
    
    i = 0;
    path_id = 0;
    while (i < info->room_count && path_id < info->max_path)
    {
        if (info->link_tab[info->start->index][i])
        {
            info->link_tab[info->start->index][i][path_id] = 1;
            info->link_tab[i][info->start->index][path_id] = 1;
            
        }
        i++;
    }
}