/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:39:02 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/24 18:40:38 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	update_sup(t_game *game)
{
	player_animation(&game->player);
	collec_animation(&game->collects_imgs);
	effect_animation(&game->effect);
	enemy_animation(&game->enemy_imgs);
	mlx_clear_window(&game->mlx, game->window.reference);
	put_map(game);
}

int	update(t_game *game)
{
	if (game->collects != -1)
		update_sup(game);
	if (game->collects == -1)
	{
		mlx_clear_window(&game->mlx, game->window.reference);
		game->effect.img = mlx_xpm_file_to_image(&game->mlx,
				"assets/sprites/respect.xpm",
				&game->img_size.x, &game->img_size.y);
		mlx_put_image_to_window(game->mlx, game->window.reference,
			game->effect.img, (game->wndw_size.x - 455) / 2,
			(game->wndw_size.y - 256) / 2);
	}
	else if (game->player.tile == NULL)
	{
		mlx_clear_window(&game->mlx, game->window.reference);
		game->effect.img = mlx_xpm_file_to_image(&game->mlx,
				"assets/sprites/wasted.xpm",
				&game->img_size.x, &game->img_size.y);
		mlx_put_image_to_window(game->mlx, game->window.reference,
			game->effect.img, (game->wndw_size.x - 530) / 2,
			(game->wndw_size.y - 256) / 2);
	}
	return (1);
}

int	ft_chartable_linecount(char **map)
{
	int	i;

	i = 0;
	while (*map++)
		i++;
	return (i);
}

t_mapchecks	init_checkerdata(char **map)
{
	t_mapchecks	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}
