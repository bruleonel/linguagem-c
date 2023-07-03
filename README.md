# Anotações Importantes | Estruturas de Dados I

Cada arquivo dessa aula será referente à uma aula prática, então esse projeto tem por objetivo ser um diário de estudos e não um projeto real.

Para executar a linguagem C no VC, você pode utilizar um compilador fora do editor (o mingw), o que será um tanto trabalhoso, e  as extensões do VC para a linguagem C, entretanto, você pode executar facilmente <a href="https://replit.com/">aqui</a>, que é a ferremanta que eu uso, é só se cadastrar e na página principal clicar em Create Repl, depois você pode copiar o código de cada arquivo aqui e colar ali.

*OBS: Em C dependendo da ferramenta, não é possível, ou pelo menos ainda não encontrei informações sobre, utilizar acentuações atravéz da configuração UTF-8 para caracteres especiais contidos na  lingua portuguesa*

Fontes: Universidade Unicesumar e Livro Estruturas de Dados I, Estruturas de Dados II.

## Sobre a Linguagem | Relembrando alguns Conceitos:

Para gerar números aleatório dentro de um array, podemos usar a função rand();
Para que a função rand sempre gere números diferentes, podemos usar o srand, pssando como parâmetro o horário (que sempre será diferente)

Ex:

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/88768827-bc69-4016-a3d7-2386b67e75e0)


## Ponteiros

Ex1:

![ao-vivo1](https://github.com/bruleonel/linguagem-c/assets/104650333/192db369-d31c-478b-9676-a517e6f28e1a)

Ex2:

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/f93e3d19-1e35-4044-a78c-d6d7ec1da859)

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/ac0be514-bf39-4ff6-9e3f-0a403b6deff8)

*Obs:. A função imprimir só conseguiu alterar o endereço porque recebeu o endereço e não a variável*


## sizeof()

Retorna o tamnanho em bits

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/dd422489-9671-4d2f-bd8e-73888df3e6f2)

Retorno:

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/f3de4b1e-cd6a-45b5-b4a3-379895970349)

## Vetor

O vetor já é uma ponteiro!
*OBS:. Cuidado ao guardar informações no vetor sem a alocação da memória, ele até aceita, porém pode ser sobreposto por outros programas*

EX:

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/20ce061a-f5d1-4ca1-98d0-330c8131f8eb)

Quando você quiser descobrir a quantidade de elementos de um vetor:

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/70777474-17a7-4153-9f60-4f9c6dbe4fc9)


## Malloc
A função malloc aloca um espaço de memória e retorna um ponteiro do tipo void para o início do espaço de memória alocado.

### Sintaxe

````
<ponteiro> = (<cast>*) malloc(<tamanho em bytes>); 
p = (int*) malloc(4);
````
![malloc](https://github.com/bruleonel/linguagem-c/assets/104650333/6b623f6b-6688-44b9-b00f-4cbe811fb2e3)

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

Como saber o tamanho do vetor?
![como-saber-o-tamanho-do-vetor](https://github.com/bruleonel/linguagem-c/assets/104650333/9d549085-1c46-4167-b1ec-a449b83b99cb)

## Listas

### Listas Simplesmente Encadeadas
![Captura de tela 2023-05-29 195716](https://github.com/bruleonel/linguagem-c/assets/104650333/b7c0a396-557f-43ab-93cf-f5de5cb22351)

### Listas Duplamente Encadeadas
![Captura de tela 2023-05-29 195726](https://github.com/bruleonel/linguagem-c/assets/104650333/49ad677b-3039-45b1-b6dd-540131415ee7)

### Listas 
![Captura de tela 2023-05-29 200123](https://github.com/bruleonel/linguagem-c/assets/104650333/35c9893f-ec2f-4a3f-88ac-518354a1c8df)

### Pilha || Stack

<div align="center">
    <img src="/img/pilha.png">
</div>


![image](https://github.com/bruleonel/linguagem-c/assets/104650333/c681cb32-50f2-4e49-9344-c955858bd898)
![image](https://github.com/bruleonel/linguagem-c/assets/104650333/dd2e27ea-45a0-4ccc-8ff1-4a35f6672fc9)
![image](https://github.com/bruleonel/linguagem-c/assets/104650333/22e77178-6def-48c6-a103-5246f1b60358)



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

### Fila

<div align="center">
    <img src="/img/fila.png">
</div>

![image](https://github.com/bruleonel/linguagem-c/assets/104650333/06dd040d-2d80-4fc0-8a17-1cefdd7cb380)
![image](https://github.com/bruleonel/linguagem-c/assets/104650333/9948d137-ab73-4387-9d8d-fcc62cd5e0e9)
![image](https://github.com/bruleonel/linguagem-c/assets/104650333/bc602808-93f5-4348-98cd-c95083f23fb8)




Este tipo de estrutura de dados é dita ser FIFO (First in, first out), ou seja, o primeiro elemento a entrar na estrutura é o primeiro a sair. O nome fila, por si só, já é auto-explicativo. Imagine uma fila de banco. A primeira pessoa que chegou na fila, é a que vai ser atendida primeiro.

**Estrutura de Dados da Fila**

````
struct tipo_pilha {
    int dados [tamanho];
    int inicio;
    int fim;
}
````

# Anotações Importantes | Estruturas de Dados Dois

## Arvores Binárias

<div align="center">
    <img src="img/arvore.png">
</div>

Uma árvore binária é uma estrutura de dados que pode ser representada como uma hierarquia onde cada elemento é chamado de nó. O nó inicial ou o primeiro elemento é chamado de raiz.

*Só existe um caminho de um nó ao outro*

**Definição:** Conjunto finito de elementos T = { R, E, D}

- No exemplo acima há três subconjuntos distintos:
- Raiz (R);
- Subárvore binária esquerda (E);
- Subárvore binária direita (D).

- Pode ser vazio, T = 0.

Exemplo:     

T.a = { R.a, E.a, D.a }

R.a = {A}

E.a = T.b

D.a = T.c

<div align="center">
    <img src="img/b1.png">
    <img src="img/b2.png">
</div>

Nesse exemplo A é pai de B e C, da mesma maneira C e B é filho de A. Um nó sem filho é um nó folha.

Os nós acima são nós **ancestrais** e abaixo **descendente**.

### Nível

<div align="center">
    <img src="img/ni.png">
</div>

### Altura

<div align="center">
    <img src="img/h.png">
</div>

*Obs: Qual a altura de B?*

<div align="center">
    <img src="img/b.png">
</div>

## Arvores Estritamente Binárias

<div align="center">
    <img src="img/exb.png">
</div>

Árvore estritamente binária: Cada nó possui exatamente 0 ou 2 filhos. Árvore binária completa: Nós com menos de 2 filhos ficam no úlimo ou no penúltimo nível da árvore. Árvore binária cheia: Nós com menos de 2 filhos ficam no último nível da árvore.

``n° de nós = (2*folhas) -1``

Seguindo o exemplo: Nós = (6 * 2) -1   =>   Nós = 11.

## Arvores Binárias Completa

<div align="center">
    <img src="img/abc.png">
</div>

Árvore binária completa : em uma árvore binária completa todos os níveis, exceto possivelmente o último , está completamente cheia, e todos os nós no último nível são, tanto à esquerda quanto possível. Assim fica claro entender o termo, "tanto à esquerda quanto possível". Caso contrário, os nós vão se sobrepôr.

*Obs: Uma árvore binária completa também é uma árvore estritamente binária, porém uma árvore binária não é, necessariamente, uma árvore binária completa!*


## Implementação de Árvores Binárias

**Estática:** Sem registros e com registros;
**Dinâmicas:** Utiliza registros com ponteiros.

### Busca em árvores Binárias

- Árvore binária ordenada;
- Árvore balanceada.
