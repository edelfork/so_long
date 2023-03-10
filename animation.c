/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:39:51 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/24 18:39:52 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	collec_animation(t_collect_img *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
		img->current_img = img->img_0;
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

void	enemy_animation(t_enemy_img *img)
{
	static int	basic_count;
	static int	follower_count;

	if (basic_count == img->basic_anim)
		img->basic_current = img->basic_01;
	else if (basic_count > img->basic_anim * 2)
	{
		img->basic_current = img->basic_02;
		basic_count = 0;
	}
	basic_count++;
	if (follower_count == img->follow_anim)
		img->follow_current = img->follow_01;
	else if (follower_count > img->follow_anim * 2)
	{
		img->follow_current = img->follow_02;
		follower_count = 0;
	}
	follower_count++;
}

void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
		player->current_img = player->idle_img_1;
	else if (player->framecount == player->idle_frames)
		player->current_img = player->idle_img_0;
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->action_img;
		player->framecount = 0;
	}
	player->framecount += 1;
}

void	trap_animation(t_game *game, t_enemy_img *img, int *flag)
{
	if (game->moves % 3)
	{
		img->trap_current = img->trap_01;
		*flag = 1;
	}
	else
	{
		img->trap_current = img->trap_04;
		*flag = 1;
	}
}

void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter++;
}
