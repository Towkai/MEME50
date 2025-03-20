#include"menu.h"

/**
 * 如果標準輸出不是螢幕，印出錯誤
 */
int main(void) {
    int choice = 0;

    ///--- 如果輸出被重導。印出錯誤並退出
    if (!isatty(fileno(stdout))) {
        fprintf(stderr, "You are not a terminal!\n");
        exit(1);
    }
    ///---

    do {
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    } while (choice != 'q');
    exit(0);
}


int getchoice(char* greet, char* choices[]) {
    int chosen = 0;
    int selected;
    char **option;

    do {
        printf("Choice: %s\n", greet);
        option = choices;
        while (*option) {
            printf("%s\n", *option);
            option++;
        }
        selected = getchar();
        printf("select: %c, ascii code = %d\n", selected, selected);
        option = choices;
        while (*option) {
            if (selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }
        if (!chosen)
            printf("Incorrect choisem select again\n");
    } while (!chosen);
    
    return selected;
}