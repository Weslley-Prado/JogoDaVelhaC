#include <stdio.h>

char matriz[3][3]; // Matriz para representar o tabuleiro

// Função para inicializar o tabuleiro
void inicializar_tabuleiro() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = ' ';
        }
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", matriz[i][0], matriz[i][1], matriz[i][2]);
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// Função para verificar se alguém venceu o jogo
int verificar_vencedor() {
    int i;
    
    // Verificar linhas
    for (i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ') {
            return 1; // Jogador 1 venceu
        }
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ') {
            return 2; // Jogador 2 venceu
        }
    }
    
    // Verificar colunas
    for (i = 0; i < 3; i++) {
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != ' ') {
            return 1; // Jogador 1 venceu
        }
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != ' ') {
            return 2; // Jogador 2 venceu
        }
    }
    
    // Verificar diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' ') {
        return 1; // Jogador 1 venceu
    }
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != ' ') {
        return 2; // Jogador 2 venceu
    }
    
    // Verificar empate
    int vazio = 0;
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == ' ') {
                vazio = 1;
                break;
            }
        }
    }
    if (!vazio) {
        return 3; // Jogo empatado
    }
    
    return 0; // Ninguém venceu ainda
}

// Função para realizar uma jogada
void fazer_jogada(int jogador) {
    int linha, coluna;
    printf("Jogador %d, faça sua jogada (linha coluna): ", jogador);
    scanf("%d %d", &linha, &coluna);
    
    // Verificar se a posição está livre
    if (matriz[linha][coluna] != ' ') {
        printf("Posição ocupada. Tente novamente.\n");
        fazer_jogada(jogador);
        return;
    }
    
    // Fazer a jogada
    if (jogador == 1) {
        matriz[linha][coluna] = 'X';
    } else {
        matriz[linha][coluna] = 'O';
    }
}

int main() {
    int jogador_atual = 1;
    int vencedor = 0;
    
    inicializar_tabuleiro();
    
    printf("Jogo da Velha\n");
    printf("-------------\n");
    
    while (vencedor == 0) {
        exibir_tabuleiro();
        fazer_jogada(jogador_atual);
        vencedor = verificar_vencedor();
        
        if (vencedor == 1) {
            printf("Jogador 1 venceu!\n");
        } else if (vencedor == 2) {
            printf("Jogador 2 venceu!\n");
        } else if (vencedor == 3) {
            printf("Jogo empatado!\n");
        }
        
        jogador_atual = (jogador_atual == 1) ? 2 : 1;
    }
    
    exibir_tabuleiro();
    
    return 0;
}
