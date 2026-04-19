#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "plantas.h"
#include "dados.h"
#include "persistencia.h"

int adicionar_planta(const char *nome, const char *especie, const char *data_plantio, int intervalo) {
    Planta planta;

    if (dados_total_plantas() >= MAX_PLANTAS) {
        return 0;
    }

    if (nome == NULL || nome[0] == '\0') {
        return 0;
    }

    if (especie == NULL || especie[0] == '\0') {
        return 0;
    }

    if (data_plantio == NULL || data_plantio[0] == '\0') {
        return 0;
    }

    if (intervalo <= 0) {
        return 0;
    }

    planta.id = dados_gerar_id_planta();

    strncpy(planta.nome, nome, sizeof(planta.nome) - 1);
    planta.nome[sizeof(planta.nome) - 1] = '\0';

    strncpy(planta.especie, especie, sizeof(planta.especie) - 1);
    planta.especie[sizeof(planta.especie) - 1] = '\0';

    strncpy(planta.data_plantio, data_plantio, sizeof(planta.data_plantio) - 1);
    planta.data_plantio[sizeof(planta.data_plantio) - 1] = '\0';

    planta.intervalo_rega = intervalo;
    planta.ultima_rega = 0;

    if (!dados_inserir_planta(planta)) {
        return 0;
    }

    guardar_dados(); // ← persistência automática

    return 1;
}

void listar_plantas(void) {
    int total = dados_total_plantas();

    printf("=== PLANTAS ===\n");

    if (total == 0) {
        printf("Nenhuma planta registada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        const Planta *p = dados_obter_planta(i);

        if (p != NULL) {
            printf("ID: %d | Nome: %s | Especie: %s | Data de plantio: %s | Intervalo: %d | Ultima rega: %d\n",
                   p->id,
                   p->nome,
                   p->especie,
                   p->data_plantio,
                   p->intervalo_rega,
                   p->ultima_rega);
        }
    }
}