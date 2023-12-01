#pragma once

int** GetTwoMatrixMultiply(int** A, int** B, int rowsA, int columnsA, int rowsB, int columnsB)
{
	if (columnsA != rowsB)
		throw "Перемножение матриц невозможно! Количество строк первой матрицы не равно количеству столбцов второй.";

	int** result = new int* [rowsA];

	for (int i = 0; i < rowsA; i++)
		result[i] = new int[columnsB];

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < columnsB; j++)
		{
			int num = 0;

			for (int k = 0; k < columnsA; k++)
				num += A[i][k] * B[k][j];

			result[i][j] = num;
		}
	}

	return result;
}