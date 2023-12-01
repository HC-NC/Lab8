#include <iostream>
#include <Windows.h>

#include "ReadMatrix.h"
#include "DeleteMatrix.h"
#include "GetTwoMatrixMultiply.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, M, K;

	cout << "Введите параметры матриц A[N, M] и B[M, K]:" << endl;

	cin >> N;
	cin >> M;
	cin >> K;

	if (N <= 0 || M <= 0 || K <= 0)
	{
		cout << "Error" << endl;
		return -1;
	}

	cout << "\nMatrix A:" << endl;

	int** A = ReadMatrix(N, M);

	cout << "\nMatrix B:" << endl;

	int** B = ReadMatrix(M, K);

	int** C;

	try
	{
		C = GetTwoMatrixMultiply(A, B, N, M, M, K);
	}
	catch (const char* error_message)
	{
		cout << "\n" << error_message << endl;

		DeleteMatrix(A, N);
		DeleteMatrix(B, M);

		return -2;
	}

	cout << "\nMatrix C[N, K] = A[N, M] x B[M, K]:" << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << C[i][j] << " ";

		cout << endl;
	}

	DeleteMatrix(A, N);
	DeleteMatrix(B, M);
	DeleteMatrix(C, N);
	return 0;
}