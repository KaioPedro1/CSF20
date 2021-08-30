#include "Header.h"

void apresentaDados(int *rg, char*nome, int *position, clock_t *time){
    printf("\tOperacao concluida com sucesso!\n");
    printf("RG: %d\n", *rg);
    printf("Nome: %s\n", nome);
    printf("Posicao na lista: %d\n", *position);
    printf("C(n) = %d\n", C);
    printf("M(n) = %d\n", M);
    printf("Tempo de execucao: %lf\n", ((double)*time)/((CLOCKS_PER_SEC/1000)));
}
int menu(Header *lista){
    int escolha, rg, posicao;
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
            (lista->estaOrdenado==0)?:copiaVtrParaLista(lista);
            printf("Insira os dados da pessoa que deseja adicionar a lista\nRG: ");
            scanf("%d", &rg);
            printf("Nome:");
            scanf(" %[^\n]",nome);
            inserirPosicaoN(rg,nome, lista,1);
            break;
        case 1:
            (lista->estaOrdenado==0)?:copiaVtrParaLista(lista);
            printf("Insira os dados da pessoa que deseja adicionar a lista\nRG: ");
            scanf("%d", &rg);
            printf("Nome:");
            scanf(" %[^\n]",nome);
            inserirPosicaoN(rg,nome, lista,lista->tamanho);
            break;
        case 2:
            (lista->estaOrdenado==0)?:copiaVtrParaLista(lista);
            printf("Insira os dados da pessoa que deseja adicionar a lista\nRG: ");
            scanf("%d", &rg);
            printf("Nome:");
            scanf(" %[^\n]",nome);
            printf("Informe a posicao que deseja inserir o elemento: ");
            scanf("%d", &posicao);
            inserirPosicaoN(rg,nome,lista,posicao);
            break;
        case 3:
            (lista->estaOrdenado==0)?:copiaVtrParaLista(lista);
            removerPosicaoN(lista,1);
            break;
        case 4:
            (lista->estaOrdenado==0)?:copiaVtrParaLista(lista);
            removerPosicaoN(lista, lista->tamanho);
            break;
        case 5:
            (lista->estaOrdenado==0)?:copiaVtrParaLista(lista);
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
            {   if(lista->estaOrdenado)
                {
                printf("Rg que deseja consultar: ");
                scanf("%d", &posicao);
                binarySearch(lista, posicao);
                }
                else{
                    printf("A lista não esta ordenada, tente novamente.");
                }
            }
            break;
        case 7:
            printaLista(lista);
            break;
        case 8:
            escreveArquivo(lista);
            break;
        case 9:
            printf("\tQual o tamanho da lista que voce deseja ler?\n(1)10\n(2)50\n(3)100\n(4)1.000\n(5)10.000\n(6)1.000.000\n(7)11.000.000\n");
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
            subMenuOrdenacao(lista); break;
        case -1:
            break;
        default:
            printf("Numero invalido, tente outro numero!");
            break;
    }
    return escolha;
}
void subMenuOrdenacao(Header *lista){
    int input;
    lista->vetorPtr = criaListaPtr(lista);
    clock_t time;
    printf("(1) - Selection sort\n(2) - Insertion sort\n(3) - Buble sort\n(4) - Shell sort\n(5) - Quick sort\n(6) - Merge sort\n");
    printf("Selecione qual algoritmo voce deseja utilizar: ");
    scanf("%d",&input);
    switch(input){
        case 1: selectionSortIndireto(lista); break;
        case 2: insertionSortIndireto(lista); break;
        case 3: bubleSortIndireto(lista); break;
        case 4: shellSortIndireto(lista); break;
        case 5:
            time = clock();
            M=0,C=0;
            quickSortIndireto(lista, 0, lista->tamanho-1);
            time = clock() - time;
            apresentaOrdenado(C,M, time);
            lista->estaOrdenado = 1;
            break;
        case 6:
            time = clock();
            M=0,C=0;
            mergeSortIndireto(lista, 0, lista->tamanho-1);
            time = clock() - time;
            apresentaOrdenado(C,M, time);
            break;
        default: printf("Numero invalido\n");break;
    }
}
void printaLista(Header *lista){
    Node *auxiliar = lista->primeiro;
    if(lista->estaOrdenado==0){
    int contador=1;
        while(auxiliar!= NULL){
            printf("RG:[%d]\tNome:[%s]\tPosicao:[%d] \n", auxiliar->rg,auxiliar->nome, contador);
            auxiliar = auxiliar->proximo;
            contador++;
        }
        printf("\tTamanho da lista : %d\n", lista->tamanho);
    }
    else{
        int i;
        for(i = 0; i<lista->tamanho; i++) {
            printf("RG:[%d]\tNome:[%s]\tPosicao:[%d] \n", lista->vetorPtr[i]->rg,lista->vetorPtr[i]->nome, i+1);
        }
        printf("Tamanho da lista: [%d]\n", lista->tamanho);
    }
}
Node *alocaNode(){
    Node *novo;
    novo = (Node*) malloc(sizeof(Node));
     if (novo == NULL) {
      printf ("Erro, malloc devolveu Null!\n");
      exit (1);
   }
    return novo;
}
void inserirNoFim(int rg, char *nome, Header *lista) {
    int position = lista ->tamanho+1;
    clock_t time = clock();
    Node *novo = alocaNode();
    novo-> rg= rg;
    strcpy(novo->nome, nome);
    if(lista->primeiro == NULL)
    {
        lista->primeiro = novo;
        lista->ultimo = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
        M+=2,C++;
    }
    else
    {
        novo->proximo = NULL;
        novo->anterior = lista->ultimo;
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
        M+=3;
        C++;
    }
    time = clock() - time;
    lista->estaOrdenado = 0;
    lista->tamanho++;

}
void inserirPosicaoN(int rg, char *nome, Header *lista, int posicao){
    int i=1;
    clock_t time = clock();
    Node *auxiliarAtual = lista ->primeiro;;//MUDEI AUQI POR CAUSA DA IDE
    Node *novo = alocaNode();
    novo->rg = rg;
    strcpy(novo->nome, nome);
    M=0,C=0;
    if(lista->tamanho <= 0){ //lista vazia
        lista->primeiro = novo;
        lista->ultimo = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
        M+=2;C++;
    }
    else
    {
        if (posicao == 1)//caso inserir no inicio
        {
            lista->primeiro->anterior = novo;
            novo->proximo = lista->primeiro;
            novo->anterior = NULL;
            lista->primeiro = novo;
            M+=2,C++;
        }
        else if (posicao >= lista->tamanho)//caso inserir no final
        {
            novo->proximo = NULL;
            novo->anterior = lista->ultimo;
            lista->ultimo->proximo = novo;
            lista->ultimo = novo;
            M+=2,C++;
        }
        else
        {
            while(i<posicao)// i começa em 1
            {
                if(auxiliarAtual->proximo!=NULL)
                {
                    auxiliarAtual = auxiliarAtual->proximo;
                    C++;
                }
                C++;
                i++;
            }
            novo->proximo = auxiliarAtual;
            novo->anterior = auxiliarAtual->anterior;
            auxiliarAtual->anterior->proximo = novo;
            auxiliarAtual->anterior = novo;
            M+=4;
            C++;
        }
    }
    lista->tamanho++;
    time = clock() - time;
    lista->estaOrdenado = 0;
    apresentaDados(&rg, nome, &posicao, &time);

}
void removerPosicaoN(Header*lista, int posicao){
    int flag = 1, i,tempRg;
    char tempName[MAX_NAME];
    clock_t time = clock();
    M=0, C=0;

    if(lista->tamanho <= 1){ //lista com 1 elemento
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->tamanho--;
        return;
    }
    else if(posicao == 1 || posicao>=lista->tamanho)//inicio, fim ou fora da lista
    {
        if(posicao > lista->tamanho)//caso posição maior
        {
            printf("Erro, nao foi possivel remover o elemento da posicao passada(%d), porque ele ultrapassa o tamanho da lista(%d)\n", posicao, lista->tamanho);
        }
        else if (posicao == 1) //caso primeiro elemento
        {
            tempRg = lista->primeiro->rg; strcpy(tempName,lista->primeiro->nome);//copia pra imprimir na função do final
            lista->primeiro = lista->primeiro->proximo;
            free(lista->primeiro->anterior);
        }
        else if (posicao == lista->tamanho) //caso ultimo elemento
        {
            tempRg = lista->ultimo->rg; strcpy(tempName,lista->ultimo->nome);//copia pra imprimir na função do final
            lista->ultimo = lista->ultimo->anterior;
            free(lista->ultimo->proximo);
            lista->ultimo->proximo = NULL;
        }
        flag = 0;
        C+=2;
    }
    if(flag)
    {
            Node *aux;
            aux = lista->primeiro;
            M++;
            for(i = 1; i < posicao; i++)
            {
                if(aux->proximo!=NULL){
                    aux = aux->proximo;
                    C++;
                }
            }
            strcpy(tempName,aux->nome);
            tempRg = aux->rg;
            aux-> anterior-> proximo = aux -> proximo;
            aux-> proximo -> anterior = aux -> anterior;
            free(aux);
            M+=1;
        C++;
    }
    time = clock() - time;
    apresentaDados(&tempRg, tempName,&posicao, &time);
    lista->tamanho--;
    lista->estaOrdenado = 0;
}
void escreveArquivo(Header*lista){
    FILE *arq;
    arq = fopen("ListaEncadeada.txt", "w+");
    clock_t time = clock();
    Node *auxiliar = lista->primeiro;
    int contador=1;
        if (arq == NULL)
        {
            printf("Não foi possivel inicializar o arquivo!\n");
            exit(1);
        }
        else
        {
            fprintf(arq,"-----------------------------------------------------------------------\n");
            fprintf(arq, "\tTamanho da lista : %d\n", lista->tamanho);
            while(auxiliar!= NULL)
            {
                fprintf(arq,"RG:[%d]\tNome:[%s]\tPosicao:[%d] \n", auxiliar->rg,auxiliar->nome, contador);
                auxiliar = auxiliar->proximo;
                contador++;
            }
            fprintf(arq,"-----------------------------------------------------------------------\n");
            time = clock() - time;
            printf("Sucesso ao criar arquivo\nTempo de execucao: %lf\n", ((double)time)/((CLOCKS_PER_SEC/1000)));
        }
        fclose(arq);
    lista->estaOrdenado = 0;
}
void leArquivo(Header*lista,char*filename){
    clock_t time = clock();
    char txtLine[MAX_READ],*tokenName,*tokenRG;
    FILE *arquivo;
    arquivo=fopen(filename, "r");
    C=0,M=0;
    if (arquivo == NULL)
    {
        printf("Nao foi possivel inicializar o arquivo!\n");
        exit(1);
    }
    fgets(txtLine, MAX_READ, arquivo);
    while(!feof(arquivo))
    {
        tokenName = strtok(txtLine, ",");
        tokenRG = strtok(NULL, "\n");
        inserirNoFim(atoi(tokenRG), tokenName, lista);
        fgets(txtLine, MAX_READ, arquivo);
    }
    time = clock() - time;
    printf("Lista armazenada com sucesso\nTempo de execucao: %lf\nC=%d\nM=%d", ((double)time)/((CLOCKS_PER_SEC/1000)),C,M);
    fclose(arquivo);
    lista->estaOrdenado = 0;
}



