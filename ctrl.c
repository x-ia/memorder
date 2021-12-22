/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorder.h"

int	control(void)
{
	char	hit;
	int		i;

	i = 0;
	hit = toupper(waitkb());
	while (i < COLS * ROWS + 2)
	{
		if (hit == g_key[i])
			return (i);
		i++;
	}
	if (hit == 'Q')
		return (-9);
	if (hit == 'Z')
		return (-2);
	if ('0' <= hit && hit <= '9')
		return (hit - '0');
	return (-1);
}
