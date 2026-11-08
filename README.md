# Sistema de Gerenciamento de Árvore Binária

Este projeto consiste na implementação e manipulação de uma **Árvore Binária de Busca (BST - Binary Search Tree)** em linguagem C. O programa foi desenvolvido como parte dos requisitos acadêmicos da disciplina de Estrutura de Dados.

## 🎓 Informações Acadêmicas

* **Instituição:** Universidade Veiga de Almeida (UVA)
* **Curso:** Superior de Tecnologia em Análise e Desenvolvimento de Sistemas
* **Disciplina:** Estrutura de Dados
* **Autor:** David Alcantara Dias
* **Matrícula:** 1260210397
* **Ano/Local:** Rio de Janeiro, 2026

## 🚀 Funcionalidades

O sistema oferece um menu interativo (interface textual "RENALF MEGA DATA") para gerenciar e analisar a árvore de forma dinâmica:

1. **Inserção de Nós:** Adiciona valores inteiros garantindo as propriedades de uma BST (valores menores à esquerda, maiores à direita) e valida duplicatas.
2. **Remoção de Nós:** Trata os três cenários clássicos de exclusão (nó folha, nó com um filho e nó com dois filhos).
3. **Percursos de Busca:**

   * **Pré-ordem** (Raiz - Esquerda - Direita)
   * **Em ordem** (Esquerda - Raiz - Direita) - exibe os dados ordenados crescentemente.
   * **Pós-ordem** (Esquerda - Direita - Raiz)
4. **Visualização Gráfica:** Exibe a estrutura da árvore rotacionada textualmente em 90 graus para fins visuais e didáticos.
5. **Métricas de Análise:**

   * Cálculo da **Altura** da árvore.
   * Contagem do **Total de Nós** cadastrados.

## 🛠️ Tecnologias e Bibliotecas Utilizadas

- **Linguagem:** C
- **Bibliotecas Padrão:**
  - `<stdio.h>` e `<stdlib.h>` (I/O e alocação dinâmica de memória)
  - `<string.h>` (Manipulação de strings nas validações)
  - `<locale.h>` (Tratamento de codificação e acentuação)

## 🛠️ Detalhes de Implementação

* **Validação Robusta:** O código implementa a função `lerInteiro`, que impede que caracteres ou entradas vazias quebrem a execução do programa.
* **Gerenciamento de Memória:** Possui uma rotina recursiva de liberação de memória (`liberarArvore`) executada antes do encerramento para evitar vazamento de memória (*memory leaks*).

## 🛠️ Como Compilar e Executar

### Pré-requisitos
Certifique-se de ter um compilador para a linguagem C instalado em sua máquina (como o **GCC**).

### Passos para Compilação
Abra o terminal na pasta do arquivo contendo o código-fonte e execute o seguinte comando:

```bash
gcc -o arvore_binaria programa.c
```

### Passos para Execução
Após a compilação, execute o binário gerado:

**No Windows:**
```cmd
arvore_binaria.exe
```

**No Linux / macOS:**
```bash
./arvore_binaria
```

---

**Nota de Compatibilidade:** O código possui diretivas de compilação condicional (`#ifdef _WIN32`) para garantir que os comandos de limpeza de tela (`cls`/`clear`) e o suporte a caracteres UTF-8 funcionem perfeitamente tanto no ecossistema Windows quanto em sistemas Unix-like (Linux/macOS).

## 🗂️ Estrutura de Dados Principal

O núcleo do projeto baseia-se na alocação dinâmica de nós usando ponteiros autoreferenciados:

```c
typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;
```

## 📁 Estrutura do Código-Fonte
* `No`: Estrutura base que representa um nó contendo um valor inteiro e ponteiros para os filhos esquerdo e direito.
* `inserir` / `remover` / `buscar`: Algoritmos fundamentais de manipulação da BST.
* `calcularAltura` / `contarNos`: Funções de cálculo métrico sobre a árvore.
* `exibirArvoreGrafica`: Função recursiva responsável pela projeção visual textual.
* `main`: Fluxo de controle do menu principal interativo do usuário.


Licença: Projeto desenvolvido para fins acadêmicos.

