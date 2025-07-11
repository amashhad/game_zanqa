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

typedef struct s_images{
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
}	t_images;

/*
main struct, has mlx and is parent of all structs
*/
typedef struct s_data{
	int			img_width;
	int			img_height;
	int			player_x;
	int			player_y;
	void		*mlx;
	void		*window;
	t_map		*map;
	t_images	*images;
	t_screen	*screen;
}	t_data;

void	move_player(t_data *data, int dx, int dy);

# endif
