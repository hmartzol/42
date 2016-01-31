/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 23:34:43 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include "game_2048.h"

int		main(void)
{
	srand(time(NULL));
	int side = 4;
	int i,j;
	int tmp[4][4] = {
		{2,      2,    2,     2},
		{16,     32,   64,    128},
		{256,    512,  1024,  3},
		{4096,   8192, 16384, 32768}};
	int **grid = (int **)malloc(sizeof(int *) * side);
	for (i = 0; i < 4; ++i)
		grid[i] = (int *)malloc(sizeof(int) * side);
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			grid[i][j] = tmp[i][j];
	ft_init_term(1, 0, TRUE, 0);
	i = 0;
	while (getch() != 10)
	{
	i += grid_solve_right(grid, side);
	// i += grid_solve(grid, side, 0);
	print_grid(stdscr, grid, side);
//	ft_menu_main();
//	print_grid(NULL);
//	print_highscores();
//	fill_case(grid, side);
	mvprintw(0, 0, ft_itoa(check_grid(grid, side)));
	mvprintw(0, 3, ft_itoa(i));
	}
	endwin();
	return (0);
}

/*
int		main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", power_check(ft_atoi(argv[1])));
}
*/
