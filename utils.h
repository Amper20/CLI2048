#ifndef UTILS_H_
#define UTILS_H_

int Win(int a[]);
void printcharacter(int a[]);
void moveadd(int moves[], int *movesCnt, int c);
int isValid(int a[]);
void generate(int a[]);
char* toStr(int x);
int get(int x);
void navigate(int c, int *selection);
void save(int history[1000][30], int a[], int *score, int *history_size, int moves[], int *movesCnt);

#endif
