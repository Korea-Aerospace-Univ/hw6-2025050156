#include <stdio.h>

char fromidx(int idx);
int toidx(char c);

int main(void)
{
	int N = 10;
	char c[10];
	char *p = nullptr;
	int count[52] = {0};  /* 0~25: 소문자, 26~51: 대문자 */
	int *cp = nullptr;
	int max = -1, maxIdx = -1;

	cp = count;

	for(p=c; p<c+N; p++) {
		scanf("%c", p);
		(*(cp + toidx(*p)))++;
	}

	for(p=c; p<c+N; p++)
		if(*(cp + toidx(*p)) > max) {
			max = *(cp + toidx(*p));
			maxIdx = cp + toidx(*p) - count;
		}
	
	printf("%c %d", fromidx(maxIdx), max);

	return 0;
}

char fromidx(/* idx */
	int idx)
{
	if(idx <= 'z' - 'a')
		return (char) (idx + 'a');
	else
		return (char) (idx - ('z' - 'a' + 1) + 'A');
}

int toidx(/* c */
	char c)
{
	if(c >= 'a' && c <= 'z')
		return (int) (c - 'a');
	else
		return (int) ('z' - 'a' + 1 + c - 'A');
}
