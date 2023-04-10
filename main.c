
#include "viagem.h"
#include "viagem.c"
#include "passageiro.h"
#include "passageiro.c"
#include "estacao.c"
#include "estacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaMenu() {
  printf("*****************************\n");
  printf("*****************************\n");
  printf("   Gestão Passageiros CP\n");
  printf("*****************************\n");
  printf("     ***Menu***\n");
  printf("RP - Regista passageiro\n");
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





//Registar os passageiros
void executaRP(listaPassageiros *lista) {
  // Aloca memória para uma nova estrutura passageiro
  passageiro *passenger = (passageiro *)malloc(sizeof(passageiro));

  // Abre o ficheiro "passengers.dat" em modo leitura binária
  FILE *fp;
  fp = fopen("passengers.dat", "rb");

  // Lê o email do passageiro a partir da entrada padrão
  printf("\nEmail:");
  scanf("%ms", &(passenger->email));

  // Verifica se o passageiro já foi registado anteriormente
  while (fread(passenger, sizeof(passageiro), 1, fp)) {
    if (strcmp(passenger->email, passenger->email) == 0) {
      printf("Passageiro ja anteriormente registado.");
      fclose(fp);
      return;
    }
  }

  // Fecha o ficheiro após a leitura
  fclose(fp);

  // Abre o ficheiro "passengers.dat" em modo escrita binária
  fp = fopen("passengers.dat", "ab");

  // Lê o nome do passageiro a partir da entrada padrão
  printf("\nNome:");
  scanf("%ms", &(passenger->nome));

  // Escreve a estrutura passageiro no ficheiro
  fwrite(passenger, sizeof(passageiro), 1, fp);

  // Adiciona o passageiro à lista de passageiros
  addPassenger(lista, passenger);

  // Imprime uma mensagem de sucesso e pergunta ao utilizador o que deseja fazer a seguir
  printf("Registo de passageiro bem sucedido!");
  printf("\nO que pretende fazer?");

  // Fecha o ficheiro após a escrita
  fclose(fp);
}

//Ler os Passageiros
void readPassengersFromFile(listaPassageiros *lista) {
  // abre o ficheiro "passengers.dat" em modo leitura binária
  FILE *fp;
  fp = fopen("passengers.dat", "rb");

  // verifica se o ficheiro foi aberto com sucesso
  if (fp == NULL) {
    printf("Nao foi possivel abrir o ficheiro!");
    return;
  }

  // aloca memória para uma nova estrutura passageiro
  passageiro *passenger = (passageiro *)malloc(sizeof(passageiro));

  // lê a estrutura passageiro do ficheiro e adiciona à lista de passageiros
  while (fread(passenger, sizeof(passageiro), 1, fp) == 1) {
    addPassenger(lista, passenger);

    // aloca memória para as strings de passageiro
    passenger->email = (char *)malloc((strlen(passenger->email) + 1) * sizeof(char));
    passenger->nome = (char *)malloc((strlen(passenger->nome) + 1) * sizeof(char));

    // copia os dados da estrutura passageiro para as strings alocadas
    strcpy(passenger->email, passenger->email);
    strcpy(passenger->nome, passenger->nome);

    // imprime os dados do passageiro
    printf("Email: %s\nNome: %s\n", passenger->email, passenger->nome);

    // aloca nova memória para a estrutura passageiro
    passenger = (passageiro *)malloc(sizeof(passageiro));
  }

  // fecha o arquivo após a leitura
  fclose(fp);
}

//Registar estações
void executaRE(listaEstacoes *lista) {
  int codigo;
  estacao *station = (estacao *)malloc(sizeof(estacao));
  station->nome = (char *)malloc(50 * sizeof(char));
  station->localidade = (char *)malloc(50 * sizeof(char));
  station->stockBrindes = 0;

  FILE *fp;

  // Abrir o ficheiro "estacoes.dat" em modo leitura binária
  fp = fopen("estacoes.dat", "rb");

  printf("\nCódigo da estação:");
  scanf("%d", &(station->codigo));

  // Verificar se a estação já foi registada anteriormente
  while (fread(station, sizeof(estacao), 1, fp)) {
    if (station->codigo == codigo) {
      printf("Estação já anteriormente registada.");

      // Fechar o ficheiro após a verificação
      fclose(fp);

      return;
    }
  }

  // Fechar o ficheiro após a leitura
  fclose(fp);

  // Abrir o ficheiro "estacoes.dat" em modo escrita binária
  fp = fopen("estacoes.dat", "ab");

  printf("\nNome da estação:");
  scanf(" %[^\n]", station->nome);

  printf("\nLocalidade:");
  scanf(" %[^\n]", station->localidade);

  printf("\nStock de brindes:");
  scanf("%d", &(station->stockBrindes));

  // Escrever a estrutura estacao no ficheiro
  fwrite(station, sizeof(estacao), 1, fp);

  // Adicionar a estação à lista de estações
  addEstacao(lista, station);

  printf("Registo de estação bem sucedido!");
  printf("\nO que pretende fazer?");

  // Fechar o ficheiro após a escrita
  fclose(fp);
}

//Ler as estações
void readEstacoesFromFile(listaEstacoes *lista) {
  FILE *fp;

  // abre o ficheiro estacoes.dat em modo de leitura binária
  fp = fopen("estacoes.dat", "rb");

  // verifica se o ficheiro foi aberto corretamente
  if (fp == NULL) {
    printf("Não foi possível abrir o ficheiro!");
    return;
  }

  // aloca memória para uma estrutura de estação
  estacao *station = (estacao *)malloc(sizeof(estacao));

  // lê uma estação de cada vez do ficheiro
  while (fread(station, sizeof(estacao), 1, fp) == 1) {
    // adiciona a estação lida à lista de estações
    addEstacao(lista, station);

    // aloca memória para as strings de nome e localidade da estação
    station->nome = (char *)malloc((strlen(station->nome) + 1) * sizeof(char));
    station->localidade = (char *)malloc((strlen(station->localidade) + 1) * sizeof(char));

    // copia os dados das strings da estação lida para as strings alocadas dinamicamente
    strncpy(station->nome, station->nome, 50);
    strncpy(station->localidade, station->localidade, 50);

    // imprime os dados da estação lida
    printf("Código: %d\nNome: %s\nLocalidade: %s\nStock de brindes: %d\n", station->codigo, station->nome, station->localidade, station->stockBrindes);

    // aloca memória para uma nova estrutura de estação
    station = (estacao *)malloc(sizeof(estacao));
  }

  // fecha o ficheiro
  fclose(fp);
}

//Registar viagem
void executaRV(listaPassageiros *lista, listaEstacoes *estacoes) {
  // aloca memória para os structs passageiro e viagem
  passageiro *passenger = (passageiro *)malloc(sizeof(passageiro));
  viagem *trip = (viagem *)malloc(sizeof(viagem));
  
  // lê o nome do passageiro
  printf("\nNome do passageiro:");
  scanf(" %[^\n]", passenger->nome);
  
  // lê o número de identificação do passageiro
  printf("\nNúmero de identificação:");
  scanf("%d", &(passenger->numIdentificacao));
  
  // lê o código da estação de origem da viagem
  printf("\nCódigo da estação de origem:");
  scanf("%d", &(trip->codEstacaoOrigem));
  
  // lê o código da estação de destino da viagem
  printf("\nCódigo da estação de destino:");
  scanf("%d", &(trip->codEstacaoDestino));  
  
  // busca o passageiro na lista de passageiros
  int index = buscaPassageiro(lista, passenger->numIdentificacao);
  if (index == -1) {
    printf("\nPassageiro não encontrado!");
    return;
  }
}

//Ler viagem
void readViagensFromFile(listaPassageiros *lista, listaEstacoes *estacoes) {
  FILE *fp;
  fp = fopen("viagens.dat", "rb");

  if (fp == NULL) {
    printf("Não foi possível abrir o ficheiro!");
    return;
  }

  viagem *trip = (viagem *)malloc(sizeof(viagem));

  while (fread(trip, sizeof(viagem), 1, fp) == 1) {
    // busca o passageiro na lista de passageiros
    int index = buscaPassageiro(lista, trip->numIdentificacao);
    if (index == -1) {
      printf("\nPassageiro não encontrado!");
      continue;
    }
    
    // busca as estações de origem e destino na lista de estações
    estacao *estOrigem = buscaEstacao(estacoes, trip->codEstacaoOrigem);
    estacao *estDestino = buscaEstacao(estacoes, trip->codEstacaoDestino);
    if (estOrigem == NULL || estDestino == NULL) {
      printf("\nEstação não encontrada!");
      continue;
    }
    
    // calcula o valor da viagem
    float valorViagem = calculaValorViagem(estOrigem, estDestino);
    
    // registra a viagem na lista de viagens do passageiro
    addViagemPassageiro(lista, index, trip, valorViagem);
  }

  fclose(fp);
}

//Escolha de brindes
void executaEB(listaPassageiros *lista) {
  int numPassageiro, numBrinde, MIN_VIAGENS_BRINDE = 10;

  // Recebe o número do passageiro
  printf("Insira o numero do passageiro: ");
  scanf("%d", &numPassageiro);

  // Procura o passageiro na lista
  passageiro *p = getPassageiro(lista, numPassageiro);
  if (p == NULL) {
    printf("Passageiro nao encontrado!\n");
    return;
  }

  // Verifica se o passageiro já realizou o número mínimo de viagens para ganhar um brinde
  if (p->numViagens < MIN_VIAGENS_BRINDE) {
    printf("Este passageiro ainda nao tem direito a um brinde!\n");
    return;
  }

  // Exibe as opções de brinde e recebe a escolha do usuário
  printf("Escolha um dos seguintes brindes:\n");
  printf("1 - Camiseta\n2 - Caneca\n3 - Chaveiro\n");
  scanf("%d", &numBrinde);

  // Seleciona o brinde correspondente à escolha do usuário
  switch (numBrinde) {
    case 1:
      strcpy(p->brinde, "Camiseta");
      break;
    case 2:
      strcpy(p->brinde, "Caneca");
      break;
    case 3:
      strcpy(p->brinde, "Chaveiro");
      break;
    default:
      printf("Opcao invalida!\n");
      return;
  }

  // Confirma a seleção do brinde
  printf("Brinde escolhido com sucesso!\n");
}


int main(void) {
  int estacoes;
  char comando[2];
  void executaEB(listaPassageiros *lista);
  listaPassageiros *lista = criaListaPassageiros(100);

  readPassengersFromFile(lista); // read passengers from file

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
      executaRP(lista);
    }

    else if (!strcmp(listaPassagerio, comando)) {
      showPassageiros(lista);
    }

    else if (!strcmp(registaEstacao, comando)) {
      executaRE(lista);
    }

    else if (!strcmp(consultaEstacao, comando)) {
      readEstacoesFromFile(lista);
    }

    else if (!strcmp(escolhaBrindes, comando)) {
      executaEB(lista);
    }

    else if (!strcmp(incrementaBrindes, comando)) {
      int codigoEstacao, quantidade;
  
      printf("\nCódigo da estação: ");
      scanf("%d", &codigoEstacao);
      
      estacao *est = buscaEstacao(estacoes, codigoEstacao);
  
      if (est == NULL) {
        printf("\nEstação não encontrada!");
      } else {
        printf("\nQuantidade de brindes a ser incrementada: ");
        scanf("%d", &quantidade);
        
        est->stockBrindes += quantidade;
        
        printf("\nStock de brindes atualizado com sucesso!");
      }
    }


    else if (!strcmp(topBrindes, comando)) {
      // executaRE(lista);
    }

    else if (!strcmp(registaViagem, comando)) {
    executaRV(lista, estacoes);
    }


    else if (!strcmp(help, comando)) {
      criaMenu();
    } else {
      printf("****\n Comando invalido! \n****\n\n\n");
    }
  }
}