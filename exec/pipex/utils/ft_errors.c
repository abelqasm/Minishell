/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:48:12 by abelqasm          #+#    #+#             */
/*   Updated: 2022/05/29 19:16:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(1);
}

void	ft_argmt_error(void)
{
	write(1, "Wrong number of arguments\n", 26);
	exit(0);
}
