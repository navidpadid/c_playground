struct llnode;

struct llist;

struct llist *llist_create(void);

void llist_push(struct llist *my_dllist, int item);

int llist_item_at(struct llist *my_dllist, int position);

int llist_pop_at(struct llist *my_dllist, int position);

void traverse_llist(struct llist *my_dllist);

void test_dllist(void);