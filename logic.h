#ifndef LOGIC_H_
#define LOGIC_H_

typedef struct _win_border_struct {
	char ls, rs, ts, bs, tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct {
	int startx, starty;
	int height, width;
	WIN_BORDER border;
}WIN;

void init_win_params(WIN *p_win, int i, int j);
void createBorders(WIN win[20]);
void create_box(WIN *win, int bl);
void init_win_params(WIN *p_win, int i, int j);
void initWindow(WIN win[]);
void fill(WIN win[], int a[]);
int change(int a[], int c, WIN win[], int *score, int animation);
void initcolor();

#endif
