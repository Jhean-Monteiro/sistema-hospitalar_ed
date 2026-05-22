#ifndef FILA_H
#define FILA_H

#include "paciente.h"

#define MAX_FILA 10


void fila_iniciar();
void fila_enfileirar(Paciente paciente);
Paciente fila_desenfileirar();
void fila_exibir();

#endif