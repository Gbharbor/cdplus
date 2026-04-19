#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "tarefas.h"
#include "dados.h"
#include "persistencia.h"

int criar_tarefa(const char *descricao, int data_prevista) {
    Tarefa tarefa;

    if (descricao == NULL || descricao[0] == '\0') {
        return 0;
    }

    if (data_prevista < 0) {
        return 0;
    }

    tarefa.id_tarefa = dados_gerar_id_tarefa();

    strncpy(tarefa.descricao, descricao, sizeof(tarefa.descricao) - 1);
    tarefa.descricao[sizeof(tarefa.descricao) - 1] = '\0';

    tarefa.data_prevista = data_prevista;
    tarefa.concluida = 0;

    if (!dados_inserir_tarefa(tarefa)) {
        return 0;
    }

    guardar_dados();

    return 1;
}

void listar_tarefas_pendentes(void) {
    int total = dados_total_tarefas();
    int encontrou = 0;

    printf("=== TAREFAS PENDENTES ===\n");

    for (int i = 0; i < total; i++) {
        const Tarefa *t = dados_obter_tarefa(i);

        if (t != NULL && t->concluida == 0) {
            printf("Tarefa %d: %s (prevista: %d)\n",
                   t->id_tarefa,
                   t->descricao,
                   t->data_prevista);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nao existem tarefas pendentes.\n");
    }
}

int concluir_tarefa(int id) {
    if (!dados_marcar_tarefa_concluida(id)) {
        return 0;
    }

    guardar_dados();

    return 1;
}