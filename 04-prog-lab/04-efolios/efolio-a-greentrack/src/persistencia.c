#include <stdio.h>
#include "persistencia.h"
#include "dados.h"

void carregar_dados(void) {
    dados_resetar();

    FILE *f_plantas = fopen("plantas.csv", "r");
    if (f_plantas != NULL) {
        Planta p;

        while (fscanf(f_plantas, "%d,%49[^,],%49[^,],%10[^,],%d,%d",
                      &p.id,
                      p.nome,
                      p.especie,
                      p.data_plantio,
                      &p.intervalo_rega,
                      &p.ultima_rega) == 6) {
            if (!dados_inserir_planta(p)) {
                break;
            }
        }

        fclose(f_plantas);
    }

    FILE *f_regas = fopen("regas.csv", "r");
    if (f_regas != NULL) {
        Rega r;

        while (fscanf(f_regas, "%d,%d,%d,%d",
                      &r.id_rega,
                      &r.id_planta,
                      &r.data_rega,
                      &r.quantidade_agua) == 4) {
            if (!dados_inserir_rega(r)) {
                break;
            }
        }

        fclose(f_regas);
    }

    FILE *f_tarefas = fopen("tarefas.csv", "r");
    if (f_tarefas != NULL) {
        Tarefa t;

        while (fscanf(f_tarefas, "%d,%99[^,],%d,%d",
                      &t.id_tarefa,
                      t.descricao,
                      &t.data_prevista,
                      &t.concluida) == 4) {
            if (!dados_inserir_tarefa(t)) {
                break;
            }
        }

        fclose(f_tarefas);
    }
}

void guardar_dados(void) {
    FILE *f_plantas = fopen("plantas.csv", "w");
    if (f_plantas == NULL) {
        printf("Erro ao guardar plantas.\n");
        return;
    }

    for (int i = 0; i < dados_total_plantas(); i++) {
        const Planta *p = dados_obter_planta(i);
        if (p != NULL) {
            fprintf(f_plantas, "%d,%s,%s,%s,%d,%d\n",
                    p->id,
                    p->nome,
                    p->especie,
                    p->data_plantio,
                    p->intervalo_rega,
                    p->ultima_rega);
        }
    }
    fclose(f_plantas);

    FILE *f_regas = fopen("regas.csv", "w");
    if (f_regas == NULL) {
        printf("Erro ao guardar regas.\n");
        return;
    }

    for (int i = 0; i < dados_total_regas(); i++) {
        const Rega *r = dados_obter_rega(i);
        if (r != NULL) {
            fprintf(f_regas, "%d,%d,%d,%d\n",
                    r->id_rega,
                    r->id_planta,
                    r->data_rega,
                    r->quantidade_agua);
        }
    }
    fclose(f_regas);

    FILE *f_tarefas = fopen("tarefas.csv", "w");
    if (f_tarefas == NULL) {
        printf("Erro ao guardar tarefas.\n");
        return;
    }

    for (int i = 0; i < dados_total_tarefas(); i++) {
        const Tarefa *t = dados_obter_tarefa(i);
        if (t != NULL) {
            fprintf(f_tarefas, "%d,%s,%d,%d\n",
                    t->id_tarefa,
                    t->descricao,
                    t->data_prevista,
                    t->concluida);
        }
    }
    fclose(f_tarefas);
}