#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include "paciente.h"

#define MAX_CIRCULAR 8


void fc_iniciar();
void fc_enfileirar(Paciente paciente);
Paciente fc_desenfileirar();
void fc_exibir();

#endif