#include <stdio.h>

int MenuIncial();

int main()
{
    int opcao;
   opcao = MenuIncial();
   if(opcao == 1)
   {
    printf("Animais\n");
   }
   else if(opcao == 2)
   {
    printf("pais\n");
   }
   else if(opcao == 3)
   {
    printf("series\n");
   }
   else if(opcao == 4)
   {
    printf("profison\n");
   }
   else
   {
    printf("\n Opcao invalida tente novamente =3 ");
   }
    return 0;
}

int MenuIncial()
{
    int opcao;
    printf("\n ---------------------   Menu   --------------------- ");
    printf("\n|                                                    |");
    printf("\n|       Escolha uma opcao para jogar:                |");
    printf("\n|                                                    |");
    printf("\n|       1 - Animais                                  |");
    printf("\n|       2 - Países                                   |");
    printf("\n|       3 - Series                                   |");
    printf("\n|       4 - Profissoes                               |");
    printf("\n|                                                    |");
    printf("\n ----------------------------------------------------\n\n");
    printf("Qual opcao: ");
    scanf("%d", &opcao);

    return opcao;
}