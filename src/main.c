#include "raylib.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shader Practice");
  SetWindowMonitor(0);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawFPS(0, 0);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
