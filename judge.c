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
//	printf("turn: %d\tindex: %d\tinput: %d\tROWS * COLS: %d\n", status->turn, status->index, input, ROWS * COLS);
	if (input == -9)
	{
		status->msg = MSG_QUIT;
		status->players = -status->players;
	}
	else if (input < 0 || input > ROWS * COLS + 1)
		status->msg = MSG_RANGE;
	else if (status->index == status->turn && input != ROWS * COLS + 1)
	{
		status->arr[status->index] = input;
		status->index++;
		status->msg = MSG_TURN;
	}
	else if (status->index == status->turn + 1 && input == ROWS * COLS + 1)
	{
		status->turn++;
		status->index = 0;
		status->msg = MSG_TURN;
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
