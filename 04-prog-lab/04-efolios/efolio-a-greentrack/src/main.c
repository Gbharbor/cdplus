#include <stdio.h>
#include <string.h>
#include "persistencia.h"
#include "plantas.h"
#include "regas.h"
#include "tarefas.h"

int main(void) {
    int opcao;

    carregar_dados();

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Listar plantas\n");
        printf("2 - Adicionar planta\n");
        printf("3 - Verificar plantas que precisam de rega\n");
        printf("4 - Registar rega\n");
        printf("5 - Listar tarefas pendentes\n");
        printf("6 - Criar tarefa\n");
        printf("7 - Concluir tarefa\n");
        printf("8 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                listar_plantas();
                break;

            case 2: {
                int intervalo;
                char nome[50], especie[50], data[11];

                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Especie: ");
                fgets(especie, sizeof(especie), stdin);
                especie[strcspn(especie, "\n")] = '\0';

                printf("Data de plantio (DD/MM/AAAA): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0';

                printf("Intervalo de rega (dias): ");
                if (scanf("%d", &intervalo) != 1 || intervalo <= 0) {
                    printf("Intervalo invalido.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                if (adicionar_planta(nome, especie, data, intervalo)) {
                    printf("Planta adicionada com sucesso.\n");
                } else {
                    printf("Erro ao adicionar planta.\n");
                }
                break;
            }

            case 3: {
                int data_atual;

                printf("Data atual (dias desde 01/01/2026): ");
                if (scanf("%d", &data_atual) != 1 || data_atual < 0) {
                    printf("Data invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                verificar_rega(data_atual);
                break;
            }

            case 4: {
                int id_planta, data_rega, quantidade;

                printf("ID da planta: ");
                if (scanf("%d", &id_planta) != 1 || id_planta <= 0) {
                    printf("ID invalido.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                printf("Data da rega (dias desde 01/01/2026): ");
                if (scanf("%d", &data_rega) != 1 || data_rega < 0) {
                    printf("Data invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                printf("Quantidade de agua (ml): ");
                if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
                    printf("Quantidade invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                if (registar_rega(id_planta, data_rega, quantidade)) {
                    printf("Rega registada com sucesso.\n");
                } else {
                    printf("Erro ao registar rega.\n");
                }
                break;
            }

            case 5:
                listar_tarefas_pendentes();
                break;

            case 6: {
                char descricao[100];
                int data_prevista;

                printf("Descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';

                printf("Data prevista (dias desde 01/01/2026): ");
                if (scanf("%d", &data_prevista) != 1 || data_prevista < 0) {
                    printf("Data invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                if (criar_tarefa(descricao, data_prevista)) {
                    printf("Tarefa criada com sucesso.\n");
                } else {
                    printf("Erro ao criar tarefa.\n");
                }
                break;
            }

            case 7: {
                int id_tarefa;

                printf("ID da tarefa a concluir: ");
                if (scanf("%d", &id_tarefa) != 1 || id_tarefa <= 0) {
                    printf("ID invalido.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                if (concluir_tarefa(id_tarefa)) {
                    printf("Tarefa concluida com sucesso.\n");
                } else {
                    printf("Tarefa nao encontrada.\n");
                }
                break;
            }

            case 8:
                printf("A sair...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 8);

    return 0;
}