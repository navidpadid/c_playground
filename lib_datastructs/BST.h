struct tree_node;

struct tree;

struct tree_node *create_new_node(int item);

void insert_item(struct tree *my_tree, struct tree_node *curr_node, int item);

void print_tree(struct tree *my_tree, struct tree_node *curr_node);