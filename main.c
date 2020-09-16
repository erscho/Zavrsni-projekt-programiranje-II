#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void dodajUSkladiste(int, FILE *);

void procitajSkladiste(FILE *);

void pretraziPoTipu(FILE *);

void pretraziPoVrsti(FILE *);

void pretraziPoCijeni(FILE *);

void pretraziPoVelicini(FILE *);

void pretraziPoBoji(FILE *);

int main(void) {
	FILE *skladiste = fopen("skladiste.txt", "a");
	fclose(skladiste);
	int n, gotovo = 0;
	printf("Dobrodosli u skladiste online trgovine!\n");
	
	do {
		printf(" Koju opciju zelite?\n");
		printf(" 1. Pritisnite jedan ako zelite vidjeti sto se nalazi u online skladistu\n");
		printf(" 2. Pritisnite dva ako zelite dodati nove artikle\n");
		printf(" 3. Pritisnite tri ako zelite pretraziti artikle po tipu\n");
		printf(" 4. Pritisnite četiri ako zelite pretraziti artikle po vrsti\n");
		printf(" 5. Pritisnite pet ako zelite pretraziti artikle po cijeni\n");
		printf(" 6. Pritisnite sest ako zelite pretraziti artikle po velicini\n");
		printf(" 7. Pritisnite sedam ako zelite pretraziti artikle po boji\n");
		printf(" 8. Pritisnite osam ako zelite otvoriti novi list skladista\n");
		printf(" 9. Pritisnite devet ako ste gotovi sa radom.\n");

		do {
			scanf(" %d", &n);
			if (n < 1 || n > 9) {
				printf("Oprostite, ali ta opcija ne postoji. Pokusajte ponovo.\n");
			}
		} while (n < 1 || n > 9);

		int x;
		switch (n) {
		case 1:
			skladiste = fopen("skladiste.txt", "r");
			procitajSkladiste(skladiste);
			fclose(skladiste);
			break;
		case 2:
			skladiste = fopen("skladiste.txt", "a");
			printf("Koliko artikala zelite dodati?\n");
			scanf("%d", &x);
			dodajUSkladiste(x, skladiste);
			fclose(skladiste);
			break;
		case 3:
			skladiste = fopen("skladiste.txt", "r");
			pretraziPoTipu(skladiste);
			fclose(skladiste);
			break;
		case 4:
			skladiste = fopen("skladiste.txt", "r");
			pretraziPoVrsti(skladiste);
			fclose(skladiste);
			break;
		case 5:
			skladiste = fopen("skladiste.txt", "r");
			pretraziPoCijeni(skladiste);
			fclose(skladiste);
			break;
		case 6:
			skladiste = fopen("skladiste.txt", "r");
			pretraziPoVelicini(skladiste);
			fclose(skladiste);
			break;
		case 7:
			skladiste = fopen("skladiste.txt", "r");
			pretraziPoBoji(skladiste);
			fclose(skladiste);
			break;
		case 8:
			skladiste = fopen("skladiste.txt", "w");
			fclose(skladiste);
			break;
		case 9:
			gotovo = 1;
			break;
		default:
			break;
		}
	} while (!gotovo);

	return 0;
}

void dodajUSkladiste(int x, FILE *skladiste)
{
	for (int i = 0; i < x; i++)
	{
		artikl a;
		printf("Unesite spol: (M,Z) ");
		scanf("%s", a.tip);
		printf("\nUnesite vrstu artikla kojeg zelite dodati: ");
		scanf("%s", a.vrsta);
		printf("\nUnesite velicinu artikla kojeg zelite dodati: ");
		scanf("%s", a.velicina);
		printf("\nUnesite cijenu artikla kojeg zelite dodati: ");
		scanf("%lf", &a.cijena);
		printf("\nUnesite boju artikla kojeg zelite dodati: ");
		scanf("%s", a.boja);
		if(ftell(skladiste) != 0) fprintf(skladiste, "\n");
		fprintf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, a.cijena, a.boja);
	}
}

void procitajSkladiste(FILE *skladiste)
{
	fseek(skladiste, 0, SEEK_END);
    int size = ftell(skladiste);
	if(size == 0){
		printf("Skladiste je prazno!\n\n");
		return;
	}
	fseek(skladiste, 0, SEEK_SET);

	while (1)
	{
		if (feof(skladiste))
		{
			break;
		}
		artikl a;
		fscanf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, &a.cijena, a.boja);
		printf("Tip: %s ", a.tip);
		printf("Vrsta: %s ", a.vrsta);
		printf("Velicina: %s ", a.velicina);
		printf("Cijena: %.2lf ", a.cijena);
		printf("Boja: %s", a.boja);
		printf("\n");
	}
	printf("\n");
}

void pretraziPoTipu(FILE *skladiste)
{
	char trazeniTip[40];
	printf("Odaberite koji tip artikla zelite: ");
	scanf("%s", trazeniTip);
	int i = 0;
	printf("\n");
	while (1)
	{
		if (feof(skladiste))
		{
			break;
		}
		artikl a;
		fscanf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, &a.cijena, a.boja);

		if (strcmp((const char *)trazeniTip, (const char *)a.tip) == 0)
		{
			printf("Tip: %s ", a.tip);
			printf("Vrsta: %s ", a.vrsta);
			printf("Velicina: %s ", a.velicina);
			printf("Cijena: %.2lf ", a.cijena);
			printf("Boja: %s", a.boja);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void pretraziPoVrsti(FILE *skladiste)
{
	char trazenaVrsta[40];
	printf("Odaberite koju vrsta artikla zelite: ");
	scanf("%s", trazenaVrsta);
	int i = 0;
	printf("\n");
	while (1)
	{
		if (feof(skladiste))
		{
			break;
		}
		artikl a;
		fscanf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, &a.cijena, a.boja);

		if (strcmp((const char *)trazenaVrsta, (const char *)a.vrsta) == 0)
		{
			printf("Tip: %s ", a.tip);
			printf("Vrsta: %s ", a.vrsta);
			printf("Velicina: %s ", a.velicina);
			printf("Cijena: %.2lf ", a.cijena);
			printf("Boja: %s", a.boja);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void pretraziPoCijeni(FILE *skladiste)
{
	double cijenaMin, cijenaMax;
	printf("Unesite minimalnu cijenu koju zelite: ");
	scanf("%lf", &cijenaMin);
	printf("Unesite maksimalnu cijenu koju zelite: ");
	scanf("%lf", &cijenaMax);
	int i = 0;
	printf("\n");
	while (1)
	{
		if (feof(skladiste))
		{
			break;
		}
		artikl a;
		fscanf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, &a.cijena, a.boja);

		if (a.cijena <= cijenaMax && a.cijena >= cijenaMin)
		{
			printf("Tip: %s ", a.tip);
			printf("Vrsta: %s ", a.vrsta);
			printf("Velicina: %s ", a.velicina);
			printf("Cijena: %.2f ", a.cijena);
			printf("Boja: %s", a.boja);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void pretraziPoVelicini(FILE *skladiste)
{
	char trazenaVelicina[40];
	printf("Odaberite koju velicinu artikla zelite: ");
	scanf("%s", trazenaVelicina);
	int i = 0;
	printf("\n");
	while (1)
	{
		if (feof(skladiste))
		{
			break;
		}
		artikl a;
		fscanf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, &a.cijena, a.boja);

		if (strcmp((const char *)trazenaVelicina, (const char *)a.velicina) == 0)
		{
			printf("Tip: %s ", a.tip);
			printf("Vrsta: %s ", a.vrsta);
			printf("Velicina: %s ", a.velicina);
			printf("Cijena: %.2lf ", a.cijena);
			printf("Boja: %s", a.boja);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void pretraziPoBoji(FILE *skladiste)
{
	char trazenaBoja[40];
	printf("Unesite koju boju artikla zelite: ");
	scanf("%s", trazenaBoja);
	int i = 0;
	printf("\n");
	while (1)
	{
		if (feof(skladiste))
		{
			break;
		}
		artikl a;
		fscanf(skladiste, "%s %s %s %lf %s", a.tip, a.vrsta, a.velicina, &a.cijena, a.boja);

		if (strcmp((const char *)trazenaBoja, (const char *)a.boja) == 0)
		{
			printf("Tip: %s ", a.tip);
			printf("Vrsta: %s ", a.vrsta);
			printf("Velicina: %s ", a.velicina);
			printf("Cijena: %.2lf ", a.cijena);
			printf("Boja: %s", a.boja);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}