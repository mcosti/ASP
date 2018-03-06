#include "gplot.h"

/*************************************************************
 * Nume: check_X_display()
 * Intrare:
 * Iesire: POSIX : 0, daca variabila de mediu e definita, 1 altfel. 
 * Functionalitate: Verifica variabila de mediu DISPLAY si implicit
 * starea serverului X
 * Obs: 
 *************************************************************/
int check_X_display(void) {
    char * display;
    if((display = getenv("DISPLAY")) == NULL) {
        fprintf(stderr, "check_X_display(): Variabila de mediu DISPLAY nu e definita. \n");
        return 1;
    }
    else return 0;
}
/*************************************************************
 * Nume: gplot_init()
 * Intrare:
 * Iesire: gplot_ctrl* 
 * Functionalitate: Functia initializeaza structura de control pentru o sesiune
 *                  gnuplot. Initializeaza stilul grafic
 * Obs: 
 *************************************************************/
gplot_ctrl* gplot_init (void) {
    gplot_ctrl * handle;
    if(check_X_display()) return NULL;
    // Initializarea spatiului RAM pentru structura de control
    if((handle = (gplot_ctrl *) malloc(sizeof(gplot_ctrl))) == NULL) {
        fprintf(stdderr, "gplot_init(): Eroare alocare memorie \n");
        return NULL;
    }
}

