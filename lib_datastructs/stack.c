#include <stdlib.h>
#include <stdio.h>
#include "lib_datastructs/stack.h"

struct item {
  char *str;
  struct item *next;
  struct item *prev;
};


struct stack {
    struct item *begining;
    struct item *end;
    int len;
};

struct stack *create_stack(void) {
    struct stack *st = malloc(sizeof(struct stack));
    st->begining = NULL;
    st->end = NULL;
    st->len = 0;
}

void push_stack(struct stack *st, char *item) {
    struct item *new_item = malloc(sizeof(struct item));
    new_item->str = item; //can be separated into another function
    new_item->next = NULL;
    new_item->prev = NULL;
    
    if (st->len == 0) {
        st->begining = st->end = new_item;
        ++st->len;
        return;
    }
    
    struct item *old_end = st->end;
    st->end = new_item;
    old_end->next = new_item;
    new_item->prev = old_end;
    ++st->len;
}

void print_stack(struct stack *st) {
    struct item *curr_node = st->end;
    while(curr_node){
        printf("%s ", curr_node->str);
        curr_node = curr_node->prev;
    }
    printf("\n");
}