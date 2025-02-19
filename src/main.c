#include "raylib.h"
#include "rlgl.h"
#include "voronoi/voronoi.h"
#include <string.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

Texture get_default_texture(void) {
  return (Texture){.id = rlGetTextureIdDefault(),
                   .width = 1,
                   .height = 1,
                   .mipmaps = 1,
                   .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};
}

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shader Practice");
  SetWindowMonitor(0);

  Shader shader = LoadShader(NULL, "src/voronoi/fs.glsl");

  int time_loc = GetShaderLocation(shader, "time");
  int point1_loc = GetShaderLocation(shader, "point1");
  int point2_loc = GetShaderLocation(shader, "point2");

  float time = 0.0;
  Vector2 points[2];
  init_points(points);

  Texture t = get_default_texture();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    SetShaderValue(shader, time_loc, &time, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, point1_loc, &points[0], SHADER_UNIFORM_VEC2);
    SetShaderValue(shader, point2_loc, &points[1], SHADER_UNIFORM_VEC2);

    BeginShaderMode(shader);
    DrawTexturePro(t, (Rectangle){0, 0, 1, 1},
                   (Rectangle){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT},
                   (Vector2){0, 0}, 0, BLACK);
    EndShaderMode();

    DrawFPS(0, 0);
    EndDrawing();

    time += GetFrameTime();
  }

  CloseWindow();

  return 0;
}
