#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 2
#define COL_SIZE 2

/*
------------------------------------- CHALLENGE 3 -------------------------------------
			��ó : ���� ������ �ѾƸ� - 3. ������� p.28_Warming up
---------------------------------------------------------------------------------------
				������ �� : �Լ��� �����
*/

void main(void)
{
	int A[ROW_SIZE][COL_SIZE] = { {3,5}, {10,2} };
	int A1[ROW_SIZE][COL_SIZE];
	int A2[ROW_SIZE][COL_SIZE]; // ( (1 / defA) * (A * A1)) = E = (A*A1) / defA  
	int i, j, k, sum, mul = 1, mul2 = 1, defA;

	for (i = 0; i < ROW_SIZE; i++)
	{
		for (j = 0; j < COL_SIZE; j++)
		{
			if (i == j)	mul *= A[i][j];
			else mul2 *= A[i][j];
		}
	}

	defA = mul - mul2;
	if (defA != 0)
	{
		for (i = 0; i < ROW_SIZE; i++)
		{
			for (j = 0; j < COL_SIZE; j++)
			{
				if (i == j) A1[i][j] = A[!i][!j];
				else  A1[i][j] = -A[i][j];
			}
		}
		for (i = 0; i < ROW_SIZE; i++)
		{
			for (j = 0; j < COL_SIZE; j++)
			{
				sum = 0;
				k = 0;
				while (k < COL_SIZE)
				{
					sum += (A[i][k] * A1[k][j]);
					k++;
				}
				A2[i][j] = sum / defA;
			}
		}
	}
	else
	{
		fprintf(stderr, "��Ľ��� 0�̸� ������� �������� �ʽ��ϴ�.");
		exit(1);
	}
}