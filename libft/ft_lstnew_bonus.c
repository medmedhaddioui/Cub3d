/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:07:58 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/18 16:26:47 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/*int main() {
    int example_content = 42;

    t_list *new_node = ft_lstnew(&example_content);

    if (new_node)
	{
        printf("Content of the new node: %d\n", *((int *)new_node->content));
        free(new_node);
    }
	else
        printf("Memory allocation failed.\n");
    return 0;
}*/