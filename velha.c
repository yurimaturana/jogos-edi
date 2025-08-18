#include <stdio.h>
#include <stdlib.h>

void imprimir(int jogo[3][3]);
int gameOver(char *vitoria, int jogo[3][3]);

int main() {
    int jogo[3][3] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
    };
    int jogada = 0;
    char vencedor;

    while (!gameOver(&vencedor, jogo) && jogada < 9) {
        system("clear");
        imprimir(jogo);

        printf("VEZ DE %c\nINSIRA A ENTRADA [LINHA] [COLUNA]\n", jogada % 2 == 0 ? 'x' : 'o');
        int linha, coluna;
        scanf("%d %d", &linha, &coluna);

        if (jogo[linha-1][coluna-1] == ' ' && linha - 1 < 3 && linha - 1 >= 0 && coluna - 1 < 3 && coluna - 1 >= 0) {
            jogo[linha-1][coluna-1] = jogada % 2 == 0 ? 'x' : 'o';
            jogada++;
        }
    }

    system("clear");
    imprimir(jogo);

    if (vencedor == 'x' || vencedor == 'o')
        printf("JOGO FINALIZADO\nVencedor: %c\n", vencedor);
    else
        printf("JOGO FINALIZADO\nEmpate!");

    return 0;
}

void imprimir(int jogo[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (j < 2)
                printf(" %c |", jogo[i][j]);
            else
                if (i < 2)
                    printf(" %c\n---+---+---\n", jogo[i][j]);
                else
                    printf(" %c\n", jogo[i][j]);
}

int gameOver(char *vitoria, int jogo[3][3]) {
    int resposta = 0;
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (jogo[i][j] != ' ') {
                if (i - 1 >= 0 && i + 1 < 3 && jogo[i-1][j] == jogo[i][j] && jogo[i+1][j] == jogo[i][j]) {
                    resposta = 1;
                    break;
                }
                if (j - 1 >= 0 && j + 1 < 3 && jogo[i][j-1] == jogo[i][j] && jogo[i][j+1] == jogo[i][j]) {
                    resposta = 1;
                    break;
                }
                if (i - 1 >= 0 && i + 1 < 3 && j - 1 >= 0 && j + 1 < 3 &&
                    ((jogo[i-1][j+1] == jogo[i][j] && jogo[i+1][j-1] == jogo[i][j]) ||
                    (jogo[i-1][j-1] == jogo[i][j] && jogo[i+1][j+1] == jogo[i][j]))) {
                    resposta = 1;
                    break;
                }
            }
        }
        if (resposta) break;
    }

    if (resposta) *vitoria = jogo[i][j];

    return resposta;
}
