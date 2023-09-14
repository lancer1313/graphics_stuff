#pragma once

#include <vector>
#include <cmath>

#include "structs.h"

// Функция получения экземаляра единичной матрицы
inline std::vector<std::vector<double>> GetIdentity3X3Matrix()
{
	std::vector<std::vector<double>> newMatrix(3, std::vector<double>(3));
	newMatrix[0][0] = 1; newMatrix[0][1] = 0; newMatrix[0][2] = 0;
	newMatrix[1][0] = 0; newMatrix[1][1] = 1; newMatrix[1][2] = 0;
	newMatrix[2][0] = 0; newMatrix[2][1] = 0; newMatrix[2][2] = 1;
	return newMatrix;
}

// Функция получения экземпляра матрицы поворота
inline std::vector<std::vector<double>> GetRotation3X3Matrix(double fi)
{
	std::vector<std::vector<double>> newMatrix(3, std::vector<double>(3));
	newMatrix[0][0] = std::cos(fi); newMatrix[0][1] = -std::sin(fi); newMatrix[0][2] = 0;
	newMatrix[1][0] = std::sin(fi); newMatrix[1][1] = std::cos(fi); newMatrix[1][2] = 0;
	newMatrix[2][0] = 0; newMatrix[2][1] = 0; newMatrix[2][2] = 1;
	return newMatrix;
}

// Функция получения экземпляра матрицы масштабирования
inline std::vector<std::vector<double>> GetScale3X3Matrix(double kx, double ky)
{
	std::vector<std::vector<double>> newMatrix(3, std::vector<double>(3));
	newMatrix[0][0] = kx; newMatrix[0][1] = 0; newMatrix[0][2] = 0;
	newMatrix[1][0] = 0; newMatrix[1][1] = ky; newMatrix[1][2] = 0;
	newMatrix[2][0] = 0; newMatrix[2][1] = 0; newMatrix[2][2] = 1;
	return newMatrix;
}

// Функция получения экземпляра матрицы перемещения
inline std::vector<std::vector<double>> GetTranslation3X3Matrix(double tx, double ty)
{
	std::vector<std::vector<double>> newMatrix(3, std::vector<double>(3));
	newMatrix[0][0] = 1; newMatrix[0][1] = 0; newMatrix[0][2] = tx;
	newMatrix[1][0] = 0; newMatrix[1][1] = 1; newMatrix[1][2] = ty;
	newMatrix[2][0] = 0; newMatrix[2][1] = 0; newMatrix[2][2] = 1;
	return newMatrix;
}

// Функция применения афинных преобразований к точке
void ApplyAffineToVec3(Vec3& vec, const std::vector<std::vector<double>>& matrix)
{
	double x = vec.x, y = vec.y;
	vec.x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * 1;
	vec.y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * 1;
}