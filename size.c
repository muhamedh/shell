#include <stdio.h>
#include <stdlib.h>

int main(void){
	char a[1024];
	fgets(a, 1024, stdin);
	printf("%d", strlen(a));
	return 0;
}

