#include "vectorVoid.h"

vectorVoid createVectorVoid(int n, int baseTypeSize){
    if (malloc(sizeof(baseTypeSize) * n) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid){malloc(sizeof(baseTypeSize) * n), 0, n, baseTypeSize};

}


void reserveVoid(vectorVoid *v, int newCapacity){
    if (newCapacity == 0){
        free(v->data);
    }else{

        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);

        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }else{
            if (newCapacity <= v->size)
                v->size = newCapacity;

            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}


void shrinkToFitVoid(vectorVoid *v){
    reserveVoid(v, v->size);
}


void clearVoid(vectorVoid *v){
    v->size = 0;
}


void deleteVectorVoid(vectorVoid *v){
    free(v->data);
}


bool isEmptyVoid(vectorVoid *v){
    return (v->size == 0);
}


bool isFullVoid(vectorVoid *v){
    return (v->size == v->capacity);
}


void getVectorValueVoid(vectorVoid *v, int index, void *destination){
    if (v == NULL || destination == NULL) {
        fprintf(stderr, "Error: NULL pointer argument detected\n");
        exit(1);
    }

    if (index >= v->size) {
        fprintf(stderr, "Error: Index %zu is out of bounds (vector size: %zu)\n", index, v->size);
        exit(1);
    }
    // Получить адрес начала данных для index-ого элемента вектора
    char *source = (char *) v->data + index * v->baseTypeSize;
    // Копирование данных из вектора в destination
    memcpy(destination, source, v->baseTypeSize);
}


void setVectorValueVoid(vectorVoid *v, int index, void *source){
    if (v == NULL || source == NULL) {
        fprintf(stderr, "Error: NULL pointer argument detected\n");
        exit(1);
    }

    if (index >= v->size){
        fprintf(stderr, "Error: Index %zu is out of bounds (vector size: %zu)\n", index, v->size);
        exit(1);
    }
    // Вычислить адрес для index-ого элемента вектора и копировать данные
    char *destination = (char *)(v->data + index * v->baseTypeSize);
    memcpy(destination, source, v->baseTypeSize);
}


void popBackVoid(vectorVoid *v){
    if(isEmptyVoid(v)){
        fprintf(stderr, "vector is empty");
        exit(1);
    }else{
        v->size--;
        shrinkToFitVoid(v);
    }
}


void pushBackVoid(vectorVoid *v, void *source){
    if (isFullVoid(v)) {
        reserveVoid(v, v->capacity == 0 ? 1 : v->capacity * 2);
    }

    char *destination = (char *)(v->data + v->size++ * v->baseTypeSize);

    memcpy(destination, source, v->baseTypeSize);
}