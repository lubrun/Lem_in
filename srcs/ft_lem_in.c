/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lem_in.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 14:21:25 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 14:31:48 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lem_in.h"

int     main(void)
{
    t_info  info;

    info = parse_info();
    if (info.error)
        return (info.error);
    find_path();
    return (1);
}