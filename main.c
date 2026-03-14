#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RANDOM 10

const char *lowercase = "abcdefghijklmnopq";
const char *uppercase = "ABCDEFGHIJKLMNOPQ";
const char *number    = "1234567890";
const char *symbol    = "!@#$%^&*()_+";

int randomize_number(int limit) {
    int r = rand() % limit;
    return r;
}

int main() {
    const char* keyStrings[] = {
        lowercase,
        uppercase,
        number,
        symbol
    };

    #ifdef DEBUG
        printf("--- DEBUG MODE:---\n");
        printf("Seed = 42\n");
        srand(42);                      // Fixed seed for reproducible debugging
    #else
        srand(time(NULL));              // Real randomness for production
    #endif

    int size = (int) sizeof(keyStrings) / sizeof(keyStrings[0]);
    int pwd_size = 16;

    for(int i = 0; i < pwd_size ; i++) {
        int n = randomize_number(size);
        const char *opt = keyStrings[n];
        int opt_size = strlen(opt);

        printf("%c", opt[randomize_number(opt_size)]);
    }

    printf("\n");

    return 0;
}
