# 📘 Funções e Procedimentos em C++

## 1. Conceitos Fundamentais

### 1.1 O que são Funções e Procedimentos

Funções e procedimentos são elementos fundamentais na programação modular, permitindo dividir o código em blocos reutilizáveis com finalidades específicas.

- **Funções**:
  - Sempre retornam um valor.
  - Possuem um tipo de retorno (ex: `int`, `float`, `double`, etc.).
  - Devem incluir uma instrução `return`.

- **Procedimentos**:
  - Não retornam valor.
  - Declarados com o tipo `void`.
  - Executam ações sem necessidade de retorno, como exibir mensagens.

Essa separação melhora a organização, reutilização e manutenção do código.

---

### 1.2 Estrutura de uma Função

Uma função em C++ é composta por elementos bem definidos, que seguem uma estrutura padrão:

- **Tipo de retorno**: define o tipo de dado que a função irá retornar (ou `void` se não houver retorno).
- **Nome da função**: deve seguir convenções de nomenclatura claras e descritivas.
- **Parâmetros**: lista tipada de variáveis de entrada, entre parênteses.
- **Corpo da função**: bloco de comandos entre `{}`; deve conter a lógica da função e, se necessário, a instrução `return`.

As variáveis declaradas dentro da função são **locais** e não são acessíveis fora dela.

---

### 1.3 Tipos de Retorno

Em C++, o tipo de retorno de uma função pode ser:

- Tipos primitivos: `int`, `float`, `char`, `double`, `long`.
- Ponteiros: como `int*`, `char*`.
- Estruturas (`struct`): permitindo o retorno de conjuntos de dados.

> **Importante**: Funções que retornam um valor devem sempre utilizar `return`. Caso contrário, ocorrerá erro de compilação.

A função pode ser chamada de dentro da função `main()` ou de outras funções, retornando o controle ao ponto de chamada após sua execução. Isso permite **modularidade** e **encadeamento** de lógicas no programa.

---

## 2. Parâmetros de uma Função

### 2.1 Tipos de Passagem de Parâmetros

Em C++, os parâmetros podem ser passados de duas formas:

- **Por valor**:
  - Envia apenas uma cópia da variável.
  - Alterações feitas dentro da função não afetam o valor original.
  - É o modo padrão de passagem.

- **Por referência**:
  - Envia o endereço da variável.
  - Permite modificar diretamente o valor original.
  - Indicado quando se deseja retornar múltiplos valores ou otimizar o uso de memória.

---

### 2.2 Considerações sobre Passagem por Referência

- Utiliza ponteiros para manipular diretamente as variáveis originais.
- A função recebe endereços de memória e utiliza operadores (`*` e `&`) para acessá-los.
- Essa abordagem é essencial para funções que precisam alterar variáveis externas ou lidar com estruturas de dados maiores.

---

> 💡 **Dica:** Saber escolher entre passagem por valor e por referência impacta diretamente no desempenho e comportamento das funções em programas reais.