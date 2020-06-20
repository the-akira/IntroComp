#include <stdio.h>

// programa que converte Fahrenheit para Celsius
int main()
{
	float fahr, celsius;
	float lower, upper, step; 

	lower = 0;
	upper = 300;
	step = 10;

	fahr = lower;
	printf("Fahrenheit | Celsius\n");
	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %16.2f\n", fahr, celsius);
		fahr = fahr + step;
	}
}