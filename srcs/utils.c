#include "../includes/cub3d.h"

int FixAng(int a)
{ 
	if(a>359)
		a-=360;
	if(a<0)
		a+=360;
	 return a;
}
float degToRad(int a)
{ 
	return a*M_PI/180.0;
}

int collision(t_data *d, float x, float y)
{
    int i;
    int j;
    i = (int)(x / 32);
    j = (int)(y / 32);
    if (d->map[j][i] == '1')
        return (1);
    return (0);
}