#ifndef MYHEADER_H
#define MYHEADER_H

void input_int_var(int* a, int t);												// функция ввода целочисленной переменной
void input_str(wchar_t**** array_of_matrix, int n1, int n, int m, int k);		// функция ввода элементов массива строковых матриц

wchar_t**** memory_alloc(int n1, int n, int m, int k);							// функция выделения памяти для массива матриц строк
wchar_t** memory_alloc(int len, int k);											// функция выделения памяти для массива палиндромов
wchar_t* memory_alloc(int len);													// функция выделения памяти для строки

int is_palindrome(const wchar_t* str, int len, int i);							// функция проверки является ли строка палиндромом
void count_palindroms(wchar_t**** array_of_matrix, int n1, int n, int m, int k);// функция нахождения и подсчёта палиндромов
void save_palindroms(wchar_t*** ans, wchar_t* str, int len, int count);			// функция записи строк в массив палиндромов

void output_matrices(wchar_t**** array_of_matrix, int n1, int n, int m);		// функция вывода значений массива матриц строк
void output_ans(wchar_t** ans, int len);										// функция вывода значений массива палиндромов

void memory_free(wchar_t**** array_of_matrix, int n1, int n, int m);			// функция очистки памяти массива матриц строк
void memory_free(wchar_t** str_array, int len);									// функция очистки памяти массива палиндромов
void memory_free(wchar_t* str);													// функция очистки памяти строки

void restart_program(int* flag);												// функция запроса на перезапуск программы
#endif 