#include"menu.h"

/**
 * 如果標準輸出不是螢幕，印出錯誤
 */
int main(void) {
    if (!isatty(fileno(stdout)))
        fprintf(stderr, "You are not a terminal, OK.\n");
    
    int choice = 0;
    FILE* input = ttyopen("r");
    FILE* output = ttyopen("w");
    if (!input || !output) {
        fprintf(stderr, "Unable to open %s\n", DEVTTY);
        exit(1);
    }
    do {
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);    //寫入標準輸出
    } while (choice != 'q');
    exit(0);
}


int getchoice(char* greet, char* choices[]) {
    FILE* input = ttyopen("r");
    FILE* output = ttyopen("w");

    int chosen = 0;
    int selected;
    char **option;

    do {
        fprintf(output, "Choice: %s\n", greet);
        option = choices;
        while (*option) {
            fprintf(output, "%s\n", *option);
            option++;
        }
        selected = fgetc(input);
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
            fprintf(output, "Incorrect choisem select again\n");
    } while (!chosen);
    
    return selected;
}