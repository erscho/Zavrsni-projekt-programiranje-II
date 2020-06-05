#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void file_read() {
	FILE * skladiste;
	skladiste = fopen("skladiste.txt", "r");
	char ch;
	if (skladiste == NULL)
	{
		perror("Pogreska pri otvaranju filea.\n");
		exit(EXIT_FAILURE);
	}

	printf("Sadrzaj filea je:\n");

	while ((ch = fgetc(skladiste)) != EOF)
		printf("%c", ch);
	fclose(skladiste);
}