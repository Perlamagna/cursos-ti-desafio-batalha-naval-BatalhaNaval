#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

int main() {

    int tabuleiro[TAM_TAB][TAM_TAB];

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int i, j;

    // =================================================
    // 1. Inicializar tabuleiro com água
    // =================================================
    for(i = 0; i < TAM_TAB; i++){
        for(j = 0; j < TAM_TAB; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // =================================================
    // 2. Criar matriz da habilidade CONE
    // Cone apontando para baixo
    // =================================================
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int meio = TAM_HAB / 2;

            if(j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // =================================================
    // 3. Criar matriz da habilidade CRUZ
    // =================================================
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int meio = TAM_HAB / 2;

            if(i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // =================================================
    // 4. Criar matriz da habilidade OCTAEDRO (losango)
    // =================================================
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int meio = TAM_HAB / 2;

            if(abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =================================================
    // 5. Definir pontos de origem das habilidades
    // =================================================
    int origemConeL = 2;
    int origemConeC = 2;

    int origemCruzL = 6;
    int origemCruzC = 4;

    int origemOctL = 5;
    int origemOctC = 8;

    int offset = TAM_HAB / 2;

    // =================================================
    // 6. Sobrepor CONE no tabuleiro
    // =================================================
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int linha = origemConeL + i - offset;
            int coluna = origemConeC + j - offset;

            if(linha >= 0 && linha < TAM_TAB &&
               coluna >= 0 && coluna < TAM_TAB){

                if(cone[i][j] == 1)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // =================================================
    // 7. Sobrepor CRUZ
    // =================================================
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int linha = origemCruzL + i - offset;
            int coluna = origemCruzC + j - offset;

            if(linha >= 0 && linha < TAM_TAB &&
               coluna >= 0 && coluna < TAM_TAB){

                if(cruz[i][j] == 1)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // =================================================
    // 8. Sobrepor OCTAEDRO
    // =================================================
    for(i = 0; i < TAM_HAB; i++){
        for(j = 0; j < TAM_HAB; j++){

            int linha = origemOctL + i - offset;
            int coluna = origemOctC + j - offset;

            if(linha >= 0 && linha < TAM_TAB &&
               coluna >= 0 && coluna < TAM_TAB){

                if(octaedro[i][j] == 1)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // =================================================
    // 9. Exibir tabuleiro final
    // =================================================
    printf("TABULEIRO COM HABILIDADES\n\n");

    for(i = 0; i < TAM_TAB; i++){
        for(j = 0; j < TAM_TAB; j++){

            if(tabuleiro[i][j] == 0)
                printf("~ ");     // água
            else if(tabuleiro[i][j] == 3)
                printf("N ");     // navio
            else if(tabuleiro[i][j] == 5)
                printf("* ");     // habilidade
        }
        printf("\n");
    }

    return 0;
}