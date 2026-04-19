#include <stddef.h>
#include "dados.h"

static Planta plantas[MAX_PLANTAS];
static Rega regas[MAX_REGAS];
static Tarefa tarefas[MAX_TAREFAS];
static int total_plantas = 0;
static int total_regas = 0;
static int total_tarefas = 0;

int dados_total_plantas(void) {
    return total_plantas;
}
int dados_total_regas(void) {
    return total_regas;
}
int dados_total_tarefas(void) {
    return total_tarefas;
}
const Planta *dados_obter_planta(int i) {
    if (i < 0 || i >= total_plantas) {
        return NULL;
    }
    return &plantas[i];
}
const Rega *dados_obter_rega(int i) {
    if (i < 0 || i >= total_regas) {
        return NULL;
    }
    return &regas[i];
}
const Tarefa *dados_obter_tarefa(int i) {
    if (i < 0 || i >= total_tarefas) {
        return NULL;
    }
    return &tarefas[i];
}
int dados_inserir_planta(Planta planta) {
    if (total_plantas >= MAX_PLANTAS) {
        return 0;
    }
    plantas[total_plantas++] = planta;
    return 1;
}
int dados_inserir_rega(Rega rega) {
    if (total_regas >= MAX_REGAS) {
        return 0;
    }
    regas[total_regas++] = rega;
    return 1;
}
int dados_inserir_tarefa(Tarefa tarefa) {
    if (total_tarefas >= MAX_TAREFAS) {
        return 0;
    }
    tarefas[total_tarefas++] = tarefa;
    return 1;
}
int dados_procurar_planta_por_id(int id) {
    for (int i = 0; i < total_plantas; i++) {
        if (plantas[i].id == id) {
            return i;
        }
    }
    return -1;
}
int dados_procurar_tarefa_por_id(int id) {
    for (int i = 0; i < total_tarefas; i++) {
        if (tarefas[i].id_tarefa == id) {
            return i;
        }
    }
    return -1;
}
int dados_atualizar_ultima_rega(int id_planta, int data) {
    int indice = dados_procurar_planta_por_id(id_planta);
    if (indice == -1) {
        return 0;
    }

    plantas[indice].ultima_rega = data;
    return 1;
}
int dados_marcar_tarefa_concluida(int id_tarefa) {
    int indice = dados_procurar_tarefa_por_id(id_tarefa);
    if (indice == -1) {
        return 0;
    }

    tarefas[indice].concluida = 1;
    return 1;
}
int dados_gerar_id_planta(void) {
    int maior = 0;
    for (int i = 0; i < total_plantas; i++) {
        if (plantas[i].id > maior) {
            maior = plantas[i].id;
        }
    }
    return maior + 1;
}
int dados_gerar_id_rega(void) {
    int maior = 0;
    for (int i = 0; i < total_regas; i++) {
        if (regas[i].id_rega > maior) {
            maior = regas[i].id_rega;
        }
    }
    return maior + 1;
}
int dados_gerar_id_tarefa(void) {
    int maior = 0;
    for (int i = 0; i < total_tarefas; i++) {
        if (tarefas[i].id_tarefa > maior) {
            maior = tarefas[i].id_tarefa;
        }
    }
    return maior + 1;
}
void dados_resetar(void) {
    total_plantas = 0;
    total_regas = 0;
    total_tarefas = 0;
}