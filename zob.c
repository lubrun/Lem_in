/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zob.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/19 17:07:07 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 17:08:14 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_bitcmp(int a, int b)
{
	int	i;

	i = 32;
	while (i >= 0)
	{
		if ((1 & a >> i) != (1 & b >> 1))
			return (0);
		i--;
	}
	return (1);
}

int		main(void)
{
	int i;

	i = -2147483648;
	while (i < 214748364)
	{
		if (ft_bitcmp(i, 0))
			i = i + 0;
		i++;
	}
	return (0);
}
