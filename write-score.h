// Write Score To File //

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *file;
int line = 0;

int lineNumber()
{
	char chr;

	if (access("scores.txt", F_OK) != 0)
	{
		file = fopen("scores.txt", "w");
		fprintf(file, "--SCORES--\n");
		fclose(file);
	}

	file = fopen("scores.txt", "r");

	chr = getc(file);
	while (chr != EOF)
	{
		if (chr == '\n')
		{
			line = line + 1;
		}
		chr = getc(file);
	}
	fclose(file);
	if (line == 0)
	{
		return 1;
	}
	else
	{
		return line - 1;
	}
}

void writeDate(int data)
{
	int scoreCount = 1;
	lineNumber();
	if (access("scores.txt", F_OK) == 0)
	{
		scoreCount = line;
		file = fopen("scores.txt", "a");
		fprintf(file, "\nScore_%d = %d", scoreCount, data);
	}
	else
	{
		scoreCount = line;
		file = fopen("scores.txt", "a");
		fprintf(file, "\nScore_%d = %d", scoreCount, data);
	}
	fclose(file);
}