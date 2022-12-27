#include "../includes/cub3d.h"

// Function to calculate the distance between two points
double distance(t_point p1, t_point p2)
{
    double xDifference = p1.x - p2.x;
    double yDifference = p1.y - p2.y;
    return sqrt(xDifference * xDifference + yDifference * yDifference);
}

// Function to calculate the intersection point between two lines
t_point lineIntersectionPoint(t_line l1, t_line l2)
{
    // Calculate the coefficients of the equation for the line
    double A1 = l1.end.y - l1.start.y;
    double B1 = l1.start.x - l1.end.x;
    double C1 = A1 * l1.start.x + B1 * l1.start.y;
    double A2 = l2.end.y - l2.start.y;
    double B2 = l2.start.x - l2.end.x;
    double C2 = A2 * l2.start.x + B2 * l2.start.y;
    double det = A1 * B2 - A2 * B1;

    // Calculate the intersection point
    t_point intersection;
    intersection.x = (B2 * C1 - B1 * C2) / det;
    intersection.y = (A1 * C2 - A2 * C1) / det;
    return intersection;
}

// Function to check if two lines intersect
int linesIntersect(t_line l1, t_line l2)
{
    t_point intersection = lineIntersectionPoint(l1, l2);

    // Check if the intersection point is within the bounds of the two lines
    if (intersection.x >= fmin(l1.start.x, l1.end.x) &&
        intersection.x <= fmax(l1.start.x, l1.end.x) &&
        intersection.x >= fmin(l2.start.x, l2.end.x) &&
        intersection.x <= fmax(l2.start.x, l2.end.x) &&
        intersection.y >= fmin(l1.start.y, l1.end.y) &&
        intersection.y <= fmax(l1.start.y, l1.end.y) &&
        intersection.y >= fmin(l2.start.y, l2.end.y) &&
        intersection.y <= fmax(l2.start.y, l2.end.y))
    {
        return 1;
    }
    return 0;
}

// Function to cast a ray from a point in a given direction
void castRay(t_point start, double angle, t_data *d, t_point *intersection)
{
    // Create a line from the start point in the given direction
    t_line ray;
    ray.start = start;
    ray.end.x = start.x + cos(angle);
    ray.end.y = start.y + sin(angle);

    // Set the intersection point to be the end of the ray
    *intersection = ray.end;
    // Check for intersection with each wall
    int i;
    i = -1;
    while (++i < d->width)
    {
        if (d->map[][] == 1 && linesIntersect(ray, wall.line))
        {
            // Calculate the distance to the intersection point
            t_point tempIntersection = lineIntersectionPoint(ray, wall.line);
            double dist = distance(start, tempIntersection);
            // Check if this is the closest intersection
            if (dist < distance(start, *intersection))
            {
                *intersection = tempIntersection;
            }
        }
        i++;
    }
}