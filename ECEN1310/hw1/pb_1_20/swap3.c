#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

void swap3(int* a, int* b, int* c){
	assert (a != NULL);
	assert (b != NULL);
	assert (c != NULL);
	
	int current_b = *b;
	int current_c = *c;

	*b = *a;
	*c = current_b;
	*a = current_c;
}

int main(){
	int a = 0, b = 1, c = 2;
	swap3(&a, &b, &c);
	assert (a == 2);
	assert (b == 0);
	assert (c == 1);
	printf("Order is now: %d, %d, %d\n", a, b, c);
	return 0;
}
