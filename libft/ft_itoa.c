/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:30:15 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/21 15:29:51 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_fill(char *str, int i, int n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		str[0] = '-';
		j = 1;
		n *= -1;
	}
	else if (n >= 0)
		i--;
	while (j <= i)
	{
		str[i--] = n % 10 + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		a;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	a = n;
	while (a / 10 != 0 && i++)
		a /= 10;
	if (n < 0)
		str = (char *) ft_calloc(i + 2, sizeof(char));
	else
		str = (char *) ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str_fill(str, i, n);
	return (str);
}

/*int main(void)
{
    char *str1 = ft_itoa(-2147483648);
    char *str2 = ft_itoa(-5);
    char *str3 = ft_itoa(-984548);
    char *str4 = ft_itoa(-2147483647);
    char *str5 = ft_itoa(2147483647);
    char *str6 = ft_itoa(2147483647);
    char *str7 = ft_itoa(-2);
	printf ("%s::\n", str1);
	printf ("%s::\n", str2);
	printf ("%s::\n", str3);
	printf ("%s::\n", str4);
	printf ("%s::\n", str5);
	printf ("%s::\n", str6);
	printf ("%s::\n", str7);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
    return (0);
}*/