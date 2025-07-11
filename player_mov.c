#include "game.h"

int	is_valid_move(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || !data->map->map[y] || !data->map->map[y][x]
		|| data->map->map[y][x] == '1')
		return (0);
	return (1);
}

void	update_player_position(t_data *data, int new_x, int new_y)
{
	data->map->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map->map[data->player_y][data->player_x] = 'P';
}

void	render_tile(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->window, data->images->img_floor, j
		* data->img_width, i * data->img_height);
	if (data->map->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->images->img_wall, j
			* data->img_width, i * data->img_height);
	else if (data->map->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->window, data->images->img_player, j
			* data->img_width, i * data->img_height);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx, data->window);
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			render_tile(data, i, j);
			j++;
		}
		i++;
	}
}

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (!is_valid_move(data, new_x, new_y))
		return ;
	update_player_position(data, new_x, new_y);
	render_map(data);
}