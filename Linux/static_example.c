#include <stdio.h>

int nextvalue()
{
static int i = 0;
i++;
return i;
}
int main()
{
int i;
for(i = 10; i > 0; i--)
{
printf("%d\n", nextvalue());
}
return 0;
}
