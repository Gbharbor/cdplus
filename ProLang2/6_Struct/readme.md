# Guia Completo sobre `struct` em C++

## O que é uma `struct`?

Uma `struct` (abreviação de **structure**) é uma forma de **agrupamento de dados** em C e C++. Ela permite que você armazene diferentes tipos de dados sob um único nome. Cada item dentro de uma `struct` é chamado de **membro** ou **campo** da `struct`, e pode ser de qualquer tipo de dado: `int`, `float`, `string`, até mesmo outras `structs`.

## Declarando uma `struct`

Para declarar uma `struct`, você usa a palavra-chave `struct` seguida de um nome e, dentro de chaves `{}`, os membros que ela vai conter.

### Exemplo1

```cpp
struct Pessoa {
    string nome;
    int idade;
    float altura;
};
```

Após declarar a `struct`, você pode criar variáveis desse tipo, como se fosse um tipo de dado comum:

```cpp
Pessoa p1, p2;  // Declarando duas variáveis do tipo Pessoa
```

## Acessando membros de uma `struct`

Para acessar os membros de uma `struct`, usamos o **operador ponto (`.`)**.

### Exemplo2

```cpp
p1.nome = "João";
p1.idade = 25;
```

## Métodos dentro de uma `struct`

Em C++, uma `struct` pode conter **métodos** (funções associadas a uma `struct`), o que a torna mais poderosa, permitindo a programação orientada a objetos.

### Exemplo de `struct` com um método

```cpp
struct Pessoa {
    string nome;
    int idade;
    
    void exibirInfo() {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};
```

## Leitura e escrita em uma `struct`

Você pode ler e escrever dados em uma `struct` usando o operador ponto e funções de entrada e saída (`cin`, `cout` em C++).

### Exemplo3

```cpp
cout << "Digite o nome: ";
getline(cin, p1.nome);  // Usamos getline para ler o nome com espaços

cout << "Digite a idade: ";
cin >> p1.idade;

cout << "Digite a altura: ";
cin >> p1.altura;
```

## Passando `structs` para funções

Em C++, você pode passar uma `struct` para uma função de duas maneiras:

1. **Por valor**: Cria-se uma cópia da `struct`, e qualquer modificação não afeta a original.
2. **Por referência**: Passa-se o endereço da `struct`, permitindo modificar os dados diretamente.

### Exemplo de passagem por **valor**

```cpp
void imprimirPessoa(Pessoa p) {
    cout << "Nome: " << p.nome << " - Idade: " << p.idade << endl;
}
```

### Exemplo de passagem por **referência**

```cpp
void atualizarIdade(Pessoa& p) {
    p.idade += 1;  // Modifica diretamente o valor de idade
}
```

## Usando `typedef` e `using` para `structs`

- **`typedef`**: Cria um **alias** para o tipo, facilitando o uso de `structs` sem ter que escrever "struct" toda vez.
  
  ### Exemplo com `typedef`

  ```cpp
  typedef struct Pessoa {
      string nome;
      int idade;
      float altura;
  } Pessoa;
  ```

- **`using`**: Uma alternativa mais moderna em C++ para criar aliases de tipos.
  
  ### Exemplo com `using`

  ```cpp
  struct Pessoa {
      string nome;
      int idade;
      float altura;
  };
  
  using PessoaAlias = Pessoa;  // Alias para a struct
  ```

## Construtores em `structs`

Em C++, **`structs`** podem ter **construtores**, que são funções especiais usadas para inicializar os membros da `struct` quando ela é criada.

### Exemplo de `struct` com construtor

```cpp
struct Ponto {
    int x, y;

    Ponto(int _x, int _y) {  // Construtor
        x = _x;
        y = _y;
    }

    void imprimir() {
        cout << "Ponto: (" << x << ", " << y << ")" << endl;
    }
};
```

## Ponteiros com `structs`

Assim como em C, você pode usar **ponteiros** para manipular `structs` em C++. Para acessar os membros através de um ponteiro, você usa o operador **seta (`->`)**.

### Exemplo4

```cpp
Ponto* pPtr = &p1;  // Ponteiro para a struct Ponto
cout << "Coordenada x de p1: " << pPtr->x << endl;
cout << "Coordenada y de p1: " << pPtr->y << endl;
```

## Estruturas Aninhadas

Em C++, assim como em C, você pode ter **`structs` dentro de outras `structs`**. Isso é útil quando você precisa representar dados mais complexos.

### Exemplo de estrutura aninhada

```cpp
struct Data {
    int dia, mes, ano;
};

struct Pessoa {
    string nome;
    Data nascimento;  // Estrutura aninhada
};
```

## Resumo da Passagem de `structs` para Funções

- Passar uma `struct` por **valor** significa que uma cópia da `struct` é feita, e alterações não afetam o original.
- Passar uma `struct` por **referência** significa que qualquer modificação na função afetará diretamente o objeto original.

## Considerações Finais

- **`structs`** em C++ são tipos compostos que permitem agrupar dados diferentes. Elas podem ter métodos, construtores e outras funcionalidades típicas de programação orientada a objetos.
- **Passagem por valor** e **passagem por referência** são importantes para decidir se você quer manipular uma cópia ou a própria `struct` original em funções.
- Com **`typedef`** e **`using`**, podemos tornar o código mais limpo, criando aliases para tipos complexos.
