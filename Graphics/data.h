#pragma once

#include <vector>

#include "structs.h"

// Размер окна и начальный масштаб
constexpr int WIDTH = 640;
constexpr int HEIGHT = 480;
constexpr float SCALE = 2;

// Координаты середины окна
constexpr int WIDTH_CENTER = WIDTH / 2;
constexpr int HEIGHT_CENTER = HEIGHT / 2;

// Угол поворота
const double FI = 0.04;

// Коэффициенты приближения
const double KX_PLUS = 1.1, KY_PLUS = 1.1;

// Коэффициенты отдаления
const double KX_MINUS = 0.9, KY_MINUS = 0.9;

// Коэффициенты перемещения по оси Х
const double TRANSL_RIGTH = 3, TRANSL_LEFT = -3;

static std::vector<Vec3> points
{
	// Корпус и крыша
	{WIDTH_CENTER + 40, HEIGHT_CENTER - 70, 1},					// 0
	{WIDTH_CENTER + 40, HEIGHT_CENTER + 70, 1},					// 1
	{WIDTH_CENTER - 40, HEIGHT_CENTER + 70, 1},					// 2
	{WIDTH_CENTER - 40, HEIGHT_CENTER - 70, 1},					// 3
	{WIDTH_CENTER, HEIGHT_CENTER - 70 - 40, 1},					// 4

	// Верхнее окно, внешнее
	{WIDTH_CENTER + 20, HEIGHT_CENTER - 50, 1},					// 5
	{WIDTH_CENTER + 20, HEIGHT_CENTER - 10, 1},					// 6
	{WIDTH_CENTER - 20, HEIGHT_CENTER - 10, 1},					// 7
	{WIDTH_CENTER - 20, HEIGHT_CENTER - 50, 1},					// 8

	// Нижнее окно, внешнее
	{WIDTH_CENTER + 20, HEIGHT_CENTER + 10, 1},					// 9
	{WIDTH_CENTER + 20, HEIGHT_CENTER + 50, 1},					// 10
	{WIDTH_CENTER - 20, HEIGHT_CENTER + 50, 1},					// 11
	{WIDTH_CENTER - 20, HEIGHT_CENTER + 10, 1},					// 12

	// Верхнее окно, внутреннее
	{WIDTH_CENTER + 10, HEIGHT_CENTER - 40, 1},					// 13
	{WIDTH_CENTER + 10, HEIGHT_CENTER - 20, 1},					// 14
	{WIDTH_CENTER - 10, HEIGHT_CENTER - 20, 1},					// 15
	{WIDTH_CENTER - 10, HEIGHT_CENTER - 40, 1},					// 16

	// Нижнее окно, внутреннее
	{WIDTH_CENTER + 10, HEIGHT_CENTER + 20, 1},					// 17
	{WIDTH_CENTER + 10, HEIGHT_CENTER + 40, 1},					// 18
	{WIDTH_CENTER - 10, HEIGHT_CENTER + 40, 1},					// 19
	{WIDTH_CENTER - 10, HEIGHT_CENTER + 20, 1},					// 20

	// Правое крыло
	{WIDTH_CENTER + 40 + 40, HEIGHT_CENTER + 70, 1},			// 21
	{WIDTH_CENTER + 40 + 40, HEIGHT_CENTER + 70 + 40, 1},		// 22

	// Левое крыло
	{WIDTH_CENTER - 40 - 40, HEIGHT_CENTER + 70, 1},			// 23
	{WIDTH_CENTER - 40 - 40, HEIGHT_CENTER + 70 + 40, 1}		// 24
};

// Соединения между точками
static std::vector<Connection> connections
{
	{0,1},
	{0,3},
	{1,2},
	{2,3},
	{4,0},
	{4,3},
	{5,6},
	{5,8},
	{6,7},
	{7,8},
	{9,10},
	{9,12},
	{10,11},
	{11,12},
	{13,14},
	{13,16},
	{14,15},
	{15,16},
	{17,18},
	{17,20},
	{18,19},
	{19,20},
	{1,21},
	{1,22},
	{21,22},
	{2,23},
	{2,24},
	{23,24}
};