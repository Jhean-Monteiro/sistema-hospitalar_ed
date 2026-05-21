#ifndef FILA_H
#define FILA_H

#include "paciente.h"

#define MAX_FILA 10

void fila_iniciar();
<<<<<<< HEAD
int fila_vazia();
int fila_cheia();
=======
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)
void fila_enfileirar(Paciente paciente);
Paciente fila_desenfileirar();
void fila_exibir();

#endif