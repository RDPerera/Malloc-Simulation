#include<stdio.h>
#include "mymalloc.c"
int main()
{
	printMemory(metaList);
	
    char * x=MyMalloc(10000);
    printMemory(metaList);
    
    char * y=MyMalloc(1000);
    printMemory(metaList);
    
    MyFree(y);
    printMemory(metaList);
    
    char * z=MyMalloc(27000);
    printMemory(metaList);
    
    return 0;
}
