#include <ncurses.h>

int checkpos(int newy,int newx);
int screen();
void print();
void print1();
void while1();
void mvplayerup();
void mvplayerdown();
void mvplayerleft();
void mvplayerright();
int playermove(int y, int x);
void monster1decision(void);
int map;
struct player {
	int yposition;
	int xposition;
};
struct player newplayer; 
struct player Player;
struct player monster1;
int main() {
	screen();
	Player.yposition = 6;
	Player.xposition = 13;
	monster1.yposition = 6;
	monster1.xposition = 46;
	print();
	while1();
	endwin();	
}
int screen()
{
	initscr();
	noecho();
	curs_set(0);
	return 0;
}
void print(){
	map = 1;
	mvprintw(1,12, "-------------------_----------------");
	mvprintw(2,12, "|                                  |");
	mvprintw(3,12, "|                       ---        |");
	mvprintw(4,12, "|   -  -  -  -          -          |");
	mvprintw(5,12, "|                       ---        |");
	mvprintw(6,12, "|      -                           |");
	mvprintw(7,12, "|                                  |");
	mvprintw(8,12, "|                  -               |");
	mvprintw(9,12, "|                               -  |");
	mvprintw(10,12, "|   - -   -           -       -    |");
	mvprintw(11,12, "|-------                           |");
	mvprintw(12,12, "|                                  |");
	mvprintw(13,12, "|                                  |");
	mvprintw(14,12, "------------------------------------");
	mvprintw(Player.yposition, Player.xposition, "@");
	mvprintw(monster1.yposition, monster1.xposition, "M");
}
void print1() {
	map = 2;
	mvprintw(1,12, "-----_------------------------------");
	mvprintw(2,12, "|            -                  -  |");
	mvprintw(3,12, "|                       -   -      |");
	mvprintw(4,12, "|  -         -                     |");
	mvprintw(5,12, "|      -         -    -            |");
	mvprintw(6,12, "|  -                          -    |");
	mvprintw(7,12, "|         -         -     -        |");
	mvprintw(8,12, "|      -    -  -    -              |");
	mvprintw(9,12, "|         -             -   -  - - |");
	mvprintw(10,12, "|  -     -        -                |");
	mvprintw(11,12, "|        -                         |");
	mvprintw(12,12, "|  -                    -      -   |");
	mvprintw(13,12, "|                                  |");
	mvprintw(14,12, "------------------------------------");
	mvprintw(Player.yposition, Player.xposition, "@");
	mvprintw(monster1.yposition, monster1.xposition, "M");
}
void print2() {
	map = 3;
	mvprintw(1,12, "-------------_----------------------");
	mvprintw(2,12, "|                            -     |");
	mvprintw(3,12, "|       -   -    -      -          |");
	mvprintw(4,12, "|    -        -     -      -       |");
	mvprintw(5,12, "|       -              -    - -    |");
	mvprintw(6,12, "|    -   -                  -      |");
	mvprintw(7,12, "|     -                      -     |");
	mvprintw(8,12, "|        -                -  -     |");
	mvprintw(9,12, "|    -                             |");
	mvprintw(10,12, "|       -              -    -      |");
	mvprintw(11,12, "|     -                        -   |");
	mvprintw(12,12, "|      -                  -        |");
	mvprintw(13,12, "|  -     -                  -      |");
	mvprintw(14,12, "------------------------------------");
	mvprintw(Player.yposition, Player.xposition, "@");		
}
void while1(void) {	
	char ch;
	int newy, newx;
	while((ch = getch()) != 'q') {	
		switch(ch) {			
			case 'w':
				newy = Player.yposition - 1;
				newx = Player.xposition;
				checkpos(newy,newx);
				break;
			
			case 's': 
				newy = Player.yposition + 1;
				newx = Player.xposition;
				checkpos(newy,newx);
				break;
			case 'a':
				newy = Player.yposition;
				newx = Player.xposition - 1;
				checkpos(newy,newx);
				break;
			case 'd':
				newy = Player.yposition;
				newx = Player.xposition + 1;
				checkpos(newy,newx);
				break;
		}
	}				
}
int checkpos(int newy,int newx) {

	if(mvinch(Player.yposition,Player.xposition) == mvinch(monster1.yposition,monster1.xposition)){
			printw("GAMEOVER");
		}
			

	else if (mvinch(newy,newx) == '_' && map == 1) {
		Player.yposition = 13;
		Player.xposition = 31;
		monster1.xposition = 35;
		monster1.yposition = 4;
		print1();	
	}
	else if (mvinch(newy,newx) == '_' && map == 2) {
		Player.yposition = 13;
		Player.xposition = 31;
		monster1.xposition = 22;
		monster1.yposition = 2;
		print2();
	}
	else if (mvinch(newy,newx) == '#' && map == 2) {
		Player.yposition = 2;
		Player.xposition = 31;
		monster1.yposition = 6;
		monster1.xposition = 46;	
		print();
	}	
	else if(mvinch(newy,newx) == '_' && map == 3) {
		printw("YOU WIN");
		
		}	
	else if (mvinch(newy,newx) == ' ' || mvinch(newy,newx) == 'M') {
		playermove(newy,newx);
		monster1decision();
	}
}
int playermove(int y, int x){
	mvprintw(Player.yposition,Player.xposition, " ");
	Player.yposition = y;
	Player.xposition = x;
	mvprintw(Player.yposition,Player.xposition, "@");
}
void monster1decision(){
	if(Player.yposition > monster1.yposition && mvinch(monster1.yposition + 1,monster1.xposition) == ' ' || mvinch(monster1.yposition + 1,monster1.xposition) == '@') {
		mvprintw(monster1.yposition,monster1.xposition," ");
		monster1.yposition += 1;
		mvprintw(monster1.yposition,monster1.xposition,"M");
	}	
	if(Player.xposition > monster1.xposition && mvinch(monster1.yposition,monster1.xposition + 1) == ' ' || mvinch(monster1.yposition,monster1.xposition + 1) == '@' ) {
	mvprintw(monster1.yposition,monster1.xposition," ");
	monster1.xposition +=1;
	mvprintw(monster1.yposition,monster1.xposition,"M");
	}
	if(Player.yposition < monster1.yposition && mvinch(monster1.yposition - 1,monster1.xposition) == ' ' || mvinch(monster1.yposition - 1,monster1.xposition) == '@' ) {
	mvprintw(monster1.yposition,monster1.xposition," ");
	monster1.yposition -= 1;
	mvprintw(monster1.yposition,monster1.xposition,"M");
	}
	if(Player.xposition < monster1.xposition && mvinch(monster1.yposition,monster1.xposition - 1) == ' ' || mvinch(monster1.yposition,monster1.xposition - 1) ==  '@' ) {
	mvprintw(monster1.yposition,monster1.xposition," ");
	monster1.xposition -= 1;
	mvprintw(monster1.yposition,monster1.xposition,"M");
	}
}
