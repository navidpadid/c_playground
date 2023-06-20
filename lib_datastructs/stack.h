struct item;

struct stack;

struct stack *create_stack(void);

void push_stack(struct stack *st, char *item);

void print_stack(struct stack *st);