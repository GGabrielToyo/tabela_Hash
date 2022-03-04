#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"

 tab tabela;

void mostrar_tabela () {
    int i, j;
    int cont = 1;

        printf("\n-------------------------------TABELA----------------------------------------\n");
        for (i = 0; i < 13; i++) {
                printf("\t%dº LINHA\n", cont);
                printf("\t-----------\n");
                for (j = 0; j < 10; j++) {
                    if (tabela.linha[i].vet[j].chave != -1) {
                        printf("\t%dº COLUNA ->|Chave:%d Valor:%.2f|\n", i + 1, tabela.linha[i].vet[j].chave , tabela.linha[i].vet[j].valor);
                    } else {
                        printf("\tVazio\n");
                    }
                }
                printf("\n");
                cont++;
        }
        printf("\n----------------------------------------------------------------------------\n");

return 0;
}

void inicializa_tabela (){// Inicializa a tabela com valor de chave -1
    int i, j;

    for (i = 0; i < 13; i++) {
        for (j = 0; j < 10; j++) {
            tabela.linha[i].vet[j].chave = -1;
        }
    }

return 0;
}

int gerar_codigo_hash_linha (int chave){ //Valor para as linhas da tabela de acordo com a chave
return chave % 13;
}

int gerar_codigo_hash_coluna (int chave) { //Valor para as colunas da tabela de acordo com a chave
return chave % 10;
}

elemento ler_elemento () { //Lê chave e valor
    elemento lerElemento;

    printf("\n\tEntre com chave: ");
    scanf("%d", &lerElemento.chave );
    printf("\n\tEntre com o valor: ");
    scanf("%f", &lerElemento.valor);

return lerElemento;
}

void inserir () { // Insere os elemento lidos
    elemento elem;
    int indiceL; //Indice linha
    int indiceC; //Indice coluna

    elem = ler_elemento(); //Recebe chave e valor do elemento
    indiceL = gerar_codigo_hash_linha(elem.chave); // Gera a linha
    indiceC = gerar_codigo_hash_coluna(elem.chave);// Gera a coluna

    while (tabela.linha[indiceL].vet[indiceC].chave != -1) { // Se a chave for -1 significa que espaço está vazio e então sai do while
        indiceL = gerar_codigo_hash_linha(indiceL + 1); // soma 1 ao indeice atual e gera outra
        indiceC = gerar_codigo_hash_coluna(indiceC + 1); // soma 1 ao indeice atual e gera outro
    }

    tabela.linha[indiceL].vet[indiceC] = elem; // Insere elemento

return 0;
}

elemento* buscar (int chave) { //Ponteiro para buscar um elemento tendo como parametro a chave
    int indiceL = gerar_codigo_hash_linha(chave); //Gera linha
    int indiceC = gerar_codigo_hash_coluna(chave);// Gera coluna

    while (tabela.linha[indiceL].vet[indiceC].chave != -1) {// se chave for igual a -1 está vazio
        if (tabela.linha[indiceL].vet[indiceC].chave == chave) { //Verefica se chave do elemento é igual a chave que foi buscada
            return &tabela.linha[indiceL].vet[indiceC];
        } else {
            indiceL = gerar_codigo_hash_linha(indiceL + 1);// soma 1 ao indeice atual e gera outra
            indiceC = gerar_codigo_hash_coluna(indiceC + 1);// soma 1 ao indeice atual e gera outra
        }
    }

return  NULL;
}

elemento* excluir_elemento (int chave) {//Ponteiro para excluir um elemento tendo como parametro a chave
    int indiceL = gerar_codigo_hash_linha(chave);//Gera linha
    int indiceC = gerar_codigo_hash_coluna(chave);// Gera coluna

    while (tabela.linha[indiceL].vet[indiceC].chave != -1) {// se chave for igual a -1 está vazio
        if (tabela.linha[indiceL].vet[indiceC].chave == chave) {//Verefica se chave do elemento é igual a chave que foi buscada para a exclusão
             tabela.linha[indiceL].vet[indiceC].chave = -1;//Se encontrar a chave, ele atribui -1 retornando ao ponto inicial onde todas as chaves são -1
             tabela.linha[indiceL].vet[indiceC].valor = 0;//Valor recebe 0
            return &tabela.linha[indiceL].vet[indiceC];
        } else {
            indiceL = gerar_codigo_hash_linha(indiceL + 1);// soma 1 ao indeice atual e gera outra
            indiceC = gerar_codigo_hash_coluna(indiceC + 1);// soma 1 ao indeice atual e gera outra
        }
    }
return NULL;
}


