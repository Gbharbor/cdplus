#ifndef DADOS_H
#define DADOS_H

#define MAX_PLANTAS 100
#define MAX_REGAS 500
#define MAX_TAREFAS 200

typedef struct {
    int id;
    char nome[50];
    char especie[50];
    char data_plantio[11];
    int intervalo_rega;
    int ultima_rega;
} Planta;

typedef struct {
    int id_rega;
    int id_planta;
    int data_rega;
    int quantidade_agua;
} Rega;

typedef struct {
    int id_tarefa;
    char descricao[100];
    int data_prevista;
    int concluida;
} Tarefa;

/* ===== FUNÇÕES DE ACESSO ===== */

/* Totais */
int dados_total_plantas(void);
int dados_total_regas(void);
int dados_total_tarefas(void);

/* Acesso */
const Planta *dados_obter_planta(int i);
const Rega *dados_obter_rega(int i);
const Tarefa *dados_obter_tarefa(int i);

/* Procura */
int dados_procurar_planta_por_id(int id_planta);
int dados_procurar_tarefa_por_id(int id);

/* Inserção */
int dados_inserir_planta(Planta p);
int dados_inserir_rega(Rega r);
int dados_inserir_tarefa(Tarefa t);

/* Atualização */
int dados_marcar_tarefa_concluida(int id_tarefa);
int dados_atualizar_ultima_rega(int id_planta, int data);

/* IDs */
int dados_gerar_id_planta(void);
int dados_gerar_id_rega(void);
int dados_gerar_id_tarefa(void);

/* Reset */
void dados_resetar(void);

#endif