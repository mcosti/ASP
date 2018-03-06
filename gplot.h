#ifndef _GPLOT_H_
#define _GPLOT_H_

// includeri standard
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define GP_CMD_SIZE 1024

// definesc o structura pentru manipulare subprocesului gnuplot
typedef struct _GPLOT_CTRL_ {
    // streamul de control al subprocesului
    FILE* gp; 
    // string format plotare
    char pstyle[32];
} gplot_ctrl;

/*************************************************************
 * Nume: check_X_display()
 * Intrare:
 * Iesire: POSIX : 0, daca variabila de mediu e definita, 1 altfel. 
 * Functionalitate: Verifica variabila de mediu DISPLAY si implicit
 * starea serverului X
 * Obs: 
 *************************************************************/
int check_X_display(void);


/*************************************************************
 * Nume: gplot_init()
 * Intrare:
 * Iesire: gplot_ctrl* 
 * Functionalitate: Functia initializeaza structura de control pentru o sesiune
 *                  gnuplot. Initializeaza stilul grafic
 * Obs: 
 *************************************************************/
gplot_ctrl* gplot_init(void);


#endif

