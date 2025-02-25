#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRA 100
//#define MAX_TAMANHO 100

int MenuIncial(char NomeArq[]);
void BuscarPalavra(char NomeArquivo[],int faixa, char Spalavra[MAX_PALAVRA]);
int sorteiaPalavra(int faixa);
int qntPalavras(char NomeArquivo[]);
int ExecutaJogo();
void VerificaChances(int contador);
void MensagemVitoria();
void DesenhaForca(int contador);

int main()
{
    int opcao;
    char Spalavra[MAX_PALAVRA];
    char NomeArq[MAX_PALAVRA];
    int qnt, jogo;

    opcao = MenuIncial(NomeArq);

    qnt = qntPalavras(NomeArq);    // palavra sorteada
   BuscarPalavra(NomeArq, qnt, Spalavra);

  // printf("PALAVRA SORTEADA: %s\n", Spalavra); 
   jogo = ExecutaJogo(Spalavra);
   
    return 0;
}

int MenuIncial(char NomeArq[])
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

    do 
    {
    
    if (opcao < 1 || opcao > 5) 
    {
        printf("\n\n       Opcao invalida tente novamente =3\n");
    }
    } while (opcao < 1 || opcao > 5);

    
    if(opcao == 1)
   {
    strcpy(NomeArq, "Animais.txt");
    printf("\nA opcao escolida foi animais\n");
   }
   else if(opcao == 2)
   {
    strcpy(NomeArq, "paises.txt");
    printf("\nA opcao escolida foi paises\n");
   }
   else if(opcao == 3)
   {
    strcpy(NomeArq, "series.txt");
    printf("\nA opcao escolida foi series\n");
   }
   else if(opcao == 4)
   {
    strcpy(NomeArq, "profissoes.txt");
    printf("\nA opcao escolida foi profissoes\n");
   }
   else if(opcao == 5)
   {
    strcpy(NomeArq, "frutas.txt");
    printf("\nA opcao escolida foi frutas\n");
   }
   
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
        fscanf(fListas,"%[^\n]\n", Spalavra);
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
    while (fscanf(fListas,"%[^\n]\n", temp) != EOF)
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
        printf("\nVoce pode errar apenas 5 vezes\n");
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
        printf("\nNem tudo esta perdido, mas ta quase!\n");
        break;
        case 6:
        printf("\nUltima(s) chance(s)...\n");
        break;
    }
}

void MensagemVitoria()

{
    printf("\n************************************************\n");
    printf("**           IEEEEEEEEEEEEEEEE                **\n");
    printf("**                                            **\n");
    printf("**               PARABENS!                    **\n");
    printf("**                                            **\n");
    printf("**                 VOCE                       **\n");
    printf("**                                            **\n");
    printf("**             VENCEU O JOGO                  **\n");
    printf("************************************************\n");

}

void DesenhaForca(int contador)
{
        switch(contador)
        {           
        case 1:
        printf(" ________\n");
        printf("|        |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        break;
        case 2:
        printf(" ________\n");
        printf("|        |\n");
        printf("|       X X\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        break;
        case 3:
        printf(" ________\n");
        printf("|        |\n");
        printf("|       X X\n");
        printf("|        |\n");
        printf("|\n");
        printf("|\n");
        break;
        case 4:
        printf(" ________\n");
        printf("|        |\n");
        printf("|       X X\n");
        printf("|       /| \n");
        printf("|\n");
        printf("|\n");
        break;
        case 5:
        printf(" ________\n");
        printf("|        |\n");
        printf("|       X X\n");
        printf("|       /|\\ \n");
        printf("|\n");
        printf("|\n");
        break;
        case 6:
        printf(" ________\n");
        printf("|        |\n");
        printf("|       X X\n");
        printf("|       /|\\ \n");
        printf("|       /\n");
        printf("|\n");
        break;
        case 7:
        printf(" ________\n");
        printf("|        |\n");
        printf("|       X X\n");
        printf("|       /|\\ \n");
        printf("|       / \\\n");
        printf("|\n");
        break;
        }

}

int ExecutaJogo(char Spalavra[])
{
    int i;
    int  erros=0, acertos = 0, rept = 0;
    int l = strlen(Spalavra);
    char Pdigitada[l+1];
    char letra;
    char Ldigitadas[26];
    int qntDig = 0;

    DesenhaForca(1);
    for(i = 0; i < l+1; i++)
    {
        if(Spalavra[i] == ' ')
        {
            Pdigitada[i] = ' ';
        } else if(Spalavra[i] == '\n')
        {
            Pdigitada[i] = '\n';
        }
        else
        Pdigitada[i] = '_';

    }
    Pdigitada[l-1] = '\0';
    
    printf("\nPALAVRA: %s", Pdigitada);
    printf("\n");
    VerificaChances(1);
    
    while(erros < 6)
    {
        int enct = 0;

       /* printf("\nLetras digitadas: ");
        for(i=0; i < qntDig; i++)
        {
            printf("%c ", Ldigitadas[i]);
        }*/

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

      /* for(i = 0; i < qntDig; i++) // MEXER NESSA PARTE
        {
            if(Ldigitadas[i] == letra)
            {
                rept = 1;
                break;
            }
           
        }
        if(rept) continue;

        Ldigitadas[qntDig++] = letra;*/

    for(i = 0; i < l+1; i++)
    {
        if(Spalavra[i] == letra && Pdigitada[i] == '_')
        {
            Pdigitada[i] = letra;
            acertos++;
            enct = 1;
        }
        
    }
    if(!enct)
    {
        erros++;
    }

    DesenhaForca(erros+1);
    printf("\nPALAVRA: %s\n", Pdigitada);
    VerificaChances(erros+1);

    if(acertos == l-1)
    {
        MensagemVitoria();
        return 1;
    }
}
    printf("\nVocê perdeu! A palavra era: %s\n", Spalavra);
   
    return 0;

}