#include <stdio.h>	            
#include <stdlib.h>	            

int main() {
	int flag = 1;			    // флаг цикла
	int check = 0;			    // переменная для проверки ввода
	int n = 0;                  // размерность массива
	int min = 0, max = 0;       // минимальный и максимальный элементы массива
	while (flag)			    // основной цикл программы
	{
		double mark = 0;        // результат
		printf("Sports event takes place. \n\
One of sportsmen has just finished his performance. \n\
Judges must choose marks to evaluate the performance (from 0 to 10).\n");
		printf("This program calculates the final mark for sportsmen.");
		while (check != 1)	                                                                // цикл ввода и проверки
		{
			printf("Enter decimal number of judges (n >= 3): n = ");		                // вывод сообщения с описанием вводимой величины
			check = scanf_s("%d", &n);								                        // ввод значения
			if (check != 1)														            // проверка правильности типа введённого значения
				printf("Input error: not a decimal number, retry entering.\n");             // вывод сообщения об ошибке
			else if (n < 3)                                                                 // проверка правильности введённого значения
			{
				printf("Input error: number of judges is less than 3, retry entering.\n");  // вывод сообщения об ошибке
				check = 0;                                                                  // обнуление переменной для проверки ввода
			}
			rewind(stdin);														            // очистка буфера ввода
		}
		check = 0;																            // обнуление переменной для проверки ввода

		int* array = (int*)calloc(n, sizeof(int));  // выделение памяти для массива
		for (int i = 0; i < n; i++)				    // цикл перебора элементов массива
		{
			while (check != 1)			            // цикл ввода и проверки
			{
				printf("Enter decimal number: mark from judge %d = ", i + 1);				        // вывод сообщения с описанием вводимой величины
				check = scanf_s("%d", array + i);								                    // ввод значения
				if (check != 1)														                // проверка правильности введённого значения
				{
					printf("\033[0;31m");
					printf("Input error: not a decimal number, retry entering.\n");                 // вывод сообщения об ошибке
					printf("\033[0m");
				}
				else if (*(array + i) < 0 || *(array + i) > 10)
				{
					printf("\033[0;31m");
					printf("Input error: mark must be valid: 0 <= mark <= 10, retry entering.\n");  // вывод сообщения об ошибке
					printf("\033[0m");
					check = 0;                                                                      // обнуление переменной для проверки ввода
				}
				rewind(stdin);		            // очистка буфера ввода
			}
			check = 0;                          // обнуление переменной для проверки ввода
		}
		printf("All marks: ");                  // вывод названия массива
		for (int i = 0; i < n; i++)				// цикл перебора элементов массива
		{
			printf("%4d", *(array + i));        // вывод элементов массива
		}
		printf("\n");                           // переход на новую строку в консоли

		for (int i = 1; i < n; i++)             // цикл перебора элементов массива
		{
			if (*(array + i) < *(array + min))  // нахождение минимального элемента
				min = i;                        // присваивание переменной значения минимального элемента массива
			if (*(array + i) > *(array + max))  // нахождение максимального элемента
				max = i;                        // присваивание переменной значения максимального элемента массива
		}
		printf("Maximum mark is \033[0;31m %d \033[0m \n", *(array + max));         // вывод максимального элемента массива
		printf("Minimum mark is \033[0;31m %d \033[0m \n", *(array + min));         // вывод минимального элемента массива

		for (int i = 0; i < n; i++)													// цикл перебора элементов массива
		{
			if (i != max && i != min)												// условие невхождения максимального и минимального элементов массива в итоговую рассчётную формулу
				mark += *(array + i);												// суммирование всех элементов массива, кроме максимального и минимального
		}
		printf("Summary of all marks besides maximum and minimum is %.2f\n", mark);	// вывод промежуточной суммы
		mark /= ((double)n - 2);													// расчёт окончательного результата

		printf("Final mark for sportsman is %.2f \n", mark);						// вывод окончательного результата 

		free(array);																// освобождение выделенной памяти для массива

		printf("Restart the program? (any/0)\n");									// запрос на перезапуск программы 
		scanf_s("%d", &flag);														// ввод значения флага цикла программы
		if (flag != 0)																// проверка значения флага
			printf("Restarting the program...\n");									// вывод сообщения о перезапуске программы
		else
			printf("Ending the program...\n");										// вывод сообщения о завершении работы программы
	}
	return 0;
}
