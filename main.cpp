#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include "Renderer3D.h"

int main(int argc,char* args[]) {
    // cube

    std::vector<Point3D> points{
        Point3D{-1.0f, -1.0f, -1.0f}, Point3D{1.0f, -1.0f, -1.0f},
        Point3D{1.0f, -1.0f, 1.0f}, Point3D{-1.0f, -1.0f, 1.0f},
        Point3D{-1.0f, 1.0f, -1.0f}, Point3D{1.0f, 1.0f, -1.0f},
        Point3D{1.0f, 1.0f, 1.0f}, Point3D{-1.0f, 1.0f, 1.0f}
    };

    std::vector<Vertex> vertices{
        Vertex{0, 1}, Vertex{1, 2}, Vertex{2, 3},
        Vertex{3, 0}, Vertex{4, 5}, Vertex{5, 6},
        Vertex{6, 7}, Vertex{7, 4}, Vertex{0, 4},
        Vertex{1, 5}, Vertex{2, 6}, Vertex{3, 7}
    };

    // pyramid

    std::vector<Point3D> points2{
        Point3D{-1.0f, -1.0f, -1.0f}, Point3D{1.0f, -1.0f, -1.0f},
        Point3D{1.0f, -1.0f, 1.0f}, Point3D{-1.0f, -1.0f, 1.0f},
        Point3D{0.0f, 1.0f, 0.0f}
    };

    std::vector<Vertex> vertices2{
        Vertex{0, 1}, Vertex{0, 2}, Vertex{1, 3}, Vertex{2, 3},
        Vertex{0, 4}, Vertex{1, 4}, Vertex{2, 4}, Vertex{3, 4}
    };

    // thingy
    std::vector<Point3D> points3{
        Point3D{-1.0f, -1.0f, -1.0f}, Point3D{-1.0f, -1.0f, 1.0f},
        Point3D{1.0f, -1.0f, -1.0f}, Point3D{1.0f, -1.0f, 1.0f},
        Point3D{-1.0f, 1.0f, -1.0f}, Point3D{-1.0f, 1.0f, 1.0f}
    };

    std::vector<Vertex> vertices3{
        Vertex{0, 1}, Vertex{0, 2}, Vertex{1, 3}, Vertex{2, 3},
        Vertex{0, 4}, Vertex{1, 4}, Vertex{2, 4}, Vertex{3, 4}
    };


    using clock = std::chrono::high_resolution_clock;

    auto previousTime = clock::now();

    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow("3D Renderer",960,540,0);
    renderer = SDL_CreateRenderer(window,NULL);


    bool running = true;
    SDL_Event event;

    Renderer3D renderer3D1(window,renderer,points2,vertices2
    );
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) {running = false; break;}

        }
        auto currentTime = clock::now();
        std::chrono::duration<float> deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        float fps = 1.0f / deltaTime.count();

        std::cout << "FPS: " << int(fps) << std::endl;
        renderer3D1.render();
    }

    return 0;
}