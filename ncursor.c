#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
int main() {
	char *st_info[] = {"BR" , "BL" , "G" , "R" , "Y"};
	int items_num = sizeof(st_info) / sizeof(st_info[0]);
	int select_item = 0;
	bool flag = true;	
	

	initscr();//initialize the screen      <===> endwin();
	cbreak();//turn off line buffering     <===> nocbreak();
	noecho();//turn off echoing of typed keys <===> echo();
	keypad(stdscr, TRUE);//turn on keypad mode ==> up down left right  <===> keypad(stdscr, FALSE);
			     //
	while (flag){
		clear();
		
		// Print the list
		printw("Select Info : \n");
		for (int i = 0; i < items_num; i++){
			if (i == select_item){
				printw("-> %s\n", st_info[i]);
			}else{
				printw("   %s\n", st_info[i]);
			}
		}
		int c = getch();	
		switch(c){
			case KEY_UP:
				if (select_item > 0){
					select_item--;
				}
				break;
			case KEY_DOWN:
				if(select_item < items_num - 1){
					select_item++;
				}
				break;
			case '\n': //Enter
				mvprintw(items_num + 2 , 0,"Station Info : %s\n", st_info[select_item]);
				refresh();//For the screen to update ==> used in curses mode
				getch();
				flag = false;
				break;
		}
	}
	endwin();//end curses mode == (nocbreak() + echo() + keypad(stdscr, FALSE))
	
	printf("Size = %d\n", sizeof(st_info) / sizeof(st_info[0]));


	return 0;
}

