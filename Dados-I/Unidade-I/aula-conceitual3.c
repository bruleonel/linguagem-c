#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p;
    p = (int *) malloc(4);

    if(p == NULL) {
        printf("erro!\n");
    } else {
        *p = 10;
        printf("O valor de p eh = %i\n", p);
        free(p);
    }
}