#include "print.h"
#include <ncurses.h>
// BIBLIOTECA FOLOSITA PENTRU AFISAREA MESAJELOR
// STERGERE, TOT CE NU FOLOSESTE FERESTRE CA PARAMETRI
void clrscr(){
	char space[1000];
	for(int i = 0; i < COLS; i++)
		space[i] = ' ';
	space[COLS] = '\0';
	for(int i = 0; i < LINES; i++)
		mvprintw(i,0,"%s",space);  	
}

void printcharacter(int a[]){
	int maxi;
	for(int i = 0; i < 16; i++)
		maxi = (maxi > a[i] ? maxi : a[i]);
	if(maxi <= 256){
		mvprintw(4,40,"%s","                                    ");
		mvprintw(5,40,"%s","                                    "); 
		mvprintw(6,40,"%s","                                    "); 
		mvprintw(7,35,"%s","                                          "); 
		mvprintw(8,40,"%s","                                    "); 
		mvprintw(9,40,"%s","                                    "); 
		mvprintw(10,40,"%s","                                    ");
		mvprintw(11,40,"%s","                                    ");
		mvprintw(12,40,"%s","                                    ");
		mvprintw(13,40,"%s","                                    ");
		mvprintw(4,40,"%s"," __    _  _______  _______  _______ ");
		mvprintw(5,40,"%s","|  |  | ||       ||       ||  _    |"); 
		mvprintw(6,40,"%s","|   |_| ||   _   ||   _   || |_|   |"); 
		mvprintw(7,35,"%s","LVL: |       ||  | |  ||  | |  ||       |"); 
		mvprintw(8,40,"%s","|  _    ||  |_|  ||  |_|  ||  _   | "); 
		mvprintw(9,40,"%s","| | |   ||       ||       || |_|   |"); 
		mvprintw(10,40,"%s","|_|  |__||_______||_______||_______|");
		refresh();
		return;
	}
	if(maxi <= 512){
		mvprintw(4,40,"%s","                                    ");
		mvprintw(5,40,"%s","                                    "); 
		mvprintw(6,40,"%s","                                    "); 
		mvprintw(7,35,"%s","                                          "); 
		mvprintw(8,40,"%s","                                    "); 
		mvprintw(9,40,"%s","                                    "); 
		mvprintw(10,40,"%s","                                    ");
		mvprintw(11,40,"%s","                                    ");
		mvprintw(12,40,"%s","                                    ");
		mvprintw(13,40,"%s","                                    ");
		mvprintw(4,40,"%s","_______   _______    ______  ");
		mvprintw(5,40,"%s","|       \\ |       \\  /      \\ "); 
		mvprintw(6,40,"%s","| $$$$$$$\\| $$$$$$$\\|  $$$$$$\\"); 
		mvprintw(7,35,"%s","LVL: | $$__/ $$| $$__| $$| $$  | $$"); 
		mvprintw(8,40,"%s","| $$__/ $$| $$__| $$| $$  | $$"); 
		mvprintw(9,40,"%s","| $$    $$| $$    $$| $$  | $$"); 
		mvprintw(10,40,"%s","| $$$$$$$ | $$$$$$\\ | $$  | $$");
		mvprintw(11,40,"%s","| $$      | $$  | $$| $$__/ $$");
		mvprintw(12,40,"%s","| $$      | $$  | $$ \\$$    $$");
		mvprintw(13,40,"%s"," \\$$       \\$$   \\$$  \\$$$$$$");
		refresh();
		return;
	}
	if(maxi >= 2048){
		mvprintw(4,40,"%s","                                    ");
		mvprintw(5,40,"%s","                                    "); 
		mvprintw(6,40,"%s","                                    "); 
		mvprintw(7,35,"%s","                                      "); 
		mvprintw(8,40,"%s","                                    "); 
		mvprintw(9,40,"%s","                                    "); 
		mvprintw(10,40,"%s","                                    ");
		mvprintw(11,40,"%s","                                    ");
		mvprintw(12,40,"%s","                                    ");
		mvprintw(13,40,"%s","                                    ");
		mvprintw(4,40,"%s","  ____   ___   ___   ");
		mvprintw(5,40,"%s"," /    | /   \\ |   \\  "); 
		mvprintw(6,40,"%s","|   __||     ||    \\ "); 
		mvprintw(7,35,"%s","LVL: |  |  ||  O  ||  D  |"); 
		mvprintw(8,40,"%s","|  |_ ||     ||     |"); 
		mvprintw(9,40,"%s","|     ||     ||     |"); 
		mvprintw(10,40,"%s","|___,_| \\___/ |_____|");
		refresh();
		return;
	}
	
}
void printWin(){
	clrscr();       
	mvprintw(0,COLS/2-33,"%s"," __      __   ______   __    __        __       __  ______  __    __ ");
	mvprintw(1,COLS/2-33,"%s","|  \\    /  \\ /      \\ |  \\  |  \\      |  \\  _  |  \\|      \\|  \\  |  \\");
	mvprintw(2,COLS/2-33,"%s"," \\$$\\  /  $$|  $$$$$$\\| $$  | $$      | $$ / \\ | $$ \\$$$$$$| $$\\ | $$");
	mvprintw(3,COLS/2-33,"%s","  \\$$\\/  $$ | $$  | $$| $$  | $$      | $$/  $\\| $$  | $$  | $$$\\| $$");
	mvprintw(4,COLS/2-33,"%s","   \\$$  $$  | $$  | $$| $$  | $$      | $$  $$$\\ $$  | $$  | $$$$\\ $$");
	mvprintw(5,COLS/2-33,"%s","   \\$$  $$  | $$  | $$| $$  | $$      | $$  $$$\\ $$  | $$  | $$$$\\ $$");
	mvprintw(6,COLS/2-33,"%s","    \\$$$$   | $$  | $$| $$  | $$      | $$ $$\\$$\\$$  | $$  | $$\\$$ $$");
	mvprintw(7,COLS/2-33,"%s","    | $$    | $$__/ $$| $$__/ $$      | $$$$  \\$$$$ _| $$_ | $$ \\$$$$");
	mvprintw(8,COLS/2-33,"%s","    | $$     \\$$    $$ \\$$    $$      | $$$    \\$$$|   $$ \\| $$  \\$$$");
	mvprintw(9,COLS/2-33,"%s","     \\$$      \\$$$$$$   \\$$$$$$        \\$$      \\$$ \\$$$$$$ \\$$   \\$$");
}
void printMENU(int poz, int arg){
	clrscr();       
	mvprintw(0,COLS/2-33,"%s","     ______  _______        ______  _____   ______    ____   ____ ");
	mvprintw(1,COLS/2-33,"%s","    |      \\/       \\   ___|\\     \\|\\    \\ |\\     \\  |    | |    |");
	mvprintw(2,COLS/2-33,"%s","   /          /\\     \\ |     \\     \\\\\\    \\| \\     \\ |    | |    |");
	mvprintw(3,COLS/2-33,"%s","  /     /\\   / /\\     ||     ,_____/|\\|    \\  \\     ||    | |    |");
	mvprintw(4,COLS/2-33,"%s"," /     /\\ \\_/ / /    /||     \\--'\\_|/ |     \\  |    ||    | |    |");
	mvprintw(5,COLS/2-33,"%s","|     |  \\|_|/ /    / ||     /___/|   |      \\ |    ||    | |    |");
	mvprintw(6,COLS/2-33,"%s","|     |       |    |  ||     \\____|\\  |    |\\ \\|    ||    | |    |");
	mvprintw(7,COLS/2-33,"%s","|\\____\\       |____|  /|____ '     /| |____||\\_____/||\\___\\_|____|");
	mvprintw(8,COLS/2-33,"%s","| |    |      |    | / |    /_____/ | |    |/ \\|   ||| |    |    |");
	mvprintw(9,COLS/2-33,"%s"," \\|____|      |____|/  |____|     | / |____|   |___|/ \\|____|____|");
	mvprintw(10,COLS/2-33,"%s","    \\(          )/       \\( |_____|/    \\(       )/      \\(   )/  ");
	if(poz == 0){
		mvprintw(18,COLS/2-2,"%s", "QUIT");
		mvprintw(16,COLS/2-3,"%s", "RESUME");
		mvprintw(14,COLS/2-7,"%s", "!@ NEW GAME @!");
		mvprintw(20,COLS/2-9,"%s", "2048 C BUTMALAI DAN");
	}
	if(poz == 1){
		mvprintw(18,COLS/2-2,"%s", "QUIT");
		mvprintw(14,COLS/2-4,"%s", "NEW GAME");
		if(arg)
			mvprintw(16,COLS/2-6,"%s", "!@ RESUME @! NO SAVED DATA!");
		else
			mvprintw(16,COLS/2-6,"%s", "!@ RESUME @!");
		mvprintw(20,COLS/2-9,"%s", "2048 C BUTMALAI DAN");
	}	
	if(poz == 2){
		mvprintw(16,COLS/2-3,"%s", "RESUME");
		mvprintw(14,COLS/2-4,"%s", "NEW GAME");
		mvprintw(18,COLS/2-5,"%s", "!@ QUIT @!");
		mvprintw(20,COLS/2-9,"%s", "2048 C BUTMALAI DAN");	
	}
	refresh();
}  
void printGAMEOVER(){
	clrscr();
	mvprintw(0,COLS/2-33,"%s","      ___           ___           ___           ___        ");
	mvprintw(1,COLS/2-33,"%s","     /  /\\         /  /\\         /  /\\         /  /\\       ");
	mvprintw(2,COLS/2-33,"%s","    /  /::\\       /  /::\\       /  /::|       /  /::\\      ");
	mvprintw(3,COLS/2-33,"%s","   /  /:/\\:\\     /  /:/\\:\\     /  /:|:|      /  /:/\\:\\     ");
	mvprintw(4,COLS/2-33,"%s","  /  /:/  \\:\\   /  /::\\ \\:\\   /  /:/|:|__   /  /::\\ \\:\\    ");
	mvprintw(5,COLS/2-33,"%s"," /__/:/_\\_ \\:\\ /__/:/\\:\\_\\:\\ /__/:/_|::::\\ /__/:/\\:\\ \\:\\   ");
	mvprintw(6,COLS/2-33,"%s"," \\  \\:\\__/\\_\\/ \\__\\/  \\:\\/:/ \\__\\/  /~~/:/ \\  \\:\\ \\:\\_\\/   ");
	mvprintw(7,COLS/2-33,"%s","  \\  \\:\\ \\:\\        \\__\\::/        /  /:/   \\  \\:\\ \\:\\     ");
	mvprintw(8,COLS/2-33,"%s","   \\  \\:\\/:/        /  /:/        /  /:/     \\  \\:\\_\\/     ");
	mvprintw(9,COLS/2-33,"%s","    \\  \\::/        /__/:/        /__/:/       \\  \\:\\       ");
	mvprintw(10,COLS/2-33,"%s","     \\__\\/         \\__\\/         \\__\\/         \\__\\/       ");
	mvprintw(11,COLS/2-38,"%s","              ___                         ___           ___      ");
	mvprintw(12,COLS/2-38,"%s","             /  /\\          ___          /  /\\         /  /\\     ");  
	mvprintw(13,COLS/2-38,"%s","            /  /::\\        /  /\\        /  /::\\       /  /::\\    "); 
	mvprintw(14,COLS/2-38,"%s","           /  /:/\\:\\      /  /:/       /  /:/\\:\\     /  /:/\\:\\   "); 
	mvprintw(15,COLS/2-38,"%s","          /  /:/  \\:\\    /  /:/       /  /::\\ \\:\\   /  /::\\ \\:\\  ");
	mvprintw(16,COLS/2-38,"%s"," 	   /__/:/ \\__\\:\\  /__/:/  ___  /__/:/\\:\\ \\:\\ /__/:/\\:\\_\\:\\ ");
	mvprintw(17,COLS/2-38,"%s"," 	   \\  \\:\\ /  /:/  |  |:| /  /\\ \\  \\:\\ \\:\\_\\/ \\__\\/~|::\\/:/ ");
	mvprintw(18,COLS/2-38,"%s"," 	    \\  \\:\\  /:/   |  |:|/  /:/  \\  \\:\\ \\:\\      |  |:|::/  ");
	mvprintw(19,COLS/2-38,"%s"," 	     \\  \\:\\/:/    |__|:|__/:/    \\  \\:\\_\\/      |  |:|\\/   ");
	mvprintw(20,COLS/2-38,"%s"," 	      \\  \\::/      \\__\\::::/      \\  \\:\\        |__|:|~    ");
	mvprintw(21,COLS/2-38,"%s"," 	       \\__\\/           ~~~~        \\__\\/         \\__\\|     ");
	refresh();
}

void movePrint(int *movesCnt, int moves[]){
	mvprintw(0,35,"%s", "MOVES:                                 ");
	int  poz = 43;
	for(int i = 0; i < *movesCnt; i++)
	{
		if(moves[i] == KEY_UP){
			mvprintw(0,poz,"%s ", "UP");
			poz += 3;
		}
		if(moves[i] == KEY_DOWN){
			mvprintw(0,poz,"%s ", "DOWN");
			poz += 5;
		}
		if(moves[i] == KEY_LEFT){
			mvprintw(0,poz,"%s ", "LEFT");
			poz += 5;
		}
		if(moves[i] == KEY_RIGHT){
			mvprintw(0,poz,"%s ", "RIGHT");
			poz += 6;
		}
	}
}
