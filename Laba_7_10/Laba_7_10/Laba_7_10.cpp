#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include "Myheader.h"

int main()
{

	setlocale(LC_ALL, "ru_RU.UTF-8");							// локализация консоли
	int flag = 1;												// флаг основного цикла программы
	int n, m, n1, k;											// размерности матрицы и строки
	wchar_t**** array_of_matrices;								// указатель на массив матриц строк
	while (flag)												// основной цикл программы
	{
		n = 0, m = 0, n1 = 0, k = 0;							// инициализация переменных
		array_of_matrices = NULL;

		void (*matrices_actions[2]) (wchar_t****, int, int, \
		int, int) = { input_str, count_palindroms };			// массив функций взаимодействий с матрицей

		input_int_var(&n1, 1);									// ввод количества матриц
		input_int_var(&n, 2);									// ввод количество строк матрицы
		input_int_var(&m, 3);									// ввод количество столбцов матрицы
		input_int_var(&k, 4);									// ввод размерности строки

		array_of_matrices = memory_alloc(n1, n, m, k);			// выделение памяти для массива матриц

		matrices_actions[0](array_of_matrices, n1, n, m, k);	// ввод элементов матрицы

		output_matrices(array_of_matrices, n1, n, m);			// вывод массива матриц до изменений

		matrices_actions[1](array_of_matrices, n1, n, m, k);	// функция нахождения и вывода палиндромов

		memory_free(array_of_matrices, n1, n, m);				// очистка памяти массива матриц

		restart_program(&flag);									// запрос на перезапуск программы
	}
	return 0;
}