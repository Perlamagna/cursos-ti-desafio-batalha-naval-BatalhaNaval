#include <stdio.h>

int main() {

    // Tamanho fixo do tabuleiro
    int tamanho = 10;

    // Matriz 10x10 representando o tabuleiro
    int tabuleiro[10][10];

    // Vetores representando os navios (tamanho fixo = 3)
    int navioHorizontal[3] = {3,3,3};
    int navioVertical[3] = {3,3,3};

    // Coordenadas iniciais dos navios
    int linhaH = 2;   // linha inicial do navio horizontal
    int colunaH = 4;  // coluna inicial do navio horizontal

    int linhaV = 5;   // linha inicial do navio vertical
    int colunaV = 1;  // coluna inicial do navio vertical

    int i, j;

    // --------------------------------------------------
    // 1. Inicializar todo o tabuleiro com água (0)
    // --------------------------------------------------
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // --------------------------------------------------
    // 2. Validar se o navio horizontal cabe no tabuleiro
    // --------------------------------------------------
    if(colunaH + 3 <= tamanho){

        // Verificar se não há sobreposição
        int sobreposicao = 0;

        for(i = 0; i < 3; i++){
            if(tabuleiro[linhaH][colunaH + i] != 0){
                sobreposicao = 1;
            }
        }

        // Posicionar navio se não houver sobreposição
        if(!sobreposicao){
            for(i = 0; i < 3; i++){
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    // --------------------------------------------------
    // 3. Validar se o navio vertical cabe no tabuleiro
    // --------------------------------------------------
    if(linhaV + 3 <= tamanho){

        int sobreposicao = 0;

        for(i = 0; i < 3; i++){
            if(tabuleiro[linhaV + i][colunaV] != 0){
                sobreposicao = 1;
            }
        }

        if(!sobreposicao){
            for(i = 0; i < 3; i++){
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // --------------------------------------------------
    // 4. Exibir o tabuleiro
    // --------------------------------------------------
    printf("Tabuleiro Batalha Naval (10x10)\n\n");

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}