#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RANDOM 10

typedef enum {
    LOWERCASE,
    UPPERCASE,
    NUMBER,
    SYMBOL
} KeyType;

const char* keyStrings[] = {
    [LOWERCASE] = "abcdefghijklmnopq",
    [UPPERCASE] = "ABCDEFGHIJKLMNOPQ",
    [NUMBER]    = "1234567890",
    [SYMBOL]    = "!@#$%^&*()_+",
};

int randomize_number(int limit) {
    int r = rand() % limit;
    return r;
}

int main() {
    #ifdef DEBUG
        printf("--- DEBUG MODE:---\n");
        printf("Seed = 42\n");
        srand(42);                      // Fixed seed for reproducible debugging
    #else
        srand(time(NULL));              // Real randomness for production
    #endif

    int opt[] = {
        LOWERCASE,
        UPPERCASE,
        NUMBER,
        SYMBOL
    };

    int opt_size = (int) sizeof(opt) / sizeof(int);
    int pwd_size = 16;

    for(int i = 0; i < pwd_size ; i++) {
        int rand_number = randomize_number(opt_size);
        const char *s   = keyStrings[rand_number];
        int s_size      = strlen(s);
        char val        = s[randomize_number(s_size)];

        printf("%c", val);
    }

    printf("\n");

    return 0;
}
