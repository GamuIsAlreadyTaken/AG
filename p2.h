#ifndef ALG_INSERTION_SHELL_SORT
#define ALG_INSERTION_SHELL_SORT

void ord_ins(int v[], int n);
void ord_shell(int v[], int n);

void test_ord_ins();
void test_ord_shell();

void time_ord_ins_rand();
void time_ord_ins_asc();
void time_ord_ins_desc();
void time_ord_shell_rand();
void time_ord_shell_asc();
void time_ord_shell_desc();

#endif