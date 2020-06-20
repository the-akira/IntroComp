#include <stdio.h>

#define LOWER 300
#define UPPER 0
#define STEP -20

// programa que converte Fahrenheit para Celsius
int main()
{
	int fahr;
	float celsius;
	for(fahr = LOWER; fahr >= UPPER; fahr += STEP){
		celsius = (5.0/9.0) * (fahr - 32);
		printf("%3d %6.1f\n", fahr, celsius);
	}
}