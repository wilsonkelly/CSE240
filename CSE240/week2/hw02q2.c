#include <stdio.h>
#pragma warning(disable : 4996)

//functions
int addf(int a, int b) {
	return a + b;
}

int squared_addf(int a, int b) {
	return ((a * a) + (b * b));
}

int absf(int a) {
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

int oddf(int a) {
	if (a % 2 == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

//macros
#define addm(a,b) (a+b)
#define squared_addm(a,b) (a*a+b*b)
#define absm(a) (((a) < (0)) ? (-a) : (a))
#define oddm(a) (((a) % (2)==0) ? (0) : (1))

int main(){
		
	int a = 3, b = 6;
	printf("addf(a, b) = %d", addf(a, b));
	printf("\naddm(a, b) = %d", addm(a, b));
	printf("\naddf(a++, b--) = %d", addf(a++, b--));
	a = 3, b = 6;  // reset a, b values; 
	printf("\naddm(a++, b--) = %d", addm(a++, b--));
	
	a = 3, b = 6;
	printf("\nsquared_addf(a, b) = %d", squared_addf(a, b));
	printf("\nsquared_addm(a, b) = %d", squared_addm(a, b));
	printf("\nsquared_addf(--a, b++) = %d", squared_addf(--a, b++));
	a = 3; b = 6;
	printf("\nsquared_addm(--a, b++) = %d", squared_addm(--a, b++));

	a = 3; b = 6;
	printf("\nabsf(a) = %d", absf(a));
	printf("\nabsm(a) = %d", absm(a));
	printf("\nabsf(--a) = %d", absf(--a));
	a = 3; b = 6;
	printf("\nabsm(--a) = %d", absm(a--));
	
	a = 3; b = 6;
	printf("\noddf(a) = %d", absf(a));
	printf("\noddm(a) = %d", absm(a));
	printf("\noddf(++a) = %d", absf(++a));
	a = 3; b = 6;
	printf("\noddm(++a) = %d", absm(++a));
}