#include "Header.h"
#include <time.h>

void apresentaDados(Dados*lista, int position, clock_t *time){
    printf("\tOperacao concluida com sucesso!\n");
    printf("RG: %d\n", lista[position].rg);
    printf("Nome: %s\n", lista[position].nome);
    printf("Posicao na lista: %d\n", position);
    printf("C(n) = %d\n", C);
    printf("M(n) = %d\n", M);
    printf("Tempo de execucao: %lf\n", ((double)*time)/((CLOCKS_PER_SEC/1000)));
}

Dados *alocaDados(int size){
    Dados *novo;
    novo = (Dados*) malloc(sizeof(Dados)*size);
    if (novo == NULL) {
        printf ("Erro, malloc devolveu Null!\n");
        exit (1);
    }
   return novo;
}

int menu(Dados *lista){
    int posicao, escolha;
    Dados aux;
    char nome[MAX_NAME];
    printf("\t\t\tMENU\n------------------------------------------\n");
    printf("(0) - Inserir um elemento no inicio da lista.\n");
    printf("(1) - Inserir um elemento no fim da lista.\n");
    printf("(2) - Inserir um elemento na posicao N da lista.\n");
    printf("(3) - Retirar um elemento do inicio da lista.\n");
    printf("(4) - Retirar um elemento do final da lista.\n");
    printf("(5) - Retirar um elemento na posicao N da lista.\n");
    printf("(6) - Procurar um elemento pelo RG.\n");
    printf("(7) - Mostrar a lista no terminal.\n");
    printf("(8) - Salvar a lista em um arquivo.\n");
    printf("(9) - Ler a lista de um arquivo no formato .txt\n");
    printf("(10) - Ordenar lista\n");
    printf("(-1) - Sair.\n");
    printf("\tEscolha uma opcao: ");
    scanf("%d",&escolha);
    switch(escolha)
    {
        case 0:
            printf("Insira os dados da pessoa que deseja adicionar a lista\nRG: ");
            scanf("%d", &aux.rg);
            printf("Nome:");
            scanf(" %[^\n]",aux.nome);
            inserirPosicaoN(lista,&aux,0);
            break;
        case 1:
            printf("Insira os dados da pessoa que deseja adicionar a lista\nRG: ");
            scanf("%d",&aux.rg);
            printf("Nome:");
            scanf(" %[^\n]",aux.nome);
            inserirPosicaoN(lista,&aux,Tamanho);
            break;
        case 2:
            printf("Insira os dados da pessoa que deseja adicionar a lista\nRG: ");
            scanf("%d",&aux.rg);
            printf("Nome:");
            scanf(" %[^\n]",aux.nome);
            printf("Informe a posicao que deseja inserir o elemento: ");
            scanf("%d", &posicao);
            inserirPosicaoN(lista,&aux, posicao);
            break;
        case 3:
            removerPosicaoN(lista, 1);
            break;
        case 4:
            removerPosicaoN(lista,Tamanho);
            break;
        case 5:
            printf("Informe a posicao do elemento que deseja retirar: ");
            scanf("%d", &posicao);
            removerPosicaoN(lista, posicao);
            break;
        case 6:
            printf("\tEscolha qual metodo de busca voce deseja utilizar:\n(1)Busca Linear\n(2)Busca binaria(vetor tem que estar ordenado)\n");
            scanf("%d", &posicao);
            if(posicao==1)
            {
            printf("Rg que deseja consultar: ");
            scanf("%d", &posicao);
            buscaLinearRG(lista, posicao);
            }
            else
            {
            printf("Rg que deseja consultar: ");
            scanf("%d", &posicao);
            binarySearch(lista, posicao);
            }
            break;
        case 7:
            printaLista(lista);
            break;
        case 8:
            escreveArquivo(lista);
            break;
        case 9:
            printf("\tQual o tamanho da lista que voce deseja ler?\n(1)10\n(2)50\n(3)100\n(4)1.000\n(5)10.000\n(6)1.000.000\n(7)100.000.000\n");
            scanf("%d", &posicao);
            switch(posicao){
                case 1:
                    strcpy(nome,"NomeRG10.txt");
                    break;
                case 2:
                    strcpy(nome,"NomeRG50.txt");;

                    break;
                case 3:
                    strcpy(nome,"NomeRG100.txt");
                    break;
                case 4:
                    strcpy(nome,"NomeRG1K.txt");
                    break;
                case 5:
                    strcpy(nome,"NomeRG10K.txt");
                    break;
                case 6:
                    strcpy(nome,"NomeRG1M.txt");
                    break;
                case 7:
                    strcpy(nome,"NomeRG100M.txt");
                    break;
                default:
                    printf("Opcao invalida!");
                    break;
                }
            leArquivo(lista, nome);
            break;
        case 10:
            menuOrdenacao(lista); break;
        case -1:
            break;
        default:
            printf("Numero invalido, tente outro numero!");
            break;
    }
    return escolha;
}
void menuOrdenacao(Dados *lista){
    int input;
    
    printf("(1) - Selection sort\n(2) - Insertion sort\n(3) - Buble sort\n(4) - Shell sort\n(5) - Quick sort\n(6) - Merge sort\n");
    printf("Selecione qual algoritmo voce deseja utilizar: ");
    scanf("%d",&input);
    switch(input){
        case 1: selectionSortDireto(lista); break;
        case 2: insertionSortDireto(lista); break;
        case 3: bubleSortDireto(lista); break;
        case 4: shellSortDireto(lista); break;

        case 5:
        clock_t time = clock();
            M=0,C=0;
            quickSortDireto(lista, 0, Tamanho-1);
            time = clock() - time;
            apresentaOrdenado(C,M, time);
            break;
        case 6:
            clock_t time = clock();
            M=0,C=0;
            mergeSortDireto(lista, 0, Tamanho-1);
            time = clock() - time;
            apresentaOrdenado(C,M, time);
            break;
       default: printf("Numero invalido\n");break;
    }
}
void printaLista(Dados *lista){
    int i;
    for(i = 0; i<Tamanho;i++) {
        printf("RG:[%d]\tNome:[%s]\tPosicao:[%d] \n", lista[i].rg,lista[i].nome, i+1);
    }
    printf("Tamanho da lista: [%d]\n", Tamanho);
}
void inserirNoFinal(Dados *lista, Dados *info){
    lista[Tamanho]= *info;
    M++;
    Tamanho++;
}
void inserirPosicaoN(Dados*lista , Dados *info,int posicao){
    int i;
    clock_t time = clock();
    M=0, C=0;
    if (Tamanho == 0){//lista vazia
        lista [0] = *info;M++,C++;
    }
    else{
        for(i = Tamanho; i>posicao && posicao<=Tamanho; i--)
        {
            lista[i] = lista[i - 1];
            C++;
        }
        lista[posicao]= *info;
        C++,M++;
        }
    Tamanho++;
    time = clock() - time;
    apresentaDados(lista, posicao, &time);
}
void removerPosicaoN(Dados *lista, int posicao){
    int i, tempRG = lista[posicao-1].rg;
    clock_t time = clock();
    char tempName[MAX_NAME]; strcpy(tempName, lista[posicao-1].nome);
    C=0,M=0;
    if(posicao<=0||posicao>Tamanho)
    {
        printf("Erro ao remover dados, posicao informada fora do intervalo valido(1-%d)\n",Tamanho);
    }
    else
    {
        for(i=posicao-1;i<Tamanho;i++)
        {
            lista[i] = lista[i+1];
            C++,M++;
        }
        C++;
    }
    time = clock() - time;
    printf("\tOperacao concluida com sucesso!\n");
    printf("RG: %d\n", tempRG);
    printf("Nome: %s\n", tempName);
    printf("Posicao na lista: %d\n", posicao);
    printf("C(n) = %d\n", C);
    printf("M(n) = %d\n", M);
    printf("Tempo de execucao: %lf\n", ((double)time)/((CLOCKS_PER_SEC/1000)));
    Tamanho--;
}
void escreveArquivo(Dados*lista){
    FILE *arq;
    clock_t time = clock();
    arq = fopen("ListaSequencial.txt", "w+");
    int contador;
    if (arq == NULL)
    {
        printf("Não foi possivel inicializar o arquivo!\n");
        exit(1);
    }
    else
    {
        fprintf(arq,"-----------------------------------------------------------------------\n");
        fprintf(arq, "\tTamanho da lista : %d\n", Tamanho);
        for(contador = 0; contador<Tamanho; contador++)
        {
            fprintf(arq,"RG:[%d]\tNome:[%s]\tPosicao:[%d] \n",lista[contador].rg,lista[contador].nome, contador+1);
        }
        fprintf(arq,"-----------------------------------------------------------------------\n");
        time = clock() - time;
        printf("Sucesso ao criar arquivo\nTempo de execucao: %lf\n", ((double)time)/((CLOCKS_PER_SEC/1000)));
    }
    fclose(arq);
}
void leArquivo(Dados*lista, char*filename){
    char txtLine[MAX_READ];
    Dados token;
    FILE *arquivo;
    clock_t time = clock();
    arquivo=fopen(filename, "r");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel inicializar o arquivo!\n");
        exit(1);
    }
    fgets(txtLine, MAX_READ, arquivo);
    while(!feof(arquivo))
    {
        strcpy(token.nome, strtok(txtLine, ","));
        token.rg = atoi(strtok(NULL, "\n"));
        inserirNoFinal(lista, &token);
        fgets(txtLine, MAX_READ, arquivo);
    }
    time = clock() - time;
    printf("Lista armazenada com sucesso\nTempo de execucao: %lf\nC(n) = %d\nM(n) = %d\n", ((double)time)/((CLOCKS_PER_SEC/1000)), C,M);
    fclose(arquivo);
}


