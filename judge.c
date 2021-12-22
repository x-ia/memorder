/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorder.h"

t_status	*judge(t_status *status, int input)
{
	if (input < 0 || input > ROWS * COLS)
		status->msg = MSG_RANGE;
	else if (status->index == status->turn)
	{
		status->arr[status->index] = input;
		status->msg = MSG_TURN;
		status->turn++;
		status->index = 0;
	}
	else if (status->arr[status->index] == input)
	{
		status->index++;
		status->msg = MSG_TURN;
	}
	else
	{
		status->players = -status->players;
		status->msg = MSG_LOSE;
	}
	return (status);
}
