/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct node *reverse_list(struct node* head) {
    
    struct node *curr_node = head;
    struct node *reverse_head = NULL;
    struct node *next_node = NULL;
    
    while (curr_node) {
        next_node = curr_node->next;
        curr_node->next = NULL;
        
        if (reverse_head) {
            curr_node->next = reverse_head;
        }
        
        reverse_head = curr_node;
        curr_node = next_node;
    }
    
    return reverse_head;
}

struct node *reverse_partial(struct node *head, int idx, int len) {
 // 1 2 3 4 5, idx = 0, len = 3,  3 2 1 4 5 
 // 1 2 3 4 5, idx = 2, len = 2,  1 2 4 3 5
 // idx = 0 , len > size of llist
    //
    // 0) save the node at idx and detach + save the first node head
    // 1) idx + 1 -> head_reverse
    // 2) detach the node at len - 1 and save the len node 
    // 3) call the reverse_list on the left sub_llist
    // 4) attach the 0) to head of 3) and attach the end of  to 2)
    
    struct node *first_part_head = head;
    struct node *second_part_head = NULL;
    struct node *third_part_head = NULL;
    
    struct node *before_idx_node = head;
    for (int i = 0; i < idx - 1; i++) {
        before_idx_node = before_idx_node->next;
    }
    
   
    
    if (before_idx_node != head) {
        second_part_head = before_idx_node->next;
    } else {
        second_part_head = before_idx_node;
    }
    
    struct node *end_sublist_node = second_part_head;
    for (int i = 0; i < len - 1; i++) {
        end_sublist_node = end_sublist_node->next;
    }
    third_part_head = end_sublist_node->next;
    // printf("%d\n", third_part_head->val);
    end_sublist_node->next = NULL;
    
    if (before_idx_node != head) {
        before_idx_node->next = reverse_list(second_part_head);
    } else {
        first_part_head = reverse_list(second_part_head);
    }
    
    struct node *curr_node = first_part_head;
    while(curr_node->next) {
        curr_node = curr_node->next;
    }
    curr_node->next = third_part_head;
    
    return first_part_head;
}



void print_llist(struct node *head) {
    struct node *curr_node = head;
    while (curr_node) {
        if (curr_node->next) {
            printf("%d,", curr_node->val);
        } else {
            printf("%d", curr_node->val);
        }
     curr_node = curr_node->next;
    }
    printf("\n");
}

struct node *make_llist(int n) {
    struct node *prev_node = NULL;
    struct node *head = NULL;
    
    for(int i = 0; i < n; i++) {
        struct node *curr_node = malloc(sizeof(struct node));
        curr_node->val = i + 1;
        if (prev_node) {
            prev_node->next = curr_node;
        }
        prev_node = curr_node;
        if (i == 0) {
            head = prev_node;
        }
    }
    prev_node->next = NULL;
    
    return head;
}

int main(void)
{
    //- reverse a singly linked list with O(1) space e.g. 1 --> 2 --> 3 --> 4 --> 5 5 --> 4 --> 3 --> 2 --> 1 
    // struct node vals[5];
    // vals[0].val = 1; 
    // vals[0].next = &vals[1]; 
    // vals[1].val = 2; 
    // vals[1].next = &vals[2]; 
    // vals[2].val = 3; 
    // vals[2].next = &vals[3]; 
    // vals[3].val = 4; 
    // vals[3].next = &vals[4]; 
    // vals[4].val = 5; 
    // vals[4].next = NULL;
    
    struct node *vals = make_llist(5);
    
    print_llist(vals);

    // struct node *new_head = reverse_list(vals);
    // print_llist(new_head);
    struct node *new_head = reverse_partial(vals, 2, 3);
    print_llist(new_head);
   
    return 0;
}