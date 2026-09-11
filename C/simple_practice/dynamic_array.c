/* dynamic_array.c

Implements a resizable array via malloc/realloc
*/
#import <stdio.h>
#import <stdlib.h>

struct DynamicArray;

typedef struct DynamicArrayMethods {
    void (*add) (struct DynamicArray array, int element);
    void (*initialize) (struct DynamicArray * array, int length);
} DynamicArrayMethods;

typedef struct DynamicArray {
    int *data;
    int length;
    const DynamicArrayMethods* methods;
} DynamicArray;

void addToDynamicArray(DynamicArray array, int element) {
    printf("addToDynamicArray not implemented\n"); 
};

void initializeDynamicArray(DynamicArray * array, int length) {
     int *data = calloc(length, sizeof(*data));
     if (data == NULL) {
        printf("ERROR: Failed to malloc in initializeDynamicArray");
     }
     // TODO zero out data
     array->data = data;
     array->length = length;
};

static const DynamicArrayMethods IntDynamicArrayMethods = {
    .add = addToDynamicArray,
    .initialize = initializeDynamicArray
};

int main(int argc, char * argv[]) {
    printf("Starting testing...\n");
    int length = 10;

    DynamicArray arr = {.methods = &IntDynamicArrayMethods};
    arr.methods->initialize(&arr, length);

    printf("Array length: %d, expected %d\n", arr.length, length);
    printf("Array contents:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("Array item %d: %d\n", i, arr.data[i]);
    }

    return 0;
}