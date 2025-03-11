#include <stdio.h>

#define TAMANHO 10

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') {
            tabuleiro[x][y + i] = 3;
        } else if (direcao == 'V') {
            tabuleiro[x + i][y] = 3;
        } else if (direcao == 'D') { // Diagonal principal
            tabuleiro[x + i][y + i] = 3;
        } else if (direcao == 'A') { // Diagonal secundária
            tabuleiro[x + i][y - i] = 3;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int x, int y, char habilidade) {
    if (habilidade == 'C') { // Cone
        tabuleiro[x][y] = 1;
        if (x + 1 < TAMANHO) {
            tabuleiro[x + 1][y] = 1;
            if (y - 1 >= 0) tabuleiro[x + 1][y - 1] = 1;
            if (y + 1 < TAMANHO) tabuleiro[x + 1][y + 1] = 1;
        }
        if (x + 2 < TAMANHO) {
            for (int i = y - 2; i <= y + 2; i++) {
                if (i >= 0 && i < TAMANHO) tabuleiro[x + 2][i] = 1;
            }
        }
    } else if (habilidade == 'O') { // Octaedro
        if (x - 1 >= 0) tabuleiro[x - 1][y] = 1;
        if (x + 1 < TAMANHO) tabuleiro[x + 1][y] = 1;
        if (y - 1 >= 0) tabuleiro[x][y - 1] = 1;
        if (y + 1 < TAMANHO) tabuleiro[x][y + 1] = 1;
        tabuleiro[x][y] = 1;
    } else if (habilidade == 'X') { // Cruz
        for (int i = 0; i < TAMANHO; i++) {
            tabuleiro[i][y] = 1;
            tabuleiro[x][i] = 1;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionando navios
    posicionarNavio(tabuleiro, 2, 2, 4, 'H');
    posicionarNavio(tabuleiro, 5, 5, 3, 'V');
    posicionarNavio(tabuleiro, 1, 1, 3, 'D');
    posicionarNavio(tabuleiro, 6, 8, 3, 'A');
    
    // Exibindo tabuleiro com navios
    printf("Tabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);
    
    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 'C');
    aplicarHabilidade(tabuleiro, 7, 7, 'O');
    aplicarHabilidade(tabuleiro, 2, 7, 'X');
    
    // Exibindo tabuleiro após habilidades
    printf("\nTabuleiro com habilidades aplicadas:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}