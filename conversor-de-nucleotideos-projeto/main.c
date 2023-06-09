//Aluna: Bruna Leonel Matr�cula: 22165682-5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

struct no {
    char dado;
    struct no* prox;
};

struct fila {
    struct no* inicio;
    struct no* fim;
};

struct pilha {
    struct no* topo;
};

void fila_entrar(struct fila* f, struct pilha* p);
void fila_sair(struct fila* f);
void fila_mostrar(struct fila* f);
void menu_mostrar();
void pilha_inserir(struct pilha* p, char dado);
void pilha_sair(struct pilha* p);
void pilha_mostrar(struct pilha* p);
void fila_limpar(struct fila* f);
void pilha_limpar(struct pilha* p);
void pilha_inverter(struct pilha* p);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int op;
    struct fila f;
    struct pilha p;
    f.inicio = NULL;
    f.fim = NULL;
    p.topo = NULL;

    while (1) {
        system("cls || clear");
        fila_mostrar(&f);
        printf("Pilha: ");
        pilha_mostrar(&p);
        menu_mostrar();
        scanf("%d", &op);

        switch (op) {
            case 1:
                fila_limpar(&f);
                pilha_limpar(&p);
                fila_entrar(&f, &p);
                break;
            case 2:
                if (f.inicio != NULL) {
                    fila_sair(&f);
                    pilha_sair(&p);
                } else {
                    printf("\nA fila est� vazia!\n");
                    system("pause");
                }
                break;
            case 0:
                exit(0);
        }
    }

    return 0;
}

void fila_entrar(struct fila* f, struct pilha* p) {
    char sequencia[100];
    printf("\nDigite a sequ�ncia de nucleot�deos: ");
    scanf("%s", sequencia);
    int tamanho = strlen(sequencia);

    int i;
    for (i = 0; i < tamanho; i++) {
        char dado = toupper(sequencia[i]); // Converte para mai�scula

        if (dado == 'A' || dado == 'T' || dado == 'G' || dado == 'C') {
            struct no* novo = (struct no*)malloc(sizeof(struct no));
            novo->dado = dado;
            novo->prox = NULL;

            if (f->inicio == NULL) {
                f->inicio = novo;
                f->fim = novo;
            } else {
                f->fim->prox = novo;
                f->fim = novo;
            }

            pilha_inserir(p, dado);
        } else {
            printf("Sequ�ncia inv�lida! Apenas as letras A, T, G e C s�o permitidas.\n");
            break; // Sai do loop se uma sequ�ncia inv�lida for encontrada
        }
    }
}


void fila_sair(struct fila* f) {
    if (f->inicio != NULL) {
        struct no* temp = f->inicio;
        f->inicio = f->inicio->prox;
        if (f->inicio == NULL)
            f->fim = NULL;
        free(temp);
    }
}

void fila_mostrar(struct fila* f) {
    struct no* atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%c", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void menu_mostrar() {
    printf("\nEscolha uma op��o:\n");
    printf("1 - Digitar sequ�ncia de nucleot�deos\n");
    printf("2 - Excluir letras das sequ�ncias\n");
    printf("0 - Sair\n");
}

void pilha_inserir(struct pilha* p, char dado) {
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->prox = p->topo;
    p->topo = novo;

    if (dado == 'A')
        novo->dado = 'T';
    else if (dado == 'T')
        novo->dado = 'A';
    else if (dado == 'C')
        novo->dado = 'G';
    else if (dado == 'G')
        novo->dado = 'C';
    else
        printf("Sequ�ncia inv�lida!\n");
}

void pilha_sair(struct pilha* p) {
    if (p->topo != NULL) {
        struct no* atual = p->topo;
        struct no* anterior = NULL;
        
        while (atual->prox != NULL) {
            anterior = atual;
            atual = atual->prox;
        }
        
        if (anterior != NULL) {
            anterior->prox = NULL;
        } else {
            p->topo = NULL;
        }
        
        free(atual);
    }
}


void pilha_mostrar(struct pilha* p) {
    struct no* atual = p->topo;
    while (atual != NULL) {
        printf("%c", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void fila_limpar(struct fila* f) {
    while (f->inicio != NULL) {
        fila_sair(f);
    }
    f->fim = NULL;
}

void pilha_limpar(struct pilha* p) {
    while (p->topo != NULL) {
        pilha_sair(p);
    }
}

void pilha_inverter(struct pilha* p) {
    struct no* anterior = NULL;
    struct no* atual = p->topo;
    struct no* proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    p->topo = anterior;
}
