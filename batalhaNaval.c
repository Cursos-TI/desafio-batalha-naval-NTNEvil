#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define CODIGO_NAVIO 3
#define CODIGO_HABILIDADE 5

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        for(int j = 0; j < TAMANHO_TABULEIRO; j++){
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

void ativarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[5][3], int posX, int posY){
    // posX e posY sao as posicoes referentes ao centro da habilidade
    int posXFinal = posX - 2; // posicao inicial com base no centro da habilidade eixo x
    int posYFinal = posY - 1; // posicao inicial com base no centro da habilidade eixo y

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (habilidade[j][i] == 1 && posicaoExiste(posXFinal + j, posYFinal + i)) // verifica se a posicao existe e se a habilidade e 1
            {
                tabuleiro[posXFinal + j][posYFinal + i] = CODIGO_HABILIDADE;
            }
        }
    }
}

int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // inicializa o tabuleiro com 0

    // habilidades
    int habCone[5][3] = {
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    };

    int habOctaedro[5][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0},
        {0, 0, 0}
    };

    int habCruz[5][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0},
        {0, 1, 0}
    };

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

    exibirTabuleiro(tabuleiro); // exibe o tabuleiro com navios

    printf("\n\n");

    ativarHabilidade(tabuleiro, habOctaedro, 5, 5); // ativa a habilidade octaedro no tabuleiro

    ativarHabilidade(tabuleiro, habCone, 2, 2); // ativa a habilidade cone no tabuleiro

    ativarHabilidade(tabuleiro, habCruz, 8, 8); // ativa a habilidade cruz no tabuleiro

    exibirTabuleiro(tabuleiro); // exibe o tabuleiro depois das habilidades serem usadas

    return 0;
}
