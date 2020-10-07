#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void euler(int input, int *numbers)
{
	int p_max;
	int step;
	int current;
	int i;

	i = 2;
	p_max = sqrt(input);
	while (i <= p_max)
	{
		step = i;
		current = i + step;
		while (current < input)
		{
			numbers[current] = 1;
			current += step;
		}
		i++;
		while (i <= p_max && numbers[i] == 1)
		{
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	FILE *file;

	int *numbers;
	int i;
	int step;
	int p_max;
	int input;
	int current;

	if (argc != 3)
	{
		printf("Usage : ./Sieve [number] [output_file]\n");
		return 1;
	}

	file = fopen(argv[2], "wb+");

	input = atoi(argv[1]);
	numbers = malloc(input * sizeof(int));

	euler(input, numbers);
	i = 2;
	while (i < input)
	{
		if (numbers[i] != 1)
		{
			fprintf(file,"%d ", i);
		}
		i++;
	}
}
