/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorder.h"

void	disp_panel(void)
{
	int	row;
	int	col;
	int	key;

	key = 0;
	row = ROWS;
	while (row > 0)
	{
		row--;
		col = 0;
		printf("\n-");
		while (col++ < COLS)
			printf("----");
		col = 0;
		printf(" \n| ");
		while (col++ < COLS)
			printf("%c | ", g_key[key++]);
	}
	col = 0;
	printf("\n-");
	while (col++ < COLS)
		printf("----");
	printf("\n\n\n\n\n\n\n\n\n");
}

void	disp_init(void)
{
	printf("%s\n", MSG_SELECT);
}

void	disp_proc(t_status *status, int input)
{
	int	j;

	up(5);
	clr_line();
	j = 0;
	if (status->players < 0 || (status->index == status->turn && input >= 0))
	{
		while (j < status->index)
			printf("%c ", g_key[status->arr[j++]]);
//		if (input >= 0)
			printf("%c", g_key[input]);
	}
	printf("\n");
	clr_line();
//	printf("index: %d\tturn: %d\tplayers: %d\t", status->index, status->turn, status->players);
//	if(status->index >= 0)
//		printf("status->arr[i]: %d", status->arr[status->index]);
	if (status->players < 0)
	{
		j = 0;
		while (j++ < status->index)
			printf("  ");
		printf("^\n");
		j = 0;
		while (j++ < status->index)
			printf("  ");
		printf("%c\n", g_key[status->arr[j]]);
	}
	else
		printf("\n\n");
	printf("\n");
	clr_line();
	printf("Player %d: %s\n", status->turn % status->players + 1, status->msg);
}
