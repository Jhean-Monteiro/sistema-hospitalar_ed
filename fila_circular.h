#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include "paciente.h"

#define MAX_CIRCULAR 8

void fc_iniciar();
<<<<<<< HEAD
int fc_vazia();
int fc_cheia();
=======
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)
void fc_enfileirar(Paciente paciente);
Paciente fc_desenfileirar();
void fc_exibir();

#endif