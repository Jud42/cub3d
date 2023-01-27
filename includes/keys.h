/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Blaze <Blaze@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:11:40 by Blaze             #+#    #+#             */
/*   Updated: 2023/01/26 01:42:33 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__

#  include "../lib/mlx/linux/mlx.h"
#  define UP 122
#  define DOWN 115
#  define ROT_LEFT 65361
#  define ROT_RIGHT 65363
#  define LEFT 113
#  define RIGHT 100
#  define CLOSE 65307

# elif __APPLE__

#  include "../lib/mlx/mlx.h"
#  define UP 13
#  define DOWN 1
#  define ROT_LEFT 123
#  define ROT_RIGHT 124
#  define LEFT 0
#  define RIGHT 2
#  define CLOSE 53

# endif

#endif
