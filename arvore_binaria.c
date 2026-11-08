/*======================================================================================
Instituição: UNIVERSIDADE VEIGA DE ALMEIDA
Autor: David Alcantara Dias
Matrícula: 1260210397
IMPLEMENTAÇÃO E MANIPULAÇÃO DE UMA ARVORE BINÁRIA
Curso: Superior de Tecnologia em Analise e Desenvolvimento de Sistemas
Discilina: Estrutura de Dados
Rio de janeiro 2026
=======================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estrutura do nó
typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

//criação de um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//inserção de um nó
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

//Busca algum valor na árvore
int buscar(No* raiz, int valor) {
    if (raiz == NULL)
        return 0;

    if (raiz->valor == valor)
        return 1;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

//Encontrar o menor valor da subarvore
No* encontrarMenor(No* no) {
    No* atual = no;

    while (atual && atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

//Remoção de um nó
No* remover(No* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    }
    else {
        // Nó sem nenhum filho
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        // Nó com apenas um filho
        if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos
        No* temp = encontrarMenor(raiz->dir);
        raiz->valor = temp->valor;
        raiz->dir = remover(raiz->dir, temp->valor);
    }
    return raiz;
}

//Percurso em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

//Percurso pré-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

//Percurso pós-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
} 

int arvoreVazia(No *raiz) {
    if (raiz == NULL) {
        printf("\nAVISO: A arvore esta vazia! Nenhum dado cadastrado.\n");
        return 1;
    }
    return 0;
}

/* --- MÉTRICAS E VISUALIZAÇÃO GRÁFICA --- */

// Calcula a altura da árvore
int calcularAltura(No* raiz) {
    if (raiz == NULL)
        return -1; // Árvore vazia tem altura -1 (ou 0 dependendo da convenção. -1 indica que folha tem altura 0)
    
    int altEsq = calcularAltura(raiz->esq);
    int altDir = calcularAltura(raiz->dir);
    
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

// Conta o número total de nós
int contarNos(No* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

// Desenha a estrutura da árvore textual horizontalmente (Visualização Gráfica)
void exibirArvoreGrafica(No* raiz, int espaco) {
    // Base de parada da recursão
    if (raiz == NULL)
        return;

    // Aumenta a distância entre os níveis
    espaco += 8;

    // Processa o filho da direita primeiro (topo visual)
    exibirArvoreGrafica(raiz->dir, espaco);

    // Imprime o nó atual após os espaços necessários
    printf("\n");
    for (int i = 8; i < espaco; i++) {
        printf(" ");
    }
    printf("[ %d ]\n", raiz->valor);

    // Processa o filho da esquerda (base visual)
    exibirArvoreGrafica(raiz->esq, espaco);
}

/* --- FUNÇÕES AUXILIARES --- */

// Valida inteiro
int lerInteiro(const char *mensagem) {
    char entrada[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            continue;
        }

        valor = strtol(entrada, &fim, 10);

        if (fim == entrada) {
            printf("Erro: digite um numero inteiro valido!\n");
            continue;
        }

        while (*fim == ' ' || *fim == '\t') {
            fim++;
        }

        if (*fim != '\n' && *fim != '\0') {
            printf("Erro: digite apenas numeros!\n");
            continue;
        }

        return (int)valor;
    }
}



//Limpar tela
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

//Libera memória da árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

//Função principal
int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul"); 
    #else 
    setlocale(LC_ALL, "Portuguese");
    #endif
    No* raiz = NULL;
    int opcao, valor;

    do {
        limparTela();
        printf("\n==========================================================\n");
        printf("     Sistema de Gerenciamento de Arvore Binaria          \n");
        printf("                    RENALF MEGA DATA                      \n");
        printf("==========================================================\n");
        printf("\nMENU DE OPÇÕES:\n");
        printf("1. Inserir Nó\n");
        printf("2. Remover Nó\n");
        printf("3. Buscar pré-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pós-ordem\n");
        printf("6. Visualizar Estrutura da Árvore\n");
        printf("7. Exibir Métricas (Altura e Total de Nós)\n");
        printf("0. Encerrar\n");
        opcao = lerInteiro("\nDigite a opção desejada: ");

        switch (opcao) {
            case 1:
                valor = lerInteiro("\nDigite o valor a ser inserido: ");

                if (buscar(raiz, valor)) {
                    printf("Erro: valor ja existe na arvore!\n");
                } 
                else {
                    raiz = inserir(raiz, valor);
                    printf("Valor inserido com sucesso!\n");
                }
                pausar();
                break;
            case 2:
                if (arvoreVazia(raiz)){
                    pausar();
                    break;
                }
                valor = lerInteiro("\nDigite o valor a ser removido: ");

                if (buscar(raiz, valor)) {
                    raiz = remover(raiz, valor);
                    printf("Valor removido com sucesso!\n");
                } else {
                    printf("Erro: valor nao encontrado na arvore!\n");
                }
                pausar();
                break;
    
            case 3:
                if (arvoreVazia(raiz)) {
                    pausar();
                    break;
                }
                printf("Pré-ordem: ");
                preOrdem(raiz);
                printf("\n");
                pausar();
                break;
            case 4:
                if (arvoreVazia(raiz)) {
                    pausar();
                    break;
                }
                printf("Em ordem: ");
                emOrdem(raiz);
                printf("\n");
                pausar();
                break;
            case 5:
                if (arvoreVazia(raiz)) {
                    pausar();
                    break;
                }
                printf("Pós-ordem: ");
                posOrdem(raiz);
                printf("\n");
                pausar();
                break;
            case 6:
                if (arvoreVazia(raiz)) {
                    pausar();
                    break;
                }
                printf("\n--- ESTRUTURA VISUAL DA ÁRVORE (Rotacionada 90° para a esquerda) ---\n");
                exibirArvoreGrafica(raiz, 0);
                printf("\n--------------------------------------------------------------------\n");
                pausar();
                break;
            case 7:
                if (arvoreVazia(raiz)) {
                    pausar();
                    break;
                }
                printf("\n--- MÉTRICAS DA ÁRVORE ---\n");
                printf("Altura da árvore: %d\n", calcularAltura(raiz));
                printf("Quantidade total de nós: %d\n", contarNos(raiz));
                pausar();
                break;
            case 0:
                limparTela();
                printf("Encerrando o programa...\n");   
                break;    
            default:
                printf("Opcao invalida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);

    liberarArvore(raiz);
    return 0;
}
