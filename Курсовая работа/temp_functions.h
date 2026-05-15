// Предотвращение двойного включения заголовочного файла temp_functions_h
#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

// Подключение стандартных библиотек
#include <stdio.h> // для функций ввода-вывода
#include <stdlib.h> // для работы с памятью
#include <string.h> //для строковых функций

// Определяем структуру Record, которая хранит одну запись данных: год, месяц, день, час, минуту и температуру
typedef struct 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} Record;

// Объявляем функции
// Функция read_csv читает CSV-файл, заполняет массив records и возвращает количество записей (count). Возвращает 0 при успехе, -1 — при ошибке.
int read_csv(const char *filename, Record **records, size_t *count);
// Функция print_month_stats выводит статистику (средняя, мин., макс.) за заданный месяц
void print_month_stats(Record *records, size_t count, int month);
// Функция print_year_stats выводит годовую статистику
void print_year_stats(Record *records, size_t count);

#endif