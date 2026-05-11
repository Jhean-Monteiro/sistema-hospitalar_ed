#ifndef PACIENTE_H
#define PACIENTE_H

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
    int gravidade; // 1 a 5
    int tipo; // 1=Emergência, 2=Consulta, 3=Exame
} Paciente;

#endif