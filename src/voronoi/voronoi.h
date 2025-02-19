#ifndef VORONOI_H
#define VORONOI_H

#include "raylib.h"

void init_points(Vector2 *points);
void move_points(Vector2 *points, float time);
void draw_points(Vector2 *points);

#endif
