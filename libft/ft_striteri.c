/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:51:15 by abelqasm          #+#    #+#             */
/*   Updated: 2021/11/19 21:43:04 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return ;
	while (s[len])
		len++;
	if (s)
	{
		while (i < len)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
