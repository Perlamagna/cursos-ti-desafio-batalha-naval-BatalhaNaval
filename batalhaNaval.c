#include <stdio.h>

int main() {

    // Constantes do jogo
    int TAM = 10;
    int NAVIO = 3;
    int AGUA = 0;
    int NAVIO_PARTE = 3;

    // Tabuleiro 10x10
    int tabuleiro[10][10];

    int i, j, k;

    // ----------------------------------------
    // 1. Inicializar o tabuleiro com água
    // ----------------------------------------
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    // ========================================
    // NAVIO 1 - HORIZONTAL
    // ========================================
    int linhaH = 1;
    int colunaH = 2;

    if(colunaH + NAVIO <= TAM){

        int sobreposicao = 0;

        for(k = 0; k < NAVIO; k++){
            if(tabuleiro[linhaH][colunaH + k] != AGUA){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(k = 0; k < NAVIO; k++){
                tabuleiro[linhaH][colunaH + k] = NAVIO_PARTE;
            }
        }
    }

    // ========================================
    // NAVIO 2 - VERTICAL
    // ========================================
    int linhaV = 4;
    int colunaV = 7;

    if(linhaV + NAVIO <= TAM){

        int sobreposicao = 0;

        for(k = 0; k < NAVIO; k++){
            if(tabuleiro[linhaV + k][colunaV] != AGUA){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(k = 0; k < NAVIO; k++){
                tabuleiro[linhaV + k][colunaV] = NAVIO_PARTE;
            }
        }
    }

    // ========================================
    // NAVIO 3 - DIAGONAL PRINCIPAL (↘)
    // linha e coluna aumentam juntas
    // ========================================
    int linhaD1 = 0;
    int colunaD1 = 0;

    if(linhaD1 + NAVIO <= TAM && colunaD1 + NAVIO <= TAM){

        int sobreposicao = 0;

        for(k = 0; k < NAVIO; k++){
            if(tabuleiro[linhaD1 + k][colunaD1 + k] != AGUA){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(k = 0; k < NAVIO; k++){
                tabuleiro[linhaD1 + k][colunaD1 + k] = NAVIO_PARTE;
            }
        }
    }

    // ========================================
    // NAVIO 4 - DIAGONAL SECUNDÁRIA (↙)
    // linha aumenta e coluna diminui
    // ========================================
    int linhaD2 = 2;
    int colunaD2 = 9;

    if(linhaD2 + NAVIO <= TAM && colunaD2 - NAVIO + 1 >= 0){

        int sobreposicao = 0;

        for(k = 0; k < NAVIO; k++){
            if(tabuleiro[linhaD2 + k][colunaD2 - k] != AGUA){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(k = 0; k < NAVIO; k++){
                tabuleiro[linhaD2 + k][colunaD2 - k] = NAVIO_PARTE;
            }
        }
    }

    // ----------------------------------------
    // 2. Mostrar o tabuleiro no console
    // ----------------------------------------
    printf("TABULEIRO BATALHA NAVAL (10x10)\n\n");

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}