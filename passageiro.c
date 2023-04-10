#include "passageiro.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Cria uma nova lista de passageiros dada uma capacidade inicial
 * Retorna um apontador para a nova lista se tudo correr bem, ou NULL se a
 * alocação de memoria falhar
 *
 * @param capacity capacidade inicial do numero de passageiros
 * @return A pointer to the new PassengerList, or NULL if memory allocation
 * failed.
 */
listaPassageiros *criaListaPassageiros(int capacity) {
  listaPassageiros *list = (listaPassageiros *)malloc(sizeof(listaPassageiros));
  if (list == NULL) {
    return NULL;
  }
  list->passengers = (passageiro **)malloc(capacity * sizeof(passageiro *));
  if (list->passengers != NULL) {
    list->size = 0;
    list->capacity = capacity;
  } else {
    free(list);
    return NULL;
  }
  return list;
}

/**
 * Destroi a lista de passageiros libertando a memoria reservada
 * bem como a memoria de cada elemento da lista
 *
 * @param apontador para a lista de passageiros
 * @return null
 */
void destroiListaPassageiros(listaPassageiros *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->passengers[i]->nome);
    free(list->passengers[i]);
  }
  free(list->passengers);
  free(list);
}

/**
 * Adiciona um novo passageiro a lista
 * Se a lista tiver na sua capacidade maxima impede de adicionar
 *
 * @param apontador para a lista de passagerios, e um apontador para o
 * passageiro a adicionar
 * @return null
 */
void addPassenger(listaPassageiros *list, passageiro *passenger) {
  if (list->size == list->capacity) {
    printf("a lista esta cheia");
  }
  list->passengers[list->size++] = passenger;
}

/**
 * Lista todos os elementos da lista
 *
 * @param apontador para a lista de passageiros
 * @return null
 */
void showPassageiros(listaPassageiros *list) {
  printf("Passenger list:\n");
  for (int i = 0; i < list->size; i++) {
    printf("%s (%s)\n", list->passengers[i]->nome, list->passengers[i]->email);
  }
}