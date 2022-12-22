#include "cub3d.h" 

/*
    WEST (W): 0° = 360° or 0
    NORTH (N): 270°
    EAST (E): 180°
    SOUTH (S): 90°
 */

double	dist(double ax, double ay, double bx, double by, double ang) 
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

static int	find_expo(int n)
{
	int	expo;

	expo = 0;
	while ((int)pow(2, expo) != n)
		expo++;
	return (expo);
}

void	ray_cast(t_data *d)
{
   	//float because when a convert double to int he decrement -1 (576 to 575)
	int r, mx, my, mp, wall, expo; 
	float rx, ry, ra, xo, yo;
	float aTan;
	
	ra = d->pa;
	aTan = -1/tan(ra);
	expo = find_expo(PIX);
	if (ra > PI)
	{
		ry = (int)d->posY - PIX;
		rx = (d->posY - ry) * aTan + d->posX;
		yo = -PIX;
		xo = -yo * aTan;	
	}
	if (ra < PI)
	{
		ry = (int)d->posY + PIX;
		rx = (d->posY - ry) * aTan + d->posX;
		yo = PIX;
		xo = -yo * aTan;	
	}
	wall = 0;
	while (!wall)
	{
		mx = (int)rx / PIX;
		my = (int)ry / PIX;
		//test
		if (mx >= d->mapX)
			mx = d->mapX - 1;
		else if (mx < 0)
			mx = 0;
		if (my >= d->mapY)
			my = d->mapY - 1;
		else if (my < 0)
			my = 0;
		//
		printf("mx == %d\t my == %d\n", mx, my);
		if (d->map[my][mx] == '1')
		{
			wall = 1;
			//exit (0);
		}
		else
		{
			rx += xo;
			ry += yo;
		}
	}
	draw_direction(d, COL_DIR_P, mx * PIX, my * PIX);
}
