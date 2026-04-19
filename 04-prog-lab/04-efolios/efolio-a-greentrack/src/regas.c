#include <stdio.h>
#include <stddef.h>
#include "regas.h"
#include "dados.h"
#include "persistencia.h"

int registar_rega(int id_planta, int data, int quantidade) {
    Rega rega;

    if (data < 0 || quantidade <= 0) {
        return 0;
    }

    if (dados_procurar_planta_por_id(id_planta) == -1) {
        return 0;
    }

    rega.id_rega = dados_gerar_id_rega();
    rega.id_planta = id_planta;
    rega.data_rega = data;
    rega.quantidade_agua = quantidade;

    if (!dados_inserir_rega(rega)) {
        return 0;
    }

    if (!dados_atualizar_ultima_rega(id_planta, data)) {
        return 0;
    }

    guardar_dados();

    return 1;
}

int verificar_rega(int data_atual) {
    int encontrou = 0;
    int total = dados_total_plantas();

    printf("=== PLANTAS QUE PRECISAM DE REGA ===\n");

    for (int i = 0; i < total; i++) {
        const Planta *p = dados_obter_planta(i);

        if (p == NULL) {
            continue;
        }

        int dias = data_atual - p->ultima_rega;

        if (dias >= p->intervalo_rega) {
            printf("Planta %s (ID: %d) precisa de rega! (ultima: %d dias atras)\n",
                   p->nome,
                   p->id,
                   dias);
            encontrou = 1;
        }
    }

    return encontrou;
}