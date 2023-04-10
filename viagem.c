#include "viagem.h"
#include <stdio.h>
#include <stdlib.h>

listaViagens *criaListaViagens(int capacity) {
  listaViagens *list = (listaViagens *)malloc(sizeof(listaViagens));
  if (list == NULL) {
    return NULL;
  }
  list->viagens = (viagem **)malloc(capacity * sizeof(viagem *));
  if (list->viagens != NULL) {
    list->size = 0;
    list->capacity = capacity;
  } else {
    free(list);
    return NULL;
  }
  return list;
}

void destroiListaViagens(listaViagens *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->viagens[i]);
  }
  free(list->viagens);
  free(list);
}

void addViagem(listaViagens *list, viagem *trip) {
  if (list->size == list->capacity) {
    printf("A lista de viagens está cheia.\n");
    return;
  }
  list->viagens[list->size++] = trip;
}

void showViagens(listaViagens *list) {
  printf("Lista de viagens:\n");
  for (int i = 0; i < list->size; i++) {
    printf("%s (%s) viajou de %s para %s\n", list->viagens[i]->passenger->nome, list->viagens[i]->passenger->email, list->viagens[i]->origem->nome, list->viagens[i]->destino->nome);
  }
}
