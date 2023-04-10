#ifndef H_ESTACAO
#define H_ESTACAO

typedef struct _estacao {
  char *email;
  char *nome;
} estacao;

typedef struct _listaEstacoes {
  estacao **estacoes;
  int size;
  int capacity;
} listaEstacoes;

// Prototipos
listaEstacoes *criaListaEstacoes(int capacity);

#endif