#include <stdio.h>

// Funções
void selecionar_peça(int *peça);
void selecionar_direção(int peça, int *direção);
void movimento_torre(int direção, int casas, int passo);
void movimento_bispo(int direção, int casas, int passo);
void movimento_rainha(int direção, int casas, int passo);
void simular_movimento(int peça, int direção);
void resumo_movimento(int peça, int direção, int casas);

int main() {
    int peça, direção, casas = 0;

    selecionar_peça(&peça);
    selecionar_direção(peça, &direção);
    simular_movimento(peça, direção);
    resumo_movimento(peça, direção, casas);

    return 0;
}

    // Menu de escolha das peças

void selecionar_peça(int *peça) {
    do {
        printf("Jogo de Xadrez\n");
        printf("Digite a peça que deseja mover:\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha\n");
        printf("4 - Cavalo\n");

        scanf("%d", peça);
        if (*peça < 1 || *peça > 4) {
            printf("Peça inválida. Digite novamente.\n");
        }
    } while (*peça < 1 || *peça > 4);

    // Explicação do movimento das peças
    if (*peça == 1) {
        printf("A peça selecionada foi a Torre e ela move-se em linha reta nas direções horizontal e vertical.\n");
    } else if (*peça == 2) {
        printf("A peça selecionada foi o Bispo e ela move-se em linha reta nas direções diagonais.\n");
    } else if (*peça == 3) {
        printf("A peça selecionada foi a Rainha e ela move-se em linha reta nas direções horizontal, vertical e diagonal.\n");
    } else if (*peça == 4) {
        printf("A peça selecionada foi o Cavalo e ela move-se em forma de L (2 casas em uma direção e 1 casa na perpendicular).\n");
    }
}
    // Menu de escolha de direção
void selecionar_direção(int peça, int *direção) {
    do {
        printf("Escolha a direção que deseja mover sua peça, levando em consideração a sua limitação de movimento pré-estabelecida:\n");
        printf("1 - Horizontal\n");
        printf("2 - Vertical\n");
        printf("3 - Diagonal\n");
        printf("4 - (Exclusivo para Cavalo) L, cima, direita\n");
        printf("5 - (Exclusivo para Cavalo) L, baixo, direita\n");
        printf("6 - (Exclusivo para Cavalo) L, baixo, esquerda\n");
        printf("7 - (Exclusivo para Cavalo) L, cima, esquerda\n");

        scanf("%d", direção);

        if (*direção < 1 || *direção > 7) {
            printf("Direção inválida. Digite novamente.\n");
        } else if (peça == 1 && *direção == 3) {
            printf("A Torre não pode se mover em diagonal.\n");
            *direção = 0;
        } else if (peça == 2 && (*direção == 1 || *direção == 2)) {
            printf("O Bispo não pode se mover na horizontal ou vertical.\n");
            *direção = 0;
        } else if (peça == 4 && (*direção == 1 || *direção == 2 || *direção == 3)) {
            printf("O Cavalo não pode se mover na horizontal, vertical ou diagonal.\n");
            *direção = 0;
        }
    } while (*direção < 1 || *direção > 7);
}

void movimento_torre(int direção, int casas, int passo) {
    if (passo > casas) {
        return; // Condição de parada da recursão
    }

    switch (direção) {
        case 1: // Movimento para cima
            printf("Cima - Casa %d\n", passo);
            break;
        case 2: // Movimento para a direita
            printf("Direita - Casa %d\n", passo);
            break;
        case 3: // Movimento para baixo
            printf("Baixo - Casa %d\n", passo);
            break;
        case 4: // Movimento para a esquerda
            printf("Esquerda - Casa %d\n", passo);
            break;
        default:
            printf("Direção inválida para a torre.\n");
            return;
    }

    // Chamada recursiva para simular o movimento das casas restantes
    movimento_torre(direção, casas, passo + 1);
}

void movimento_bispo(int direção, int casas, int passo) {
    if (passo > casas) {
        return; 
    }

    switch (direção) {
        case 1: // Diagonal superior esquerda
            printf("Diagonal Superior Esquerda - Casa %d\n", passo);
            break;
        case 2: // Diagonal superior direita
            printf("Diagonal Superior Direita - Casa %d\n", passo);
            break;
        case 3: // Diagonal inferior esquerda
            printf("Diagonal Inferior Esquerda - Casa %d\n", passo);
            break;
        case 4: // Diagonal inferior direita
            printf("Diagonal Inferior Direita - Casa %d\n", passo);
            break;
        default:
            printf("Direção inválida para o bispo.\n");
            return;
    }

    // Chamada recursiva para simular o movimento das casas restantes
    movimento_bispo(direção, casas, passo + 1);
}

void movimento_rainha(int direção, int casas, int passo) {
    if (passo > casas) {
        return; 
    }

    switch (direção) {
        case 1: // Movimento para cima
            printf("Cima - Casa %d\n", passo);
            break;
        case 2: // Movimento para a direita
            printf("Direita - Casa %d\n", passo);
            break;
        case 3: // Movimento para baixo
            printf("Baixo - Casa %d\n", passo);
            break;
        case 4: // Movimento para a esquerda
            printf("Esquerda - Casa %d\n", passo);
            break;
        case 5: // Diagonal superior esquerda
            printf("Diagonal Superior Esquerda - Casa %d\n", passo);
            break;
        case 6: // Diagonal superior direita
            printf("Diagonal Superior Direita - Casa %d\n", passo);
            break;
        case 7: // Diagonal inferior esquerda
            printf("Diagonal Inferior Esquerda - Casa %d\n", passo);
            break;
        case 8: // Diagonal inferior direita
            printf("Diagonal Inferior Direita - Casa %d\n", passo);
            break;
        default:
            printf("Direção inválida para a rainha.\n");
            return;
    }

    // Chamada recursiva para simular o movimento das casas restantes
    movimento_rainha(direção, casas, passo + 1);
}

void simular_movimento(int peça, int direção) {
    int casas = 0;

    if (peça == 4) {
        // Movimento fixo do cavalo
        if (direção == 4) {
            printf("Movendo 2 casas para cima e 1 casa para a direita:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Cima - Casa %d\n", i);
            }
            printf("Direita - Casa 1\n");
        } else if (direção == 5) {
            printf("Movendo 2 casas para baixo e 1 casa para a direita:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Baixo - Casa %d\n", i);
            }
            printf("Direita - Casa 1\n");
        } else if (direção == 6) {
            printf("Movendo 2 casas para baixo e 1 casa para a esquerda:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Baixo - Casa %d\n", i);
            }
            printf("Esquerda - Casa 1\n");
        } else if (direção == 7) {
            printf("Movendo 2 casas para cima e 1 casa para a esquerda:\n");
            for (int i = 1; i <= 2; i++) {
                printf("Cima - Casa %d\n", i);
            }
            printf("Esquerda - Casa 1\n");
        }
    } else {
        // Movimento para outras peças
        do {
            printf("Digite quantas casas deseja mover (1 a 8):\n");
            scanf("%d", &casas);

            if (casas < 1 || casas > 8) {
                printf("Quantidade de casas inválida. Digite novamente.\n");
            }
        } while (casas < 1 || casas > 8);

        if (peça == 1) {
            movimento_torre(direção, casas, 1); 
        } else if (peça == 2) {
            movimento_bispo(direção, casas, 1); 
        } else if (peça == 3) {
            movimento_rainha(direção, casas, 1); 
        }
    }
}

void resumo_movimento(int peça, int direção, int casas) {
    printf("\nResumo do movimento:\n");
    printf("Você escolheu a peça %d e a direção %d.\n", peça, direção);
    if (peça != 4) {
        printf("Quantidade de casas movidas: %d\n", casas);
    }
}