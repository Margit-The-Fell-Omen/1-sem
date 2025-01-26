#ifndef MYHEADER_H
#define MYHEADER_H

void input_int_var(int* a, int min, int max);			// функция ввода целочисленной переменной
void input_double_var(double* a);						// функция ввода вещественной переменной

double** matrix_memory_alloc(int n);					// функция выделения памяти для матрицы

void input_matrix(double** array, int n, int choise);	// функция ввода элементов матрицы
void output_matrix(double** array, int n, int t);		// функция вывода матрицы в консоль
void change_matrix(double** array, int n);				// функция сортировки матрицы

void matrix_memory_free(double** array, int n);			// функция освобождения памяти матрицы

void restart_program(int* flag);						// функция запроса на перезапуск программы
#endif 