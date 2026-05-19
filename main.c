#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "pilha.h"
#include "fila.h"
#include "fila_circular.h"

void cadastrar_paciente();
void atender_paciente();
void mostrar_pacientes();
void transferir_paciente();
void relatorios();
void teste_estresse();

int main() {
	srand(time(NULL));
	clock_t inicio, fim;
	double tempo_gasto;
	inicio = clock();
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
		printf("6. Teste de estresse\n");
		printf("0. Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			cadastrar_paciente();
			break;
		case 2:
			atender_paciente();
			break;
		case 3:
			mostrar_pacientes();
			break;
		case 4:
			transferir_paciente();
			break;
		case 5:
			relatorios();
			break;
		case 6:
			teste_estresse();
			break;
		case 0:
			printf("Encerrando sistema...\n");
			break;
		default:
			printf("Opcao invalida!\n");
		}
	} while (opcao != 0);

	fim = clock();
	tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %.4f segundos\n", tempo_gasto);
}

void cadastrar_paciente() {
	Paciente p;
	printf("\n--- CADASTRO DE PACIENTE ---\n");
	printf("Nome: ");
	scanf(" %49[^\n]", p.nome);
	printf("Idade: ");
	scanf("%d", &p.idade);
	printf("Gravidade (1 a 5): ");
	scanf("%d", &p.gravidade);
	if (p.gravidade >= 4) {
		printf("Gravidade alta! Direcionando para Emergencia.\n");
		p.tipo = 1;
	} else {
		printf("Tipo de atendimento: \n");
		printf("1. Emergencia\n2. Consulta\n3. Exame\n");
		printf("Opcao: ");
		scanf("%d", &p.tipo);
	}
	switch (p.tipo) {
	case 1:
		pilha_empilhar(p);
		break;
	case 2:
		fila_enfileirar(p);
		break;
	case 3:
		fc_enfileirar(p);
		break;
	default:
		printf("Tipo invalido!\n");
	}
}

void atender_paciente() {
	int opcao;
	Paciente p;
	printf("\n--- ATENDER PACIENTE ---\n");
	printf("1. Emergencia\n2. Consulta\n3. Exame\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	switch (opcao) {
	case 1:
		p = pilha_desempilhar();
		break;
	case 2:
		p = fila_desenfileirar();
		break;
	case 3:
		p = fc_desenfileirar();
		break;
	default:
		printf("Opcao invalida!\n");
		return;
	}
	if (p.nome[0] != '\0') {
		printf("\n=== PACIENTE ATENDIDO ===\n");
		printf("Nome: %s\n", p.nome);
		printf("Idade: %d\n", p.idade);
		printf("Gravidade: %d\n", p.gravidade);
	}
}

void mostrar_pacientes() {
	int opcao;
	printf("\n--- MOSTRAR PACIENTES ---\n");
	printf("1. Emergencia\n2. Consulta\n3. Exame\n4. Todos\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	switch (opcao) {
	case 1:
		pilha_exibir();
		break;
	case 2:
		fila_exibir();
		break;
	case 3:
		fc_exibir();
		break;
	case 4:
		pilha_exibir();
		fila_exibir();
		fc_exibir();
		break;
	default:
		printf("Opcao invalida!\n");
	}
}

void transferir_paciente() {
	int origem, destino;
	printf("\n--- TRANSFERIR PACIENTE ---\n");
	printf("Origem: 1. Emergencia 2. Consulta 3. Exame\n");
	printf("Opcao: ");
	scanf("%d", &origem);
	Paciente p;
	switch (origem) {
	case 1:
		p = pilha_desempilhar();
		break;
	case 2:
		p = fila_desenfileirar();
		break;
	case 3:
		p = fc_desenfileirar();
		break;
	default:
		printf("Opcao invalida!\n");
		return;
	}
	if (p.nome[0] == '\0') return;
	printf("Destino: 1. Emergencia 2. Consulta 3. Exame\n");
	printf("Opcao: ");
	scanf("%d", &destino);
	switch (destino) {
	case 1:
		pilha_empilhar(p);
		break;
	case 2:
		fila_enfileirar(p);
		break;
	case 3:
		fc_enfileirar(p);
		break;
	default:
		printf("Opcao invalida!\n");
	}
}

void relatorios() {
	printf("\n=== RELATORIO GERAL ===\n");
	pilha_exibir();
	fila_exibir();
	fc_exibir();
}

void teste_estresse() {
	int n;
	printf("\nQuantidade de operacoes: ");
	scanf("%d", &n);

 
	clock_t inicio = clock();
 
	for (int i = 0; i < n; i++) {
		Paciente p;
		snprintf(p.nome, MAX_NOME, "Paciente%d", i + 1);
		p.idade     = 1 + rand() % 99;
		p.gravidade = 1 + rand() % 5;
		p.tipo      = 1 + rand() % 3;
 
		// a cada 3 insercoes, remove 1 para nao deixar as estruturas travadas no limite
		if (i % 3 == 0) {
			switch (p.tipo) {
			case 1: if (!pilha_vazia()) pilha_desempilhar(); break;
			case 2: if (!fila_vazia())  fila_desenfileirar(); break;
			case 3: if (!fc_vazia())    fc_desenfileirar(); break;
			}
		} else {
			switch (p.tipo) {
			case 1: if (!pilha_cheia()) pilha_empilhar(p); break;
			case 2: if (!fila_cheia())  fila_enfileirar(p); break;
			case 3: fc_enfileirar(p); break;
			}
		}
	}
 
	clock_t fim = clock();
 
	double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("%d operacoes realizadas em %.4f segundos\n", n, tempo);
}