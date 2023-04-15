#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
int main() {
	char *st_info[] = {"BR" , "BL" , "G" , "R" , "Y"};
	int items_num = sizeof(st_info) / sizeof(st_info[0]);
	const char *BR[] = {
		"BR1-Taipei Zoo",
		"BR2-Muzha",
		"BR3-Wanfang Community",
		"BR4-Wanfang Hospital",
		"BR5-Xinhai",
		"BR6-Linguang",
		"BR7-Liuzhangli",
		"BR8-Technology Building",
		"BR9-Daan",
		"BR10-Zhongxiao Fuxing",
		"BR11-Nanjing Fuxing",
		"BR12-Zhonshan Junior High School",
		"BR13-Songshan Airport",
		"BR14-Dazhi",
		"BR15-Jiannan Road",
		"BR16-Xihu",
		"BR17-Gangqian",
		"BR18-Wende",
		"BR19-Neihu",
		"BR20-Dahu Park",
		"BR21-Huzhou",
		"BR22-Donghu",
		"BR23-Nangang Software Park",
		"BR24-Taipei Nangang Exhibition Center"
	};
	const char *G[] = {
		"G1-Xindian",
		"G2-Xindian District Office",
		"G3-Qizhang",
		"G4-Dapinglin",
		"G5-Jingmei",
		"G6-Wanlong",
		"G7-Gongguan",
		"G8-Taipower Building",
		"G9-Guting",
		"G10-Chiang Kai-Shek Memorial Hall",
		"G11-Xiaonanmen",
		"G12-Ximen",
		"G13-Beimen",
		"G14-Zhonshan",
		"G15-Songjiang Nanjing",
		"G16-Nanjing Fuxing",
		"G17-Taipei Arena",
		"G18-Nanjing Sanmin",
		"G19-Songshan"
	};
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
				sleep(1);
				flag = false;
				break;
		}
	}
	//for sub item selection list
	flag = true;
	//initscr();//initialize the screen      <===> endwin();
	//cbreak();//turn off line buffering     <===> nocbreak();
	//noecho();//turn off echoing of typed keys <===> echo();
	//keypad(stdscr, TRUE);//turn on keypad mode ==> up down left right  <===> keypad(stdscr, FALSE);
	
	int sub_nums = 0;

		switch(select_item){
			case 0:
				sub_nums = sizeof(BR) / sizeof(BR[0]);
				printw("Your now in the list of %s line\n", st_info[select_item]);
				refresh();
				break;
			case 1:
				printw("BL Line\n");
				refresh();
				break;
			case 2:
				sub_nums = sizeof(G) / sizeof(G[0]);//init the sub item nums
				//print the sub item list
				printw("Your now in the list of %s line\n", st_info[select_item]);
				for (int i = 0; i < sub_nums; i++){
					printw("%s\n", G[i]);
				}
				refresh();
				break;
			case 3:
				printw("R Line\n");
				refresh();
				break;
			case 4:
				printw("Y Line\n");
				refresh();
				break;
			default:
				break;

		}

	sleep(1);

	endwin();//end curses mode == (nocbreak() + echo() + keypad(stdscr, FALSE))
	printf("Size = %d\n", sizeof(st_info) / sizeof(st_info[0]));


	return 0;
}

