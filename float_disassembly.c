// Author: Dhruv Shetty

#include <stdio.h>
#include "float.h"

int main(){

	int s, e, i;
	float m;
	int binary[32], exp[8], frac[23];
	int count = 22;
	int count1 = 7;
	int base;
	int sumExp;
	float sumFrac, basedec;
	int bias = 127;

	float n;
    scanf("%f",&n);

	// Interprets bit vector of float n as an integer
	int *a;
	a = (int *)&n;

	// Checks if n is positive or negative for the sign bit and to place the bit vector into an array
	if (n<0){
		s = -1;
		// Takes negative value and stores its' bit vector into an array
		neg_float_to_pos_binary(binary, a, 32);
	}
	else {
		s = 1;
		// Takes positive value and stores its' bit vector into an array
		float_to_binary(binary, a, 32);
	}

	// Separates the binary bits into exp and frac. Exp gets 8 values, frac gets 23. (sign bit gets 1 for a total of 32)
	for (i = 31; i >= 0; i--) {
		if(i<=31 && i>=9){
			frac[count]=binary[i];
			count--;
		}
		else if(i<=8 && i>=1){
			exp[count1]=binary[i];
			count1--;
		}
	}

	// Converts exp from binary to decimal
    sumExp = binarytodec(exp, 8, 1);

	// Converts frac from binary to decimal
	sumFrac = binaryfractodec(frac, 23, 0.5);

	// Determines if number is normalized, denormalized, or a special case
	// Denormalized case
	if(sumExp==0){
		m = sumFrac;
		e = 1-bias;
		printf("%d\n", s);
		printf("%d\n", e);
		printf("%1.20f\n", m);
	}
	// Normalized case
	else if (sumExp > 0 && sumExp < 255){
		m = sumFrac + 1.0;
		e = sumExp - bias;
		printf("%d\n", s);
		printf("%d\n", e);
		printf("%1.20f\n", m);
	}
	// Special cases
	else {
		if(sumExp == 255){
			if(s == 1 && sumFrac == 0){
				printf("+infinity\n");
			}
			else if(s == -1 && sumFrac == 0){
				printf("-infinity\n");
			}
			else {
				printf("NaN\n");
			}
		}
	}
	return 0;
}