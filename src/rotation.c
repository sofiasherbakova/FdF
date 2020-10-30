/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:47:52 by ffood             #+#    #+#             */
/*   Updated: 2020/01/29 17:31:04 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*
** Rotation coordinate by x axis
** method: multiplication by rotation matrix
*/

void	rotate_x(int *y, int *z, double alpha)
{
	int y1;

	y1 = *y;
	*y = y1 * cos(alpha) + *z * sin(alpha);
	*z = -y1 * sin(alpha) + *z * cos(alpha);
}

/*
** Rotation coordinate by y axis
** method: multiplication by rotation matrix
*/

void	rotate_y(int *x, int *z, double beta)
{
	int x1;

	x1 = *x;
	*x = x1 * cos(beta) + *z * sin(beta);
	*z = -x1 * sin(beta) + *z * cos(beta);
}

/*
** Rotation coordinate by z axis
** method: multiplication by rotation matrix
*/

void	rotate_z(int *x, int *y, double gamma)
{
	int x1;
	int y1;

	x1 = *x;
	y1 = *y;
	*x = x1 * cos(gamma) - y1 * sin(gamma);
	*y = x1 * sin(gamma) + y1 * cos(gamma);
}

/*
** Addition of  of 3D
** change coordinates by using isometric formulas
** wist default angle 0.8
*/

void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
