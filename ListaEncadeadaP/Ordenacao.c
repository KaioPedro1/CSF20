#include "Header.h"

Node **criaListaPtr(Header *listaOriginal){
    Node  **vetTest;
    vetTest =(Node**)malloc (listaOriginal->tamanho*(sizeof(Node**)));
    Node *novo;
    novo = listaOriginal->primeiro;
    for(int i = 0; i<listaOriginal->tamanho; i++){
        *(vetTest+i) = novo;
        novo = novo->proximo;
    }
    return vetTest;
}

void copiaVtrParaLista(Header *listaOrdenadaIndireta){
    int tamanho = listaOrdenadaIndireta->tamanho;
    listaOrdenadaIndireta->primeiro = NULL;
    listaOrdenadaIndireta->ultimo = NULL;
    listaOrdenadaIndireta->tamanho = 0;
    for(int i=0; i<tamanho; i++){
        inserirNoFim(listaOrdenadaIndireta->vetorPtr[i]->rg, listaOrdenadaIndireta->vetorPtr[i]->nome, listaOrdenadaIndireta);
    }
    free(listaOrdenadaIndireta->vetorPtr);
    listaOrdenadaIndireta->estaOrdenado = 0;
}

void apresentaOrdenado(int c, int m, clock_t tempo){
    printf("\tLista ordenada com sucesso\nC(n) = %d\nM(n) = %d\nTempo em MS: %lf\n", c, m, (double)tempo);
}

void selectionSortIndireto(Header *lista)
{
    int i,j,menor; C=0, M=0;
    clock_t time = clock();
    Node *aux_troca;
    int tamanho = lista->tamanho;
    for (i=0; i<tamanho;i++)
    {
        menor = i;
        C++, M++;
        for(j=i+1; j<tamanho;j++)
        {
            if(lista->vetorPtr[j]->rg < lista->vetorPtr[menor]->rg){
                menor = j;
                C++, M++;
            }
        }
        aux_troca = lista->vetorPtr[menor] ;
        lista->vetorPtr[menor]= lista->vetorPtr[i];
        lista->vetorPtr[i] = aux_troca;
        C++, M+=3;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
    lista->estaOrdenado = 1;
}

void insertionSortIndireto(Header *listaOriginal){
    int i, j; C=0, M=0;
    Node *aux_troca;
    clock_t time = clock();
    for (i=1; i<listaOriginal->tamanho;i++)
    {
        aux_troca = listaOriginal->vetorPtr[i];
        for(j=i-1; j>=0 && listaOriginal->vetorPtr[j]->rg > aux_troca->rg; j--)
        {
            listaOriginal->vetorPtr[j+1] = listaOriginal->vetorPtr[j];
            C++, M++;
        }
        listaOriginal->vetorPtr[j+1] = aux_troca;
        C++, M+=2;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
    listaOriginal->estaOrdenado = 1;
}

void bubleSortIndireto(Header *listaOriginal){
    int i,j; C=0,M=0;
    Node *aux_troca;
    clock_t time = clock();
    for(i=0; i<listaOriginal->tamanho;i++)
    {
        for(j=i+1; j<listaOriginal->tamanho; j++)
        {
            if(listaOriginal->vetorPtr[i]->rg > listaOriginal->vetorPtr[j]->rg)
            {
                aux_troca = listaOriginal->vetorPtr[j];
                listaOriginal->vetorPtr[j] = listaOriginal->vetorPtr[i];
                listaOriginal->vetorPtr[i] = aux_troca;
                C++, M+=3;
            }
            C++;
        }
        C++;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
    listaOriginal->estaOrdenado=1;
}

void shellSortIndireto(Header *listaOriginal){
    int i, j, h;
    C=0, M=0;
    Node *aux_troca;
    clock_t time = clock();
    h = listaOriginal->tamanho/7; //mudar o h muda consideravelmente o tempo
    while(h>0){
        for(i=h; i<listaOriginal->tamanho; i++){
            aux_troca = listaOriginal->vetorPtr[i];
            for(j=i; j>=h && listaOriginal->vetorPtr[j-h]->rg > aux_troca->rg; j = j - h){
                listaOriginal->vetorPtr[j] = listaOriginal->vetorPtr[j-h];
                C++, M++;
            }
            listaOriginal->vetorPtr[j] = aux_troca;
            C++, M+=2;
        }
        h = h/2;
        C++, M++;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
    listaOriginal->estaOrdenado = 1;
}

void binarySearch(Header *listaOriginal, int rg){
    int inicio=0,
    meio,
    fim = listaOriginal->tamanho-1,
    encontrou = 0;
    C=0,M=0;
    clock_t time = clock();
        while(inicio<=fim){
            meio = (inicio+fim)/2;
                if(listaOriginal->vetorPtr[meio]->rg == rg)
                {
                    C++;
                    time = clock() - time;
                    printf("\t\nDADOS ENCONTRADOS\nRG:%d\nNome: %s\nPosicao na lista:%d\nC(n) = %d\nM(n) = %d\n",listaOriginal->vetorPtr[meio]->rg, listaOriginal->vetorPtr[meio]->nome, meio+1,C,M);
                    printf("Tempo de execucao: %lf\n", (double)time / ((CLOCKS_PER_SEC / 1000)));
                    encontrou = 1;
                    break;
                }
                else if(listaOriginal->vetorPtr[meio]->rg < rg)
                {
                    inicio = meio+1;
                    C++, M++;
                }
                else{
                    fim = meio-1;
                    C++, M++;
                }
                M++, C++;
        }
        if (!encontrou){
            C++;
            printf("\tNao foi possivel encontrar o RG:%d\n", rg);
    }
}

void buscaLinearRG(Header*lista, int rg){
    Node *auxiliar = lista->primeiro;
    clock_t time = clock();
    int contador=1, encontrou=0;
    M=0,C=0;
    if(lista->estaOrdenado==0){
        while(auxiliar!=NULL)
        {
            if(rg == auxiliar->rg)
            {
                time = clock() - time;
                C++;
                printf("\tDADOS ENCONTRADOS\nRG:%d\nNome: %s\nPosicao na lista:%d\nC(n) = %d\nM(n) = %d\n",auxiliar->rg, auxiliar->nome, contador,C, M);
                printf("Tempo de execucao: %lf\n", (double)time / ((CLOCKS_PER_SEC / 1000)));
                encontrou=1;
                break;
            }
            C++;
            contador++;
            auxiliar = auxiliar->proximo;
        }
    }
    else{
        for(int i = 0; i<lista->tamanho-1; i++){
            if(lista->vetorPtr[i]->rg == rg){
                time = clock() - time;
                C++;
                printf("\tDADOS ENCONTRADOS\nRG:%d\nNome: %s\nPosicao na lista:%d\nC(n) = %d\nM(n) = %d\n",lista->vetorPtr[i]->rg, lista->vetorPtr[i]->nome, i+1,C, M);
                printf("Tempo de execucao: %lf\n", (double)time / ((CLOCKS_PER_SEC / 1000)));
                encontrou=1;
                break;
            }
            C++;
        }
        if(encontrou==0)
        {
            C++;
            printf("\tNao foi possivel encontrar o RG:%d\n", rg);
        }
    }
}

void quickSortIndireto(Header *listaOriginal, int inicioVet, int fimVet){
    Node *aux_troca;
   int i,j, pivot;
   i = inicioVet;
   j = fimVet;
   pivot = listaOriginal->vetorPtr[(inicioVet+fimVet)/2]->rg;
   do{
       while(listaOriginal->vetorPtr[i]->rg < pivot){
            i++;
            C++;
        }
       while(listaOriginal->vetorPtr[j]->rg > pivot){
            j--;
            C++;
        }
        if(i<=j){
            aux_troca = listaOriginal->vetorPtr[i];
            listaOriginal->vetorPtr[i]=listaOriginal->vetorPtr[j];
            listaOriginal->vetorPtr[j] = aux_troca;
            i++,j--;
            C++,M+=3;
        }
        C++;
    }while(i<j);
   if(j>inicioVet) quickSortIndireto(listaOriginal, inicioVet, j);
   if(i<fimVet) quickSortIndireto(listaOriginal, i, fimVet);
}

void  mergeSortIndireto(Header *listaOriginal, int inicioVet, int fimVet){
    int meio;
    if(inicioVet<fimVet){
        C++;
        meio = (inicioVet+fimVet)/2;
        mergeSortIndireto(listaOriginal, inicioVet, meio);
        mergeSortIndireto(listaOriginal, meio + 1, fimVet);
        merge(listaOriginal,inicioVet,meio, fimVet);
    }
}
void merge(Header  *listaOriginal, int inicio, int meio,int fim)
{
    int i,j ,k, tam;
    i=inicio;
    j=meio+1;
    k= 0;
    tam= fim-inicio+1;
    Node **aux;
    aux = (Node **) malloc(tam* (sizeof(Node**)));
    while(i<=meio && j<=fim){
        if(listaOriginal->vetorPtr[i]->rg<listaOriginal->vetorPtr[j]->rg){
            aux[k] = listaOriginal->vetorPtr[i];
            i++;
        }
        else{
            aux[k]= listaOriginal->vetorPtr[j];
            j++;
        }
        k++;C++,M+=2;
    }

        while(j<=fim){
            aux[k]=listaOriginal->vetorPtr[j];
            j++,k++;C++,M++;
        }
        while(i<=meio){
            aux[k]=listaOriginal->vetorPtr[i];
            i++,k++;C++,M++;
        }
    for(k=inicio; k<=fim; k++){
        listaOriginal->vetorPtr[k] = aux[k-inicio];
        C++,M++;
    }
    free(aux);
}

//FALHEI AQUI TAMBÉM
/*void mergeSortV2(Header *listaOriginal){
    Header *left, *right;
    int meio, tamanho = Tamanho-1, i;//TAMANHO TEM QUE SER O TAMANHO DO ARRAY, CUIDADO COM RECURSÃO
    if(tamanho<2){
        return;
    }
    meio = tamanho/2;
    left = alocaDados(meio);
    right = alocaDados(tamanho - meio);
    for(i = 0; i<meio-1;i++){
        left[i]=listaOriginal[i];
    }
    for(i = meio; i<tamanho-1;i++){
        right[i-meio]=listaOriginal[i];
    }
    mergeSortV2(left);
    mergeSortV2(right);
    mergeV2(left, meio, right, tamanho-meio, listaOriginal);
}
void mergeV2(Header *left, int sizeL, Header *right, int sizeR, Header *list)
{
    int i=0, j=0, k=0, tamL=sizeL, tamR=sizeR;
    while(i<tamL && j < tamR){
        if(left[i].rg>=right[j].rg){
            list[k]=left[i];
            i++;
        }
        else{
            list[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<tamL){
        list[k]=left[i];
        i++, k++;
    }
    while(j<tamR){
        list[k]=right[j];
        j++, k++;
    }
}




FALHEI
void selectionSortIndireto(Header *listaOriginal){
    int i,j,M=0,menor,C=0;
    Header **vetorPonteiro;
    vetorPonteiro = (Header**) malloc (Tamanho* sizeof(Header*));
    for(i = 0; i<Tamanho; i++){
        vetorPonteiro[i] = &listaOriginal[i];
       // printf("%d\t%x\n", vetorPonteiro[i]->rg,&listaOriginal[i]);
    }
     for (i=0; i<Tamanho;i++)
    {
        menor = i;
        C++, M++;
        for(j=i+1; j<Tamanho;j++)
        {
            if(listaOriginal[j].rg < listaOriginal[menor].rg){
                menor = j;
                C++, M++;
            }
        }
        vetorPonteiro[i]=&listaOriginal[menor];
        printf("\t%d\n",vetorPonteiro[i]->rg);
        C++, M+=1;
    }
}*/
/*Node *iteratorIndireto(Header *lista, int index){
    int i;
    if (index < 0 || index>=lista->tamanho){
        return NULL;
    }
    Node *ponteiro = lista->primeiro;
    for (i = 0; i<index; i++){
        ponteiro = ponteiro->proximo;
    }
    return ponteiro;
}*/
/*void bubleSortIndireto(Header *lista){
    int i,j;
    for(i = 0; i < lista->tamanho; i++){
        Node *ptr_i = iteratorIndireto(lista, i);
        for(j=i+1; j<lista->tamanho; j++){
            Node *ptr_j = iteratorIndireto(lista, j);
            if(ptr_i->rg > ptr_j->rg){
                Node *temp = ptr_j;
                ptr_j = ptr_i;
                ptr_i = temp;
            }
        }
    }
}

*/