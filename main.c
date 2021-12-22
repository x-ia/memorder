/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memorder.h"

const unsigned char	g_key[] = { \
	'w', 'e', 'r', 't', \
	's', 'd', 'f', 'g', \
	'x', 'c', 'v', 'b'};

int	main(void)
{
	t_status	*status;
	int			input;

	input = -1;
	status = status_init();
	disp_panel();
	while (status->players > 0)
	{
		disp_proc(status, input);
		input = control();
		status = judge(status, input);
	}
	disp_proc(status, input);
	status_term(status);
	return (0);
}
