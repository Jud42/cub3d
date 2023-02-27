
#ifndef KEYS_TEXTURE_H
# define KEYS_TEXTURE_H

# include "mlx.h"

 # ifdef __linux__ //clavier azerty
	# define UP 122
	# define DOWN 115
	# define LEFT 113
	# define RIGHT 100
	# define ROT_LEFT 65361
	# define ROT_RIGHT 65363
	# define CLOSE 65307 

 # else
	# define UP 13
	# define DOWN 1
	# define ROT_LEFT 123
	# define ROT_RIGHT 124
	# define LEFT 0
	# define RIGHT 2
	# define CLOSE 53
 # endif

#endif
