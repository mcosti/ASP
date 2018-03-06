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
    
    if((handle->gp = popen("gnuplot", "w")) == NULL) {
        fprintf(stderr, "gplot_init(): Eroare deschidere subproces gplot \n");
        free(handle);
        return NULL;
    }

    strcpy(handle->pstyle, "lines");
    return handle;
} // gplot_init();

void gplot_cmd(gplot_ctrl * h, char * cmd, ...) {
    va_list ap;
    char local_cmd[GP_CMD_SIZE];
    va_start(ap, cmd); // Initializam lista
    vsprintf(local_cmd, cmd, ap); // Variabila in care stocam, ultimul element, lista.
    va_end(ap);
    strcat(local_cmd, "\n"); // Terminator pentru comanda
    fputs(local_cmd, h->gp);
    fflush(h->gp); // Eliminam new line-ul din stream
    return;
} // gplot_cmd()

void gplot_set_xlabel(gplot_ctrl * h, char * xtitle) {
    if(check_X_display()) return;
    char local_cmd[GP_CMD_SIZE];
    sprintf(local_cmd, "set xlabel \"%s\"", xtitle);
    gplot_cmd(h, local_cmd);
    return;
}

void gplot_set_ylabel(gplot_ctrl * h, char * ytitle) {
    if(check_X_display()) return;
    char local_cmd[GP_CMD_SIZE];
    sprintf(local_cmd, "set ylabel \"%s\"", ytitle);
    gplot_cmd(h, local_cmd);
    return;
}

void gplot_set_style(gplot_ctrl * h, char * style) {
    // Exemple: lines, points, linespoints
    if(check_X_display()) return;
    char local_cmd[GP_CMD_SIZE];
    sprintf(local_cmd, "set style \"%s\"", style);
    gplot_cmd(h, local_cmd);
    return;
}


