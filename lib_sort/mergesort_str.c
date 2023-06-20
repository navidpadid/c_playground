/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lib_datastructs/string_io.h"
#include <string.h>
#include "lib_sort/mergesort_str.h"

void merge_str(char **a, char **left, int left_len, char **right, int right_len) {
    int left_ptr = 0;
    int right_ptr = 0;
    int a_ptr = 0;
    
    for (a_ptr = 0; a_ptr < left_len + right_len; ++a_ptr) {
        if (right_ptr == right_len || (left_ptr < left_len && strcmp(right[right_ptr], left[left_ptr]) > 0)) {
            a[a_ptr] = realloc(a[a_ptr], (strlen(left[left_ptr]) + 1) * sizeof(char));
            strcpy(a[a_ptr], left[left_ptr]);
            ++left_ptr;
        } else {
            a[a_ptr] = realloc(a[a_ptr], (strlen(right[right_ptr]) + 1) * sizeof(char));
            strcpy(a[a_ptr], right[right_ptr]);
            ++right_ptr;
        }
    }
    
    return;

}


void merge_sort_str(char **a, int len) {
    if (len <= 1){
        return;
    }
    int left_len = len / 2;
    int right_len = len - left_len;
    char **left = malloc(left_len * sizeof(char *));
    char **right = malloc(right_len * sizeof(char *));

    int i = 0;
    for (i = 0; i < left_len; ++i) {
        left[i] = malloc((strlen(a[i]) + 1) * sizeof(char));
        strcpy(left[i], a[i]);
    }
    for (i = 0; i < right_len; ++i) {
        right[i] = malloc((strlen(a[i + left_len]) + 1) * sizeof(char));
        strcpy(right[i], a[i + left_len]);
    }
    merge_sort_str(left, left_len);
    merge_sort_str(right, right_len);
    merge_str(a, left, left_len, right, right_len);
    free(left);
    free(right);


    return;
}

void test_merge_sort_str(){
    
    struct strings_len *str_len = read_strings();
        
    merge_sort_str(str_len->str, str_len->len);
    
    print_strings(str_len);

    free(str_len);
}


