struct ints_len {
  int *a;
  int len;
};

int read_int();

struct ints_len *read_ints();

void print_ints(int *ints, int len);