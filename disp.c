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

	key = 1;
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
	printf("\n\n\n\n");
}

void	disp_init(void)
{
	printf("%s:\t", MSG_SELECT);
}

void	disp_players(int players)
{
	printf("%d\n", players);
}

void	disp_proc(t_status *status)
{
	up(2);
	clr_line();
	printf("Player %d: %s\n", status->turn % status->players + 1, status->msg);
	clr_line();
	printf("[%d]: ", status->index);
//	printf("index: %d\tturn: %d\tplayers: %d\t", status->index, status->turn, status->players);
//	if(status->index >= 0)
//		printf("status->arr[i]: %d", status->arr[status->index]);
}

void	disp_input(int input)
{
	printf("%c\n", g_key[input]);
	clr_line();
}

void	disp_diff(t_status *status, int input)
{
	int	j;

	printf("\n");
	j = 0;
	while (j < status->index)
		printf("%c ", g_key[status->arr[j++]]);
	printf("%c", g_key[input]);
	printf("\n");
	j = 0;
	while (j++ < status->index)
		printf("  ");
	printf("^\n");
	j = 0;
	while (j++ < status->index)
		printf("  ");
	printf("%c\n", g_key[status->arr[status->index]]);
}
