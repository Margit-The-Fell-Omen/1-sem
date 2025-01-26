#include <stdio.h>
#include <locale.h>
#include "Myheader.h"

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");				// локализация консоли
	int flag = 1;									// флаг цикла
	int n, choice;									// размерность матрицы и метод ввода значений матрицы
	double** array;									// указатель на матрицу
	while (flag)									// основной цикл программы
	{
		n = 0;										// инициализация переменных
		choice = 0;
		array = NULL;							

		input_int_var(&n, 0, 0);					// ввод зазмерности квадратной матрицы

		array = matrix_memory_alloc(n);				// выделение памяти для матрицы
		input_int_var(&choice, 1, 3);				// выбор метода ввода значений матрицы
		input_matrix(array, n, choice);				// ввод значений матрицы	
		output_matrix(array, n, 1);					// вывод матрицы в консоль
		change_matrix(array, n);					// изменение позиций элементов в матрице
		output_matrix(array, n, 2);					// вывод матрицы в консоль
		matrix_memory_free(array, n);				// освобождение памяти, выделенной для матрицы
		restart_program(&flag);						// запрос на перезапуск программы
	}
	return 0;
}