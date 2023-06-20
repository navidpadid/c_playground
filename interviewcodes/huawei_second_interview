// find the greatest sum on a path from root to leaf of a binary tree

//               6
//         4             1
//   3          2     100       200
  
//   6 +1 + 200 = 207
  
  
struct node {
  int val;
  int sum;
  struct node *left;
  struct node *right;
};



int greatest_sum_path(struct node *curr_node) { //begin with the root of the tree
  if (!curr_node) {
    return 0;
  }
  
    int left_sum = greatest_sum_path(curr_node->left);
    int right_sum = greatest_sum_path(curr_node->right);
  
  if (left_sum >= right_sum) {
    curr_node->sum = left_sum;
  } else {
    curr_node->sum = right_sum;
  }
  
  return curr_node->sum + val;
}