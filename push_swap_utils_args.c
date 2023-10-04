/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:55:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 12:37:52 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_arg(char **list_num_s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (list_num_s[i])
	{
		j = 0;
		while (list_num_s[i][j] != '\0')
		{
			c = list_num_s[i][j];
			if (!ft_isdigit(c))
			{
				if (!((c == '-' || c == '+') && j == 0))
					error (NULL);
			}
			j++;
		}
		i++;
	}
	if (((c == '-' || c == '+') && j == 1 && i == 1))
		error(NULL);
	return (0);
}

int	check_max_int(int num, char *str)
{
	char	*max;
	char	*min;
	int		i;

	i = -1;
	max = "2147483647\0";
	min = "-2147483648\0";
	if (num == 2147483647)
	{
		while (max[++i] != '\0')
		{
			if (max[i] != str[i] || ft_strlen (str) > 10)
				return (1);
		}
	}
	i = -1;
	if (num == -2147483648)
	{
		while (min[++i] != '\0')
		{
			if (min[i] != str[i] || ft_strlen (str) > 11)
				return (1);
		}
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
		{
			free (split[i]);
			i++;
		}
		free (split);
	}
}
