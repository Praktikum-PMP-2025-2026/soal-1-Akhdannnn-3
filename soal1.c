/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul               : 3 – Structures and Dynamic Arrays
*   Hari dan Tanggal    : Selasa, 5 Mei 2026
*   Nama (NIM)          : Ahmad Akhdan Tristan Salman (13224039)
*   Nama File           : soal1.c
*   Deskripsi           : Program untuk mengurutkan data meteorit dan cetak tiga terbaik.
* 
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char data[1000];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == 1000 - 1;
}

int push(Stack *s, char c) {
    if (isFull(s)) return 0;
    s->data[++(s->top)] = c;
    return 1;
}

char pop(Stack *s) {
    if (isEmpty(s)) return 0;
    return s->data[(s->top)--];
}

int cekPasangan(char ch) {
    if( ch == '(' || ch == ')' ||
        ch == '{' || ch == '}' || 
        ch == '[' || ch == ']' )
        return 1;
    
    return 0;
}

int cekKurung(const char *str) {
    Stack s;
    initStack(&s);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            if (!push(&s, ch)) return 0;
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) return 0;
            char topChar = pop(&s);
            if (!cekPasangan(topChar, ch)) return 0;
        }
    }

    return isEmpty(&s);
}

int main() {
    char input[1000];

    if (!fgets(input, sizeof(input), stdin)) {
        printf("Gagal membaca input.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    if (cekKurung(input)) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}
