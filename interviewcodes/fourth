/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/** * Definition for a binary tree node. * 
 * struct TreeNode { *
 * int val;
 * struct TreeNode *left;
* struct TreeNode *right;
* }; */


struct TreeNode* invertTree(struct TreeNode* root){ 
    if (!root) {
        return NULL;
    }
    
    struct TreeNode *left_node = NULL;
    struct TreeNode *right_node = NULL;

    
    left_node = root->left;
    right_node = root->right;
    
    root->left = right_node;
    root->right = left_node;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}; 




int main()
{
    printf("Hello World");

    return 0;
}
