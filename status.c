/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorder.h"

t_status	*status_init(void)
{
	t_status	*status;
	int			i;

	status = malloc(sizeof(t_status));
	i = 0;
	while (i < MAX_TURN)
		status->arr[i++] = 0;
	status->players = status_players();
	status->turn = 0;
	status->index = 0;
	status->msg = MSG_TURN;
	return (status);
}

int	status_players(void)
{
	int	players;

	players = -1;
	disp_init();
	while (players < 0 || players > MAX_TURN)
	{
		players = control();
		if (players < 0)
			players += 10;
	}
	disp_players(players);
	return (players);
}

void	status_term(t_status *status)
{
	free (status);
}
