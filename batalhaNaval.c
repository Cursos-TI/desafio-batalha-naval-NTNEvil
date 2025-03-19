#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define CODIGO_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // percorre a matriz e exibe o valor de cada posição
            printf("%d ", tabuleiro[j][i]);
        }
        printf("\n");
    }
}

void adicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posX, int posY, int orientacao){
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        if (orientacao == 0) // navio horizontal
        { 
            tabuleiro[posX + i][posY] = CODIGO_NAVIO;
        } 
        else // navio vertical
        { 
            tabuleiro[posX][posY + i] = CODIGO_NAVIO;
        }
    }
}

bool posicaoExiste(int posX, int posY){
    return posX >= 0 && posX < TAMANHO_TABULEIRO && posY >= 0 && posY < TAMANHO_TABULEIRO; // verifica se a posição existe no tabuleiro
}

bool verificarPosicaoValidaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posX, int posY, int orientacao){
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        if (orientacao == 0) // navio horizontal
        { 
            if (!posicaoExiste(posX + i, posY) || tabuleiro[posX + i][posY] != 0) // verifica se a posição existe e se a posição está vazia
            {
                return false;
            }
        } 
        else // navio vertical
        { 
            if (!posicaoExiste(posX, posY + i) || tabuleiro[posX][posY + i] != 0) // verifica se a posição existe e se a posição está vazia
            {
                return false;
            }
        }
    }
    return true;
}

void adicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posX, int posY, int orientacao){
    // orientacao 0 == para baixo e para a direita
    // orientacao 1 == para cima e para a esquerda
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        if (orientacao == 0) // orientacao do navio e para baixo e para a direita
        { 
            tabuleiro[posX + i][posY + i] = CODIGO_NAVIO;
        } 
        else // orientacao do navio e para cima e para a esquerda
        { 
            tabuleiro[posX - i][posY - i] = CODIGO_NAVIO;
        }
    }
}

bool verificarPosicaoValidaNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posX, int posY, int orientacao){
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        if (orientacao == 0) // orientacao do navio e para baixo e para a direita
        { 
            if (!posicaoExiste(posX + i, posY + i) || tabuleiro[posX + i][posY + i] != 0) // verifica se a posição existe e se a posição está vazia
            {
                return false;
            }
        } 
        else // orientacao do navio e para cima e para a esquerda 
        { 
            if (!posicaoExiste(posX - i, posY - i) || tabuleiro[posX - i][posY - i] != 0) // verifica se a posição existe e se a posição está vazia
            {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // inicializa o tabuleiro com 0

    // navio horizontal
    bool posicaoValidaNavio1 = verificarPosicaoValidaNavio(tabuleiro, 0, 0, 0); // verficar se a posicao e valida e salva o resultado na variavel
    posicaoValidaNavio1 ? adicionarNavio(tabuleiro, 0, 0, 0) : printf("Posicao invalida\n"); // se a posicao for valida adiciona o navio no tabuleiro
    
    // navio vertical
    bool posicaoValidaNavio2 = verificarPosicaoValidaNavio(tabuleiro, 3, 3, 1); // verficar se a posicao e valida e salva o resultado na variavel
    posicaoValidaNavio2 ? adicionarNavio(tabuleiro, 3, 3, 1) : printf("Posicao invalida\n"); // se a posicao for valida adiciona o navio no tabuleiro

    // navio diagonal 1
    bool posicaoValidaNavio3 = verificarPosicaoValidaNavioDiagonal(tabuleiro, 7, 7, 0); // verficar se a posicao e valida e salva o resultado na variavel
    posicaoValidaNavio3 ? adicionarNavioDiagonal(tabuleiro, 7, 7, 0) : printf("Posicao invalida\n"); // se a posicao for valida adiciona o navio no tabuleiro

    // navio diagonal 2
    bool posicaoValidaNavio4 = verificarPosicaoValidaNavioDiagonal(tabuleiro, 3, 8, 1); // verficar se a posicao e valida e salva o resultado na variavel
    posicaoValidaNavio4 ? adicionarNavioDiagonal(tabuleiro, 3, 8, 1) : printf("Posicao invalida\n"); // se a posicao for valida adiciona o navio no tabuleiro

    exibirTabuleiro(tabuleiro); // exibe o tabuleiro

    return 0;
}
