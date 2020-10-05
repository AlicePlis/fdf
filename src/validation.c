/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:56:35 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/10 10:56:36 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	valid_color(char *str)
{
	if (str[0] != '0' || str[1] != 'x')
		return (0);
	str += 2;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'F') || (*str >= '0' && *str <= '9') ||
		(*str >= 'a' && *str <= 'f'))
			str++;
		else
			return (0);
	}
	return (1);
}

static int	valid_z(char *str)
{
	if (*str == '-')
		str++;
	while (*str && *str != ',')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	if (*str == ',')
		return (valid_color(++str));
	return (1);
}

static int	valid_line(char *str, int *n)
{
	char	**nums;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	if (!(nums = ft_strsplit(str, ' ')))
		return (0);
	while (nums[i])
	{
		if (flag)
			flag = valid_z(nums[i]);
		ft_memdel((void**)&nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
	if (*n == 0)
		*n = i;
	else if ((*n != 0 && i != *n) || !flag)
		return (0);
	return (1);
}

int			valid_file(int fd)
{
	char	*line;
	int		n;
	int		i;

	n = 0;
	while ((i = get_next_line(fd, &line)))
	{
		if (i < 0)
			return (0);
		if (!valid_line(line, &n))
		{
			ft_memdel((void**)&line);
			return (0);
		}
		ft_memdel((void**)&line);
	}
	return (1);
}
