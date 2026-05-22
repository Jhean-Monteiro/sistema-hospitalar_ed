#include <stdio.h>
#include "fila_circular.h"


// FILA DO EXAME


Paciente fc[MAX_CIRCULAR];
static int frente = -1;
static int tras = -1;

void fc_iniciar(){
    frente = -1;
    tras = -1;
}

<<<<<<< HEAD
int fc_vazia() {
    return frente == -1;
}

int fc_cheia() {
=======
static int fc_vazia() {
    return frente == -1;
}

static int fc_cheia() {
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)
    return frente == (tras + 1) % MAX_CIRCULAR;
}

void fc_enfileirar(Paciente paciente){
    if(fc_cheia()){
        printf("Fila de exames cheia! removendo o paciente mais antigo: %s\n", fc[frente].nome);
        frente = (frente + 1) % MAX_CIRCULAR; // 
    }

    if (fc_vazia()){
        frente = 0;
    }

    tras = (tras + 1) % MAX_CIRCULAR;
    fc[tras] = paciente;
    printf("Paciente %s adicionado a fila de exames.\n", paciente.nome);

}

Paciente fc_desenfileirar(){
    Paciente vazio = {"", 0, 0, 0};
    if (fc_vazia()){
        printf("Nenhum paciente na fila de exames!\n");
        return vazio;
    }

    Paciente atendido = fc[frente];
    printf("Paciente %s foi atendido\n", atendido.nome);

    if (frente == tras) { // era o último elemento
        frente = -1;
        tras = -1;
    } else {
        frente = (frente + 1) % MAX_CIRCULAR;
    }

    return atendido;
}

void fc_exibir() {
    if (fc_vazia()) {
<<<<<<< HEAD
        printf("Erro: Nenhum paciente na fila de exames!\n");
=======
        printf("Erro: Nenhum paciente para exibir!\n");
>>>>>>> 2bc80a5 (adicionado static em funções utilizadas apenas em um arquivo e retiradas as mesmas dos arquivos de cabeçalho)
        return;
    }

    printf("=== EXAMES (primeiro -> ultimo) ===\n");

    int i = frente;
    while (i != tras) {
        printf("Nome: %s / Idade: %d / Gravidade: %d\n", fc[i].nome, fc[i].idade, fc[i].gravidade);

        i = (i+1) % MAX_CIRCULAR;
    }

    // imprime o ultimo
    printf("Nome: %s / Idade: %d / Gravidade: %d\n",
        fc[tras].nome, fc[tras].idade, fc[tras].gravidade);
}