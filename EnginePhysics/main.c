    // Libraries
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    // Header Files
    #include "vector.h"
    #include "raylib.h"

    // Constants
    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 400

    // Global Variables
    vector ball;
    float ball_acc = 10.0f; // 10 Pixels per second per second
    float friction_acc = 3; // 3 Pixels per second per second
    float ball_radius = 30; // 30 Pixel radius

    // Declarations
    static void update();
    static void draw();


    int main(int argc, char *argv[]) {
        // Initialize game window
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib - basic window");
        SetTargetFPS(60); 

        vector_init(&ball, (float) SCREEN_WIDTH / 2, (float) SCREEN_HEIGHT / 2);

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
        bool keyDown = false;

        // Calculate new velocities
        if (IsKeyDown(KEY_W)) {
            ball.y_vel -= (ball_acc - friction_acc) * dt;
            keyDown = true;
        }
        if (IsKeyDown(KEY_S)) {
            ball.y_vel += (ball_acc - friction_acc) * dt;
            keyDown = true;
        }
        if (IsKeyDown(KEY_A)) {
            ball.x_vel -= (ball_acc - friction_acc) * dt;
            keyDown = true;
        }
        if (IsKeyDown(KEY_D)) {
            ball.x_vel += (ball_acc - friction_acc) * dt;
            keyDown = true;
        }

        if (!keyDown) {
            if (ball.x_vel != 0) {
                ball.x_vel += copysignf(friction_acc * dt, -1 * ball.x_vel);
                
                //copysignf(ball.x_vel, -1 * ball.x_vel) * friction_acc * dt;
            }
            if (ball.y_vel != 0) {
                ball.y_vel += copysignf(friction_acc * dt, -1 * ball.y_vel);
                // ball.y_vel += ((ball.y_vel) / fabs(ball.y_vel)) * friction_acc * dt;
            }
        }
        

        // Calculate new posiitons
        ball.x_pos += ball.x_vel;
        ball.y_pos += ball.y_vel;

        // Check X posiitoning
        if (ball.x_pos - ball_radius < 0) {
            ball.x_pos = 0 + ball_radius;
            ball.x_vel = 0;
        }
        else if (ball.x_pos + ball_radius > SCREEN_WIDTH) {
            ball.x_pos = SCREEN_WIDTH - ball_radius;
            ball.x_vel = 0;
        }
        // Check Y positioning
        if (ball.y_pos - ball_radius < 0) {
            ball.y_pos = 0 + ball_radius;
            ball.y_vel = 0;
        }
        else if (ball.y_pos + ball_radius > SCREEN_HEIGHT) {
            ball.y_pos = SCREEN_HEIGHT - ball_radius;
            ball.y_vel = 0;
        }
    }

    /**
     * This function holds all the draw commands.
     */
    static void draw() {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Use W, A, S, D to move!", 190, 200, 20, LIGHTGRAY);
            DrawCircle((int)ball.x_pos, (int)ball.y_pos, ball_radius, MAROON);
        EndDrawing();
    }