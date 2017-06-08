/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:24:32 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:24:54 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_error_and_exit(const char *error_text, Uint8 sdl)
{
	const char *buf;

	ft_putstr(error_text);
	if (sdl == 1)
	{
		buf = SDL_GetError();
		ft_putstr(buf);
	}
	write(1, "\n", 1);
	SDL_Quit();
	exit(1);
}

void	wolf_error(Uint8 error_code)
{
	if (error_code == MALLOCK_ERROR)
		print_error_and_exit("Mallock allocation error.", 0);
	else if (error_code == INIT_ERROR)
		print_error_and_exit("Unable to init SDL. ", 1);
	else if (error_code == WINDOW_ERROR)
		print_error_and_exit("Unable to init Window. ", 1);
	else if (error_code == RENDERER_ERROR)
		print_error_and_exit("Unable to init Renderer. ", 1);
	else if (error_code == TEXTURE_ERROR)
		print_error_and_exit("Unable to init Textue. ", 1);
}
