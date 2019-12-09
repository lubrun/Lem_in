/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:08:47 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 10:16:09 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strtrimfront(char const *s)
{
	char	*ptr;
	int		n;
	int		c;

	n = 0;
	c = 0;
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n++;
	c = n;
	if (s[n] == '\0')
		return (ptr = ft_strnew((size_t)1));
	while (s[n] != '\0')
		n++;
	ptr = ft_strsub(s, c, (size_t)n);
	return (ptr);
}

static	char	*ft_strtrimback(char const *s)
{
	char	*ptr;
	int		n;

	n = 0;
	while (s[n] != '\0')
		n++;
	while ((s[n] == ' ' || s[n] == '\t' ||
				s[n] == '\n' || s[n] == '\0') && n > 0)
		n--;
	if (n == 0)
		return (ptr = ft_strnew(1));
	ptr = ft_strsub(s, 0, (size_t)n + 1);
	return (ptr);
}

char			*ft_strtrim(char const *s)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = ft_strtrimfront(s);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_strtrimback((char const *)ptr);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
