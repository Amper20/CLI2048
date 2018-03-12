#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "utils.h"

//UTILITARE

//SALVARE DATE, AM FOLOSIT O MATRICE PENTRU A SALVA MUTARILE PENTRU A REALIZA IN VIITOR O OPTIUNE DE UNDO
void save(int history[1000][30], int a[], int *score, int *history_size, int moves[], int *movesCnt){
	int i; 
	for(int i = 0 ; i < 16; i++) //SAVING THE STATE
		history[(*history_size)][i] = a[i];
	history[(*history_size)][16] = (*score);
	history[(*history_size)][17] = (*movesCnt);
	for(i = 18; i < history[(*history_size)][17]; i++)
		history[(*history_size)][i] = moves[i-18];
	(*history_size)++;
}
// NAVIGARE PRIN MENU
void navigate(int c, int *selection){
	if(c == KEY_UP)
		(*selection)--;
	if(c == KEY_DOWN)
		(*selection)++;
	if((*selection)< 0)
		(*selection) = 0;
	if((*selection) > 2)
		(*selection) = 2;
}
// VERIFICA DACA JOCULA  FOST CISTIGAT
int Win(int a[]){
	for(int i = 0; i < 16; i++)
		if(a[i] >= 2048)
			return 1;
	return 0;
}
// ADAUGA MISCARI VALIDE LA LISTA
void moveadd(int moves[], int *movesCnt, int c){
	if(*movesCnt  >= 5){
		for(int i = 0; i < *movesCnt; i++)
			moves[i] = moves[i+1];
		moves[*movesCnt-1] = c;
	}else{
		moves[*movesCnt] = c;
		(*movesCnt)++;
	}
}
// VERIFICA VALIDITATEA SITUATIEI CURENTE
int isValid(int a[]){
	int b[5][5], k = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			b[i][j] = a[k];
			k++;
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(!b[i][j])
				return 3;
			if(i + 1 < 4)
				if(b[i][j] == b[i+1][j])
					return 1;
			if(i - 1 >= 0)
				if(b[i][j] == b[i-1][j])
					return 1;
			if(j - 1 >= 0)
				if(b[i][j] == b[i][j-1])
					return 2;
			if(j + 1 < 4)
				if(b[i][j] == b[i][j+1])
					return 2;
		}
	}
	return 0;
}
// GENEREAZA PSEUDORANDOM UN ELEMENT NOU
void generate(int a[]){
	int available[20], j = 0;
	for(int i = 0 ; i < 16; i++){
		if(!a[i]){
			available[j] = i;
			j++;
		}
	}
	int r = rand()%j;
	a[available[r]] = (rand()%3 == 0? 4 : 2); 
}
// CONVERTESTE ELEMENTELE IN STRING
char* toStr(int x){
	char* c = malloc(7*sizeof(char));
	int i = 0;
	if(x == 0){
		for(; i < 5; i++)
			c[i] = ' ';
	}
	while(x){
		c[i] = x%10 + '0';
		x/=10;
		i++;
	}
	c[i] = '\0';
	for(int i = 0 ; i < strlen(c)/2; i++){
		char swp = c[i];
		c[i] = c[strlen(c) - 1 + i];
		c[strlen(c) - 1 + i] = swp;
	}
	return c;
}
// MAPUL CULORILOR
int get(int x){
	if(x == 2)
		return 1;
	if(x == 4)
		return 2;
	if(x == 8)
		return 3;
	if(x == 16)
		return 4;
	if(x == 32)
		return 5;
	if(x == 64)
		return 6;
	if(x == 128)
		return 7;
	if(x == 256)
		return 8;
	if(x == 512)
		return 9;
	if(x == 1024)
		return 10;
	if(x == 2048)
		return 11;
	return 0;
}
