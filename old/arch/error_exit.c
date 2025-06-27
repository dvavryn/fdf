/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:34:32 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 11:34:32 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *msg, int status)
{
	write(2, "ERROR\n", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(status);
}
