#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRA 100 // define o tamanho maximo da palavra

// declaracao das funcoes

// funcao para exibir o menu para o jogador escolher uma categoria e retornar a opcao do jogador
int MenuIncial(char NomeArq[]); 

//funcao para buscar uma palavra aleatoria dentro do arquivo
void BuscarPalavra(char NomeArquivo[], int faixa, char Spalavra[MAX_PALAVRA]);

//funcao para sorteiar um numero aleatorio dentro de um intervalo
int sorteiaPalavra(int faixa);

//funcao que conta a quantidade de palavras(linhas) que tem no arquivo
int qntPalavras(char NomeArquivo[]);

//funcao que roda todo o jogo
int ExecutaJogo(char Spalavra[]);

//funcao para informar ao jogador quantas chances ele possui
void VerificaChances(int contador);

//funcao para imprimir a mensagem de vitoria
void MensagemVitoria();

//funcao que desenha a forca conforme os erros do jogador
void DesenhaForca(int contador);

int main()
{
    int opcao;
    char Spalavra[MAX_PALAVRA];
    char NomeArq[MAX_PALAVRA];
    int qnt, jogo;

    // Exibe o menu e recebe a opcao do jogador
    opcao = MenuIncial(NomeArq);

    // conta quantas palavras tem no arquivo selecionado
    qnt = qntPalavras(NomeArq);

    // escolhe uma palavra aleatoria no arquivo
    BuscarPalavra(NomeArq, qnt, Spalavra);

    // inicia o jogo
    jogo = ExecutaJogo(Spalavra);

    return 0;
}

int MenuIncial(char NomeArq[])
{
    int opcao;

    do
    {
        //exibe o menu com as categorias 
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
        printf("Qual opcao: "); //pergunta a opcao do jogador
        scanf("%d", &opcao); //le qual foi a opcao do jogador e armazena em opcao

        //verificacao para ver se a opcao escolida esta entre 1 e 5
        if (opcao < 1 || opcao > 5)
        {
            printf("\n\n       Opcao invalida tente novamente =3\n");
        }
    } while (opcao < 1 || opcao > 5); //continua pedido ate que a opcao seja valida


    //condicao para cada opcao valida que o jogador fizer
    if (opcao == 1)
    {
        strcpy(NomeArq, "Animais.txt"); //copia o nome do arquivo correspondente para a variável NomeArq
        printf("\nA opcao escolida foi animais\n"); //exibe a escolha
    }
    else if (opcao == 2)
    {
        strcpy(NomeArq, "paises.txt"); //copia o nome do arquivo correspondente para a variável NomeArq
        printf("\nA opcao escolida foi paises\n"); //exibe a escolha
    }
    else if (opcao == 3)
    {
        strcpy(NomeArq, "series.txt"); //copia o nome do arquivo correspondente para a variável NomeArq
        printf("\nA opcao escolida foi series\n"); //exibe a escolha
    }
    else if (opcao == 4)
    {
        strcpy(NomeArq, "profissoes.txt"); //copia o nome do arquivo correspondente para a variável NomeArq
        printf("\nA opcao escolida foi profissoes\n"); //exibe a escolha
    }
    else if (opcao == 5)
    {
        strcpy(NomeArq, "frutas.txt"); //copia o nome do arquivo correspondente para a variável NomeArq
        printf("\nA opcao escolida foi frutas\n"); //exibe a escolha
    }

    //retorna a opcao escolida
    return opcao; 
}

void BuscarPalavra(char NomeArquivo[], int faixa, char Spalavra[MAX_PALAVRA])
{
    //abre o arquivo em modo de leitura
    FILE *fListas = fopen(NomeArquivo, "r");

    //condicao para verificar se o arquivo foi aberto de forma correta 
    if (fListas == NULL)
    {
        //printa uma mensagem de erro se o arquivo nao for encontrado
        printf("Arquivo nao encontrado\n");
        exit(1); //encerra o programa
    }

    //loop para percorrer o arquivo ate a linha da palavra sorteada
    for (int i = 0; i <= sorteiaPalavra(faixa); i++)
    {
        //le a linha do arquivo e armazena em Spalavra
        fscanf(fListas, "%[^\n]\n", Spalavra);
    }

    //fecha o arquivo apos a leitura
    fclose(fListas);
}

int sorteiaPalavra(int faixa)
{
    srand((unsigned)time(NULL)); // srand eh um gerador de numeros aleatorios, unsigned armazena apenas valores positivos maiores ou igual a zero e time(NULL) retorna o tempo atual
    return rand() % faixa;       // retorna rand(), que eh um numero aleatorio, % faixa faz com que o valor esteja dentro do intervalo
}

int qntPalavras(char NomeArquivo[])
{
    char temp[MAX_PALAVRA]; //variavel temporaria para armazenar cada linha do arquivo
    int qnt = 0; //contador de linhas

    //abre o arquivo em modo leitura
    FILE *fListas = fopen(NomeArquivo, "r");

    //condicao para verificar se o arquivo foi aberto de forma correta 
    if (fListas == NULL)
    {
        //printa uma mensagem de erro se o arquivo nao for encontrado
        printf("Arquivo nao encontrado\n");
        exit(1); //encerra o programa
    }

    //le cada linha do arquivo e conta quatas existem
    while (fscanf(fListas, "%[^\n]\n", temp) != EOF)
    {
        qnt++; //incrementa ao contador cada linha lida
    }

    //fecha o arquivo apos a leitura
    fclose(fListas);
    //retorna a quantidade total de palavras
    return qnt; 
}

void VerificaChances(int contador)
{

    switch (contador) //verifica o valor do contador e printa a mensagem correspondente
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
    //apenas varios printf's para imprimir a mensagem de vitoria
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
    switch (contador) //odesenho evolui a cada erro cometido pelo jogador, sendo que a cada erro uma parte do boneco sera desenha
    {
    case 1:
        printf("\n ________\n");
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
    //declaracao de variaveis
    int i;
    int erros = 0, acertos = 0;
    int l = strlen(Spalavra); //para saber o tamanho da palavra
    char Pdigitada[l + 1]; //string para armazenar a palavra que esta sendo formada pelo jogador, contando com o '\0'
    char letra; 
    char Ldigitadas[26]; //string que armazena as letras ja digitadas
    int qntDig = 0;

    //desenha a forca inicial
    DesenhaForca(1);
    for (i = 0; i < l + 1; i++) //loop para iniciar a string Pdigitada com underline representando as letras ocultas
    {
        if (Spalavra[i] == ' ')
        {                           //se a palavra secreta tiver espaco eh para ele ser mantido
            Pdigitada[i] = ' ';
        }
        else if (Spalavra[i] == '\n')
        {
            Pdigitada[i] = '\n';    //e se tiver quebra de linha eh para manter a quebra de linha
        }
        else  //caso contrario substituir por espaco
            Pdigitada[i] = '_';
    }
    Pdigitada[l - 1] = '\0'; //para finalizar a string corretamente

    //para printar a palavra que sera formada
    printf("\nPALAVRA: %s", Pdigitada);
    printf("\n");
    VerificaChances(1); //mostra as chances iniciais

    //loop principal do jogo enquanto o jogar tiver menos de 6 erros
    while (erros < 6)
    {
        //inicilizacao das variaveis dentro do loop
        int enct = 0; //verifica se a letra foi encontrada
        int rept = 0; //verifica se a letra for repetida

        //printa as letras ja digitadas
        printf("\nLetras digitadas: ");

        //loop para as letras ja digitadas
        for (i = 0; i < qntDig; i++)
        {
            printf("%c ", Ldigitadas[i]); //imprime as letras ja digitadas que estao armazenadas na string de acordo com a sua posicao
        }

        //printa para o jogador digitar uma letra
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra); //le a letra digitada e armazena em leta

        //loop para verificar se a letra ja foi digitada antes
        for (i = 0; i < qntDig; i++) 
        {
            if (Ldigitadas[i] == letra) 
            {
                rept = 1; //define se a letra ja foi digitada
                break;
            }
        }
        if (rept) //se a letra ja foi digitada, avisa ao jogador e continua o loop
        {
            printf("\nVoce ja digitou essa letra antes!...\n");
            DesenhaForca(erros + 1); //redesenha a forca, sem contabilizar o erro, por exemplo, caso a letra errada tenha sido digitada novamente
            printf("\nPALAVRA: %s\n", Pdigitada);
            VerificaChances(erros + 1); //verifica as chances do jogador, sem contabilizar o erro, por exemplo, caso a letra errada tenha sido digitada novamente
            continue;
        }

        //armazena a nova letra digitada
        Ldigitadas[qntDig++] = letra; 

        //loop para verificar se a letra digitada esta presente na palavra secreta
        for (i = 0; i < l + 1; i++)
        {
            if (Spalavra[i] == letra && Pdigitada[i] == '_')
            {
                Pdigitada[i] = letra; //para substituir o underline pela letra correta
                enct = 1; //define que a letra foi encontrada
            }
        }
        if (!enct) //se a letra nao for encontrada
        {
            erros++; //incrementa ao erros
        }

        //atualiza o desenho da forca
        DesenhaForca(erros + 1);
        //mostra a formacao da palava conforme os acertos
        printf("\nPALAVRA: %s\n", Pdigitada);
        //atualiza as chances restantes
        VerificaChances(erros + 1);

        if (strncmp(Pdigitada, Spalavra, l - 1) == 0) //verifica se o jogador a palavra toda
        {
            MensagemVitoria(); //se sim eh exibida a mensagem de vitoria 
            return 1; //retorna 1 para indicar que o jogador venceu
        }
    }
    //se o loop terminar, significa que o joador perdeu e eh mostrada a palavra secreta
    printf("\nVocê perdeu! A palavra era: %s\n", Spalavra);

    return 0;
}