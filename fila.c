#include <stdio.h>
#include "fila.h"

<<<<<<< HEAD
// FILA DE CONSULTAS
=======
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)

Paciente fila[MAX_FILA];
static int frente = 0; // começa de zero na fila linear
static int tras = -1;

void fila_iniciar() {
    frente = 0;
    tras = -1;
}

<<<<<<< HEAD
int fila_vazia(){
    return frente > tras;
}

int fila_cheia() {
=======
static int fila_vazia(){
    return frente > tras;
}

static int fila_cheia() {
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)
    return tras == MAX_FILA -1;
}

void fila_enfileirar(Paciente paciente) {
    if(fila_cheia()){
        printf("Erro: Fila de consultas cheia!\n");
        return;
    }
    tras++;
    fila[tras] = paciente;
    printf("Paciente %s adicionado à fila de consultas.\n", paciente.nome);
}

Paciente fila_desenfileirar() {
    Paciente vazio = {"",0,0,0};
    if (fila_vazia()){
        printf("não existe paciente para desenfileirar.\n");
        return vazio;
    }

    Paciente atendido = fila[frente];
    frente++; // espaço anterior é 'perdido'
    return atendido;
}

void fila_exibir() {
    if (fila_vazia()){
<<<<<<< HEAD
        printf("não existe paciente na fila de consultas.\n");
=======
        printf("não existe paciente para exibir.\n");
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)
        return;
    }

    printf("=== CONSULTAS (primeiro -> ultimo) ===\n");
    for (int i = frente; i <= tras; i++) {
        printf("Nome: %s / Idade: %d / Gravidade: %d\n", fila[i].nome, fila[i].idade, fila[i].gravidade);
    }
}