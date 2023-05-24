# Anotações Importantes

Cada arquivo dessa aula será referente à uma aula prática, então esse projeto tem por objetivo ser um diário de estudos e não um projeto real.

Para executar a linguagem C no VC, utilizei um compilador fora do editor (o mingw) e mais as extensões do VC para a linguagem C mas eles podem ser executas facilmente <a href="https://replit.com/">aqui</a>, só se cadastrar e na página principal clicar em Create Repl, depois você pode copiar o código e colar ali.

*OBS: Não é possível, ou pelo menos não encontrei informações referente à configuração UTF-8, para lingua portuguesa, então aqui não haverá palavras com caracteres especiais*

Fontes: Universidade Unicesumar e Livro Estruturas de Dados I, Estruturas de Dados II.

## Malloc
A função malloc aloca um espaço de memória e retorna um ponteiro do tipo void para o início do espaço de memória alocado.

### Sintaxe

````
<ponteiro> = (<cast>*) malloc(<tamanho em bytes>); 
p = (int*) malloc(4);
````

## Free
A função free libera o espaço de memória alocado.

## Criando Vetores Dinamicos

O objetivo desses vetores é usar somente a quantidade de memória que for precisar, aqui ao contrário dos vetores de tamanho fixo, não ficamos limitados ao tamanho.

Como utilizar:

````
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int tam;
    int *vetor;

    printf ("Escolha o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int *) malloc(sizeof (int)*tam);
    for (int i = 0; i < tam; i++) {
        vetor[i] = pow(2,i);
        printf ("Posicao %d: %d\n", i, vetor[i]);
    }
    system("Pause");
    return(0);
}
````
### Sizeof

O operador sizeof indica a quantidade de armazenamento, em bytes, necessária para armazenar um objeto do tipo do operando.
## Listas

### Pilha || Stack

<img src="/img/pilha.png">

Pilha ou stack é uma lista linear em que todas as inserções e remoções de elemento só podem ser feitos em uma extremidade chamada topo.As pilhas também são chamadas de estruturas LIFO (Last In First Out) ou seja o último elemento inserido é o primeiro removido.

**Push** Empilhar | **Pop** Desempilhar

**Estrutura de Dados da Pilha**

````
struct tipo_pilha {
    int dados [tamanho];
    int inicio;
    int topo;
}
````