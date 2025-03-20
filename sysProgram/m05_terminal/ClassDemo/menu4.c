#include<termios.h>
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

    ///---取得指定終端機的設定並存到initial_settings的位址中
    struct termios initial_settings, new_settings;
    tcgetattr(fileno(input), &initial_settings);
    new_settings = initial_settings;    //new_settings用來做修矮，initial_settings當作備份
    new_settings.c_lflag &= ~ICANON;    //關閉標準輸入功能
    new_settings.c_lflag &= ~ECHO;      //關閉ECHO功能
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_lflag &= ~ISIG       //關閉訊號功能
    ///---
    if (tcsetattr(fileno(input), TCSANOW, &new_settings) != 0)
        fprintf(stderr, "could not set sttributes\n");

    do {
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);    //寫入標準輸出
    } while (choice != 'q');
    tcsetattr(fileno(input), TCSANOW, &initial_settings)
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

        do {
            selected = fgetc(input);
            printf("select: %c, ascii code = %d\n", selected, selected);
        } while (selected == '\n' || selected == '\r');
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