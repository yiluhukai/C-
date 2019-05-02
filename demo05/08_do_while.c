/*
 *
 *		do... while循环 
 *
 */
#include <stdio.h>
int  main()
{
	int score = 0;
	do{
		printf("%d\n",score);
		scanf("%d",&score);
	}while(score<0 || score >100);
	return 0;
}
