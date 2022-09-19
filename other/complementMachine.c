#include <stdio.h>

int main()
{	
	char name[31];
	
	printf("What's your name?\n");
	
	scanf("%s", name);
		
	printf("Hello %s, you look great today!\n",name);
	return 0;
}
