#ifndef H_PASSAGEIRO
#define H_PASSAGEIRO

typedef struct _passageiro {
  char *email;
  char *nome;
  int *numIdentificacao;
  int *numViagens;
  char brinde;
} passageiro;

// Usamos um duplo apontador: um apontador para uma alocação dinamica de arrays
typedef struct _listaPassageiro {
  passageiro **passengers;
  int size;
  int capacity;
} listaPassageiros;

// Prototipos
listaPassageiros *criaListaPassageiros(int capacity);
void addPassenger(listaPassageiros *list, passageiro *passenger);
void destroiListaPassageiros(listaPassageiros *list);
void showPassageiros(listaPassageiros *list);

#endif