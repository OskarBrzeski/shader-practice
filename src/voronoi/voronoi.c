#include "voronoi.h"
#include "raylib.h"

void init_points(Vector2 *points) {
  points[0] = (Vector2){.x = 0.2, .y = 0.3};
  points[1] = (Vector2){.x = 0.8, .y = 0.7};
}

void draw_points(Vector2 *points) {
  int screen_width = GetScreenWidth();
  int screen_height = GetScreenHeight();
  for (int i = 0; i < 2; i++) {
    Vector2 p = points[i];
    DrawCircle(p.x * screen_width, p.y * screen_height, 10.0, WHITE);
  }
}
