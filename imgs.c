/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:40:06 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/24 18:40:07 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	get_collects_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/plant_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.img_1 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/plant_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/effect_w.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	get_players_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/player_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/player_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/player_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

void	get_enemies_imgs(t_game *game)
{
	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/enemy_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_02 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/enemy_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_current = game->enemy_imgs.basic_02;
	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/enemy_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_02 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/enemy_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
	game->enemy_imgs.trap_01 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/spikes_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.trap_04 = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/spikes_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.trap_current = game->enemy_imgs.trap_04;
}

void	get_exit_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
}

t_game	get_images(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/wall_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_bord = mlx_xpm_file_to_image(&game->mlx,
			"assets/sprites/wall_d.xpm",
			&game->img_size.x, &game->img_size.y);
	get_collects_imgs(game);
	get_players_imgs(game);
	get_exit_imgs(game);
	get_enemies_imgs(game);
	return (*game);
}
