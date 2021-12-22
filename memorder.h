/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4inrow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORDER_H
# define MEMORDER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>

# define ROWS 3
# define COLS 4
# define USEC_PAUSE 1000000
# define MAX_TURN 100
# define MSG_SELECT "Input number of players"
# define MSG_TURN "Your turn (Press the keys in order, then press SPACE key.)"
# define MSG_RANGE "Unable to input (the key is out of range.)"
# define MSG_LOSE "You LOSE!"
# define MSG_DRAW "DRAW GAME!"
# define MSG_QUIT "Retired"

# define clr		printf("\033[2J") // Clear terminal
# define clr_right	printf("\033[0K") // Clear from the cursor to end of line
# define clr_left	printf("\033[1K") // Clear from the cursor to head of line
# define clr_line()	printf("\033[2K") // Clear the line
# define location(x,y)	printf("\033[%d;%dH" ,x,y) // Move the cursor to
# define right(x)	printf("\033[%dC" ,x) // Move the cursor right
# define left(x)	printf("\033[%dD" ,x) // Move the cursor left
# define down(y)	printf("\033[%dB" ,y) // Move the cursor down
# define up(y)		printf("\033[%dA" ,y) // Move the cursor up

typedef struct s_status
{
	int		arr[MAX_TURN];
	int		players;
	int		turn;
	int		index;
	char	*msg;
}	t_status;

extern const unsigned char	g_key[];
t_status	*status_init(void);
int			status_players(void);
void		status_term(t_status *status);
void		disp_init(void);
void		disp_players(int players);
void		disp_panel(void);
void		disp_proc(t_status *status);
void		disp_input(int input);
void		disp_diff(t_status *status, int input);
int			control(void);
int			waitkb(void);
int			kbhit(void);
t_status	*judge(t_status *status, int input);

#endif
