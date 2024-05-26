#include "unordered_array_set.h"


unordered_array_set unordered_array_set_create(size_t capacity){
    return (unordered_array_set){malloc(sizeof(int) * capacity), 0, capacity};

}


unordered_array_set unordered_array_set_create_from_array(int *a, int size){
    unordered_array_set set = unordered_array_set_create(size);
    for(int i = 0; i < size; i++){
        set.data[i] = a[i];
        set.size++;
    }
    return set;

}


size_t unordered_array_set_in(unordered_array_set set, int value){
    linearSearch_(set.data, set.size, value);
}


bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set){
    for(int i = 0; i < subset.size; i++){
        int isTrue = 0;
        for(int j = 0; j < set.size; j++){
            if(subset.data[i] == set.data[j]){
                isTrue = 1;
            }
        }
        if(isTrue == 0){
            return 0;

        }
    }
    return 1;

}


bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2){
    if (set1.size != set2.size){
        return 0;

    }
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;

}


void unordered_array_set_isAbleAppend(unordered_array_set *set){
    assert(set->size < set->capacity);
}


void unordered_array_set_insert(unordered_array_set *set, int value){
    unordered_array_set_isAbleAppend(set);
    if(linearSearch_(set->data, set->size, value) == set->size){
        append_(set->data, &set->size, value);
    }

}


void unordered_array_set_delete_element(unordered_array_set *set, int value){
    for (int i = 0; i < set->size; i++){
        if (set->data[i] == value) {
            deleteByPosSaveOrder_(set->data, &set->size, i);
            break;
        }
    }
}


unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2){
    unordered_array_set a = unordered_array_set_create(set1.size + set2.size);
    for(int i = 0; i < set1.size; i++){
        unordered_array_set_insert(&a, set1.data[i]);
    }
    for(int i = 0; i < set2.size; i++){
        int is_original = 1;
        for (int j = 0; j < set1.size; j++){
            if (set2.data[i] == set1.data[j]){
                is_original = 0;
                break;
            }
        }
        if (is_original){
            unordered_array_set_insert(&a, set2.data[i]);
        }
    }
    return a;

}


unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2){
    unordered_array_set a = unordered_array_set_create(set1.size < set2.size ? set2.size : set1.size);
    for(int i = 0; i < set1.size; i++){
        int is_original = 0;
        for (int j = 0; j < set2.size; j++){
            if (set1.data[i] == set2.data[j]){
                is_original = 1;
                break;
            }
        }
        if (is_original){
            for (int k = 0; k < a.size; k++){
                if (set1.data[i] == set2.data[k]){
                    is_original = 0;
                    break;
                }
            }
        }
        if (is_original){
            unordered_array_set_insert(&a, set1.data[i]);
        }
    }
    return a;

}


unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2){
    unordered_array_set set = unordered_array_set_create(set1.size);
    for(int i = 0; i < set1.size; i++){
        int is_original = 1;
        for(int j = 0; j < set2.size; j++){
            if(set1.data[i] == set2.data[j]){
                is_original = 0;
                break;
            }
        }
        if(is_original){
            unordered_array_set_insert(&set, set1.data[i]);
        }
    }
    return set;

}


unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet){
    unordered_array_set comp = unordered_array_set_create(set.size + universumSet.size);
    assert(unordered_array_set_isSubset(set, universumSet));
    comp = unordered_array_set_difference(universumSet, set);
    unordered_array_set_shrinkToFit(&comp);
    return comp;

}


unordered_array_set  unordered_array_set_symmetric_difference(unordered_array_set set1, unordered_array_set set2){
    unordered_array_set a = unordered_array_set_difference(set1, set2);
    unordered_array_set b = unordered_array_set_difference(set2, set1);
    unordered_array_set c = unordered_array_set_union(a,b);
    unordered_array_set_delete(a);
    unordered_array_set_delete(b);
    return c;

}


void unordered_array_set_print(unordered_array_set set){
    printf("{");

    for(int i = 0; i < set.size; i++){
        if(i != set.size - 1) {
            printf("%d, ", set.data[i]);

        }else {
            printf("%d", set.data[i]);

        }
    }
    printf("}\n");

}


void unordered_array_set_delete(unordered_array_set set){
    free(set.data);
}


static void unordered_array_set_shrinkToFit(unordered_array_set *a){
    if (a->size != a->capacity){
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}