#include <stdio.h>
#include <stdlib.h>

#define N 5					// Количество строк массива
#define M 3					// Количество столбцов массива

int main() {
	int flag = 1;			// флаг цикла
	int check = 0;			// флаг проверки ввода
	int x;					// переменная для выбора метода ввода
	int min = 0, count = 0; // минимальный элемент массива и счётчик кратных элементов
	int array[N][M];		// массив
	while (flag)			// цикл программы
	{
		printf("This program counts total number of multiples of minimal array element.\n");
		printf("Enter 1 for manual input or 2 for random input of array elements\n");
		scanf_s("%d", &x);																// получение строки
		switch (x)
		{
		case 1:
			printf("Enter %d digits\n", N);
			for (int i = 0; i < N; i++)													// цикл по элементам массива
				for (int j = 0; j < M; j++)
				{
					while (check != 1)														// цикл ввода и проверки
					{
						printf("Enter decimal number: array[%d] = ", i);					// вывод сообщения с описанием вводимой величины
						check = scanf_s("%d", &array[i][j]);										// ввод значения
						if (check != 1)														// проверка правильности введённой переменной
						{
							printf("Input error: not a decimal number, retry entering.\n"); // вывод сообщения об ошибке
						}
						rewind(stdin);														// очистка буфера ввода
					}
					check = 0;																// обнуление флага цикла ввода
				}
			break;
		case 2:
			for (int i = 0; i < N; i++)			// цикл по элементам массива
				for (int j = 0; j < M; j++)
					array[i][j] = rand() % 200 - 100;	// заполнение массива случайными значениями
			break;
		default:
			break;
		}
		for (int i = 0; i < N; i++)				// цикл по строкам
			for (int j = 0; j < M; j++)			// цикл по столбцам
				if ((i == 0 && j == 0) || array[i][j] < array[i - 1][j - 1])			// нахождение минимального элемента
					min = array[i][j];													// присваивание переменной значения минимального элемента массива
		for (int i = 0; i < N; i++)				// цикл перебора строк
		{
			if (min == 0)						// проверка деления на 0
			{
				count = 1;						// присваивание значения счётчику
				break;
			}
			for (int j = 0; j < M; j++)			// цикл перебора столбцов
				if (array[i][j] % min == 0)		// подсчёт количества кратных элементов
					count++;					// присваивание значения счётчику
		}
		printf("Array: \n");
		for (int i = 0; i < N; i++)				// цикл по строкам
		{
			for (int j = 0; j < M; j++)			// цикл по столбцам
				printf("%d\t", array[i][j]);		// вывод элемента массива
			printf("\n");
		}
		printf("Minimal element of array[%d][%d] is %d.\n", N, M, min);								// Вывод значения минимального значения массива
		printf("Total number of multiples of %d in array[%d][%d] is %d.\n", min, N, M, --count);	// вывод результата
		printf("Restart the program? (any/0)\n");													// Запрос на перезапуск программы 
		scanf_s("%d", &flag);																		// ввод значения флага цикла программы
		if (flag != 0)																				// проверка значения флага
			printf("Restarting the program...\n");													// вывод сообщения о перезапуске программы
		else
			printf("Ending the program...\n");														// вывод сообщения о завершении работы программы
	}
	return 0;
}
