#include "optim.h"
#include <ncurses.h>
#include <stdlib.h>
// incearca toate posibilele mutari si returneaza un tablou cu mutarile cele mai "optime"
int* optim(int a[]){
	
	int c[20], aux[5], *key = malloc(5*sizeof(int));
	
	for(int i = 0 ; i < 16; i++)
		c[i] = a[i];
	aux[0] = optimChange(c, KEY_DOWN);// muata tabla in taote directiile si alege miscarea potrivita 
	key[0] = KEY_DOWN;
	
	for(int i = 0 ; i < 16; i++)
		c[i] = a[i];
	aux[1] = optimChange(c, KEY_RIGHT);
	key[1] = KEY_RIGHT;
	
	for(int i = 0 ; i < 16; i++)
		c[i] = a[i];
	aux[2] = optimChange(c, KEY_LEFT);
	key[2] = KEY_LEFT;
	
	for(int i = 0 ; i < 16; i++)
		c[i] = a[i];
	aux[3] = optimChange(c, KEY_UP);
	key[3] = KEY_UP;
	
	for(int i = 0; i < 4; i++){//sorteaza descrescator conform valoarea returnate de optimchange
		for(int j = 0; j < 4; j++){
			if(aux[i] > aux[j]){
				int c = aux[i];
				aux[i] = aux[j];
				aux[j] = c;
				c = key[i];
				key[i] = key[j];
				key[j] = c;
			}
		}
	}
	return key;
}

int optimChange(int a[], int c){ // returneaza numarul de celule libere dupa mutare
	int b[5][5],available[5][5], k = 0, ret = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			b[i][j] = a[k];
			available[i][j] = 1;
			k++;
		}
	}
	if(c == KEY_DOWN){//down
		for(int j = 3; j >= 0; j--)
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
								}
					}
		for(int j = 3; j >= 0; j--)
			for(int i = 3; i > 0; i--)
				if(b[i][j] == b[i-1][j] && available[i][j] && available[i-1][j] && b[i][j] && b[i-1][j]){
					b[i][j] += b[i-1][j];
					b[i-1][j] = 0;
					available[i][j] = 1;
					available[i-1][j] = 1;
				}
			for(int i = 0 ; i < 4; i++)
				for(int j = 0; j < 4; j++)
					if(!b[i][j])
						ret++;
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
							}
				}
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 3; j++)	
				if(b[i][j] == b[i][j+1] && available[i][j] && available[i][j+1] && b[i][j+1] && b[i][j]){
					b[i][j] += b[i][j+1];
					b[i][j+1] = 0;
					available[i][j] = 1;
					available[i][j+1] = 1;
				}
		for(int i = 0 ; i < 4; i++)
				for(int j = 0; j < 4; j++)
					if(!b[i][j])
						ret++;
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
							}
				}
		for(int i = 0; i < 4; i++)
			for(int j = 3; j >= 0; j--)	
				if(b[i][j] == b[i][j-1] && available[i][j] && available[i][j-1] && b[i][j-1] && b[i][j]){
					b[i][j] += b[i][j-1];
					b[i][j-1] = 0;
					available[i][j] = 1;
					available[i][j-1] = 1;
				}
		for(int i = 0 ; i < 4; i++)
				for(int j = 0; j < 4; j++)
					if(!b[i][j])
						ret++;
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
							}
				}
		for(int j = 3; j >= 0; j--)
			for(int i = 0; i < 4; i++)
				if(b[i][j] == b[i+1][j] && available[i][j] && available[i+1][j] && b[i][j] && b[i+1][j]){
					b[i][j] += b[i+1][j];
					b[i+1][j] = 0;
					available[i][j] = 1;
					available[i+1][j] = 1;
				}
		for(int i = 0 ; i < 4; i++)
				for(int j = 0; j < 4; j++)
					if(!b[i][j])
						ret++;	
	}
	return ret;
}

