/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:06:57 by azbk              #+#    #+#             */
/*   Updated: 2024/03/08 17:19:16 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_random(void)
{
	char	buff[4];
	int		nbr;
	int		fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (-1);
	if (read(fd, buff, 4) < 0)
	{
		close(fd);
		return (-1);
	}
	nbr = *(int *)buff;
	close(fd);
	if (nbr < 0)
		nbr *= -1;
	return ('0' + (nbr % 10));
}

char	*create_random_name(void)
{
	char	random_name[8];
	int i;

	i = 0;
	while (i < 7)
	{
		random_name[i] = ft_random();
		if (random_name[i] == -1)
			return (NULL);
		i++;
	}
	random_name[i] = '\0';
	return (ft_strdup(random_name));
}
