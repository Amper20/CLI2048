#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "optim.h"
#include "utils.h"
#include "print.h"
#include "logic.h"

int main(int argc, char *argv[]){
	
	srand(time(NULL));// time
	WIN win[20]; // arena de joc
	int a[20] = {0}, score = 0, moves[7] = {0}, movesCnt = 0, *C, selection = 0, resume = 0, history[1000][30], history_size = 0;
	int c = ' ', u = 0, firstStart = 1, resumeERR = 0;
	time_t mytime = time(NULL);
	cbreak(); // ncurses set up keyboard		
	initscr();
	keypad(stdscr, TRUE); 
	noecho();
	timeout(10000); // getch() timeout
	start_color(); // color settings
	initcolor();
	while(c != 'G'&& u >= 0){
		if(Win(a)){
			clrscr();
			printWin();
			u = -5;
		}else{
				if(!u){ // menu state u = 0
					clrscr();
					firstStart = 1;
					printMENU(selection, resumeERR); // show menu
					c = getch();
					navigate(c, &selection);
					if(c == 10){ // ON ENTER PRESS ACCTION UPDATE VARIABLES STATE
						if(selection == 0){
							u = 1;
							resume = 0;
							for(int i = 0 ; i < 16; i++)
								a[i] = 0;
							score = 0;
							for(int i = 0 ; i < movesCnt;i++)
								moves[i] = 0;
						}
						if(selection == 1){
							if(history_size != 0){
								u = 1;
								resume = 1;
								resumeERR = 0;
							}else
									resumeERR = 1; //daca nu exista un punct de resume afisam mesajul corespunzator
						}
						if(selection == 2)
							u = -1;	
					}
				}else{ // game state u = 1
						if(firstStart){
							clrscr();
							if(resume){// ON RESUME ACTIONS GET DATA FROM HISTORY
								score = history[history_size-1][16];
								for(int i = 0 ; i < 16; i++)
									a[i] = history[history_size-1][i];
								movesCnt = history[history_size-1][17];
								for(int i = 18; i < history[history_size-1][17]; i++)
									moves[i-18] = history[history_size-1][i];
							}
							initWindow(win);
							createBorders(win);
							if(!resume)
								generate(a);
							save(history, a, &score, &history_size, moves, &movesCnt);
							fill(win, a);// UPDATING SCREEN FOR FIRST TIME
							mytime = time(NULL); // afisez ora si scorul
							mvprintw(17,20,"Time: %s", ctime(&mytime));
							mvprintw(17,0,"Socore: %d",score);
							movePrint(&movesCnt, moves);
							firstStart = 0;
						}
						if(isValid(a)){// daca exista o situtie de joc in care se poate de efectuat o mutare
							createBorders(win);
							movePrint(&movesCnt, moves);
							int k = 0, j = 0;
							fill(win, a);
							save(history, a, &score, &history_size, moves, &movesCnt);// salvam starea curenta
							printcharacter(a); // afisam nivelul la care a ajuns jucatorul
							c = getch();
							if(c == 'q' || c == 'Q')
								u = 0;
							else{
									if(c < 0)
										C = optim(a);// daca timpul trece de timeout gasim cea mai optima metoda
									else 
										k = change(a, c, win, &score, 30000);
									j = 0;
									while(!k && c < 0){// cautam prima mutare valida
										k = change(a, C[j], win, &score, 30000);
										if(k)
											c = C[j];
										j++;
									}	
									fill(win, a);
									mytime = time(NULL);// afisam timpul
									mvprintw(17,20,"Time: %s", ctime(&mytime));
									mvprintw(17,0,"Socore: %d",score);
									if(k){
										moveadd(moves, &movesCnt, c);//adauga miscarea valida
										movePrint(&movesCnt, moves); //afisam miscarile valide
									}
									if(k)
										generate(a); //genereaza un element nou
							}
						}else 
							c = 'G'; // GAMEOVER
				}
			}
	}
	if(c == 'G'){
		printGAMEOVER(); // Afiseaza gameover
	}
	if(u >= 0 || u == -5)
		getch(); // daca joaca a fost cistigata facem o pauza de timp timeout
	endwin(); //sfirsit ncurses
	free(C); // eliberam memoria
	return 0;

}
