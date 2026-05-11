// Pilha de emergencia
#include <stdio.h>
#include "pilha.h"


Paciente pilha[MAX_PILHA]; // vetor que representa a pilha
static int topo = -1;

void pilha_iniciar() {
    topo = -1;
}

int pilha_vazia(){
    return topo == -1;
}

int pilha_cheia(){
    return topo == MAX_PILHA -1;
}

void pilha_empilhar(Paciente paciente){
    if (pilha_cheia()){
        printf("Emergência cheia!\n");
        return;
    }
    topo++;
    pilha[topo] = paciente;
    printf("Paciente %s encaminhado para Emergência.\n", paciente.nome);
}

Paciente pilha_desempilhar(){
    Paciente vazio = {"", 0, 0, 0};
    if(pilha_vazia()){
        printf("Não há ninguém para remover.\n");
        return vazio;
    }
    Paciente atendido = pilha[topo];
    topo--;
    return atendido;
}

void pilha_exibir(){
    if(pilha_vazia()){
        printf("Não há ninguém na Emergência.\n");
        return;
    }
    printf("== EMERGÊNCIA: (topo -> base) ===\n");
    for (int i = topo; i >= 0; i--) {
        printf("Nome: %s / Idade: %d / Gravidade: %d\n", pilha[i].nome, pilha[i].idade, pilha[i].gravidade);
    }
}