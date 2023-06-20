#include "lib_datastructs/string_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//only this file knows the fields of the strings_len
// struct strings_len {
//     int len;
//     char **str;
// };

void print_strings(struct strings_len *strings_len) {
    int i = 0;
    for (i = 0; i < strings_len->len; i++) {
        if (i == strings_len->len - 1) {
            printf("%s\n", strings_len->str[i]);
        } else {
            printf("%s,", strings_len->str[i]);
        }
    }
}

char *read_str(void) {
    char c = 0;
    if (scanf(" %c", &c) != 1) {   // ignore initial WS
        return NULL;
    }
  
    int maxlen = 1;
    int len = 1;
    char *str = malloc(maxlen * sizeof(char));
    str[0] = c;
    
    while (1) {
    if (scanf("%c", &c) != 1) {
      break;
    }
    
    if (c == ' ' || c == '\n') {
      break;
    }
    if (len == maxlen) {  // DOUBLE the allocated array size
      maxlen *= 2;
      str = realloc(str, maxlen * sizeof(char));
    }
    ++len;
    str[len - 1] = c;
    }
    
    // shrink the array back down to the correct size
    str = realloc(str, (len + 1) * sizeof(char));
    str[len] = '\0';
    return str;
}

struct strings_len *read_strings(void) {
    int n = 0;
    printf("Enter number of strings in the array:\n");
    
    scanf("%d", &n);
    printf("Enter %d strings\n", n);
    
    char **str = malloc(n * sizeof(char *));
    int i = 0;
    for (i = 0; i < n; i++) {
        str[i] = read_str();
    }


    struct strings_len *str_len = malloc(sizeof(struct strings_len));
    str_len->len = n;
    str_len->str = str;
    
    return str_len;
}


