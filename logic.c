#include "logic.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <unistd.h>

//Initializare culori
void initcolor(){
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_BLUE);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
}

//efectueaza mutarea data de utilizator, returneaza nuamrul de celule ce difera dupa mutare
int change(int a[], int c, WIN win[], int *score, int animation){
	int b[5][5],available[5][5], k = 0, aux[5][5], ret = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			b[i][j] = a[k];
			aux[i][j] = b[i][j];
			available[i][j] = 1;
			k++;
		}
	}
	if(c == KEY_DOWN){//down
		for(int j = 3; j >= 0; j--)//muta toatate celule in directia data de utilizator
				for(int i = 3; i > 0; i--)
					if(!b[i][j]){
						int u = 0;
						for(int k = i; k >= 0 && !u; k--)
							if(b[k][j])
								while(k!=i){										
									b[k+1][j] = b[k][j];
									b[k][j] = 0;
									u = 1;
									k++;
									for(int i = 0 ; i < 4; i++)
										for(int j = 0; j < 4; j++)
											a[i*4 + j] = b[i][j];
									fill(win,a);
									usleep(animation);
								}
					}
		for(int j = 3; j >= 0; j--) // aduna celulele egale in corespondenta cu directia data
			for(int i = 3; i > 0; i--)
				if(b[i][j] == b[i-1][j] && available[i][j] && available[i-1][j] && b[i][j] && b[i-1][j]){
					b[i][j] += b[i-1][j];
					*score += b[i][j];
					b[i-1][j] = 0;
					available[i][j] = 1;
					available[i-1][j] = 1;
				}
		for(int j = 3; j >= 0; j--) // muta iar celulele in directia data
			for(int i = 3; i > 0; i--)
				if(!b[i][j]){
					int u = 0;
					for(int k = i; k >= 0 && !u; k--)
						if(b[k][j]){
							b[i][j] = b[k][j];
							b[k][j] = 0;
							u = 1;
						}
				}
			for(int i = 0 ; i < 4; i++) // calcularea returnului
				for(int j = 0; j < 4; j++){
					a[i*4 + j] = b[i][j];
					ret += (aux[i][j] != b[i][j]);
				}
	}
	if(c == KEY_LEFT){//left
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)	
				if(!b[i][j]){
					int u = 0;
					for(int k = j; k < 4 && !u; k++)
						if(b[i][k])
							while(k!=j){										
								b[i][k-1] = b[i][k];
								b[i][k] = 0;
								u = 1;
								k--;
								for(int i = 0 ; i < 4; i++)
									for(int j = 0; j < 4; j++)
										a[i*4 + j] = b[i][j];
								fill(win,a);
								usleep(animation);
							}
				}
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 3; j++)	
				if(b[i][j] == b[i][j+1] && available[i][j] && available[i][j+1] && b[i][j+1] && b[i][j]){
					b[i][j] += b[i][j+1];
					b[i][j+1] = 0;
					*score += b[i][j];
					available[i][j] = 1;
					available[i][j+1] = 1;
				}
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)	
				if(!b[i][j]){
					int u = 0;
					for(int k = j; k < 4 && !u; k++)
						if(b[i][k])
							while(k!=j){										
								b[i][k-1] = b[i][k];
								b[i][k] = 0;
								u = 1;
								k--;
							}
				}
		for(int i = 0 ; i < 4; i++)
			for(int j = 0; j < 4; j++){
				a[i*4 + j] = b[i][j];
				ret += (aux[i][j] != b[i][j]);
			}
	}
	if(c == KEY_RIGHT){//right
		for(int i = 0; i < 4; i++)
			for(int j = 3; j >= 0; j--)	
				if(!b[i][j]){
					int u = 0;
					for(int k = j; k >= 0 && !u; k--)
						if(b[i][k])
							while(k!=j){										
								b[i][k+1] = b[i][k];
								b[i][k] = 0;
								u = 1;
								k++;
								for(int i = 0 ; i < 4; i++)
									for(int j = 0; j < 4; j++)
										a[i*4 + j] = b[i][j];
								fill(win, a);
								usleep(animation);
							}
				}
		for(int i = 0; i < 4; i++)
			for(int j = 3; j >= 0; j--)	
				if(b[i][j] == b[i][j-1] && available[i][j] && available[i][j-1] && b[i][j-1] && b[i][j]){
					b[i][j] += b[i][j-1];
					b[i][j-1] = 0;
					*score += b[i][j];
					available[i][j] = 1;
					available[i][j-1] = 1;
				}
		for(int i = 0; i < 4; i++)
			for(int j = 3; j >= 0; j--)	
				if(!b[i][j]){
					int u = 0;
					for(int k = j; k >= 0 && !u; k--)
						if(b[i][k])
							while(k!=j){										
								b[i][k+1] = b[i][k];
								b[i][k] = 0;
								u = 1;
								k++;
							}
				}
		for(int i = 0 ; i < 4; i++)
			for(int j = 0; j < 4; j++){
				ret += (aux[i][j] != b[i][j]);
				a[i*4 + j] = b[i][j];
			}
	}
	if(c == KEY_UP){//up
		for(int j = 3; j >= 0; j--)
			for(int i = 0; i < 4; i++)
				if(!b[i][j]){
					int u = 0;
					for(int k = i; k < 4 && !u; k++)
						if(b[k][j])
							while(k!=i){										
								b[k-1][j] = b[k][j];
								b[k][j] = 0;
								u = 1;
								k--;
								for(int i = 0 ; i < 4; i++)
									for(int j = 0; j < 4; j++)
										a[i*4 + j] = b[i][j];
								fill(win,a);
								usleep(animation);
							}
				}
		for(int j = 3; j >= 0; j--)
			for(int i = 0; i < 4; i++)
				if(b[i][j] == b[i+1][j] && available[i][j] && available[i+1][j] && b[i][j] && b[i+1][j]){
					b[i][j] += b[i+1][j];
					b[i+1][j] = 0;
					*score += b[i][j];
					available[i][j] = 1;
					available[i+1][j] = 1;
				}
		for(int j = 3; j >= 0; j--)
			for(int i = 0; i < 4; i++)
				if(!b[i][j]){
					int u = 0;
					for(int k = i; k < 4 && !u; k++)
						if(b[k][j])
							while(k!=i){										
								b[k-1][j] = b[k][j];
								b[k][j] = 0;
								u = 1;
								k--;
							}
				}
		for(int i = 0 ; i < 4; i++)
			for(int j = 0; j < 4; j++){
				ret += (aux[i][j] != b[i][j]);
				a[i*4 + j] = b[i][j];
			}	
	}
	return ret;
}
// umple arena de joc cu valorile numerelor
void fill(WIN win[], int a[]){
	
	for(int i = 0; i < 16; i++){
		int x = win[i].startx;
		int y = win[i].starty;
		char c[10] = "     ";
		mvprintw(y+2,x+4 - strlen(c)/2,"%s",c);
		refresh();
	}
	
	for(int i = 0; i < 16; i++){
		int color = get(a[i]);
		attron(COLOR_PAIR(color));
		int x = win[i].startx;
		int y = win[i].starty;
		mvprintw(y+1,x+1,"       ");
		mvprintw(y+2,x+1,"       ");
		mvprintw(y+3,x+1,"       ");
		char *c = toStr(a[i]);
		mvprintw(y+2,x+4 - strlen(c)/2,"%s",c);
		attroff(COLOR_PAIR(color));
		free(c);
		refresh();
	}
	
}
// creaza gridul delimitator
void createBorders(WIN win[]){
	for(int i = 0; i < 16; i++)
		create_box(&win[i], TRUE),refresh();
}
// initializarea ferestrelor cu parametri dati
void initWindow(WIN win[]){
	for(int i = 0; i < 16; i++){
			init_win_params(&win[i],i/4,i%4);
	}
}
// parametri de initializare
void init_win_params(WIN *p_win, int i, int j){
	p_win->height = 4;
	p_win->width = 8;
	p_win->starty = i*4;
	p_win->startx = j*8;
	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';
}
// creaza gridul delimitator
void create_box(WIN *p_win, int bl){
	int i, j;
	int x, y, w, h;
	x = p_win->startx;
	y = p_win->starty;
	w = p_win->width;
	h = p_win->height;
	if(bl == TRUE){ 
		mvaddch(y, x, p_win->border.tl);
		mvaddch(y, x + w, p_win->border.tr);
		mvaddch(y + h, x, p_win->border.bl);
		mvaddch(y + h, x + w, p_win->border.br);
		mvhline(y, x + 1, p_win->border.ts, w - 1);
		mvhline(y + h, x + 1, p_win->border.bs, w - 1);
		mvvline(y + 1, x, p_win->border.ls, h - 1);
		mvvline(y + 1, x + w, p_win->border.rs, h - 1); 
	}else
		for(j = y; j <= y + h; ++j)
			for(i = x; i <= x + w; ++i)
				mvaddch(j, i, ' ');
} 
