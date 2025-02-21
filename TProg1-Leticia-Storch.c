#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRA 100
//#define MAX_TAMANHO 100

int MenuIncial();
void BuscarPalavra(char NomeArquivo[],int faixa, char Spalavra[MAX_PALAVRA]);
int sorteiaPalavra();
int qntPalavras(char NomeArquivo[]);

int main()
{
    int opcao;
    char Spalavra[MAX_PALAVRA];
    char NomeArq[MAX_PALAVRA];
    int qnt;

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
    strcpy(NomeArq, "Animais.txt");
    printf("%s\n", NomeArq);
   }
   else if(opcao == 2)
   {
    strcpy(NomeArq, "paises.txt");
    printf("%s\n", NomeArq);
   }
   else if(opcao == 3)
   {
    strcpy(NomeArq, "series.txt");
    printf("%s\n", NomeArq);
   }
   else if(opcao == 4)
   {
    strcpy(NomeArq, "profissoes.txt");
    printf("%s\n", NomeArq);
   }
   else if(opcao == 5)
   {
    strcpy(NomeArq, "frutas.txt");
    printf("%s\n", NomeArq);
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

void BuscarPalavra(char NomeArquivo[], int faixa, char Spalavra[MAX_PALAVRA])
{
    FILE * fListas = fopen(NomeArquivo, "r");
    if(fListas == NULL)
    {
        printf("Arquivo nao encontrado\n");
        exit(1);
    }
    
    for(int i = 0; i <= sorteiaPalavra(faixa); i++)
    {
        fscanf(fListas," %[^\n]\n", Spalavra);
    }

    fclose(fListas);

}

int sorteiaPalavra(int faixa)
{
    srand((unsigned) time(NULL)); //srand eh um gerador de numeros aleatorios, unsigned armazena apenas valores positivos maiores ou igual a zero e time(NULL) retorna o tempo atual 
    return rand() % faixa; //retorna rand(), que eh um numero aleatorio, % faixa faz com que o valor esteja dentro do intervalo
}

int qntPalavras(char NomeArquivo[])
{
    char temp[MAX_PALAVRA];
    int qnt=0;
    FILE * fListas = fopen(NomeArquivo, "r");
    if(fListas == NULL)
    {
        printf("Arquivo nao encontrado\n");
        exit(1);
    }
    while (fscanf(fListas," %[^\n]\n", temp) != EOF)
    {
        qnt++;
    }
    fclose(fListas);
    return qnt;
}

