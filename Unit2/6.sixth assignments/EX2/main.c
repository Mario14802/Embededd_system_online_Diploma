#include <stdio.h>
#include <stdlib.h>


void alpha(void (*callback)(char));

void print_alphabet(char c) {
    printf("%c ", c);
}

int main() {
    alpha(&print_alphabet);
    return 0;
}

void alpha(void (*callback)(char)) {
    for (char c = 'a'; c <= 'z'; c++) {
        callback(c);
    }
}
