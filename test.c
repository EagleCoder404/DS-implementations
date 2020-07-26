#include <stdio.h>
#include <string.h>

int main()
{
	char a[]="x";
	char *b = (char*)malloc(1);
	printf("%d",a == 'x');
	dealloc(b);
	return 0;
}


