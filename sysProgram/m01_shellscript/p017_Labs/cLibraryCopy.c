#include<stdio.h>
#include<stdlib.h>

int mfcopy(char *file, FILE *rfp, FILE *wfp);
int main(int argc, char *argv[]) {
    if (argc == 3) {
        exit(mfcopy(argv[1], fopen(argv[1], "r"), fopen(argv[2], "w")));
    }
    else {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
}

int mfcopy(char *file, FILE *rfp, FILE *wfp) {
    if (rfp == NULL) {
        printf("Can't open %s\n", file);
        return 1;
    }
    else {
        int ch = 0;
        while ((ch = fgetc(rfp)) != EOF) {	
            fputc(ch, wfp);
        }     
        fclose(rfp);
        fclose(wfp);
        printf("%s copy *SUCCESS*", file);
        return 0;
    }
}