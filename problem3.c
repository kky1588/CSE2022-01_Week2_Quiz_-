#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber(const double min, const double max)
{
	// temp >= 0.0 && temp <= 1.0
	double temp = (double)rand() / (double)RAND_MAX;

	// temp >= min && temp <= max
	temp = min + (max - min)*temp;

	return temp;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 3;
	const double y_c = 2;
	const double r = 1;

	const double f = ((x - x_c)*(x - x_c))/((x_c)*(x_c)) + ((y - y_c)*(y - y_c))/((y_c)*(y_c)) - r * r;

	if (f > 0.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("ellipse.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 6.0);
		double y = getRandomNumber(0.0, 4.0);

		if (isInsideCircle(x, y) == true)
			fprintf(of, "%f, %f\n", x, y);
	}

	fclose(of);
}