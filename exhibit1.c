#include <stdio.h>
#include <unistd.h>
#include "header.h"

unsigned int sleep(unsigned int seconds);
int load_lvl1(FILE *);
int load_lvl2(FILE *);
int load_lvl3(FILE *);
char dun[ro][co];
FILE *fp;
int y,x;
int print(void);
static int playlocx = 1;
static int playlocy = 6;
int monlocy = 6;
int monlocx = 34;
char (*player)[36];
char (*monster1)[36];
char (*end)[36];
char (*end2)[36];
char (*end3)[36];
char ch;
void playerm_west(void);
void playerm_north(void);
void playerm_east(void);
void playerm_south(void);
void playerm_nw(void);
void playerm_ne(void);
void playerm_se(void);
void playerm_sw(void);
int while_loop(void);
int main(void)
{
	load_lvl1(fp);
	
	player = &(dun[playlocy][playlocx]);
	**player = PLAYER;
	end = &(dun[0][17]);
	end2 = &(dun[0][2]);
	end3 = &(dun[0][13]);
	**end = END;
	monster1 = &(dun[monlocy][monlocx]);
	**monster1 = M;
	
	print();
	while_loop();
}

int load_lvl1(FILE *file)
{	fp = fopen("lvl1","r");
	for(y=0;y<ro;y++)
		for(x=0;x<co;x++)
			fscanf(fp,"%c",&dun[y][x]);
	fclose(fp);
}
int load_lvl3(FILE *file)
{	fp = fopen("lvl3","r");
	for(y=0;y<ro;y++)
		for(x=0;x<co;x++)
			fscanf(fp,"%c",&dun[y][x]);
	fclose(fp);
}
int load_lvl2(FILE *file)
{	fp = fopen("lvl2","r");
	for(y=0;y<ro;y++)
		for(x=0;x<co;x++)
			fscanf(fp,"%c",&dun[y][x]);
	fclose(fp);
}
int print(void)
{
	system("clear");
	for(y=0;y<ro;y++)
		for(x=0;x<co;x++)
			printf("%c",dun[y][x]);
}

int while_loop(void)
{	
	char ch;
	int f;
	while((ch = getchar()) != 'q'){			
		ch = tolower(ch);
		if (ch == '\n'){
			continue;}
		if(**player == **end3){
			printf("YOU WIN");
			break;}
		if(**player == **end2){
				load_lvl3(fp);
				playlocy = 12;
				playlocx = 18;
				player = &(dun[playlocy][playlocx]);
				**player = PLAYER;
				end3 = &(dun[0][13]);
				**end3 = END;
				monlocy = 1;
				monlocx = 10;
				print();
				continue;}
		if(**player == **end){
			load_lvl2(fp);
			playlocy = 12;
			playlocx = 17;
			player = &(dun[playlocy][playlocx]);
			**player = PLAYER;
			end2 = &(dun[0][2]);
			**end2 = END;
			print();
			continue;}
		if(monster1 == &(dun[playlocy][playlocx])){
			**player = M;
			print();
			printf("GAME OVER");
			break;}
		else{	switch(ch){			
				case 'n':
					playerm_north();
					continue;
				case 's': 
					playerm_south();
					continue;
				case 'w':
					playerm_west();
					continue;			
				case 'e':
					playerm_east();
					continue;
				default:{
					printf("i dont understand that try again\n");
					continue;}}}}	
}

void playerm_west(void){
	if(dun[playlocy][playlocx-1] == 'w'){
		print();
		monster1decision();}
	else
		playlocx -= 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}
void playerm_east(void){
	if(dun[playlocy][playlocx+1] == 'w'){
		print();
		monster1decision();}	
	else
		playlocx += 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}
void playerm_north(void){
	if(dun[playlocy-1][playlocx] == 'w'){	print();
		monster1decision();}
	else
		playlocy -= 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}
void playerm_south(void)
{
	
	if(dun[playlocy+1][playlocx] == 'w')
	{	
		print();
		monster1decision();
	}
	else
		playlocy += 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
	

}

void playerm_nw(void)
{
	if(dun[playlocy-1][playlocx-1] == 'w')
	{	print();
		monster1decision();	
	}

	else
		playlocx -= 1;
		playlocy -= 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}		
void playerm_ne(void)
{
	if(dun[playlocy-1][playlocx+1] == 'w')
	{	print();
		monster1decision();	
	}

	else
		playlocx += 1;
		playlocy -= 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}		
void playerm_se(void)
{
	if(dun[playlocy+1][playlocx+1] == 'w')
	{	print();
		monster1decision();	
	}

	else
		playlocx += 1;
		playlocy += 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}		
void playerm_sw(void)
{
	if(dun[playlocy+1][playlocx-1] == 'w')
	{	print();
		monster1decision();	
	}

	else
		playlocx -= 1;
		playlocy += 1;
		**player = s;
		player = &(dun[playlocy][playlocx]);
		**player = PLAYER;
		print();
		monster1decision();
}		
void monster1decision(void)
{
	
	
	if(playlocy > monlocy && dun[monlocy+1][monlocx] != 'w')
	{	monlocy += 1;
		monster1m_south();
	}
	if(playlocx > monlocx && dun[monlocy][monlocx+1] != 'w')
	{	monlocx +=1;
		monster1m_east();}
	if(playlocy < monlocy && dun[monlocy-1][monlocx] != 'w')
	{	monlocy -= 1;
		monster1m_north();}
	if(playlocx < monlocx && dun[monlocy][monlocx-1] != 'w')
	{	monlocx -= 1;
		monster1m_west();
	}
}
void monster1m_north(void)
{		**monster1 = s;
		monster1 = &(dun[monlocy][monlocx]);
		**monster1 = M;
}	

void monster1m_south(void)
{		**monster1 = s;
		monster1 = &(dun[monlocy][monlocx]);
		**monster1 = M;
		print();
}	

void monster1m_east(void)
{		**monster1 = s;
		monster1 = &(dun[monlocy][monlocx]);
		**monster1 = M;
}	

void monster1m_west(void)
{		**monster1 = s;
		monster1 = &(dun[monlocy][monlocx]);
		**monster1 = M;
}
