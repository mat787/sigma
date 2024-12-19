#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int mnozenie(Matrix *mat, double a)
{
	int i, j;
for (i = 0; i<mat->r; i++) {
                for (j = 0; j < mat->c; j++) {
                       mat->data[i][j]=mat->data[i][j]*a;


}
int eliminate(Matrix *mat, Matrix *b){
  if(mat->r != mat->c)
	  return -1;
  int n=mat->r;

		return 0;
}

