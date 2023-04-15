#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    // Define the main list and sub-lists
    char* mainList[] = {"Fruits", "Vegetables", "Meat"};
    char* subList1[] = {"Apple", "Banana", "Grapes"};
    char* subList2[] = {"Carrot", "Broccoli", "Spinach"};
    char* subList3[] = {"Beef", "Chicken", "Pork"};
    char** subLists[] = {subList1, subList2, subList3};
    int numMainItems = sizeof(mainList) / sizeof(mainList[0]);
    int numSubLists = sizeof(subLists) / sizeof(subLists[0]);
    int numSubItems[3] = {3, 3, 3};
    int selectedItem = 0; // Index of the currently selected item in the main list
    int selectedSubItem = 0; // Index of the currently selected item in the sub-list

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Loop until the user selects an item
    while (1) {
        // Display the main list
        clear();
        printw("Select a category:\n");
        for (int i = 0; i < numMainItems; i++) {
            if (i == selectedItem) {
                printw("-> %s\n", mainList[i]);
            } else {
                printw("   %s\n", mainList[i]);
            }
        }
        refresh();

        // Get user input
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                selectedItem--;
                if (selectedItem < 0) {
                    selectedItem = numMainItems - 1;
                }
                break;
            case KEY_DOWN:
                selectedItem++;
                if (selectedItem >= numMainItems) {
                    selectedItem = 0;
                }
                break;
            case '\n':
                // User has selected a main item, display the sub-list
                clear();
                printw("Select an item from %s:\n", mainList[selectedItem]);
                for (int i = 0; i < numSubItems[selectedItem]; i++) {
                    if (i == selectedSubItem) {
                        printw("-> %s\n", subLists[selectedItem][i]);
                    } else {
                        printw("   %s\n", subLists[selectedItem][i]);
                    }
                }
                refresh();

                // Loop until the user selects a sub-item or goes back to the main list
                while (1) {
                    // Get user input
                    int subCh = getch();
                    switch (subCh) {
                        case KEY_UP:
                            selectedSubItem--;
                            if (selectedSubItem < 0) {
                                selectedSubItem = numSubItems[selectedItem] - 1;
                            }
                            break;
                        case KEY_DOWN:
                            selectedSubItem++;
                            if (selectedSubItem >= numSubItems[selectedItem]) {
                                selectedSubItem = 0;
                            }
                            break;
                        case '\n':
                            // User has selected a sub-item
                            endwin(); // Deinitialize ncurses
                            printf("You selected: %s from %s\n", subLists[selectedItem][selectedSubItem], mainList[selectedItem]);
			    break;
			default:
			    // User has gone back to the main list
			    selectedItem = 0;
			    selectedSubItem = 0;
			    break;
		    }
		}
	}
    }

    endwin(); // Deinitialize ncurses
    return 0;
}

