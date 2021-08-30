#include "Header.h"



void apresentaOrdenado(int c, int m, clock_t tempo){
    printf("\tLista ordenada com sucesso\nC(n) = %d\nM(n) = %d\nTempo em MS: %lf\n", c, m, (double)tempo);
}
void selectionSortDireto(Dados *lista){
    int i,j,menor; C=0, M=0;
    clock_t time = clock();
    Dados aux_troca;
    for (i=0; i<Tamanho;i++)
    {
        menor = i;
        C++, M++;
        for(j=i+1; j<Tamanho;j++)
        {
            if(lista[j].rg < lista[menor].rg){
                menor = j;
                C++, M++;
            }
        }
        aux_troca = lista[menor];
        lista[menor]=lista[i];
        lista[i] = aux_troca;
        C++, M+=3;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
}

void insertionSortDireto(Dados *lista){
    int i, j; C=0, M=0;
    Dados aux_troca;
    clock_t time = clock();
    for (i=1; i<Tamanho;i++)
    {
        aux_troca = lista[i];
        for(j=i-1; j>=0 && lista[j].rg > aux_troca.rg; j--)
        {
            lista[j+1] = lista[j];
            C++, M++;
        }
        lista[j+1]= aux_troca;
        C++, M+=2;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
}

void bubleSortDireto(Dados *lista){
    int i,j, C=0,M=0;
    Dados aux_troca;
    clock_t time = clock();
    for(i=0; i<Tamanho;i++)
    {
        for(j=i+1; j<Tamanho; j++)
        {
            if(lista[i].rg > lista[j].rg)
            {
                aux_troca = lista[j];
                lista[j] = lista[i];
                lista[i] = aux_troca;
                C++, M+=3;
            }
            C++;
        }
        C++;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
}

void shellSortDireto(Dados *lista){
    int i, j, h, C=0, M=0;
    Dados aux_troca;
    clock_t time = clock();
    h = Tamanho/7; //mudar o h muda consideravelmente o tempo
    while(h>0){
        for(i=h; i<Tamanho; i++){
            aux_troca = lista[i];
            for(j=i; j>=h && lista[j-h].rg > aux_troca.rg; j = j - h){
                lista[j] = lista[j-h];
                C++, M++;
            }
            lista[j] = aux_troca;
            C++, M+=2;
        }
        h = h/2;
        C++, M++;
    }
    time = clock() - time;
    apresentaOrdenado(C,M,time);
}

void binarySearch(Dados *lista, int rg){
    int inicio=0,meio, fim = Tamanho-1, encontrou = 0;
    C=0,M=0;
    clock_t time = clock();
        while(inicio<=fim){
            meio = (inicio+fim)/2;
            M++, C++;
                if(lista[meio].rg == rg)
                {
                    C++;
                    time = clock() - time;
                    printf("\tDADOS ENCONTRADOS\nRG:%d\nNome: %s\nPosicao na lista:%d\nC(n) = %d\nM(n) = %d\n",lista[meio].rg, lista[meio].nome, meio+1,C,M);
                    printf("Tempo de execucao: %lf\n", (double)time / ((CLOCKS_PER_SEC / 1000)));
                    encontrou = 1;
                    break;
                }
                else if(lista[meio].rg < rg)
                {
                    inicio = meio+1;
                    C++, M++;
                }
                else{
                    fim = meio-1;
                    C++, M++;
                }
        }
        if (!encontrou){
            C++;
            printf("\tNao foi possivel encontrar o RG:%d\n", rg);
    }
}

void buscaLinearRG(Dados*lista, int rg){
    int i;
    C=0,M=0;
    clock_t time = clock();
    short int encontrou = 1;
    for(i = 0; i<=Tamanho;i++){
        C++;
        if(lista[i].rg == rg){
            C++;
            time = clock() - time;
            printf("\tDADOS ENCONTRADOS\nRG:%d\nNome: %s\nPosicao na lista:%d\nC(n) = %d\nM(n) = %d\n",lista[i].rg, lista[i].nome, i+1,C,M);
            printf("Tempo de execucao: %lf\n", (double)time / ((CLOCKS_PER_SEC / 1000)));
            encontrou = 0;
            break;
        }
    }
    if (encontrou){
        C++;
        printf("\tNao foi possivel encontrar o RG:%d\n", rg);
    }
}

void quickSortDireto(Dados *lista, int inicioVet, int fimVet){
    Dados aux_troca;
   int i,j, pivot;
   i = inicioVet;
   j = fimVet;
   pivot = lista[(inicioVet+fimVet)/2].rg;
   do{
        while(lista[i].rg < pivot){
            i++;
            C++;
        }
        while(lista[j].rg > pivot){
            j--;
            C++;
        }
        if(i<=j){
            aux_troca = lista[i];
            lista[i]=lista[j];
            lista[j] = aux_troca;
            i++,j--;
            C++,M+=3;
        }
        C++;
    }while(i<j);
   if(j>inicioVet) quickSortDireto(lista, inicioVet, j);
   if(i<fimVet) quickSortDireto(lista, i, fimVet);
}

void  mergeSortDireto(Dados *lista, int inicioVet, int fimVet){
    int meio;
    if(inicioVet<fimVet){
        C++;
        meio = (inicioVet+fimVet)/2;
        mergeSortDireto(lista,inicioVet, meio);
        mergeSortDireto(lista, meio+1, fimVet);
        merge(lista,inicioVet,meio, fimVet);
    }
}
void merge(Dados  *lista, int inicio, int meio,int fim)
{
    int i,j ,k, tam;
    i=inicio;
    j=meio+1;
    k= 0;
    tam= fim-inicio+1;
    Dados *aux;
    aux = alocaDados(tam);
    while(i<=meio && j<=fim){
        if(lista[i].rg<lista[j].rg){
            aux[k]=lista[i];
            i++;
        }
        else{
            aux[k]=lista[j];
            j++;
        }
        k++;C++,M+=2;
    }

        while(j<=fim){
            aux[k]=lista[j];
            j++,k++;C++,M++;
        }
        while(i<=meio){
            aux[k]=lista[i];
            i++,k++;C++,M++;
        }
    for(k=inicio; k<=fim; k++){
        lista[k] = aux[k-inicio];
        C++,M++;
    }
    free(aux);
}


