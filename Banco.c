#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[100];
    int numero;
    float saldo;
} conta;

typedef struct{
    char nome[100];
    int numero;
    float saldo;
} Temp;

void cadastro(conta Contas[], int quantidadeContas) {

    int numeroConta;
    int voltar = 0;
    FILE *arq;

    arq = fopen("banco.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    while (1) {
        printf("Digite o numero da conta: ");
        scanf("%d", &numeroConta);
        voltar = 0;

        if (numeroConta > 99999 || numeroConta < 0) {
                printf("\n|-------------------------------------|\n");
                printf("| Numero invalido, digite novamente   |\n");
                printf("|-------------------------------------|\n");
                voltar = 1;
                break;
            }

        if (voltar == 0) {
            Contas[quantidadeContas].numero = numeroConta;
            printf("Digite o nome da conta:");
            getchar();
            fgets(Contas[quantidadeContas].nome, 100, stdin);
            printf("Digite o valor do seu saldo:");
            scanf("%f", &Contas[quantidadeContas].saldo);

            fwrite(&Contas[quantidadeContas], sizeof(conta), 1, arq);
            printf("\n");

            fclose(arq);
            break;
        }
    }
}

void listar() {
    FILE *arq;
    conta ct;

    arq = fopen("banco.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    printf("|-----------------------|\n");
    while (fread(&ct, sizeof(conta), 1, arq) == 1) {
        printf("| Nome: %s", ct.nome);
        printf("| Conta: %d\n", ct.numero);
        printf("| Saldo: %.2f\n", ct.saldo);
        printf("|-----------------------|\n");
    }
    fclose(arq);
    system("pause");
    system("cls");
}

void selecao(int quantidadeContas, conta Contas[]){
    FILE *arq;
    int i = 0, maior, comparador = 0, movimento = 0;
    conta Temp;

    arq = fopen("banco.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    while (fread(&Contas[i], sizeof(conta), 1, arq) == 1) {
        i++;
    }

    fclose(arq);

    time_t begin = time(NULL);
    for (int j = 0; j < i - 1; j++) {
        maior = j;
        for(int k = j + 1; k < i; k++){
            if(Contas[k].saldo > Contas[maior].saldo)
                maior = k;
                comparador++;
            if(j != maior){
                Temp = Contas[j];
                Contas[j] = Contas[maior];
                Contas[maior] = Temp;
                movimento++;
            }
        }
    }
    time_t end = time(NULL);

    printf("|-----------------------|\n");
    printf("|     Lista ordenada    |\n");
    printf("|-----------------------|\n");
    for(int j = 0; j < i; j++){
        printf("| Nome: %s", Contas[j].nome);
        printf("| Conta: %d\n", Contas[j].numero);
        printf("| Saldo: %.2f\n", Contas[j].saldo);
        printf("|-----------------------|\n");
    }
    printf("|      Estatistica      |\n");
    printf("|-----------------------|\n");
    printf("| Comparacoes: %d\n", comparador);
    printf("| Movimentos: %d\n", movimento);
    printf("| Tempo percorrido: %d\n", (end - begin));
    printf("|-----------------------|\n");
    system("pause");
    system("cls");

}

void insercao(int quantidadeContas, conta Contas[]){

    int i = 0, j = 0, maior, comparador = 0, movimento = 0;
    conta Temp;

    FILE *arq;

    arq = fopen("banco.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

    while (fread(&Contas[i], sizeof(conta), 1, arq) == 1) {
        i++;
    }

    fclose(arq);

    time_t begin = time(NULL);
    for (int k = 1; k <= 15 - 1; k++){
      Temp = Contas[k];
      j = k - 1;
      comparador++;

      while (j >= 0 && Temp.saldo > Contas[j].saldo) {

         Contas[j + 1] = Contas[j];
         j--;
         movimento++;
      }

      Contas[j+1] = Temp;
      movimento++;
   }

   time_t end = time(NULL);

    printf("|-----------------------|\n");
    printf("|     Lista ordenada    |\n");
    printf("|-----------------------|\n");
    for(int index = 0; index < i; index++){
        printf("| Nome: %s", Contas[index].nome);
        printf("| Conta: %d\n", Contas[index].numero);
        printf("| Saldo: %.2f\n", Contas[index].saldo);
        printf("|-----------------------|\n");
    }
    printf("|      Estatistica      |\n");
    printf("|-----------------------|\n");
    printf("| Comparacoes: %d\n", comparador);
    printf("| Movimentos: %d\n", movimento);
    printf("| Tempo percorrido: %d\n", (end - begin));
    printf("|-----------------------|\n");
    system("pause");
    system("cls");
}

int main() {
    int selecioneOperacao, ordenacao;
    int quantidadeContas = 0;
    conta Contas[15];

    for(int i = 0; i < 15; i++){
        Contas[i].nome[100] = "";
        Contas[i].numero = 0;
        Contas[i].saldo = 0.0;
    }

    do {
        printf("=============================\n");
        printf("=========== BANCO ===========\n");
        printf("=============================\n");
        printf("\n");
        printf("|---------------------------|\n");
        printf("| 1.Cadastrar conta         |\n");
        printf("| 2.Ordenar conta           |\n");
        printf("| 3.Listar contas           |\n");
        printf("| 4.Sair                    |\n");
        printf("|---------------------------|\n");
        printf("Selecione a operacao:");
        scanf("%d", &selecioneOperacao);
        printf("\n");

        switch (selecioneOperacao) {
            case 1:
                if (quantidadeContas < 15) {
                    cadastro(Contas, quantidadeContas);
                    printf("=============================\n");
                    printf("=======CONTA CADASTRADA======\n");
                    printf("=============================\n");
                    system("pause");
                    system("cls");
                    ++quantidadeContas;
                } else {
                    printf("=============================\n");
                    printf("=======LIMITE ALCANCADO======\n");
                    printf("=============================\n");
                }
                break;
            case 2:

                do{
                    printf("|---------------------------|\n");
                    printf("|  Selecione sua ordenacao  |\n");
                    printf("|---------------------------|\n");
                    printf("| 1.Ordenacao por selecao   |\n");
                    printf("| 2.Ordenacao por insercao  |\n");
                    printf("| 3.voltar                  |\n");
                    printf("|---------------------------|\n");
                    printf("Selecione a operacao:");
                    scanf("%d", &ordenacao);
                    printf("\n");

                    switch(ordenacao){
                    case 1:
                        selecao(quantidadeContas, Contas);
                        break;
                    case 2:
                        insercao(quantidadeContas, Contas);
                        break;
                    case 3:
                        printf("======== VOLTANDO... ========\n");
                        sleep(2);
                        system("cls");
                        break;
                    default:
                        printf("=============================\n");
                        printf("======OPERACAO INVALIDA======\n");
                        printf("=============================\n");
                        system("cls");
                        break;
                    }

                }while(ordenacao != 3);
                break;
            case 3:
                listar();
                break;
            case 4:
                printf("========= SAINDO... =========\n");
                sleep(2);
                break;
            default:
                printf("=============================\n");
                printf("======OPERACAO INVALIDA======\n");
                printf("=============================\n");
                system("cls");
            break;
        }
    } while (selecioneOperacao != 4);

    return 0;
}
