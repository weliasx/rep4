#ifndef EDUCATIONPROJECT_UNORDER_ARRAY_SET_H
#define EDUCATIONPROJECT_UNORDER_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"


typedef struct unordered_array_set {
    int *data; //Элементы множества
    size_t size; //Количество элементов в множестве
    size_t capacity; //Макс. колличество элементов в множестве
} unordered_array_set;


// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity);


// возвращает множество, состоящее из элементов массива a размера size.
unordered_array_set unordered_array_set_create_from_array(int *a, size_t size);


// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set, иначе - -1
size_t unordered_array_set_in(unordered_array_set set, int value);


// возвращает true(1) если множество subset является
// подмножеством set, иначе false(0)
bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set);


// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2);


// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set);


// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value);


// удаляет элемент value из множества set
void unordered_array_set_delete_element(unordered_array_set *set, int value);


// возвращает объединение множеств set1 и set2.
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2);


// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2);


// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2);


// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universum_set);


// возвращает симметрическую разность множеств set1 и set2
unordered_array_set  unordered_array_set_symmetric_difference(unordered_array_set set1, unordered_array_set set2);


// вывод множества set
void unordered_array_set_print(unordered_array_set set);


// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set);

//освобождает лишнюю память, занимаемую множеством а
static void unordered_array_set_shrinkToFit(unordered_array_set *a);


#endif //EDUCATIONPROJECT_UNORDER_ARRAY_SET_H