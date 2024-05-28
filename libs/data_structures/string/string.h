#include <stdio.h>
#include <ctype.h>
#include <memory.h>

//Возвращает количество символов в строке(не считая ноль-символ)
int string_strlen(const char *begin);

//Возвращает указатель на первый элемент с кодом ch, расположенным
//на ленте(участке) памяти между адресами begin и end.
//Если символ не найден, возвращает значение end.
char* string_find(char *begin, char *end, int ch);

//Возвращает указатель на первый символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
//Если символ не найден, возвращает адрес первого ноль-символа.
char* string_find_non_space(char *begin);

//Возвращает указатель на первый пробельный символ, расположенный на ленте
//памяти начиная с адреса begin или на первый ноль-символ.
char* string_find_space(char *begin);

//Возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (крайний символ
//строки, за которым идет ноль-символ) и заканчивая rend (адрес символа перед началом строки).
//Если символ не найден, возвращает адрес rend.
char* string_find_non_space_reverse(char *rbegin, const char *rend);

//Возвращает указатель на первый пробельный символ справа, расположенный на
//ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
//возвращается адрес rend.
char* string_find_space_reverse(char *rbegin, const char *rend);

//Функция возвращает отрицательное значение (если lhs располагается до rhs
//в лексикографическом порядке); Значение 0 (если lhs и rhs
//равны); иначе – положительное значение.
int string_strcmp(const char *lhs, const char *rhs);

//Записывает по адресу beginDestination фрагмент памяти, начиная с
//адреса beginSource до endSource. Возвращает указатель на следующий
//свободный участок памяти в destination.
char* string_copy(const char *beginSource, const char *endSource, char *beginDestination);

//Записывает по адресу beginDestination элементы из фрагмента памяти начиная с
//beginSource заканчивая endSource, удовлетворяющие функции-предикату f. Функция
//возвращает указатель на следующий свободный для записи участок в памяти.
char* string_copy_if(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//Записывает по адресу beginDestination элементы из участка памяти начиная с
//rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
//Функция возвращает значение beginDestination по окончанию работы функции.
char* string_copy_if_reverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));