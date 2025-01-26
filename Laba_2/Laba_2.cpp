#include <stdio.h> 
#include <stdlib.h>
#include <math.h>  

#define N 10						// размерность массива

int main(void)
{
	int flag = 1;					// флаг цикла
	int check = 0;					// флаг проверки ввода
	int x;							// переменная для выбора метода ввода
	int array[N];					// массив
	while (flag)					// цикл программы
	{
		printf("This program sorts array via Shell method.\n");
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
					check = scanf_s("%d", &array[i]);										// ввод значения
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
			{
				array[i] = rand() % 200 - 100;	// заполнение массива случайными значениями
			}
			break;
		default:
			break;
		}
		int step = 1;							// начало сортировки
		for (int s = N / 2; s > 0; s /= 2)		// цикл изменения промежутков
		{
			for (int i = s; i < N; ++i)			// цикл перемещения промежутков
			{
				for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)		// цикл сортировки элементов массива
				{
					int temp = array[j];											// присваивание значения временной переменной
					array[j] = array[j + s];										// присваивание элементу массива с индексом [j] значения элемента массива с индексом [j + s]
					array[j + s] = temp;											// присваивание значения временной переменной элементу массива с индексом [j + s]
					printf("Step %d: ", step++);									// вывод номера шага сортировки
					for (int k = 0; k < N; k++)										// цикл перебора элементов массива
					{
						printf("%4d", array[k]);									// вывод значения массива с индексом [k]
					}
					printf("\n");													// переход на новую строку в консоли
				}
			}
		}
		printf("Array is sorted\n");				// вывод сообщения о конце сортировки
		printf("Sorted array:\t");					// вывод сообщения в консоль
		for (int i = 0; i < N; i++)					// цикл перебора элементов массива 
		{
			printf("%d  ", array[i]);				// вывод элемента массива с индексом [i]
		}
		printf("\n");								// переход на новую строку в консоли
		printf("Restart the program? (any/0)\n");	// Запрос на перезапуск программы 
		scanf_s("%d", &flag);						// ввод значения флага цикла программы
		if (flag != 0)								// проверка значения флага
			printf("Restarting the program...\n");  // вывод сообщения о перезапуске программы
		else
			printf("Shutting down...\n");			// вывод сообщения о завершении работы программы
	}

	return 0;
}