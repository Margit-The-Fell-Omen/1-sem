#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 20

int main(void)
{
	int check = 1;
	setlocale(LC_ALL, "");
	while (check)
	{
		int X[N];																		// вводимый массив
		int x, Y, b;																	// выбор ввода, ответ и максимальный элемент X[]
		printf("This program calculates values for digits\nbased on whether they are less or equal than 0 or more than 0\n");
		printf("Enter 1 for manual input or 2 for random input of array elements\n");
		scanf_s("%d", &x);																// получение строки
		switch (x)
		{
		case 1:
			printf("Enter %d digits\n", N);
			for (int i = 0; i < N; i++)													// цикл по элементам массива
			{
				while (check != 1)														// цикл ввода и проверки
				{
					printf("Enter decimal number: array[%d] = ", i);					// вывод сообщения с описанием вводимой величины
					check = scanf_s("%d", &X[i]);										// ввод значения
					if (check != 1)														// проверка правильности введённой переменной
					{
						printf("Input error: not a decimal number, retry entering.\n"); // вывод сообщения об ошибке
					}
					rewind(stdin);														// очистка буфера ввода
				}
				check = 0;																// обнуление флага цикла ввода
				if (i == 0 || b < X[i])													// нахождение максимального элемента X[]
				{
					b = X[i];
				}
			}
			break;
		case 2:
			for (int i = 0; i < N; i++)						// цикл по элементам массива
			{
				X[i] = rand() % 200 - 100;						// заполнение массива случайными значениями
				if (i == 0 || b < X[i])							// нахождение максимального элемента X[]
				{
					b = X[i];
				}
			}
			break;
		default:
			break;
		}
		
		for (int i = 0; i < 20; i++)
		{
			if (X[i] > 0)
			{
				Y = ((b + X[i]) * (b + X[i])) / X[i];           // вычисление ответа и его вывод
				printf("Y № %d = %d \n", (i + 1), Y);
			}
			else if (b != 0)
			{
				Y = (b * b * b * b + X[i] * X[i]) / (b - X[i]); // вычисление ответа и его вывод
				printf("Y № %d = %d \n", (i + 1), Y);
			}
			else
			{
				printf("Error (can't divide by 0) \n");         // проверка деления на 0
				break;
			}
		}
		check = 0;
		printf("Restart the program? (any/0)\n");               // Запрос на перезапуск программы 
		scanf_s("%d", &check);
		if (check != 0)
		{
			printf("Restarting the program...\n");
		}
		else
		{
			printf("Ending the program...\n");
		}

	}
	return 0;
}
