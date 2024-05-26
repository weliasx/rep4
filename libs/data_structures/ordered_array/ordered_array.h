#ifndef INC_ORDERED_ARRAY_SET_H
#define INC_ORDERED_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"

typedef struct ordered_array_set {
    int *data; // элементы множества
    int size; // количество элементов в множестве
    int capacity; // максимальное количество элементов в множестве
} ordered_array_set;

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(int capacity);

// освобождает неиспользуемую оперативную память, отведённую под множество.
static void ordered_array_set_shrinkToFit(ordered_array_set *a);

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a, int size);

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
int ordered_array_set_in(ordered_array_set *set, int value);

// функция для сравнения целочисленных элементов.
int compare_ints(const void *a, const void *b);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2);

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set);

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value);

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value);

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2);

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2);

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2);

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet);

// вывод множества set
void ordered_array_set_print(ordered_array_set set);

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set);

#endif