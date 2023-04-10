#include "estacao.h"
#include <stdio.h>
#include <stdlib.h>

listaEstacoes *criaListaEstacoes(int capacity) {
  listaEstacoes *list = (listaEstacoes *)malloc(sizeof(listaEstacoes));
  if (list == NULL) {
    return NULL;
  }
  list->estacoes = (estacao **)malloc(capacity * sizeof(estacao *));
  if (list->estacoes != NULL) {
    list->size = 0;
    list->capacity = capacity;
  } else {
    free(list);
    return NULL;
  }
  return list;
}
