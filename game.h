# ifndef GAME_H
# define GAME_H
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Map struct, has coordinates for the map, and visuals inside it
*/
typedef struct s_map{
	char	**map;
	long	x;
	long	y;
}	t_map;

typedef struct s_screen{
	;
}	t_screen;

/*
main struct, has mlx and is parent of all structs
*/
typedef struct s_data{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_screen	*screen;
}	t_data;

# endif
