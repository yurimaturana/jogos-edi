#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char palavra[101];

    printf("Insira a palavra: ");
    fgets(palavra, 101, stdin);
    palavra[strlen(palavra) - 1] = '\0';

    int tamanho = sizeof(palavra);
    int acertou = 0, erros = 0, escondidas = 0;
    int letras[26]={0};

    int i, j;
    
    while (!acertou) {
        system("clear");

        printf("LETRAS: ");
        erros = 0;
        escondidas = 0;
        for (i = 0; i < 26; i++) {
            if (letras[i]) {
                int encontrou = 0;

                for (j = 0; j < tamanho && palavra[j]; j++) {
                    if (palavra[j] == i + 'a') {
                        encontrou = 1;
                        break;
                    }
                }

                printf("%c ", i + 'A');

                if (!encontrou) {
                    erros++;
                };
            }
        }
        printf("\n");

        printf("/---\\\n");
        printf("|   %c\n", erros > 0 ? 'o' : ' ');
        printf("|  %c%c%c\n", erros > 2 ? '/' : ' ', erros > 1 ? '|' : ' ', erros > 3 ? '\\' : ' ');
        printf("|  %c %c\n", erros > 4 ? '/' : ' ', erros > 5 ? '\\' : ' ');
        printf("|\n");
        // printf("ERROS: %d\n", erros);

        for (i = 0; i < tamanho && palavra[i]; i++) {
            if (letras[palavra[i] - 'a']) printf("%c ", palavra[i] - 'a' + 'A');
            else {
                escondidas++;
                printf("_ ");
            }
        }
        
        printf("\n");

        if (escondidas == 0) {
            printf("VOCE GANHOU!");
            break;
        }

        if (erros >= 6) {
            printf("VOCE PERDEU!");
            break;
        }

        char c = ' ';
        while (c == ' ') {
            char temp, temp2;
            scanf("%c", &temp);
            if (temp >= 'a' && temp <= 'z')
                temp2 = temp;
            else if (temp >= 'A' && temp <= 'Z')
                temp2 = temp - 'A' + 'a';

            if (letras[temp2 - 'a'] == 0) {
                letras[temp2 - 'a'] = 1;
                c = temp2;
            }
        }
    }

    return 0;
}
