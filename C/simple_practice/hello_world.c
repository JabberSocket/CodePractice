#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void hello_world();
void numeric_operations();
void control_flow();
void pointers_practice();
void structs_practice();

int main(int argc, char * argv[]) {
    hello_world();
    numeric_operations();
    control_flow();
    pointers_practice();
    structs_practice();
    return(EXIT_SUCCESS);
}

void hello_world() {
    printf("Hello World!\n");
}

void numeric_operations() {
    // Basic types
    int plainInt = 5; // At least 2 bytes but commonly 4 bytes
    long int longInt = 16; // Arch dependant 4-8 bytes
    long long int longLongInt = 19; // Guaranteed 8 bytes
    float plainFloat = 4.0f; // 4 bytes, 6-7 decimal precision
    double plainDouble = 7.0; // 8 bytes, 15 decimal precision
    long double longDouble = 8.0l; // 10-16 bytes, 18-21 decimal precision

    // Guaranteed widths with <stdint.h>

    // Unsigned doubles the positive ceiling.
    int32_t guaranteedInt = 9;
    uint32_t guaranteedUInt = 0;

    // Basic operators
    
    // Division will be int division unless the numerator or denominator are decimal types
    // Int division truncates decimal remainder it does not round down
    printf("Running numeric assertions...\n");
    assert(plainInt / 5 == 1);
    assert(plainInt / 9 == 0); // Integer division
    assert(plainInt / 1.0 == 5.0); // Double division
    assert(plainInt / (double) 5 == 1.0); // Casting

    printf("Numeric assertions complete!\n");
}

void control_flow() {
    // Basic if/else/for

    bool testBool = false;
    if (!testBool) {
        printf("Negating a C99 bool works\n");
    }

    if (testBool) {
        printf("ERROR: this should be skipped\n");
    } else {
        printf("If/else works\n");
    }

    if (testBool) {
        printf("ERROR: this should be skipped\n");
    } else if (true) {
        printf("Else-if works\n");
    } else {
        printf("ERROR: this should be skipped\n");
    }

    int maxIterations = 5;
    for (int i = 0; i < maxIterations; i++) {
        printf("Testing iteration %d/%d of a for-loop)\n", i, maxIterations);
    }

    // while, do while, and switch-case statements work as expected

    // jumping is interesting
    if (!testBool) {
        goto error_handling;
    }
    printf("ERROR: this should be skipped by a goto\n");
    return; // we won't reach this

error_handling:
    printf("Goto jump works\n");
}

void pointers_practice() {
    int normalInt = 5;
    int* pointerToInt = &normalInt;
    int** pointerToPointerToInt = &pointerToInt;

    assert(*pointerToInt == 5);
    assert(**pointerToPointerToInt == 5);
    printf("Done with pointer testing\n");

    // Arrays are pointer heavy
    int uninitializedArray[5];
    int initializedArray[5] = {1, 2, 3, 4, 5};
    assert(initializedArray[2] == 3);
    //assert(uninitializedArray[3] == 1337); // accessing un-initialized array is possible!
    //assert(initializedArray[10]); // OOB access!

    for (int i = 0; i < 5; i++) {
        uninitializedArray[i] = i;
    }
    assert(uninitializedArray[3] == 3);

    int matrix[5][5] = {{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
    assert(matrix[2][3] == 4);
    printf("Done with array testing\n");
}

void structs_practice() {
    struct practiceStruct {
        int myInt;
        int* myIntPointer;
    };
    int someInt = 6;
    struct practiceStruct myPS = {.myInt=5, .myIntPointer=&someInt};
    printf("Struct myInt: %d\n", myPS.myInt);
    printf("Struct myIntPointer: %d\n", *(myPS.myIntPointer));

    typedef struct typedStruct {
        char name[10];
    } typedStruct;
    typedStruct myTS = {.name="foobar"};
    printf("Struct name: %s\n", myTS.name);
}