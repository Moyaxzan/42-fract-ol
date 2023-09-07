/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:29:50 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/07 12:11:46 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 300

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;	// bits per pixel
    int		line_len;
    int		endian;
}	t_img;

typedef	struct s_window
{
	void	*mlx_ptr;
    t_img	img;
	void	*win_ptr;
} t_window;


/*----------------init.c---------------------*/
t_window	*init_window(void);

#endif

