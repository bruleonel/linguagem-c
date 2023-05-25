#include <stdio.h>

int main(void) {
	int *p;
	printf("O valor (que corresponde ao endereco) da variavel *p eh = %p\n", p);

	int x = 10;
	printf("O valor da variavel x eh = %i\n", x);
	printf("O valor (que corresponde ao endereco) da variavel x eh = %p\n", &x);

	p = &x;
	printf("Aqui o p recebeu o endereco de x  que eh = %p\n\n", p);

	return 0;
}