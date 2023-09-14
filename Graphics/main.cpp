#include <iostream>
#include <vector>

#include <SDL.h>

#include "structs.h"
#include "data.h"
#include "matrix_functions.h"

void ChangePointsScale(std::vector<Vec3>& points, const Vec3& centeroid, double kx, double ky)
{
	for (auto& point : points)
	{
		point.x -= centeroid.x;
		point.y -= centeroid.y;
		point.z -= centeroid.z;
		ApplyAffineToVec3(point, GetScale3X3Matrix(kx, ky));
		point.x += centeroid.x;
		point.y += centeroid.y;
		point.z += centeroid.z;
	}
}

void MovePoints(std::vector<Vec3>& points, const Vec3& centeroid, double translationX, double translationY)
{
	for (auto& point : points)
	{
		point.x -= centeroid.x;
		point.y -= centeroid.y;
		point.z -= centeroid.z;
		ApplyAffineToVec3(point, GetTranslation3X3Matrix(translationX, translationY));
		point.x += centeroid.x;
		point.y += centeroid.y;
		point.z += centeroid.z;
	}
}

void RotatePoints(std::vector<Vec3>& points, const Vec3& centeroid, double angle)
{
	for (auto& point : points)
	{
		point.x -= centeroid.x;
		point.y -= centeroid.y;
		point.z -= centeroid.z;
		ApplyAffineToVec3(point, GetRotation3X3Matrix(angle));
		point.x += centeroid.x;
		point.y += centeroid.y;
		point.z += centeroid.z;
	}
}

Vec3 MakeCenteroid(const std::vector<Vec3>& points)
{
	Vec3 centeroid{ 0,0,0 };
	for (auto& point : points)
	{
		centeroid.x += point.x;
		centeroid.y += point.y;
		centeroid.z += point.z;
	}
	centeroid.x /= points.size();
	centeroid.y /= points.size();
	centeroid.z /= points.size();

	return centeroid;
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::exit(1);
	}

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(WIDTH * SCALE, HEIGHT * SCALE, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, SCALE, SCALE);

	bool isRunning = true;

	Vec3 centeroid = MakeCenteroid(points);

	while (isRunning)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				// Поворот объекта по часовой стрелке
				case SDLK_RIGHT:
					RotatePoints(points, centeroid, FI);
					break;
				// Поворот объекта против часовой стрелки
				case SDLK_LEFT:
					RotatePoints(points, centeroid, -FI);
					break;
				// Увеличение масштаба
				case SDLK_KP_PLUS:
					ChangePointsScale(points, centeroid, KX_PLUS, KY_PLUS);
					break;
				// Уменьшение масштаба
				case SDLK_KP_MINUS:
					ChangePointsScale(points, centeroid, KX_MINUS, KY_MINUS);
					break;
				// Перемещение влево
				case SDLK_1:
					MovePoints(points, centeroid, TRANSL_LEFT, 0);
					break;
				// Перемещение вправо
				case SDLK_2:
					MovePoints(points, centeroid, TRANSL_RIGTH, 0);
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

		for (auto& conn : connections)
		{
			SDL_RenderDrawLine(renderer, points[conn.a].x, points[conn.a].y, points[conn.b].x, points[conn.b].y);
		}

		SDL_RenderPresent(renderer);
	}

	return 0;
}