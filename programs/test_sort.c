/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "lib_datastructs/dllist.h"
#include "lib_datastructs/BST.h"
#include "lib_datastructs/string_io.h"

#include "lib_sort/mergesort_int.h"
#include "lib_sort/mergesort_str.h"



int compress(char* chars, int charsSize) {
    char *curr_char = chars[0];
    int ptr = 0;
    int count = 0;
    int i = 0;
    
    for (i = 1; i < charsSize; i++) {
        if (*curr_char == chars[i]) {
                count += 1;
            } else {
            chars[ptr] = *curr_char;
            ++ptr;
            chars[ptr] = (char)count;
            ++ptr;
            count = 0;
        }
        curr_char = chars[i];
    }
    
    return ptr;
}


int main_2() {
    // test_dllist();
    // test_merge_sort();
    // test_merge_sort_str();
    // struct strings_len *str_len = malloc(sizeof(struct strings_len));
    // str_len->len = n;
    // str_len->str = str;
    // printf("%d\n", str_len);
    // printf("%d\n", sizeof(struct strings_len));
    // printf("%d", sizeof(char **));
    

 
    // unsigned int x = 43261596;
    // printf("%u", reverseBits(x));

    test_merge_sort_str();
    test_merge_sort();

    return 0;
}


