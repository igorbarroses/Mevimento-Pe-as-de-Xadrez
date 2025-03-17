#include <stdio.h>

int main() {
    // Início do jogo de xadrez
    int peça, direção, casas = 0; // Declara 'casas' aqui e inicializa com 0

    // Menu de seleção de peça
    do {
        printf("Jogo de Xadrez\n");
        printf("Digite a peça que deseja mover:\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha\n");
        printf("4 - Cavalo\n");

        scanf("%d", &peça);
        if (peça < 1 || peça > 4) {
            printf("Peça inválida. Digite novamente.\n");
        }
    } while (peça < 1 || peça > 4);

    // Explicação do movimento das peças
    if (peça == 1) {
        printf("A peça selecionada foi a Torre e ela move-se em linha reta nas direções horizontal e vertical.\n");
    } else if (peça == 2) {
        printf("A peça selecionada foi o Bispo e ela move-se em linha reta nas direções diagonais.\n");
    } else if (peça == 3) {
        printf("A peça selecionada foi a Rainha e ela move-se em linha reta nas direções horizontal, vertical e diagonal.\n");
    } else if (peça == 4) {
        printf("A peça selecionada foi o Cavalo e ela move-se em forma de L (2 casas em uma direção e 1 casa na perpendicular).\n");
    }

    // Menu de escolha de direção
    do {
        printf("Escolha a direção que deseja mover sua peça, levando em consideração a sua limitação de movimento pré-estabelecida:\n");
        printf("1 - Horizontal\n");
        printf("2 - Vertical\n");
        printf("3 - Diagonal\n");
        printf("4 - (Exclusivo para Cavalo) L, cima, direita\n");
        printf("5 - (Exclusivo para Cavalo) L, baixo, direita\n");
        printf("6 - (Exclusivo para Cavalo) L, baixo, esquerda\n");
        printf("7 - (Exclusivo para Cavalo) L, cima, esquerda\n");

        scanf("%d", &direção);

        if (direção < 1 || direção > 7) {
            printf("Direção inválida. Digite novamente.\n");
        } else if (peça == 1 && direção == 3) {
            printf("A Torre não pode se mover em diagonal.\n");
            direção = 0;
        } else if (peça == 2 && (direção == 1 || direção == 2)) {
            printf("O Bispo não pode se mover na horizontal ou vertical.\n");
            direção = 0;
        } else if (peça == 4 && (direção == 1 || direção == 2 || direção == 3)) {
            printf("O Cavalo não pode se mover na horizontal, vertical ou diagonal.\n");
            direção = 0;
        }
    } while (direção < 1 || direção > 7);

    // Simulação de movimento
    printf("Simulação de movimento:\n");

    if (peça == 4) {
        // Movimento fixo do cavalo (2 casas em uma direção e 1 casa na perpendicular)
        if (direção == 4) {
            printf("Movendo 2 casas para cima e 1 casa para a direita:\n");
            for (int i = 0; i < 2; i++) {
                printf("Cima\n");
            }
            printf("Direita\n");
        } else if (direção == 5) {
            printf("Movendo 2 casas para baixo e 1 casa para a direita:\n");
            for (int i = 0; i < 2; i++) {
                printf("Baixo\n");
            }
            printf("Direita\n");
        } else if (direção == 6) {
            printf("Movendo 2 casas para baixo e 1 casa para a esquerda:\n");
            for (int i = 0; i < 2; i++) {
                printf("Baixo\n");
            }
            printf("Esquerda\n");
        } else if (direção == 7) {
            printf("Movendo 2 casas para cima e 1 casa para a esquerda:\n");
            for (int i = 0; i < 2; i++) {
                printf("Cima\n");
            }
            printf("Esquerda\n");
        }
    } else {
        // Movimento para outras peças (Torre, Bispo, Rainha)
        do {
            printf("Digite quantas casas deseja mover (1 a 5):\n");
            scanf("%d", &casas);

            if (casas < 1 || casas > 5) {
                printf("Quantidade de casas inválida. Digite novamente.\n");
            }
        } while (casas < 1 || casas > 5);

        for (int i = 1; i <= casas; i++) {
            switch (direção) {
                case 1:
                    printf("Movendo para a direita, casa %d\n", i);
                    break;
                case 2:
                    printf("Movendo para cima, casa %d\n", i);
                    break;
                case 3:
                    printf("Movendo para a diagonal, casa %d\n", i);
                    break;
            }
        }
    }

    // Resumo do movimento
    printf("\nResumo do movimento:\n");
    printf("Você escolheu a peça %d e a direção %d.\n", peça, direção);
    if (peça != 4) {
        printf("Quantidade de casas movidas: %d\n", casas);
    }

    return 0;
}