#include <stdio.h>
#include "paciente.h"
#include "pilha.h"
#include "fila.h"
#include "fila_circular.h"

// funções do menu
static void cadastrar_paciente();
static void atender_paciente();
static void mostrar_pacientes();
static void transferir_paciente();
static void relatorios();

int main() {
    pilha_iniciar();
    fila_iniciar();
    fc_iniciar();

    int opcao;

    do {
        printf("\n=== HOSPITAL SIMULADO ===\n");
        printf("1. Cadastrar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar pacientes\n");
        printf("4. Transferir paciente\n");
        printf("5. Relatorios\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar_paciente(); 
                break;
            case 2: atender_paciente();   
                break;
            case 3: mostrar_pacientes();  
                break;
            case 4: transferir_paciente(); 
                break;
            case 5: relatorios();         
                break;
            case 0: printf("Encerrando sistema...\n"); 
                break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}


static void cadastrar_paciente(){
    Paciente p;

    printf("\n--- CADASTRO DE PACIENTE ---\n");

    printf("Nome: ");
    scanf(" %49[^\n]", p.nome); // lê nome com espaço

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Gravidade (1 a 5): ");
    scanf("%d", &p.gravidade);

    // gravidade 4 ou 5 vai direto para emergencia
    if (p.gravidade >= 4) {
        printf("Gravidade alta! Direcionando para Emergencia.\n");
        p.tipo = 1; // tipo 1 = emegencia
    } else {
        printf("Tipo de atendimento: \n");
        printf("1. Emergencia\n2. Consulta\n3. Exame\n");
        printf("Opcao: ");
        scanf("%d", &p.tipo);
    }

    switch (p.tipo) {
        case 1: pilha_empilhar(p);    
            break;

        case 2: fila_enfileirar(p);   
            break;

        case 3: fc_enfileirar(p);     
            break;

        default: 
            printf("Tipo invalido!\n");
    }
}

static void atender_paciente() {
    int opcao;
    Paciente p;
    printf("\n--- ATENDER PACIENTE ---\n");
    printf("1. Emergencia\n2. Consulta\n3. Exame\n");
    printf("Opcao: ");
    scanf("%d", &opcao);


    switch (opcao){
        case 1: p = pilha_desempilhar(); break;
        case 2: p = fila_desenfileirar(); break;
        case 3: p = fc_desenfileirar(); break;
        default: printf("Opcao invalida!\n"); return;
    }

    if (p.nome[0] != '\0') {  // checa se não é o paciente vazio
        printf("\n=== PACIENTE ATENDIDO ===\n");
        printf("Nome: %s\n", p.nome);
        printf("Idade: %d\n", p.idade);
        printf("Gravidade: %d\n", p.gravidade);
    }

}

static void mostrar_pacientes() {
    int opcao;
    printf("\n--- MOSTRAR PACIENTES ---\n");
    printf("1. Emergencia\n2. Consulta\n3. Exame\n4. Todos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: pilha_exibir(); break;
        case 2: fila_exibir(); break;
        case 3: fc_exibir(); break;
        case 4:
            pilha_exibir();
            fila_exibir();
            fc_exibir();
            break;
        default: printf("Opcao invalida!\n");
    }
}

static void transferir_paciente() {
    int origem, destino;
    printf("\n--- TRANSFERIR PACIENTE ---\n");
    printf("Origem:  1. Emergencia  2. Consulta  3. Exame\n");
    printf("Opcao: ");

    scanf("%d", &origem);

    Paciente p;

    switch (origem) {
        case 1: p = pilha_desempilhar(); break;
        case 2: p = fila_desenfileirar(); break;
        case 3: p = fc_desenfileirar();   break;
        default: printf("Opcao invalida!\n"); return;
    }

    if (p.nome[0] == '\0') return;  // setor estava vazio

    printf("Destino: 1. Emergencia  2. Consulta  3. Exame\n");
    printf("Opcao: ");
    scanf("%d", &destino);

    switch (destino) {
        case 1: pilha_empilhar(p);  break;
        case 2: fila_enfileirar(p); break;
        case 3: fc_enfileirar(p);   break;
        default: printf("Opcao invalida!\n");
    }
}

static void relatorios() {
    printf("\n=== RELATORIO GERAL ===\n");
    pilha_exibir();
    fila_exibir();
    fc_exibir();
}

