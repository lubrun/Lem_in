/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoull.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 20:59:57 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 21:19:51 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned long long	ft_atoull(char *str)
{
	unsigned long long	res;
	int					x;
	int					pos;

	x = 0;
	res = 0;
	pos = 1;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
			|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' && str[x + 1] != '-')
		x++;
	if (str[x] == '-')
	{
		pos = -pos;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = (res * 10) + (str[x] - '0');
		x++;
	}
	return (res * pos);
}
