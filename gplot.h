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

/*************************************************************
 * Nume: gplot_close()
 * Intrare:
 * Iesire: gplot_ctrl* 
 * Functionalitate: Functia inchide sesiunea activa gnuplot, termina subprocesul si
 *                  elibereaza resursele alocate
 * Obs: 
 *************************************************************/
void gplot_close(gplot_ctrl *h);

/*************************************************************
 * Nume: gplot_cmd()
 * Intrare: Handle pentru sesiunea activa: gplot_ctrl, lista variabila de argumente - argumente gnuplot
 * Iesire: 
 * Functionalitate: Functia asigura comunicarea cu subprocesul gnuplot activ.
 * Obs: Sintaxa comenzilor gnuplot nu este validata.
 *************************************************************/

void gplot_cmd(gplot_ctrl * h, char * cmd, ...);

/*************************************************************
 * Nume: gplot_set_xlabel()
 * Intrare: Handle pentru sesiunea activa: gplot_ctrl, string reprezentand numele axei X
 * Iesire: 
 * Functionalitate: Functia defineste numelei axei X in graficul produs de gnuplot
 * Obs: 
 *************************************************************/

void gplot_set_xlabel(gplot_ctrl * h, char * xtitle);

/*************************************************************
 * Nume: gplot_set_ylabel()
 * Intrare: Handle pentru sesiunea activa: gplot_ctrl, string reprezentand numele axei Y
 * Iesire: 
 * Functionalitate: Functia defineste numelei axei Y in graficul produs de gnuplot
 * Obs: 
 *************************************************************/

void gplot_set_ylabel(gplot_ctrl * h, char * ytitle);

/*************************************************************
 * Nume: gplot_set_style()
 * Intrare: Handle pentru sesiunea activa: gplot_ctrl, string reprezentand stilul de reprezentare grafica
 * Iesire: 
 * Functionalitate: Functia defineste stilul de reprezentare grafica pentru subprocesul gnuplot
 * Obs: 
 *************************************************************/

void gplot_set_style(gplot_ctrl * h, char * style);

#endif

