/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lib_datastructs/int_io.h"
#include "lib_datastructs/string_io.h"
#include "lib_datastructs/stack.h"

#include "lib_sort/mergesort_int.h"
#include "lib_sort/mergesort_str.h"

// int find_max(int *arr, int len) {
//     int max = arr[0];
    
//     for (int i = 0; i < len; i++) {
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//     }
    
//     return max;
// }

// int missing_number(int *arr, int len) {
//     int max = find_max(arr, len);
//     int min = 0;

    
//     int *complete_arr = calloc(max, sizeof(int));
    
//     // for (int i = 0; i < max; i++) {
//     //     complete_arr[i] = 0;
//     // }
//     // print_ints(complete_arr, max);
    
//     for (int i = 0; i < len; i++) {
//         complete_arr[arr[i] - 1] = 1;
//     }
    
//     int missing = 0;
//     for (int i = 0; i < max; i++) {
//         if (complete_arr[i] == 0) {
//             missing = i;
//         }
//     }
    
//     return missing + 1;
// } 

// unsigned int ones(unsigned int number) {
//     int count = 0;

//     while (number > 0) {
//         if (number % 2 != 0) {
//             count += 1;
//         }
//         number >>= 1;
//     }
    
//     return count;
// }

int main()
{
    // struct ints_len *integers_len = read_ints();
    // int count = read_int();
    // printf("%d", ones(count));
    // print_ints(integers_len->a, integers_len->len);
    // printf("%d", missing_number(integers_len->a, integers_len->len));
    struct strings_len *str_len = read_strings();
    struct stack *st = create_stack();

    int i = 0;
    for (i = 0; i < str_len->len; i++) {
        push_stack(st, str_len->str[i]);
    }
    
    print_stack(st);

    test_merge_sort_str();
    test_merge_sort();
    
    return 0;
}

