#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>


char caesar_encrypt(char c, int key) {

    if(c >= 'a' && c <= 'z') {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else if(c >= 'A' && c <= 'Z') {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else {
        return c;
    }
}

char caesar_decrypt(char c, int key) {
    
    key = (26 - key % 26) % 26;
    if(c >= 'a' && c <= 'z') {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else if(c >= 'A' && c <= 'Z') {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else {
        return c;
    }
}

int main(int argc, const char* argv[]) {
    char* endptr;

    if(argc < 4) {
        printf("usage: %s <encrypt/decrypt> <key> <value>\n", argv[0]);
        return 1;
    }
    
    int key = strtoimax(argv[2], &endptr, 10);
    int len = strlen(argv[3]);
    char* processed_string = malloc(len + 1);

    if(strcmp(argv[1], "--decrypt") == 0) {
        for(int i = 0; i < len; i++)
        {
            processed_string[i] = caesar_decrypt(argv[3][i], key);
        }
    }
    else if(strcmp(argv[1], "--encrypt") == 0) {
        for(int i = 0; i < len; i++)
        {
            processed_string[i] = caesar_encrypt(argv[3][i], key);
        }
    }
    processed_string[len] = '\0';
    printf("%s\n", processed_string);

    free(processed_string);
}