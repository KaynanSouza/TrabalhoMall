#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int tamanho, interacao = 0;

void quicksort(int selecioneOperacao){

    int selecioneMetodo;

    printf(" Qual é o tamanho da lista que deseja:");// digitar tamanho da lista
    scanf("%d", &tamanho);

    int vetor[tamanho], aleatorio[tamanho];

    srand(time(NULL));//gerar numeros aleatorios em função do horario

    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;// gerar numeros aleatorios em função do tempo
        aleatorio[i] = vetor[i];
    }


    do{
        printf("\n Sua lista:\n");

        for(int i = 0; i < tamanho; i++){// formatar lista na tela
            if(i == 0)
                printf(" [");
            printf("%d", vetor[i]);
            if(i < tamanho - 1)
                printf(", ");
            if(i == tamanho - 1)
                printf("]\n");
        }
        printf("\n");

        // menu do quicksort
        printf("|------------------------------------------------|\n");
        printf("| Olá, o Quicksort é um algoritmo rapido e       |\n");
        printf("| eficiente de ordenação por divisão e conquista |\n");
        printf("|------------------------------------------------|\n");
        printf("| 1.Crescente                                    |\n");
        printf("| 2.Decrescente                                  |\n");
        printf("| 3.Aleatório                                    |\n");
        printf("| 4.Voltar                                       |\n");
        printf("|------------------------------------------------|\n");
        printf(" Selecione a operação: ");
        scanf("%d", &selecioneOperacao);
        printf("\n");

        switch(selecioneOperacao){
            case 1:
                //metodo crescente
                printf("|------------------------|\n");
                printf("| Deseja qual método:    |\n");
                printf("|------------------------|\n");
                printf("| 1.Passo a Passo        |\n");
                printf("| 2.Resultado final      |\n");
                printf("| 3.Voltar               |\n");
                printf("|------------------------|\n");
                printf(" Selecione a operação: ");
                scanf("%d", &selecioneMetodo);
                printf("\n");

                switch(selecioneMetodo){
                    case 1:
                        //metodo passo a passo
                        funcaoQuicksortCrescentePassos(vetor, 0, tamanho - 1);

                        system("pause");
                        system("cls");
                        break;
                    case 2:

                        //resultado final da lista ordenada
                        funcaoQuicksortCrescente(vetor, 0, tamanho - 1);
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        printf("========= VOLTANDO =========\n");
                        sleep(1);
                        system("cls");
                        break;
                    default:
                        printf("=============================\n");
                        printf("======OPERAÇÃO INVALIDA======\n");
                        printf("=============================\n");
                        system("cls");
                        break;
                }

                break;
            case 2:
                //metodo decrescente
                printf("|------------------------|\n");
                printf("| Deseja qual método:    |\n");
                printf("|------------------------|\n");
                printf("| 1.Passo a Passo        |\n");
                printf("| 2.Resultado final      |\n");
                printf("| 3.Voltar               |\n");
                printf("|------------------------|\n");
                printf(" Selecione a operação: ");
                scanf("%d", &selecioneMetodo);
                printf("\n");

                switch(selecioneMetodo){
                    case 1:
                        //metodo passo a passo

                        printf("|-----------------------------------|\n");
                        printf("| Deseja qual passo do programa:    |\n");
                        printf("|-----------------------------------|\n");
                        printf("| 1.Escolha do pivo                 |\n");
                        printf("| 2.Sequência particionada          |\n");
                        printf("| 3.Exemplo                         |\n");
                        printf("| 4.Voltar                          |\n");
                        printf("|-----------------------------------|\n");
                        printf(" Selecione a operação: ");
                        scanf("%d", &selecioneMetodo);
                        printf("\n");

                        system("cls");

                        printf("\n Sua lista:\n");

                        for(int i = 0; i < tamanho; i++){// formatar lista na tela
                            if(i == 0)
                                printf(" [");
                            printf("%d", vetor[i]);
                            if(i < tamanho - 1)
                                printf(", ");
                            if(i == tamanho - 1)
                                printf("]\n");
                        }
                        printf("\n");

                        printf("|------------------------------------------------------|\n");
                        switch(selecioneMetodo){
                            case 1:
                                printf("| No método de particionamento primeior deve escolher  |\n");
                                printf("| um elemento para se chamar de pivô.                  |\n");
                                printf("| O pivô da lista será o %d e iremos comparar todos os |\n", vetor[tamanho - 1]);
                                printf("| elementos da esquerda.                               |\n");
                                printf("|                                                      |\n");


                            case 2:

                                printf("| Para saber qual elemento já trocamos, devemos manter |\n");
                                printf("| uma variável i, que nos permite controlar quais      |\n");
                                printf("| elementos já foram trocados, da esquerda para        |\n");
                                printf("| esquerda para direita. Ao final de toda a interação  |\n");
                                printf("| da sequência, pegamos nosso pivô e trocamos com a    |\n");
                                printf("| posição atual da variável i.                         |\n");
                                printf("|                                                      |\n");

                            case 3:

                                printf("| Exemplo:                                             |\n");
                                printf("|                     [5, 1, 4, 2, 3]                  |\n");
                                printf("| partiçao()------------------------------             |\n");
                                printf("| 5 <= 3? continua    [5, 1, 4, 2, 3]   interação 0    |\n");
                                printf("| 1 <= 3? troque(5,1) [1, 5, 4, 2, 3]   interação 1    |\n");
                                printf("| 4 <= 4? continua    [1, 5, 4, 2, 3]   interação 2    |\n");
                                printf("| 2 <= 3? troque(5,2) [1, 2, 4, 5, 3]   interação 3    |\n");
                                printf("|     troque(i, pivô) [1, 2, 3, 5, 4]   fim interação  |\n");
                                printf("|                                                      |\n");
                                printf("|------------------------------------------------------|\n");

                                interacao = 0;

                                funcaoQuicksortDecrescentePassos(vetor, 0, tamanho -1);

                                break;


                        }


                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        //resultado final da lista ordenada
                        funcaoQuicksortDecrescente(vetor, 0, tamanho - 1);

                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        printf("========= VOLTANDO =========\n");
                        sleep(1);
                        system("cls");
                        break;
                    default:
                        printf("=============================\n");
                        printf("======OPERAÇÃO INVALIDA======\n");
                        printf("=============================\n");
                        system("cls");
                        break;
                    }
                break;
            case 3:
                //aparecer a lista aleatoria

                for(int i = 0; i < tamanho; i++){
                    vetor[i] = aleatorio[i];
                }

                printf("\n Sua lista aleatoria:\n");

                for(int i = 0; i < tamanho; i++){// formatar lista na tela
                    if(i == 0)
                        printf(" [");
                    printf("%d", vetor[i]);
                    if(i < tamanho - 1)
                        printf(", ");
                    if(i == tamanho - 1)
                        printf("]\n");
                }
                printf("\n");

                system("pause");
                printf("========== AGUARDE ==========\n");
                sleep(1);
                system("cls");


                break;
            case 4:
                printf("========= VOLTANDO =========\n");
                sleep(1);
                system("cls");
                break;
            default:
                printf("=============================\n");
                printf("======OPERAÇÃO INVALIDA======\n");
                printf("=============================\n");
                system("cls");
                break;

        }

    }while(selecioneOperacao != 4);

}

void heapsort(int selecioneOperacao){
    int tamanho, selecioneMetodo;

    printf("Qual é o tamanho da lista que deseja:");//digitar o tamanho da lista
    scanf("%d", &tamanho);

    int vetor[tamanho], aleatorio[tamanho];

    srand(time(NULL));//gerar numeros aleatorios em função do horario

    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100; //numeros de 0 ate 100
        aleatorio[i] = vetor[i];
    }

    do{

        printf("\n Sua lista:\n");

        for(int i = 0; i < tamanho; i++){// formatar lista na tela
            if(i == 0)
                printf(" [");
            printf("%d", vetor[i]);
            if(i < tamanho - 1)
                printf(", ");
            if(i == tamanho - 1)
                printf("]\n");
        }
    printf("\n");

        //menu do heapsort
        printf("|------------------------------------------------|\n");
        printf("| Olá, o Heapsort é um algoritmo generalista     |\n");
        printf("| que ordena os elementos à medida que os insere |\n");
        printf("|------------------------------------------------|\n");
        printf("| 1.Crescente                                    |\n");
        printf("| 2.Decrescente                                  |\n");
        printf("| 3.Aleatório                                    |\n");
        printf("| 4.Voltar                                       |\n");
        printf("|------------------------------------------------|\n");
        printf(" Selecione a operação: ");
        scanf("%d", &selecioneOperacao);
        printf("\n");

        switch(selecioneOperacao){
            case 1:
                //metodo crescente
                printf("|------------------------|\n");
                printf("| Deseja qual método:    |\n");
                printf("|------------------------|\n");
                printf("| 1.Passo a Passo        |\n");
                printf("| 2.Resultado final      |\n");
                printf("| 3.Voltar               |\n");
                printf("|------------------------|\n");
                printf(" Selecione a operação: ");
                scanf("%d", &selecioneMetodo);
                printf("\n");

                switch(selecioneMetodo){
                    case 1:
                        //metodo passo a passo
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        //resultado final da lista ordenada
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        printf("========= VOLTANDO =========\n");
                        sleep(1);
                        system("cls");
                        break;
                    default:
                        printf("=============================\n");
                        printf("===== OPERAÇÃO INVÁLIDA =====\n");
                        printf("=============================\n");
                        system("cls");
                        break;
                    }
                break;
            case 2:
                //metodo decrescente
                printf("|------------------------|\n");
                printf("| Deseja qual método:    |\n");
                printf("|------------------------|\n");
                printf("| 1.Passo a Passo        |\n");
                printf("| 2.Resultado final      |\n");
                printf("| 3.Voltar               |\n");
                printf("|------------------------|\n");
                printf(" Selecione a operação: ");
                scanf("%d", &selecioneMetodo);
                printf("\n");

                switch(selecioneMetodo){
                    case 1:
                        //metodo passo a passo
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        //resultado final da lista ordenada
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        printf("========= VOLTANDO =========\n");
                        sleep(1);
                        system("cls");
                        break;
                    default:
                        printf("=============================\n");
                        printf("===== OPERAÇÃO INVÁLIDA =====\n");
                        printf("=============================\n");
                        system("cls");
                        break;
                    }
                break;
            case 3:
                //aparecer a lista aleatoria

                for(int i = 0; i < tamanho; i++){
                    vetor[i] = aleatorio[i];
                }

                printf("\n Sua lista aleatoria:\n");

                for(int i = 0; i < tamanho; i++){// formatar lista na tela
                    if(i == 0)
                        printf(" [");
                    printf("%d", vetor[i]);
                    if(i < tamanho - 1)
                        printf(", ");
                    if(i == tamanho - 1)
                        printf("]\n");
                }
                printf("\n");

                system("pause");
                printf("========== AGUARDE ==========\n");
                sleep(1);
                system("cls");

                break;
            case 4:
                //voltar para o menu principal
                printf("========= VOLTANDO =========\n");
                sleep(1);
                system("cls");
                break;
            default:
                //erro na digitação
                printf("=============================\n");
                printf("===== OPERAÇÃO INVÁLIDA =====\n");
                printf("=============================\n");
                system("cls");
                break;
        }
    }while(selecioneOperacao != 4);
}

int divisaoCrescente(int vetor[], int primeiro, int ultimo) {
    int temp;

    int cabeca = vetor[ultimo];
    int i = primeiro - 1;

    for(int j = primeiro; j <= ultimo - 1; j++) { // Correção no loop
        if(vetor[j] <= cabeca) {
            i++;
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    temp = vetor[i + 1];
    vetor[i + 1] = vetor[ultimo];
    vetor[ultimo] = temp;

    return i + 1;
}

void funcaoQuicksortCrescente(int vetor[], int primeiro, int ultimo) {
    if(primeiro < ultimo) {

        int indiceCabeca = divisaoCrescente(vetor, primeiro, ultimo);
        funcaoQuicksortCrescente(vetor, primeiro, indiceCabeca - 1);
        funcaoQuicksortCrescente(vetor, indiceCabeca + 1, ultimo);

    }
}

void funcaoQuicksortCrescentePassos(int vetor[], int primeiro, int ultimo) {
    if(primeiro < ultimo) {
    int indiceCabeca = divisaoCrescente(vetor, primeiro, ultimo);

    for(int i = 0; i < tamanho; i++){// formatar lista na tela
        if(i == 0)
            printf(" [");
        printf("%d", vetor[i]);
        if(i < tamanho - 1)
            printf(", ");
        if(i == tamanho - 1)
            printf("]\n");
    }

    funcaoQuicksortCrescentePassos(vetor, primeiro, indiceCabeca - 1);
    funcaoQuicksortCrescentePassos(vetor, indiceCabeca + 1, ultimo);

    }
}

int divisaoDecrescente(int vetor[], int primeiro, int ultimo) {
    int temp;

    int cabeca = vetor[ultimo];
    int i = primeiro - 1;

    for(int j = primeiro; j <= ultimo - 1; j++) {
        if(vetor[j] >= cabeca) {
            i++;
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    temp = vetor[i + 1];
    vetor[i + 1] = vetor[ultimo];
    vetor[ultimo] = temp;

    return i + 1;
}

void funcaoQuicksortDecrescente(int vetor[], int primeiro, int ultimo) {
    if(primeiro < ultimo) {
        int indiceCabeca = divisaoDecrescente(vetor, primeiro, ultimo);
        funcaoQuicksortDecrescente(vetor, primeiro, indiceCabeca - 1);
        funcaoQuicksortDecrescente(vetor, indiceCabeca + 1, ultimo);
    }
}

void funcaoQuicksortDecrescentePassos(int vetor[], int primeiro, int ultimo) {

    if(primeiro < ultimo) {
        int indiceCabeca = divisaoDecrescente(vetor, primeiro, ultimo);

        printf("| %d <= %d? ", indiceCabeca, ultimo);
        interacao++;

        for(int i = 0; i < tamanho; i++){// formatar lista na tela

            if(i == 0)
                printf(" [");
            printf("%d", vetor[i]);
            if(i < tamanho - 1)
                printf(", ");
            if(i == tamanho - 1)
                printf("]   Interação %d\n", interacao);
        }

        funcaoQuicksortDecrescentePassos(vetor, primeiro, indiceCabeca - 1);
        funcaoQuicksortDecrescentePassos(vetor, indiceCabeca + 1, ultimo);
    }
}

void heapsortCrescente(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void heapify(int a[], int n, int i) {
    int menor = i;      // Inicializar o menor como a raiz
    int esquerda = 2 * i + 1; // Índice do filho esquerdo
    int direita = 2 * i + 2; // Índice do filho direito

    // Se o filho esquerdo for menor que o pai, atualize o menor
    if (esquerda < n && a[esquerda] < a[menor]) {
        menor = esquerda;
    }

    // Se o filho direito for menor que o pai, atualize o menor
    if (direita < n && a[direita] < a[menor]) {
        menor = direita;
    }

    // Se o menor não for a raiz, troque-os
    if (menor != i) {
        int temp = a[i];
        a[i] = a[menor];
        a[menor] = temp;

        // Chame heapify recursivamente no sub-árvore afetado
        heapify(a, n, menor);
    }
}

void heapsortDecrescente(int a[], int n) {
    // Construir um heap mínimo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Extrair elementos do heap e colocá-los na posição correta
    for (int i = n - 1; i >= 0; i--) {
        // Trocar o elemento raiz (mínimo) com o último elemento não ordenado
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Chamar heapify no heap reduzido
        heapify(a, i, 0);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int selecioneOperacao;

    do{
        printf("=============================\n");
        printf("=========== LISTAS ==========\n");
        printf("=============================\n");
        printf("\n");
        printf("|---------------------------|\n");
        printf("| 1.Quicksort               |\n");
        printf("| 2.Heapsort                |\n");
        printf("| 3.Sair                    |\n");
        printf("|---------------------------|\n");
        printf(" Selecione a operação: ");
        scanf("%d", &selecioneOperacao);
        printf("\n");
        printf("========== AGUARDE ==========\n");
        sleep(1);

        switch(selecioneOperacao){
            case 1:
                //metodo quicksort
                system("cls");
                quicksort(selecioneOperacao);
                break;
            case 2:
                //metodo heapsort
                system("cls");
                heapsort(selecioneOperacao);
                break;
            case 3:
                //saida do programa
                system("cls");
                printf("\n========== SAINDO. ===========\n");
                sleep(1);
                system("cls");
                printf("\n========== SAINDO.. ==========\n");
                sleep(1);
                system("cls");
                printf("\n========== SAINDO... =========\n");

                sleep(1);
                printf("\n==============================\n");
                printf("===== SISTEMA ENCERRANDO =======\n");
                printf("================================\n");
                break;
            default:
                //erro ao digitar
                printf("================================\n");
                printf("======= OPERAÇÃO INVÁLIDA ======\n");
                printf("================================\n");
                system("cls");

        }
    }while(selecioneOperacao != 3);

    return 0;
}
