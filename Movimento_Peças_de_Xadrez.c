#include <stdio.h>

int main (){
    // Inicio do jogo de xadrez
    int peça, direção, casas;

    // Menu de seleção de peça
    do
    {
        printf("Jogo de Xadrez\n");
        printf("Digite a peça que deseja mover:\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha\n");
     
        scanf("%d", &peça);
        if (peça < 1 || peça > 3)
        {
            printf("Peça inválida. Digite novamente.\n");
        }

    } while (peça < 1 || peça > 3);
    
 

   // Explicação do movimento das peças

   if (peça == 1)
   {
    printf("A peça selecionada foi a Torre e ela move-se em linha reta nas direções horizontal e vertical.\n");
   }
   else if (peça == 2)
   {
    printf("A peça selecionada foi o Bispo e ela move-se em linha reta nas direções diagonais.\n");
   } else if (peça == 3)
   {
    printf("A peça selecionada foi a Rainha e ela move-se em linha reta nas direções horizontal, vertical e diagonal.\n");
   }

   
   //  Menu de escolha de direção
   do
   {
    printf("Escolha a direção que Deseja mover sua peça, levando em consideração a sua limitação de movimento pré estabelecida:\n");
    printf("1 - Horizontal\n");
    printf("2 - Vertical\n");
    printf("3 - Diagonal\n");
    int direção;
    scanf("%d", &direção);

    if (direção < 1 || direção > 3)
    {
        printf("Direção inválida. Digite novamente.\n");
    } else if (peça == 1 && direção == 3)
    {
        printf("A Torre não pode se mover em diagonal.\n");
        direção = 0;
    } else if (peça == 2 && (direção == 1 || direção == 2)) {
        printf("O Bispo não pode se mover na horizontal ou vertical.\n");
        direção = 0;
        
    }
    

   } while (direção < 1 || direção > 3);
   

   // Menu de escolha de quantidade de casas
   do
   {
    printf("Digite quantas casas deseja mover:\n");
   int casas;
   scanf("%d", &casas);

   if (casas < 1 || casas > 5)
   {
        printf("Quantidade de casas inválida. Digite novamente.\n");
    }

   } while (casas < 1 || casas > 5);
   

    // Simulação de movimento

   printf("Simulação de movimento:\n");

   for (int i = 1; i <= casas; i++)
   {
        switch (direção)
    {
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

   // Resumo do movimento
   printf("\nResumo do movimento:\n");
   printf("Você escolheu a peça %d, a direção %d e moveu %d casas.\n", peça, direção, casas);
   
   
   




    return 0;







}