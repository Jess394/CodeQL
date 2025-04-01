// vulnerable.c
#include <stdio.h>
#include <string.h>

int bof(char *str) {
    char buffer[24];            
    printf("Address of buffer: %p\n", (void*)buffer);  // Debug print
    strcpy(buffer, str);       
    return 1;
}

int main(int argc, char **argv) {
    char str[517];             
    FILE *badfile = fopen("badfile", "r");
    if (!badfile) {
        perror("Failed to open badfile");
        return 1;
    }
    fread(str, sizeof(char), 517, badfile);
    fclose(badfile);
    bof(str);
    return 0;
}
