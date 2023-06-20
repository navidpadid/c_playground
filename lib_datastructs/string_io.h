struct strings_len {
    int len;
    char **str;
}; //only should be defined and declared (at the same time) here if you want to access it on both string_io.c and main.c or other files!

//struct strings_len; //with this the main.c only knows there is this strcuture but it doesn't know
// anything about its definition (eg. the fields it has) so it's incomplete but can be passed to other functions in the string_io.c file
char *read_str(void);

struct strings_len *read_strings(void);

void print_strings(struct strings_len *strings_len);