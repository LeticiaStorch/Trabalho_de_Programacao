#include <stdio.h>
#include <string.h>

int MenuIncial();
char* BuscarPalavra(char NomeArquivo[]);
int sorteiaPalavra();

int main()
{
    int opcao;
    char palavras[1000];

    do 
    {
        opcao = MenuIncial();

        if (opcao < 1 || opcao > 5) 
        {
            printf("\n\n       Opcao invalida tente novamente =3\n");
        }
    } while (opcao < 1 || opcao > 5);


    if(opcao == 1)
   {
   // strcpy(palavras,);
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
   else if(opcao == 5)
   {
    printf("frutas\n");
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
    printf("\n|       5 - Frutas                                   |");
    printf("\n|                                                    |");
    printf("\n ----------------------------------------------------\n\n");
    printf("Qual opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

char* BuscarPalavra(char NomeArquivo[])
{

}
