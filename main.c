#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Entidade.h"

int menu() {
    char s[30];
    int escolha;
    printf("\t\t\t\t\t\t SEJA BEM-VINDO\n");
    printf("\t\t\t\t***TABELA------------------------------HASH***\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\tMenu:\n");
    printf("\t\t[1] Inserir elementos na tabela\n");
    printf("\t\t[2] Remover elementos da tabela\n");
    printf("\t\t[3] Buscar elementos da tabela\n");
    printf("\t\t[4] Mostrar tabela\n");
    printf("\t\t[5] Sair\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");


    do {
        printf("\tEntre com sua escolha: ");
        fflush(stdin);
        gets (s);
        escolha = atoi(s);
    } while (escolha < 1 || escolha > 5);

return escolha;
}




int main()
{           setlocale(LC_ALL,"");
    int escolha;
    char flag = '0';
    int chave;
    elemento *elem;
    //tab tabela;

    inicializa_tabela();

        do {

        escolha = menu();

        switch (escolha) {
            case 1:
                inserir();
                //printf("\tInserindo elementos\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("\n\tDigite a chave que deseja excluir: ");
                scanf("%d", &chave);
                elem = excluir_elemento(chave);

                if (elem) {
                    printf("\n\t***Elemento removido com sucesso!***");
                    printf("\n\tChave: %d \tValor: %.2f\n", elem->chave, elem->valor);
                } else {
                    printf("\n\tChave não encontrada.\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                 printf("\n\tDigite a chave do elemento que deseja buscar: ");
                scanf("%d", &chave);
                elem = buscar(chave);

                if (elem) {
                    printf("\n\tChave: %d \tValor: %.2f\n", elem->chave, elem->valor);
                } else {
                    printf("\n\tChave não encontrada.\n");
                }
                system("pause");
                system("cls");
                break;
            case 4:
                mostrar_tabela();
                //printf("\tMostrando elementos\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\tEncerrando...\n");
                exit(0);
                break;
        }

    } while (flag == '0');
    return 0;
}


















