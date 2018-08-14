#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void merge (int Vetor[MAX], int inicio, int meio, int fim){
	int i, j, k;
	int p1 = meio + 1 - inicio; //primeira metade do vetor
	int p2 = fim - meio; //segunda metade do vetor
	int ar1[p1], ar2[p2]; //arrays temps das divisoes
	//int aux;

        for(i = 0; i < p1; i++){
            ar1[i] = Vetor[i + inicio];
        }

        for(j = 0; j< p2; j++){
            ar2[j] = Vetor[j + meio + 1];
        }
        i= 0;
        j = 0;
        k = inicio;

        while (i < p1 && j < p2){ //comparando os 2 arrays temps e ordenando para o Vetor original
            if(ar1[i] <= ar2[j]){
                Vetor[k] = ar1[i];
                i++;
            }else{
                Vetor[k] = ar2[j];
                j++;
            }
            k++;
        }
        while(i < p1){
            Vetor[k] = ar1[i];
            i++;
            k++;
        }
        while(j < p2){
            Vetor[k] = ar2[j];
            j++;
            k++;
        }
}

void mergeSort(int Vetor[MAX], int inicio, int fim){
	if(inicio < fim){
		int meio = inicio + ((fim - inicio)/2);

		mergeSort(Vetor, inicio, meio); //chamando a função para as 2 metades do array
		mergeSort(Vetor, meio + 1, fim);

		merge(Vetor, inicio, meio, fim); //combinar as 2 metades de forma ordenada
	}
}


int main(){

    int Vetor[MAX] = {12, 11, 13, 5, 6};
    int x = 0;
    mergeSort(Vetor, 0, MAX - 1);
    printf("\nArray ordenado: \n");
    for(x = 0; x < MAX; x++){
        printf("%d", Vetor[x]);
    }

    return 0;
}
