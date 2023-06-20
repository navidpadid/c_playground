#include <stdio.h>
#include <stdlib.h>
#include "lib_datastructs/dllist.h"

struct llnode {
  int item;
  struct llnode *next;
  struct llnode *prev;
};

struct llist {
    int size;
    struct llnode *head;
    struct llnode *tail;
};

struct llist *llist_create(void) {
    struct llist *my_dllist = malloc(sizeof(struct llist));
    my_dllist->size = 0;
    my_dllist->head = NULL;
    my_dllist->tail = NULL;
    
    printf("llist created!\n");
    
    return my_dllist;
}

void llist_push(struct llist *my_dllist, int item) {
    struct llnode *new_node = malloc(sizeof(struct llnode));

    new_node->item = item;
    new_node->prev = my_dllist->head;
    new_node->next = NULL;
    
    if (my_dllist->size == 0) {
        my_dllist->head = new_node;
        my_dllist->tail = new_node;
    } else {
        my_dllist->head->next = new_node; 
        my_dllist->head = new_node;
    }
    
    my_dllist->size += 1;
    
    printf("pushed one item: %d\n", item);
    
    return;
}

int llist_item_at(struct llist *my_dllist, int position) {
    struct llnode *current_node = my_dllist->tail;
    
    if (position == my_dllist->size - 1) {
        return my_dllist->head->item;
    }
    int i = 0;
    for (i = 0; i < position; ++i) {
        current_node = current_node->next;
    }
    
    return current_node->item;
}

int llist_pop_at(struct llist *my_dllist, int position) {
    struct llnode *current_node = my_dllist->tail;
    int popped_item = 0;
    
    if (position == my_dllist->size - 1) {
        current_node = my_dllist->head;
    } else {
        int i = 0;
        for (i = 0; i < position; ++i) {
        current_node = current_node->next;
        }
    }
    
    
    if (current_node == my_dllist->tail) {
        my_dllist->tail = my_dllist->tail->next;
        my_dllist->tail->prev = NULL;
    } else if (current_node == my_dllist->head) {
        my_dllist->head = my_dllist->head->prev;
        my_dllist->head->next = NULL;
    } else {
        current_node->prev->next = current_node->next;
        current_node->next->prev = current_node->prev;
    }
    
    
    current_node->prev = NULL;
    current_node->next = NULL;
    popped_item = current_node->item;
    
    free(current_node);
    
    my_dllist->size -= 1;
    
    return popped_item;
    
}

void traverse_llist(struct llist *my_dllist) {
    int len = my_dllist->size;
    struct llnode *current_node = my_dllist->tail;
    
    printf("list is: ");
    int i = 0;
    for(i = 0; i < len; i++){
        printf("%d, ", current_node->item);
        current_node = current_node->next;
    }
    printf("\n");
}

void destroy_llist(struct llist *my_dllist) {
    int len = my_dllist->size;
    struct llnode *current_node = my_dllist->tail;
    struct llnode *next_node = NULL;
    
    int i = 0;
    for(i = 0; i < len; i++){
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    
    free(my_dllist);
    printf("destroyed llist!\n");
}

void test_dllist(void) {
    struct llist *dlinked_list = llist_create();

    int i = 1;
    for(i = 1; i < 20; i++) {
        llist_push(dlinked_list, i);
    }
    
    printf("llist size: %d\n", dlinked_list->size);
    printf("item at 1 is: %d\n", llist_item_at(dlinked_list, 1));
    
    printf("popped item at position 1: %d\n", llist_pop_at(dlinked_list, 1));
    printf("popped item at position 1: %d\n", llist_pop_at(dlinked_list, 1));
    traverse_llist(dlinked_list);
    printf("popped item at position head: %d\n", llist_pop_at(dlinked_list, dlinked_list->size - 1));
    traverse_llist(dlinked_list);
    printf("popped item at position tail: %d\n", llist_pop_at(dlinked_list, 0));
    traverse_llist(dlinked_list);
    printf("popped item at position tail: %d\n", llist_pop_at(dlinked_list, 0));
    traverse_llist(dlinked_list);

    destroy_llist(dlinked_list);
}