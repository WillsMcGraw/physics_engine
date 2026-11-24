    // Libraries
    #include <stdio.h>
    #include <stdlib.h>

    // Header Files
    #include "vector.h"
    #include "raylib.h"

    // Constants
    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 400

    // Global Variables
    vector ball_position;
    float ball_speed = 200.0f; // 200 Pixels per second
    float ball_radius = 30;

    // Declarations
    static void update();
    static void draw();


    int main(int argc, char *argv[]) {
        // Initialize game window
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib - basic window");
        SetTargetFPS(60); 

        vector_init(&ball_position, (float) SCREEN_WIDTH / 2, (float) SCREEN_HEIGHT / 2);

        // Basic testing
        while (!WindowShouldClose()) {
            update();
            draw();
        }

        // Cleanup
        CloseWindow();
    }

    static void update() {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_W)) {
            if (ball_position.y - ball_radius > 0) {
                ball_position.y -= ball_speed * dt;
            }
        }
        if (IsKeyDown(KEY_S)) {
            if (ball_position.y + ball_radius < SCREEN_HEIGHT) {
                ball_position.y += ball_speed * dt;
            }
        }
        if (IsKeyDown(KEY_A)) {
            if (ball_position.x - ball_radius > 0) {
                ball_position.x -= ball_speed * dt;
            }
        }
        if (IsKeyDown(KEY_D)) {
            if (ball_position.x + ball_radius < SCREEN_WIDTH) {
                ball_position.x += ball_speed * dt;
            }
        }
    }

    /**
     * This function holds all the draw commands.
     */
    static void draw() {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Use W, A, S, D to move!", 190, 200, 20, LIGHTGRAY);
            DrawCircle((int)ball_position.x, (int)ball_position.y, ball_radius, MAROON);
        EndDrawing();
    }