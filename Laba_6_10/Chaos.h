#ifndef MYHEADER_H
#define MYHEADER_H

void input_int_var(int* a);			// функция ввода размерности строкиp
void input_str(char* str, int n);	// функция ввода строки
char* str_memory_alloc(int n);		// функция выделения памяти для строки
char* change_str(char* str);		// функция изменения строки
void output_str(char* str, int t);	// функция вывода строки в консоль
void str_memory_free(char* str);	// функция освобождения памяти строки
void restart_program(int* flag);	// функция запроса на перезапуск программы
#endif 