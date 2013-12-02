#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Calculate multiplicaiton of two integer strings
 */
char *product(const char *n1, const char *n2)
{
	int n1_len, n2_len;
	int i, j, k;
	int temp, carry;
	char *result;
	int result_len;

	n1_len = strlen(n1);
	n2_len = strlen(n2);
	result_len = n1_len + n2_len;
	result = (char *)calloc(result_len+1, sizeof(char));

	while (*n1)
		n1++;
	n1--;
	while (*n2)
		n2++;
	n2--;

	for (i=0; i<n2_len; i++) {
		carry = 0;
		for (j=0; j<n1_len; j++) {
			temp = (*n1-'0') * (*n2-'0') + result[result_len-1-j-i] + carry;
			result[result_len-1-j-i] = temp%10;
			carry = temp/10;
			n1--;
		}
		if (carry)
			result[result_len-1-j-i] = carry;
		n1 = n1 + n1_len;
		n2--;
	}
	for (k=0; k<result_len; k++) {
		result[k] = result[k] + '0';
	}
	result[k] = '\0';
	return result;
}


int main()
{
	char s1[] = "123456789";
	char s2[] = "456789123";

	printf("result: %s\n", product(s1, s2));

	return 0;
}

