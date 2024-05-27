#include "../../data_structures/string/string.h"

int string_strlen(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
    
}

char *string_find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *string_find_non_space(char *begin) {
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }

    return begin;
}

char *string_find_space(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }

    return begin;
}

char *string_find_non_space_reverse(char *rbegin, const char *rend) {
    while (rend != rbegin && isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

char *string_find_space_reverse(char *rbegin, const char *rend) {
    while (rend != rbegin && !isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

int string_strcmp(const char *lhs, const char *rhs) {
    char left_char, right_char;
    while ((left_char = *(lhs++)) == (right_char = *(rhs++)) && left_char != '\0' && right_char != '\0');
    return (left_char > right_char) - (left_char < right_char);
}

char *string_copy(const char *beginSource, const char *endSource, char *beginDestination) {
    int length = endSource - beginSource;
    memcpy(beginDestination, beginSource, sizeof(char) * length);
    beginDestination[length] = '\0';
    return beginDestination + length;
}


char *string_copy_if(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination++, beginSource, sizeof(char));
        }

        beginSource++;
    }

    return beginDestination;
}

char *string_copy_if_reverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination-- = *rbeginSource;
        }

        rbeginSource--;
    }

    return beginDestination;
}