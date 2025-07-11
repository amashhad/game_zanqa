#include <mlx.h>
/*
	mouse tracker, tracks mouse inside the window
		edits the x and y values with curr_x and curr_y of the mouse pointer
	-used in mlx_loop_hook();
*/
void	mouse_tracker(void *mlx, void *window, int x, int y)
{
	mlx_mouse_get_pos(mlx, window, &x, &y);
	printf("x: %dy: %d\n", x, y);
}

/*
	exits when the screen is between
		{coord->start_x; coord->end_x; coord->start_y; coord->end_y;}
			and button 1 is clicked
	-used in mlx_mouse_hook();
	-requires mouse_tracker;
*/
int	mouse_exit_button(int button, int x, int y, void *param)
{
	//example struct
	//example usage --> {t_coord *coord = (t_coord *)param;}
	typedef struct s_coord
	{
		int	start_x;
		int	start_y;
		int	end_x;
		int	end_y;
		int	x;
		int	y;
	} t_coord;

	t_coord *coord;
	//example struct

	if (button == 1 && (coord->x >= coord->start_x && coord->x <= coord->end_x) && (coord->y >= coord->start_y && coord->y <= coord->end_y))
		exit(0);
	return (0);
}

/*
Typical exit function; used in most loop() that needs an exit condition
*/
int	exit_fnc(void *param)
{
	(void) param;
	exit(0);
	return (0);
}
