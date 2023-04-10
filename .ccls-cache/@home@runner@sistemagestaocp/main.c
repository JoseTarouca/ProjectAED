#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaMenu() {
  printf("*****************************\n");
  printf("*****************************\n");
  printf("   Gestão Passageiros CP\n");
  printf("*****************************\n");
  printf("     ***Menu***\n");
  printf(" RP - Regista passageiro\n");
  printf("RE - Regista Estacao\n");
  printf("IB - incrementa brindes\n");
  printf("RV - Regista viagem\n");
  printf("EB - Escolha brindes\n");
  printf("CE - Consulta Estacao\n");
  printf("LP - Listagem Passageiros\n");
  printf("TB - Top brindes\n");
  printf("A - Ajuda\n");
  printf("S - Saida\n");
  printf("O que pretende fazer?\n");
};

void executaAdicionaPassageiro(listaPassageiros *lista) {

  passageiro *passenger = (passageiro *)malloc(sizeof(passageiro));

  printf("\nEmail:");
  scanf("%ms", &(passenger->email)); // Use %ms to allocate the correct amount
                                     // of memory for the string
  printf("\nNome:");
  scanf("%ms", &(passenger->nome));

  addPassenger(lista, passenger);

  printf("Passageiro criado com sucesso!");
  printf("\n o que pretende fazer?");
}

int main(void) {
  char comando[2];
  listaPassageiros *lista = criaListaPassageiros(100);

  // COMANDOS
  char saida[] = "S";
  char help[] = "A";
  char registaPassageiro[] = "RP";
  char registaEstacao[] = "RE";
  char registaViagem[] = "RV";
  char incrementaBrindes[] = "IB";
  char escolhaBrindes[] = "EB";
  char topBrindes[] = "TB";
  char consultaEstacao[] = "CE";
  char listaPassagerio[] = "LP";

  criaMenu();

  while (strcmp(comando, saida) != 0) {
    scanf(" %s", comando);

    if (!strcmp(registaPassageiro, comando)) {
      executaAdicionaPassageiro(lista);
    }

    else if (!strcmp(listaPassagerio, comando)) {
      showPassageiros(lista);
    }

    else if (!strcmp(registaEstacao, comando)) {
      // TODO
    }

    else if (!strcmp(consultaEstacao, comando)) {
      // TODO
    }

    else if (!strcmp(escolhaBrindes, comando)) {
      // TODO
    }

    else if (!strcmp(incrementaBrindes, comando)) {
      // TODO
    }

    else if (!strcmp(topBrindes, comando)) {
      // TODO
    }

    else if (!strcmp(registaViagem, comando)) {
      // TODO
    }

    else if (!strcmp(help, comando)) {
      criaMenu();
    } else {
      printf("****\n Comando invalido! \n****\n\n\n");
    }
  }
}