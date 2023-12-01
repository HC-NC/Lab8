#pragma once
#include <iostream>

namespace
{
	int** ReadMatrix(int rows, int columns)
	{
		int** matrix = new int* [rows];

		for (int i = 0; i < rows; i++)
			matrix[i] = new int[columns];


		std::cout << "¬ведите матрицу " << rows << "x" << columns << ":" << std::endl;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cin >> matrix[i][j];
		}

		return matrix;
	}
}

