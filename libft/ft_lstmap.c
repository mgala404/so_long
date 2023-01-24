/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:22:27 by mgala             #+#    #+#             */
/*   Updated: 2022/11/03 17:55:38 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pr;
	t_list	*pt;
	t_list	*po;

	po = lst;
	pr = 0;
	while (lst != 0)
	{
		pt = ft_lstnew(f(lst->content));
		if (pt == 0)
		{
			ft_lstclear(&pr, del);
			return (0);
		}
		ft_lstadd_back(&pr, pt);
		lst = lst -> next;
	}
	lst = po;
	return (pr);
}
