#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

enum{Add=1, Minus, Multi, Divide, Exit};

int main(char* argh, char* argc, char* argv)
{
	double val1, val2;
	int select;
	double result;
	//atoi();
	//select = atoi(argh);
	//val1 = atof(argc);
	//val2 = atof(argv);
	while(1)
	{
		printf("Enter val1 and val2:");
		scanf("%lf %lf", &val1, &val2);
		printf("Enter calculator mode(1:Add, 2:Minus, 3:Multi, 4:Divide, 5:Exit):");
		scanf("%d", &select);

		switch(select)
		{
			case Add:
			{
				result=Addfunc(val1,val2);
				break;
			}
			case Minus:
			{
				result=Minusfunc(val1,val2);
				break;
			}
			case Multi:
			{
				result=Multifunc(val1,val2);
				break;
			}
			case Divide:
			{
				result=Dividefunc(val1,val2);
				break;
			}
			case Exit:
			{
				return 0;
			}
			default:
			{
				printf("Repeat the other value");
				break;
			}
		}
		printf("Result value: %lf\n", result);

	}
	return 0;
}

