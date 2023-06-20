#include <stdio.h>
#include <stdlib.h>
#include "lib_datastructs/BST.h"

struct tree_node {
    int item;
    int size;
    struct tree_node *right;
    struct tree_node *left;
};

struct tree {
    struct tree_node *root;
};

struct tree_node *create_new_node(int item) {
    struct tree_node *new_node = malloc(sizeof(struct tree_node));
    new_node->item = item;
    new_node->size = 1;
    new_node->right = NULL;
    new_node->left = NULL;
    
    return new_node;
}

void insert_item(struct tree *my_tree, struct tree_node *curr_node, int item) {

    if (!my_tree->root) {
        struct tree_node *new_node = create_new_node(item);
        my_tree->root = new_node;
        return;
    }
    
    if (!curr_node) {
        curr_node = my_tree->root;
    }
    
    //insert left side
    if (item <= curr_node->item && curr_node->left) {
        curr_node->size += 1;
        curr_node = curr_node->left;
        return insert_item(my_tree, curr_node, item);
    } else if (item <= curr_node->item && !curr_node->left) {
        struct tree_node *new_node = create_new_node(item);
        curr_node->left = new_node;
        curr_node->size += 1;
        return;
    }
    
    //insert right side
    if (curr_node->right) {
        curr_node->size += 1;
        curr_node = curr_node->right;
        return insert_item(my_tree, curr_node, item);
    } else {
        struct tree_node *new_node = create_new_node(item);
        curr_node->right = new_node;
        curr_node->size += 1;
        return;
    }
}


void print_tree(struct tree *my_tree, struct tree_node *curr_node) {
    if (!curr_node) {
        return;
    }
    
    printf("%d", curr_node->item);
    
    struct tree_node *left = curr_node->left;
    struct tree_node *right = curr_node->right;
    
    print_tree(my_tree, left);
    print_tree(my_tree, right);
    
    return;
}
