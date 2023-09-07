/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:29:50 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/07 10:44:34 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 300

# include "minilibx-linux/mlx.h"
# include <stdlib.h>

typedef	struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_window;

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;	// bits per pixel
    int		line_len;
    int		endian;
}	t_img;

/*----------------init.c---------------------*/
t_window	*init_window(void);

#endif

