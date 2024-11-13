#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Definindo a estrutura para uma tarefa
typedef struct Tarefa {
    char descricao[100];
    int xp;
    int tempo; // Tempo dedicado à tarefa em minutos
    struct Tarefa* proximo;  // Ponteiro para a próxima tarefa
} Tarefa;

// Estruturas para fila e pilha
typedef struct Fila {
    Tarefa* frente;
    Tarefa* traseira;
} Fila;

typedef struct Pilha {
    Tarefa* topo;
} Pilha;

// Funções para manipulação da fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = fila->traseira = NULL;
    return fila;
}

void adicionarTarefaFila(Fila* fila, char* descricao, int xp, int tempo) {
    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->xp = xp;
    novaTarefa->tempo = tempo;
    novaTarefa->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = fila->traseira = novaTarefa;
        return;
    }

    fila->traseira->proximo = novaTarefa;
    fila->traseira = novaTarefa;
}

void lerTarefas(Fila* fila) {
    char descricao[100];
    int xp, tempo;
    char continuar;

    do {
        printf("Digite a descrição da tarefa: ");
        fgets(descricao, sizeof(descricao), stdin);
        descricao[strcspn(descricao, "\n")] = '\0'; // Remover o newline

        printf("Digite o XP da tarefa: ");
        scanf("%d", &xp);

        printf("Digite o tempo dedicado à tarefa (em minutos): ");
        scanf("%d", &tempo);

        adicionarTarefaFila(fila, descricao, xp, tempo);

        printf("Deseja adicionar outra tarefa? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpar o buffer do newline
    } while (continuar == 's' || continuar == 'S');
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Fila* minhaFila = criarFila();
    lerTarefas(minhaFila);

    // Exemplo de como percorrer e imprimir as tarefas na fila
    Tarefa* atual = minhaFila->frente;
    while (atual != NULL) {
         printf("\n\n");
        printf("Tarefa: %s, XP: %d, Tempo: %d minutos\n", atual->descricao, atual->xp, atual->tempo);
        printf("\n\n");
        atual = atual->proximo;
    }

    return 0;
}