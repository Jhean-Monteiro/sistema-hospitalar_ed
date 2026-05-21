#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

#define MAX_PILHA 10


// declaração das funções
void pilha_iniciar();
void pilha_empilhar(Paciente paciente);
Paciente pilha_desempilhar();
void pilha_exibir();

#endif