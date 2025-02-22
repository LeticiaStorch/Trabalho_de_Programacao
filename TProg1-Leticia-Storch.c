#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRA 100
//#define MAX_TAMANHO 100

int MenuIncial();
void BuscarPalavra(char NomeArquivo[],int faixa, char Spalavra[MAX_PALAVRA]);
int sorteiaPalavra(int faixa);
int qntPalavras(char NomeArquivo[]);
int ExecutaJogo();
void VerificaChances(int contador);
void MensagemVitoria();
void DesenhaForca(int contador, int flag);

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
   }
   else if(opcao == 2)
   {
    strcpy(NomeArq, "paises.txt");
   }
   else if(opcao == 3)
   {
    strcpy(NomeArq, "series.txt");
   }
   else if(opcao == 4)
   {
    strcpy(NomeArq, "profissoes.txt");
   }
   else if(opcao == 5)
   {
    strcpy(NomeArq, "frutas.txt");
   }

   qnt = qntPalavras(NomeArq);    // testando a palavra sorteada
   BuscarPalavra(NomeArq, qnt, Spalavra);

   //printf("PALAVRA SORTEADA: %s\n", Spalavra); 
   
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

void VerificaChances(int contador)
{

    switch(contador)
    {
        case 1:
        printf("\nVoce pode errar mais 5 vezes\n");
        break;
        case 2:
        printf("\nVoce pode errar mais 4 vezes\n");
        break;
        case 3:
        printf("\nvoce pode errar mais 3 vezes\n");
        break;
        case 4:
        printf("\nVoce pode errar mais 2 vezes\n");
        break;
        case 5:
        printf("\nNem tudo esta perdido, mas ta quase! so mais uma chance\n");
        break;
    }
}

void MensagemVitoria()

{
    printf("************************************************\n");
    printf("**           IEEEEEEEEEEEEEEEE                **\n");
    printf("**                                            **\n");
    printf("**               PARABENS!                    **\n");
    printf("**                                            **\n");
    printf("**                 VOCE                       **\n");
    printf("**                                            **\n");
    printf("**            VENCEU O JOGO                   **\n");
    printf("************************************************\n");

}

void DesenhaForca(int contador, int flag)
{
    if(flag == 0)
    {
        /*switch(contador)             DEPOIS PENSO
        case 1:
        printf(" ________");
        printf("|        |");
        printf("|");
        printf("|");
        printf("|");
        printf("|");
        break;
        case 2:
        printf(" ________");
        printf("|        |");
        printf("|       X X");
        printf("|");
        printf("|");
        printf("|");
        */
    }
}