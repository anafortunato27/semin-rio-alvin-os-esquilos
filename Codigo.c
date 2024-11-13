#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Definindo a estrutura para uma tarefa
typedef struct Tarefa {
    char descricao[100];
    int xp;
    int tempoEstimado; // Tempo dedicado à tarefa em minutos
    int tempoReal;
    struct Tarefa* proximo;  // Ponteiro para a próxima tarefa
} Tarefa;

// Estruturas para fila de tarefas e lista de tarefas concluídas
typedef struct Fila {
    Tarefa* frente;
    Tarefa* traseira;
} Fila;

typedef struct ListaConcluidas {
    Tarefa* inicio;
} ListaConcluidas;

// Funções para manipulação da fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = fila->traseira = NULL;
    return fila;
}

ListaConcluidas* criarListaConcluidas() {
    ListaConcluidas* lista = (ListaConcluidas*)malloc(sizeof(ListaConcluidas));
    lista->inicio = NULL;
    return lista;
}

int verificarTarefaExistente(Fila* fila, char* descricao) {
    Tarefa* atual = fila->frente;
    while (atual != NULL) {
        if (strcmp(atual->descricao, descricao) == 0) {
            return 1; // Tarefa já existe
        }
        atual = atual->proximo;
    }
    return 0; // Tarefa não existe
}

void adicionarTarefaFila(Fila* fila, char* descricao, int tempoEstimado) {
    if (verificarTarefaExistente(fila, descricao)) {
        printf("Tarefa já existente! Não foi adicionada.\n");
        return;
    }

    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->xp = 0;
    novaTarefa->tempoEstimado = tempoEstimado;
    novaTarefa->tempoReal = 0;
    novaTarefa->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = fila->traseira = novaTarefa;
    } else {
        fila->traseira->proximo = novaTarefa;
        fila->traseira = novaTarefa;
    }
}

void lerTarefas(Fila* fila) {
    char descricao[100];
    int tempoEstimado;
    char continuar;

    do {
        printf("Digite a descrição da tarefa: ");
        fgets(descricao, sizeof(descricao), stdin);
        descricao[strcspn(descricao, "\n")] = '\0'; // Remover o newline

        printf("Digite o tempo estimado dedicado à tarefa (em minutos): ");
        scanf("%d", &tempoEstimado);
        getchar(); // Limpar o buffer

        adicionarTarefaFila(fila, descricao, tempoEstimado);

        printf("Deseja adicionar outra tarefa? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpar o buffer
    } while (continuar == 's' || continuar == 'S');
}

void exibirTarefas(Fila* fila) {
    Tarefa* atual = fila->frente;
    if (atual == NULL) {
        printf("Nenhuma tarefa pendente.\n");
        return;
    }

    printf("------------------------------------------------------------\n");
    printf("| Nº | Descrição                  | XP    | Tempo Estimado | Tempo Real      |\n");
    printf("------------------------------------------------------------\n");
    int i = 1;
    while (atual != NULL) {
        printf("| %-2d | %-25s | %-5d | %-13d | %-13d |\n", i++, atual->descricao, atual->xp, atual->tempoEstimado, atual->tempoReal);
        atual = atual->proximo;
    }
    printf("------------------------------------------------------------\n");
}

void concluirTarefa(Fila* fila, ListaConcluidas* concluidas, int* xpTotal) {
    if (fila->frente == NULL) {
        printf("Nenhuma tarefa para concluir.\n");
        return;
    }

    // Exibir tarefas com numeração
    exibirTarefas(fila);

    int numero;
    printf("Digite o número da tarefa que deseja marcar como concluída: ");
    scanf("%d", &numero);
    getchar();

    Tarefa *anterior = NULL, *atual = fila->frente;
    for (int i = 1; i < numero && atual != NULL; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Tarefa inválida.\n");
        return;
    }

    char resposta;
    printf("Concluiu o tempo estimado? (s/n): ");
    scanf(" %c", &resposta);
    getchar();

    if (resposta == 's' || resposta == 'S') {
        atual->tempoReal = atual->tempoEstimado;
    } else {
        printf("Digite o tempo real dedicado à tarefa (em minutos): ");
        scanf("%d", &atual->tempoReal);
        getchar();
    }

    atual->xp += atual->tempoReal / 10; // 1 XP a cada 10 minutos
    *xpTotal += atual->xp;

    // Remover tarefa da fila
    if (anterior == NULL) {
        fila->frente = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    if (fila->traseira == atual) {
        fila->traseira = anterior;
    }

    // Adicionar a tarefa concluída na lista de concluídas
    atual->proximo = concluidas->inicio;
    concluidas->inicio = atual;

    printf("Tarefa concluída!\n");
}

void exibirTarefasConcluidas(ListaConcluidas* concluidas) {
    Tarefa* atual = concluidas->inicio;
    if (atual == NULL) {
        printf("Nenhuma tarefa concluída.\n");
        return;
    }

    printf("------------------------------------------------------------\n");
    printf("| Descrição                    | XP    | Tempo Estimado  | Tempo Real      |\n");
    printf("------------------------------------------------------------\n");
    while (atual != NULL) {
        printf("| %-25s | %-5d | %-13d | %-13d |\n", atual->descricao, atual->xp, atual->tempoEstimado, atual->tempoReal);
        atual = atual->proximo;
    }
    printf("------------------------------------------------------------\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Fila* tarefasPendentes = criarFila();
    ListaConcluidas* tarefasConcluidas = criarListaConcluidas();
    int xpTotal = 0;

    int opcao;
    do {
        printf("\n1. Adicionar Tarefa\n2. Exibir Tarefas\n3. Marcar Tarefa como Concluída\n4. Ver Tarefas Concluídas\n5. Ver XP Total\n6. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        switch (opcao) {
            case 1:
                lerTarefas(tarefasPendentes);
                break;
            case 2:
                exibirTarefas(tarefasPendentes);
                break;
            case 3:
                concluirTarefa(tarefasPendentes, tarefasConcluidas, &xpTotal);
                break;
            case 4:
                exibirTarefasConcluidas(tarefasConcluidas);
                break;
            case 5:
                printf("XP Total: %d\n", xpTotal);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}
