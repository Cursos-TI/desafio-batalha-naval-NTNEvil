#include <stdio.h>
#include <stdbool.h>

void exibirTabuleiro(int tabuleiro[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // percorre a matriz e exibe o valor de cada posição
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void adicionarNavio(int tabuleiro[10][10], int posX, int posY, int orientacao){
    int codigoNavio = 3; // 3 representa o navio no tabuleiro
    int tamanho = 3; // Tamanho do navio
    if (orientacao == 0) // orientacao do navio e horizontal
    { 
        for (int i = 0; i < tamanho; i++){
            tabuleiro[posX][posY + i] = codigoNavio;
        }
    } 
    else // orientacao do navio e vertical
    { 
        for (int i = 0; i < tamanho; i++){
            tabuleiro[posX + i][posY] = codigoNavio;
        }
    }
}

bool verificarPosicaoValida(int tabuleiro[10][10], int posX, int posY, int orientacao){
    int tamanho = 3; // Tamanho do navio
    if (orientacao == 0) // orientacao do navio horizontal
    { 
        for (int i = 0; i < tamanho; i++){
            if (tabuleiro[posX][posY + i] != 0){
                return false;
            }
        }
    } 
    else // orientacao do navio vertical
    { 
        for (int i = 0; i < tamanho; i++){
            if (tabuleiro[posX + i][posY] != 0){
                return false;
            }
        }
    }
    return true;
}

int main() {

    int tabuleiro[10][10] = {0};

    bool posicaoValidaNavio1 = verificarPosicaoValida(tabuleiro, 0, 0, 0); // verficar se a posicao e valida e salva o resultado na variavel
    posicaoValidaNavio1 ? adicionarNavio(tabuleiro, 0, 0, 0) : printf("Posicao invalida\n"); // se a posicao for valida adiciona o navio no tabuleiro
    
    bool posicaoValidaNavio2 = verificarPosicaoValida(tabuleiro, 2, 5, 1); // verficar se a posicao e valida e salva o resultado na variavel
    posicaoValidaNavio2 ? adicionarNavio(tabuleiro, 2, 5, 1) : printf("Posicao invalida\n"); // se a posicao for valida adiciona o navio no tabuleiro

    exibirTabuleiro(tabuleiro); // exibe o tabuleiro

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
