#ifndef VIAGEM_H
#define VIAGEM_H

#include "passageiro.h"
#include "estacao.h"

typedef struct _viagem {
  passageiro *passenger;
  estacao *origem;
  estacao *destino;
  int codEstacaoDestino;
  int codEstacaoOrigem;
  int numIdentificacao;
  char dataViagem;
  char trip;
} viagem;

typedef struct _listaViagens {
  viagem **viagens;
  int size;
  int capacity;
  char trip;  
} listaViagens;

// Protótipos
listaViagens *criaListaViagens(int capacity);
void addViagem(listaViagens *list, viagem *trip);
void destroiListaViagens(listaViagens *list);
void showViagens(listaViagens *list);

#endif
