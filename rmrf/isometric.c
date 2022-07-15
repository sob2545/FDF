#include "math.h"
#include "fdf.h"

void	ft_isometric(double *x, double *y, double z)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * sin(M_PI / 6) - z;
}

void	parallel(t_point *point)
{
	double	x;
	double	y;

	x = point->iso_x;
	y = point->iso_y;
	point->iso_x = x;
	point->iso_y = y;
}

