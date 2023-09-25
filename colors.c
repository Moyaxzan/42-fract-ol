/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:27:12 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/25 10:13:03 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	coefs_kirlian(float coefs[12])
{
	coefs[0] = 9.4;
	coefs[1] = 6.4;
	coefs[2] = 4.2;
	coefs[3] = 2.2;
	coefs[4] = 1.5;
	coefs[5] = 1.1;
	coefs[6] = 0.7;
	coefs[7] = 0.45;
	coefs[8] = 0.2;
	coefs[9] = 0.1;
	coefs[10] = 0.05;
}

void	colors_kirlian(int colors[12], float coefs[11])
{
	colors[0] = 0x0FFFFFF;
	colors[1] = 0x0fdebff;
	colors[2] = 0x0dca2fb;
	colors[3] = 0x0ba75c9;
	colors[4] = 0x08c4dbe;
	colors[5] = 0x03C2FA8;
	colors[6] = 0x02D237E;
	colors[7] = 0x0261D69;
	colors[8] = 0x017123F;
	colors[9] = 0x00F0C2A;
	colors[10] = 0x0000000;
	coefs_kirlian(coefs);
}

void	coefs_rainbow(float coefs[12])
{
	coefs[0] = 5.4;
	coefs[1] = 3.0;
	coefs[2] = 2.2;
	coefs[3] = 1.2;
	coefs[4] = 0.9;
	coefs[5] = 0.72;
	coefs[6] = 0.57;
	coefs[7] = 0.35;
	coefs[8] = 0.2;
	coefs[9] = 0.1;
	coefs[10] = 0.05;
}

void	colors_rainbow(int colors[12], float coefs[11])
{
	colors[0] = 0x0ff0000;
	colors[1] = 0x0ff8000;
	colors[2] = 0x0ffff00;
	colors[3] = 0x080ff00;
	colors[4] = 0x000ff80;
	colors[5] = 0x000ffff;
	colors[6] = 0x00080ff;
	colors[7] = 0x00000ff;
	colors[8] = 0x08000ff;
	colors[9] = 0x0ff00ff;
	colors[10] = 0x0ff0080;
	coefs_rainbow(coefs);
}
