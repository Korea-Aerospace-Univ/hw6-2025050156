

#include <stdio.h>

int main(void)
{
	int N = 0;
	int d1[20] = {0}, d2[20] = {0};
	int *p1 = nullptr, *p2 = nullptr;
	
	scanf("%d", &N);
	for(p1=d1; p1<d1+N; p1++)
		scanf("%d", p1);
	for(p2=d2; p2<d2+N; p2++)
		scanf("%d", p2);
	for(p1=d1, p2=d2+N-1; p1<d1+N || p2>=d2; p1++, p2--)
		printf(" %d", *p1 + *p2);

	return 0;
}
