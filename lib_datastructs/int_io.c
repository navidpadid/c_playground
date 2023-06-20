#include <stdio.h>
#include <stdlib.h>
#include "lib_datastructs/int_io.h"
#include <assert.h>

int read_int(){
    int input;
    if (scanf("%d", &input) != EOF) {
        return input;
    }
}


struct ints_len *read_ints() {
    int n = 0;
    printf("Enter number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    
    assert(n > 0);
    
    struct ints_len *ints_len = malloc(sizeof(struct ints_len));
    ints_len->a = malloc(n * sizeof(int));
    ints_len->len = n;
    int i = 0;
    for (i = 0; i < n; i++)
        ints_len->a[i] = read_int();
    
    return ints_len;
}

void print_ints(int *ints, int len) {
    int i = 0;
    for (i = 0; i < len; ++i) {
        if (i == len - 1) {
            printf("%d\n", ints[i]);
        } else {
        printf("%d,", ints[i]);
        }
    }
    
    return;
}