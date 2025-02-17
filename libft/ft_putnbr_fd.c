/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:36:35 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/15 20:32:49 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n / 10 == 0)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

/*int main(void)
{
    //ft_putnbr_fd(351, 1);
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(9, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-984548, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-2147483647, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(0, 1);
    
    return (0);
}*/