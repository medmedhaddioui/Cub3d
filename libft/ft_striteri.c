/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:15:00 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/15 20:29:14 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void f(unsigned int i, char *c)
{
    (void) i;
    *c += 1;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(i++, s++);
}

/*int main(void)
{
    char s[] = "hello world";
    ft_striteri(s, f);
    printf("%s\n", s);
    return (0);
}*/
