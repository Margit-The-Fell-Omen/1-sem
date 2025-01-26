#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "Myheader.h"

void input_int_var(int* a, int t)						// функция ввода и проверки целых чисел
{
	int check = 0;
	while (check != 1)	                                // цикл ввода и проверки
	{
		switch (t)										// вывод сообщений с описанием вводимой величины
		{
		case 1:
			printf("Введите количество матриц(целое положительное десятичное число): \n");
			break;
		case 2:
			printf("Введите количество количество строк матрицы(целое положительное десятичное число): \n");
			break;
		case 3:
			printf("Введите количество количество столбцов матрицы(целое положительное десятичное число): \n");
			break;
		case 4:
			printf("Введите размерность строки(целое положительное десятичное число): \n");
			break;
		default:
			break;
		}
		check = scanf_s("%d", a);								                                                // ввод значения
		if (check != 1)														                                    // проверка правильности типа введённого значения
			printf("\033[1;31mОшибка ввода: не целое десятичное число, попробуйте ввести еще раз.\033[0m\n");   // вывод сообщения об ошибке
		else if (*a <= 0)
		{
			printf("\033[1;31mОшибка ввода: не положительное число, попробуйте ввести еще раз.\033[0m\n");		// вывод сообщения об ошибке
			check--;
		}
		else if (*a >= 100)
		{
			printf("\033[1;31mОшибка ввода: Слишком большое число, попробуйте ввести еще раз.\033[0m\n");		// вывод сообщения об ошибке
			check--;
		}
		rewind(stdin);																							// очистка буфера ввода
	}
}

void input_str(wchar_t**** array_of_matrix, int n1, int n, int m, int k)										// функция ввода элементов массива строковых матриц
{
	wprintf(L"Введите %d строк, длиной не более %d символов: \n", n1 * n * m, k);
	wchar_t* buffer = (wchar_t*)calloc(k + 1, sizeof(wchar_t));													// выделение памяти для буффера
	for (int i = 0; i < n1; i++)																				// цикл по матрицам
		for (int j = 0; j < n; j++)																				// цикл по строкам матриц
			for (int s = 0; s < m; s++)																			// цикл по столбцам матриц
			{
				wprintf(L"Матрица \033[1;36m%d\033[0m строка \033[1;36m%d\033[0m столбец \033[1;36m%d\033[0m\n", i + 1, j + 1, s + 1);
				if (fgetws(buffer, k + 1, stdin) == NULL)														// ввод строки и проверка
				{
					perror("Ошибка ввода строки");
					exit(EXIT_FAILURE);
				}
				if (wcslen(buffer) < k)																			// проверка на соответствие заданному размеру строки
				{
					for (int x = 0; x < wcslen(buffer); x++)													
						*(*(*(*(array_of_matrix + i) + j) + s) + x) = *(buffer + x);							// копирование введённой строки из буффера
				}
				else
				{
					printf("Ошибка ввода строки: введите строку короче %d символов!\n", k);						// вывод сообщения об ошибке
					rewind(stdin);																				// очистка буффера ввода
					s--;																						
				}
				int len = wcslen(*(*(*(array_of_matrix + i) + j) + s));
				for (int x = 0; x < len; x++)
				{
					if(*(*(*(*(array_of_matrix + i) + j) + s) + x) == '\n')
					{
						*(*(*(*(array_of_matrix + i) + j) + s) + x) = '\0';
					}
				}
				rewind(stdin);																					// Очистка буфера ввода
			}
	free(buffer);																								// освобождение памяти буффера
}

wchar_t**** memory_alloc(int n1, int n, int m, int k)												// функция выделения памяти для массива матриц строк
{
	wchar_t**** array_of_matrix = (wchar_t****)calloc(n1, sizeof(wchar_t***));						// выделение памяти для матриц
	
	for (int i = 0; i < n1; i++)																	// цикл по матрицам
	{
		*(array_of_matrix + i) = (wchar_t***)calloc(n, sizeof(wchar_t**));							// выделение памяти для строк матриц
		for (int j = 0; j < n; j++)																	// цикл по строкам
		{
			*(*(array_of_matrix + i) + j) = (wchar_t**)calloc(m, sizeof(wchar_t*));					// выделение памяти для столбцов матриц
			for (int s = 0; s < m; s++)																// цикл по столбцам
				*(*(*(array_of_matrix + i) + j) + s) = (wchar_t*)calloc(k + 1, sizeof(wchar_t));	// выделение памяти для элементов матриц
		}
	}
	return array_of_matrix;
}

wchar_t** memory_alloc(int len, int k)										// функция выделения памяти для массива палиндромов
{
	wchar_t** str_array = (wchar_t**)calloc(len, sizeof(wchar_t*));			// выделение памяти для массива палиндромов
	for (int i = 0; i < len; i++) 
	{
		*(str_array + i) = (wchar_t*)calloc(k + 1, sizeof(wchar_t));		// выделение памяти для палиндрома
	}
	return str_array;
}

wchar_t* memory_alloc(int length)
{
	return (wchar_t*)malloc((length + 1) * sizeof(wchar_t));
}

void memory_free(wchar_t**** array_of_matrix, int n1, int n, int m)	// функция очистки памяти массива матриц строк
{
	if (array_of_matrix != NULL)									// проверка на существование указателя на массив матриц
		for (int i = 0; i < n1; i++)								// цикл по матрицам
		{
			for (int j = 0; j < n; j++)								// цикл по строкам
			{
				for (int s = 0; s < m; s++)							// цикл по столбцам
				{
					free(*(*(*(array_of_matrix + i) + j) + s));		// очистка памяти элемента матрицы
				}
				free(*(*(array_of_matrix + i) + j));				// очистка памяти строки матрицы
			}
			free(*(array_of_matrix + i));							// очистка памяти матриц
		}
		free(array_of_matrix);										// очмстка памяти массива матриц
		array_of_matrix = NULL;										// Обнуление указателя
}

void memory_free(wchar_t** str_array, int len)			// функция очистки памяти массива палиндромов
{
	for (int j = 0; j < len; j++) 
	{
		free(*(str_array + j));							// очистка памяти палиндрома
	}
	free(str_array);									// очистка памяти массива
	str_array = NULL;									// обнуление уакзателя
}

void memory_free(wchar_t* str)							// функция очистки памяти строки
{
	free(str);											// очистка памяти строки
	str = NULL;											// обнуление указателя
}

int is_palindrome(const wchar_t* str, int len, int i)	// функция проверки является ли строка палиндромом
{
	if (towlower(*(str + i)) != towlower(*(str + len - i - 1)))				// проверка крайних символов на идентичность
		return 0;
	else if (i >= len / 2)								// проверка на конец строки
		return 1;
	else
		is_palindrome(str, len, ++i);					// рекурсивный вызов функции для следующих символов
}

void output_ans(wchar_t** ans, int len)					// функция вывода значений массива палиндромов
{
	for (int i = 0; i < len; i++) 
	{
		wprintf(L"Палиндром номер \033[1;36m%d\033[0m\n", i + 1);
		wprintf(L"%ls\n", ans[i]);
	}
}

void count_palindroms(wchar_t**** array_of_matrix, int n1, int n, int m, int k)				// функция нахождения и подсчёта палиндромов
{
	int count = 0;																			// счётчик количества палиндромов

	for (int i = 0; i < n1; i++)															// цикл по матрицам
	{
		for (int j = 0; j < n; j++)															// цикл по строкам
		{
			for (int s = 0; s < m; s++)														// цикл по столбцам
			{
				wchar_t** ans = memory_alloc(1, k);											// выделение памяти для массива палиндромов
				int length = wcslen(*(*(*(array_of_matrix + i) + j) + s));					// вычисление длины элемента матрицы
				wchar_t* temp_str = memory_alloc(length);									// выделение памяти для временной строки

				wcscpy_s(temp_str, length + 1, *(*(*(array_of_matrix + i) + j) + s));		// копирование элемента матрицы во временную строку

				const wchar_t* delim = L" ,.!?;:\n";										// строка разделителей предложения
				wchar_t* word = temp_str;													// указатель для перехода по элементам строки

				while (*word)																// цикл по элементу строки
				{
					while (*word && wcschr(delim, *word))									// пока не резделитель
						word++;																// сдвиг указателя

					wchar_t* start = word;													// инициализация указателя на начало слова

					while (*word && !wcschr(delim, *word))									// пока не разделитель
						word++;																// сдвиг указателя

					if (*word)																// проверка на конец строки
					{
						*word = L'\0';														// запись в конец слова нуль-символа
						word++;																// сдвиг указателя
					}

					int len = wcslen(start);												// вычисление длины слова
					if (len > 0 && is_palindrome(start, len, 0))							// проверка является ли палиндром
					{
						count++;															// увеличение счётчика палиндромов
						save_palindroms(&ans, start, len, count);							// сохранение палиндрома в массив
					}
				}
				memory_free(temp_str);														// освобождение памяти, выделенной для временной строки
				if (count == 0)																// проверка на наличие палиндромов в тексте
				{
					printf("\nВ предложении %d палиндромов нет\n", s + 1 + j * m + i * n * m);
				}
				else
				{
					printf("\nВ предложении %d обнаружено %d палиндромов:\n", s + 1 + j * m + i * n * m, count);
					output_ans(ans, count);													// вывод палиндромов в консоль
				}
				count = 0;
				memory_free(ans, count);													// освобождение памяти, выделенной для массива палиндромов
			}
		}
	}


}

void save_palindroms(wchar_t*** ans, wchar_t* str, int len, int count)		// функция записи строк в массив палиндромов
{
		wchar_t** temp = (wchar_t**)calloc(count, sizeof(wchar_t*));		// создание временного массива на 1 элемент больше предыдущего

		for (int i = 0; i < count - 1; i++)
			*(temp + i) = *(*ans + i);										// копирование элементов из предыдущего массива

		*(temp + count - 1) = (wchar_t*)calloc(len + 2, sizeof(wchar_t));   // выделение памяти для нового слова

		for (int i = 0; i <= len; i++)
			*(*(temp + count - 1) + i) = *(str + i);						// запись слова

		*ans = temp;														// замена изначального массива буферным
}

void output_matrices(wchar_t**** array_of_matrix, int n1, int n, int m)		// функция вывода значений массива матриц строк
{
	wprintf(L"\n\nИсходные матрицы:\n");
	for (int i = 0; i < n1; i++)											// цикл по матрицам 
	{
		wprintf(L"Матрица %d:\n", i+1);
		for (int j = 0; j < n; j++)											// цикл по строкам
		{
			for (int s = 0; s < m; s++)										// цикл по столбцам
			{
				wprintf(L"%ls", *(*(*(array_of_matrix + i) + j) + s));
				int len = wcslen(*(*(*(array_of_matrix + i) + j) + s));
				while (len < 20)
				{
					printf(" ");
					len++;
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}


void restart_program(int* flag)																					// функция перезапуска программы
{
	printf("Для завершения работы программы введите \033[1;32m0\033[0m, иначе перезапуск программы.\n");	    // запрос на перезапуск программы 
	scanf_s("%d", flag);																						// ввод значения флага цикла программы
	if (flag != 0)																								// проверка значения флага
		printf("Перезапуск программы...\n");																	// вывод сообщения о перезапуске программы
	else
		printf("Завершение работы...\n");																		// вывод сообщения о завершении работы программы
}