#include <stdio.h>
#include <locale.h>
#include "Chaos.h"

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");				// локализация консоли
	int flag = 1;									// флаг цикла
	int n;											// размерность матрицы
	char* str;										// указатель на строку
	while (flag)									// основной цикл программы
	{
		n = 0;										// инициализация переменных
		str = NULL;

		input_int_var(&n);							// ввод зазмерности строки

		str = str_memory_alloc(n);					// выделение памяти для строки
		input_str(str, n);							// ввод строки
		output_str(str, 1);							// вывод строки до изменений
		str = change_str(str);						// изменение строки
		output_str(str, 2);							// вывод сроки после изменений
		str_memory_free(str);						// очистка памяти строки
		restart_program(&flag);						// запрос на перезапуск программы
	}
	return 0;
}