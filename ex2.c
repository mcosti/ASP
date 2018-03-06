#include "gplot.h"
#include <gsl/gsl_sf_bessel.h>
#include <math.h>

/* ia parametrii de la linia de program: program fisier_date
 * in fisier_date vom scrie (xi, J0(xi)), unde xi identifica un interval din cele NMAX
 * fisier-ul date este binar
 * vectorul de date este alocat dinamic
 * 
 * ia intervalul 0-20 si-l imparte in 200 de intervale egale
 * 
 * J0 este o functie besel (functia ce  descrie vibratia unei tobe lovite in centru)
 * 
 * libgsl.so -> librarie unde gasim J0 (double gsl_sf_bessel_J0(double x))
 * 
 */

// numarul de puncte in intervalul 0-SIZE
#define NMAX 200
#define SIZE 20


// coduri de eroare

// accesul RAM
#define MY_MEM_ERR 1
// accesul I/O
#define MY_IO_ERR 2
// apel gresit al programului
#define MY_CALL_ERR 3
// cod de succes
#define MY_SUCCESS 0

int main (int argc, char* argv[]) {
    if (argc != 2) 
    {
        fprintf(stdout, "Utilizare: %s nume_fisier\n", argv[0]);
        fprintf(stdout, "Programul calculeaza perechile (xi, J0(xi)) pe un grid de NMAX puncte pe intervalul 0-20\n");
        fprintf(stdout, "Datele sunt stocate intr-un buffer RAM alocat dinamic iar ulterior scrise intr-un fisier binar dat ca argument\n");
        fprintf(stdout, "Numele fisierului binar - nume_fisier - trebuie dat ca argument in linia de comanda\n\n");
        exit(MY_CALL_ERR);
    }
    
    // numele fisierului de iesire
	char* file_name = argv[1];
    // vaiarbila utilizata pentru indexarea punctelor din grila
    double xi;
    // buffer RAM alocat dinamic
    double* data;
    // va contine perechea extrasa din fisier
    double set[2];
    // folosit ca element de iterare
    int i;
    // stream pentru scriere in fisier
	FILE* fp;
    
    if ((fp = fopen(file_name, "w")) == NULL) 
    {
        fprintf(stderr, "%s: Nu s-a putut deschide fisierul\n", argv[0]);
        exit(MY_IO_ERR);
    }

	if ((data = (double*)malloc(2 * NMAX * sizeof(double))) == NULL) 
    {
		fprintf(stderr, "%s: Nu s-a putut aloca memorie\n", argv[0]);
		exit(MY_MEM_ERR);
	}

	// marime intervale
    double delta = (double)SIZE / NMAX;
	for (i = 0; i < 2 * NMAX; i += 2) 
    {
        xi = ((double)i) * delta / 2;
        *(data + i) = xi;
        *(data + i + 1) = gsl_sf_bessel_J0(xi);
        fprintf(fp, "%.5lf \t %.5lf \n", *(data + i), *(data + i + 1));
	}
	
	fwrite(data, sizeof(double), 2 * NMAX, fp);
    
    fclose(fp); fp = NULL;
    
    printf("Care pereche? Numar intreg par < %d ", NMAX);
    scanf("%d", &i);
    // redeschidem fisierul de date pentru citire
    if ((fp = fopen(file_name, "rb")) == NULL)
    {
        fprintf(stderr, "%s: Nu pot citi\n", argv[0]);
        exit(MY_IO_ERR);
    }
    
    // pozitionam pointerul de fisier pe locul corect
    fseek(fp, 2 * i * sizeof(double), SEEK_SET);
    
    // citire 
    fread(set, sizeof(double), 2, fp);
    
    
    printf("Perechea %d din fisierul de date: \n", i);
    printf("xi = %.5lf\t J0(xi) = %.5lf\n\n", set[0], set[1]);
    
    
    fclose(fp);
    free(data);
    
    h = gplot_init();
    gplot_set_xline(h, "x [div.]");
    gplot_set_yline(h, "J0(x) [div.]");
    gplot_cmd(h, "plot \'%s\' using 1:2 with %s", argv[1], h->pstyle);
    gplot_close(h);

    
	return MY_SUCCESS;
} // end_of_mail()
