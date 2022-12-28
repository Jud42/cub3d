#include "../includes/cub3d.h"

// Function to calculate the distance between two points

//cast ray from player to wall

void castRay(t_data *d)
{
    // Vérifier si d est NULL
    if (d == NULL)
    {
        fprintf(stderr, "Error: d is NULL\n");
        return;
    }

    int mapX = (int)d->posX/32;
    int mapY = (int)d->posY/32;

    // Vérifier si d->map est NULL
    if (d->map == NULL)
    {
        fprintf(stderr, "Error: d->map is NULL\n");
        return;
    }

    // Vérifier si les indices mapX et mapY dépassent les limites de d->map
    if (mapX < 0 || mapX >= WIN_W || mapY < 0 || mapY >= WIN_H)
    {
        fprintf(stderr, "Error: mapX or mapY is out of bounds\n");
        return;
    }

    double sideDistX;
    double sideDistY;
    double deltaDistX = fabs(1 / d->pdX);
    double deltaDistY = fabs(1 / d->pdY);
    double perpWallDist;

    int stepX;
    int stepY;

    int hit = 0;
    int side;

    if (d->pdX < 0)
    {
        stepX = -1;
        sideDistX = (d->posX - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - d->posX) * deltaDistX;
    }
    if (d->pdY < 0)
    {
        stepY = -1;
        sideDistY = (d->posY - mapY) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - d->posY) * deltaDistY;
    }

    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
        if (d->map[mapX][mapY] > 0)
            hit = 1;
    }
    //calculate distance projected on camera direction.
    if (side == 0)
        perpWallDist = (mapX - d->posX + (1 - stepX) / 2) / d->pdX;
    else
        perpWallDist = (mapY - d->posY + (1 - stepY) / 2) / d->pdY;

    //calculate height of line to draw on screen
    int lineHeight = (int)(d->resY / perpWallDist);

    //calculate lowest
    //calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + d->resY / 2;
    if(drawStart < 0)
        drawStart = 0;
    int drawEnd = lineHeight / 2 + d->resY / 2;
    if(drawEnd >= d->resY)
        drawEnd = d->resY - 1;

    // Vérifier si drawStart et drawEnd sont valides
    if (drawStart < 0 || drawStart >= d->resY || drawEnd < 0 || drawEnd >= d->resY)
    {
        fprintf(stderr, "Error: drawStart or drawEnd out of bounds\n");
        return;
    }

    //choose wall color
    int color;
    if (d->map[mapX][mapY] == 1)
        color = 0xFF0000; //red
    else if (d->map[mapX][mapY] == 2)
        color = 0x00FF00; //green
    else if (d->map[mapX][mapY] == 3)
        color = 0x0000FF; //blue
    else if (d->map[mapX][mapY] == 4)
        color = 0xFFFF00; //yellow
    else
        color = 0xFFFFFF; //white

    //give x and y sides different brightness
    if (side == 1)
        color = color / 2;

    //draw the pixels of the stripe as a vertical line
    int x = 0;
    while (x < d->resX)
    {
        img_pix_put(d->img, x, drawStart, color);
        if (drawStart < drawEnd)
                drawStart++;
        x++;
    }
}
