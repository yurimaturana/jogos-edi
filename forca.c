#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int letrasChutadas[26]={0};

void lerLetra();
void mostrarGrafico(int erros);

int main() {
    char palavra[101];

    printf("Insira a palavra: ");
    fgets(palavra, 101, stdin);
    palavra[strlen(palavra) - 1] = '\0';

    int tamanho = strlen(palavra);
    int finalizado = 0, erros = 0, faltamDescobrir = 0;
    
    int i, j;
    
    for (i = 0; i < tamanho; i++) {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            palavra[i] = palavra[i] - 'A' + 'a';
        else if ((palavra[i] >= 'a' && palavra[i] <= 'z') || palavra[i] == '-') {
            // Mantém
        }
        else palavra[i] = ' ';
    }
    
    while (!finalizado) {
        printf("\033[2J\033[H");

        printf("LETRAS: ");
        erros = 0;
        faltamDescobrir = 0;

        for (i = 0; i < 26; i++) {
            if (letrasChutadas[i]) {
                int encontrou = 0;

                for (j = 0; j < tamanho && palavra[j]; j++) {
                    if (palavra[j] == i + 'a') {
                        encontrou = 1;
                        break;
                    }
                }

                printf("%s%c \033[0;0m", !encontrou ? "\033[0;91m" : "\033[0;33m",  i + 'A');

                if (!encontrou) erros++;
            }
        }
        printf("\n");

        mostrarGrafico(erros);
        
        for (i = 0; i < tamanho && palavra[i]; i++) {
            if (palavra[i] == '-') printf("- ");
            else if (letrasChutadas[palavra[i] - 'a']) printf("\033[0;36m%c \033[0;0m", palavra[i] - 'a' + 'A');
            else {
                faltamDescobrir++;
                printf("\033[0;90m_ \033[0;0m");
            }
        }
        
        printf("\n");

        if (faltamDescobrir == 0) {
            printf("\033[0;32mVOCE GANHOU!\033[0;0m");
            finalizado = 1;
        }

        if (erros >= 6) {
            printf("\033[0;31mVOCE PERDEU!\033[0;0m");
            finalizado = 1;
        }

        lerLetra(letrasChutadas);
    }

    printf("\n");

    return 0;
}

void lerLetra() {
    char temp = getchar(), temp2;

    if (temp >= 'a' && temp <= 'z')
        temp2 = temp;
    else if (temp >= 'A' && temp <= 'Z')
        temp2 = temp - 'A' + 'a';
    else return;

    if (letrasChutadas[temp2 - 'a'] == 0)
        letrasChutadas[temp2 - 'a'] = 1;
}

void mostrarGrafico(int erros) {
    printf("\033[0;90m/---\\\033[0;0m\n");
    printf("\033[0;90m|\033[0;31m   %c\033[0;0m\n", erros > 0 ? 'o' : ' ');
    printf("\033[0;90m|\033[0;31m  %c%c%c\033[0;0m\n", erros > 2 ? '/' : ' ', erros > 1 ? '|' : ' ', erros > 3 ? '\\' : ' ');
    printf("\033[0;90m|\033[0;31m  %c %c\033[0;0m\n", erros > 4 ? '/' : ' ', erros > 5 ? '\\' : ' ');
    printf("\033[0;90m|\033[0;0m\n");
}
