/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lib_datastructs/int_io.h"
#include "lib_sort/mergesort_int.h"

void merge(int *a, int *left, int left_len, int *right, int right_len) {
    int left_ptr = 0;
    int right_ptr = 0;
    int a_ptr = 0;

    for (a_ptr = 0; a_ptr < left_len + right_len; ++a_ptr) {
        if (right_ptr == right_len || (left_ptr < left_len && left[left_ptr] <= right[right_ptr])) {
            a[a_ptr] = left[left_ptr];
            ++left_ptr;
        } else {
            a[a_ptr] = right[right_ptr];
            ++right_ptr;
        }
    }
    
    return;

}


void merge_sort(int *a, int len) {
    if (len <= 1){
        return;
    }
    int left_len = len / 2;
    int right_len = len - left_len;
    int *left = malloc(left_len * sizeof(int));
    int *right = malloc(right_len * sizeof(int));
    int i = 0;

    for (i = 0; i < left_len; ++i) {
        left[i] = a[i];
    }
    for (i = 0; i < right_len; ++i) {
        right[i] = a[i + left_len];
    }
    merge_sort(left, left_len);
    merge_sort(right, right_len);
    merge(a, left, left_len, right, right_len);
    free(left);
    free(right);


    return;
}

void test_merge_sort(){
    struct ints_len *integers_len = read_ints();
        
    merge_sort(integers_len->a, integers_len->len);
    
    print_ints(integers_len->a, integers_len->len);

    free(integers_len->a);
    free(integers_len);
}


