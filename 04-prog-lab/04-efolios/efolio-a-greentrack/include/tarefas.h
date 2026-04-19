#ifndef TAREFAS_H
#define TAREFAS_H

int criar_tarefa(const char *descricao, int data_prevista);
void listar_tarefas_pendentes(void);
int concluir_tarefa(int id);

#endif