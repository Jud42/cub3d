/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:07:26 by Blaze             #+#    #+#             */
/*   Updated: 2023/01/25 16:14:07 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	msg_error(char *s, int flag)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
	if (flag == EXIT)
		exit(EXIT_FAILURE);
	return (1);
}

int	check_extension(const char *str, const char *substr)
{
	int	len;
	int	j;

	if (!str || !substr)
		return (1);
	else if (ft_strlen(str) == ft_strlen(substr))
		return (1);
	len = ft_strlen(str) - 1;
	j = ft_strlen(substr) - 1;
	while (j >= 0 && str[len])
	{
		if (str[len] == substr[j])
		{
			len--;
			j--;
		}
		else
			return (1);
	}
	return (0);
}

void	check_error_argument(int ac, char **av)
{
	if (ac != 2)
		msg_error("Argument", EXIT);
	else if (check_extension(av[1], ".cub"))
		msg_error("Map is not valid", EXIT);
}
