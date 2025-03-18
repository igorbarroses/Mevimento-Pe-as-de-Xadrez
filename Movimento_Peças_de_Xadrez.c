#include <stdio.h>

// Funções
void selecionar_peca(int *peca);
void selecionar_direcao(int peca, int *direcao);
void movimento_torre(int direcao, int casas);
void movimento_bispo(int direcao, int casas);
void movimento_rainha(int direcao, int casas);
void simular_movimento(int peca, int direcao);
void resumo_movimento(int peca, int direcao, int casas);

int main() {
    int peca, direcao, casas = 0;

    selecionar_peca(&peca);
    selecionar_direcao(peca, &direcao);
    simular_movimento(peca, direcao);
    resumo_movimento(peca, direcao, casas);

    return 0;
}

void selecionar_peca(int *peca) {
    do {
        printf("Jogo de Xadrez\n");
        printf("Digite a peca que deseja mover:\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha\n");
        printf("4 - Cavalo\n");

        scanf("%d", peca);
        if (*peca < 1 || *peca > 4) {
            printf("Peca invalida. Digite novamente.\n");
        }
    } while (*peca < 1 || *peca > 4);

    // Explicação do movimento das pecas
    if (*peca == 1) {
        printf("A peca selecionada foi a Torre e ela move-se em linha reta nas direcoes horizontal e vertical.\n");
    } else if (*peca == 2) {
        printf("A peca selecionada foi o Bispo e ela move-se em linha reta nas direcoes diagonais.\n");
    } else if (*peca == 3) {
        printf("A peca selecionada foi a Rainha e ela move-se em linha reta nas direcoes horizontal, vertical e diagonal.\n");
    } else if (*peca == 4) {
        printf("A peca selecionada foi o Cavalo e ela move-se em forma de L (2 casas em uma direcao e 1 casa na perpendicular).\n");
    }
}

void selecionar_direcao(int peca, int *direcao) {
    do {
        printf("Escolha a direcao que deseja mover sua peca, levando em consideracao a sua limitacao de movimento pre-estabelecida:\n");
        printf("1 - Horizontal\n");
        printf("2 - Vertical\n");
        printf("3 - Diagonal\n");
        printf("4 - (Exclusivo para Cavalo) L, cima, direita\n");
        printf("5 - (Exclusivo para Cavalo) L, baixo, direita\n");
        printf("6 - (Exclusivo para Cavalo) L, baixo, esquerda\n");
        printf("7 - (Exclusivo para Cavalo) L, cima, esquerda\n");

        scanf("%d", direcao);

        if (*direcao < 1 || *direcao > 7) {
            printf("Direcao invalida. Digite novamente.\n");
        } else if (peca == 1 && *direcao == 3) {
            printf("A Torre nao pode se mover em diagonal.\n");
            *direcao = 0;
        } else if (peca == 2 && (*direcao == 1 || *direcao == 2)) {
            printf("O Bispo nao pode se mover na horizontal ou vertical.\n");
            *direcao = 0;
        } else if (peca == 4 && (*direcao == 1 || *direcao == 2 || *direcao == 3)) {
            printf("O Cavalo nao pode se mover na horizontal, vertical ou diagonal.\n");
            *direcao = 0;
        }
    } while (*direcao < 1 || *direcao > 7);
}

void movimento_torre(int direcao, int casas) {
    for (int i = 1; i <= casas; i++) {
        switch (direcao) {
            case 1: // Movimento para cima
                printf("Cima\n");
                break;
            case 2: // Movimento para a direita
                printf("Direita\n");
                break;
            case 3: // Movimento para baixo
                printf("Baixo\n");
                break;
            case 4: // Movimento para a esquerda
                printf("Esquerda\n");
                break;
            default:
                printf("Direcao invalida para a torre.\n");
                return;
        }
    }
}

void movimento_bispo(int direcao, int casas) {
    for (int i = 1; i <= casas; i++) {
        switch (direcao) {
            case 1: // Diagonal superior esquerda
                printf("Diagonal Superior Esquerda\n");
                break;
            case 2: // Diagonal superior direita
                printf("Diagonal Superior Direita\n");
                break;
            case 3: // Diagonal inferior esquerda
                printf("Diagonal Inferior Esquerda\n");
                break;
            case 4: // Diagonal inferior direita
                printf("Diagonal Inferior Direita\n");
                break;
            default:
                printf("Direcao invalida para o bispo.\n");
                return;
        }
    }
}

void movimento_rainha(int direcao, int casas) {
    for (int i = 1; i <= casas; i++) {
        switch (direcao) {
            case 1: // Movimento para cima
                printf("Cima\n");
                break;
            case 2: // Movimento para a direita
                printf("Direita\n");
                break;
            case 3: // Movimento para baixo
                printf("Baixo\n");
                break;
            case 4: // Movimento para a esquerda
                printf("Esquerda\n");
                break;
            case 5: // Diagonal superior esquerda
                printf("Diagonal Superior Esquerda\n");
                break;
            case 6: // Diagonal superior direita
                printf("Diagonal Superior Direita\n");
                break;
            case 7: // Diagonal inferior esquerda
                printf("Diagonal Inferior Esquerda\n");
                break;
            case 8: // Diagonal inferior direita
                printf("Diagonal Inferior Direita\n");
                break;
            default:
                printf("Direcao invalida para a rainha.\n");
                return;
        }
    }
}

void simular_movimento(int peca, int direcao) {
    int casas = 0;

    if (peca == 4) {
        // Movimento fixo do cavalo
        if (direcao == 4) {
            printf("Movendo 2 casas para cima e 1 casa para a direita:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Cima\n");
            }
            printf("Direita\n");
        } else if (direcao == 5) {
            printf("Movendo 2 casas para baixo e 1 casa para a direita:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Baixo\n");
            }
            printf("Direita\n");
        } else if (direcao == 6) {
            printf("Movendo 2 casas para baixo e 1 casa para a esquerda:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Baixo\n");
            }
            printf("Esquerda\n");
        } else if (direcao == 7) {
            printf("Movendo 2 casas para cima e 1 casa para a esquerda:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Cima\n");
            }
            printf("Esquerda\n");
        }
    } else {
        // Movimento para outras pecas
        do {
            printf("Digite quantas casas deseja mover (1 a 8):\n");
            scanf("%d", &casas);

            if (casas < 1 || casas > 8) {
                printf("Quantidade de casas invalida. Digite novamente.\n");
            }
        } while (casas < 1 || casas > 8);

        if (peca == 1) {
            movimento_torre(direcao, casas);
        } else if (peca == 2) {
            movimento_bispo(direcao, casas);
        } else if (peca == 3) {
            movimento_rainha(direcao, casas);
        }
    }
}

void resumo_movimento(int peca, int direcao, int casas) {
    printf("\nResumo do movimento:\n");
    printf("Voce escolheu a peca %d e a direcao %d.\n", peca, direcao);
    if (peca != 4) {
        printf("Quantidade de casas movidas: %d\n", casas);
    }
}