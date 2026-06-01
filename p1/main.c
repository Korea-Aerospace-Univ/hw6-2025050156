

#include <stdio.h>

char fromidx(int idx);

int main(void)
{
	int N = 10;
	char c[10];
	char *p = nullptr;
	int count[52] = {0};  /* 0~25: 소문자, 26~51: 대문자 */
	int *cp = nullptr;
	int max = -1, maxIdx = -1;
	int firstIdx[52] = {0};
	int *fp = nullptr;

	for(p=c, cp=count, fp=firstIdx; p<c+N; p++) {
		scanf("%c", p);
		if(*p >= 'a' && *p <= 'z') {
			(*(cp + *p - 'a'))++;
			if(!(*(fp + *p - 'a')))
				(*(fp + *p - 'a')) = p - c + 1;
		} else if(*p >= 'A' && *p <= 'Z') {
			(*(cp + ('z' - 'a' + 1) + *p - 'A'))++;
			if(!(*(fp + ('z' - 'a' + 1) + *p - 'A')))
				(*(fp + ('z' - 'a' + 1) + *p - 'A')) = p - c + 1;
		}
	}

	for(cp=count; cp<count+52; cp++)
		if(*cp > max || (*cp == max && *(fp + maxIdx) - 1 > *(fp + (cp - count)) - 1)) {
			max = *cp;
			maxIdx = cp - count;
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
