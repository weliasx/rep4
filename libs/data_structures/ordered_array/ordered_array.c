#include "ordered_array_set.h"

ordered_array_set ordered_array_set_create(size_t capacity){
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};

}


static void ordered_array_set_shrinkToFit(ordered_array_set *a){
    if (a->size != a->capacity){
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}


ordered_array_set ordered_array_set_create_from_array(const int *a, int size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (int i = 0; i < size; i++){
        ordered_array_set_insert(&set, a[i]);
    }
    ordered_array_set_shrinkToFit(&set);
    return set;

}


int ordered_array_set_in(ordered_array_set *set, int value){
    return binarySearch_(set->data, set->size, value);

}


int compare_ints(const void *a, const void *b){
    const int *num1 = (const int *) a;
    const int *num2 = (const int *) b;
    return *num1 - *num2;

}


bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2){
    if (set1.size != set2.size){
        return 0;

    }
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;

}


bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set){
    for (size_t i = 0; i < subset.size; i++){
        if (binarySearch_(set.data, set.size, subset.data[i]) == -1) {
            return 0;

        }
    }
    return 1;

}


void ordered_array_set_isAbleAppend(ordered_array_set *set){
    assert (set->size < set->capacity);
}


void ordered_array_set_insert(ordered_array_set *set, int value){
    ordered_array_set_isAbleAppend(set);
    if (binarySearch_(set->data, set->size, value) == -1){
        int index_insert = binarySearchMoreOrEqual_(set->data, set->size, value);
        for(int i = set->size; i > index_insert; i--){
            set->data[i] = set->data[i - 1];
        }
        set->size++;
        set->data[index_insert] = value;
    }
}


void ordered_array_set_deleteElement(ordered_array_set *set, int value){
    int index = binarySearch_(set->data, set->size, value);
    if(index != -1){
        for(int i = index; i < set->size - 1; i++){
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}


ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; i++){
        ordered_array_set_insert(&set, set1.data[i]);
    }
    for (int j = 0; j < set2.size; j++){
        ordered_array_set_insert(&set, set2.data[j]);
    }
    ordered_array_set_shrinkToFit(&set);
    return set;

}


ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set set = ordered_array_set_create_from_array(set1.data, set1.size);
    for(int i = 0; i < set.size;){
        int index = binarySearch_(set2.data, set2.size, set.data[i]);
        if(index == -1) {
            ordered_array_set_deleteElement(&set, set.data[i]);
        }else {
            i++;
        }
    }
    return set;

}


ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set set = ordered_array_set_create_from_array(set1.data, set1.size);
    for (int i = 0; i < set.size; i++){
        int index = binarySearch_(set2.data, set2.size, set.data[i]);
        if (index != -1) {
            ordered_array_set_deleteElement(&set, set.data[i--]);
        }
    }
    return set;

}


ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2){
    ordered_array_set a = ordered_array_set_difference(set1, set2);
    ordered_array_set b = ordered_array_set_difference(set2, set1);
    ordered_array_set c = ordered_array_set_union(a, b);
    ordered_array_set_delete(a);
    ordered_array_set_delete(b);
    return c;

}


ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet){
    ordered_array_set comp = ordered_array_set_create(set.size + universumSet.size);
    assert(ordered_array_set_isSubset(set, universumSet));
    comp = ordered_array_set_difference(universumSet, set);
    ordered_array_set_shrinkToFit(&comp);
    return comp;

}


void ordered_array_set_print(ordered_array_set set){
    printf("{");

    if (set.size > 0){
        for (int i = 0; i < set.size; ++i){
            printf("%d", set.data[i]);

            if (i < set.size - 1){
                printf(", ");

            }
        }
    }
    printf("}\n");

}


void ordered_array_set_delete(ordered_array_set set){
    free(set.data);
}