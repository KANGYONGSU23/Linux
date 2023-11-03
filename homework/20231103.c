#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	putenv("MYDATA=5");
	printf("%s\n", getenv("MYDATA"));

	execl("20231103[01]", "20231103[01]", (char *)0);
}
