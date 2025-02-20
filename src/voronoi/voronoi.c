#include "voronoi.h"
#include "raylib.h"
#include <math.h>

void init_points(Vector2 *points) {
  points[0] = (Vector2){.x = 0.2, .y = 0.3};
  points[1] = (Vector2){.x = 0.5, .y = 0.8};
  points[2] = (Vector2){.x = 0.8, .y = 0.4};
}

void move_points(Vector2 *points, float time) {
  points[0].x = 0.2 + sin(time) / 11;
  points[0].y = 0.3 + cos(time) / 9;

  points[1].x = 0.5 + sin(time) / 14;
  points[1].y = 0.8 + cos(time) / 20;
}

void draw_points(Vector2 *points) {
  int screen_width = GetScreenWidth();
  int screen_height = GetScreenHeight();
  for (int i = 0; i < 3; i++) {
    Vector2 p = points[i];
    DrawCircle(p.x * screen_width, p.y * screen_height, 10.0, WHITE);
  }
}
