#include <stdio.h>
#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

				if(mat->c != b->r)
				{
                        printf("Blad nieprawidlowych rozmiarow macierzy");
                        return 2;
				}

                for(int z=0; z < mat->c && z < mat->r; z++)
                {
                        if(mat->data[z][z]== 0)
                        {
                                printf("Blad dzielenia przez 0 (element na diagonali = 0)");
                                return 1;
                        }
                }

                x->data[x->r-1][0] = b->data[b->r-1][0] / mat->data[mat->r-1][mat->c-1];

                double suma = 0;
                for (int i= x->r-2; i >= 0; i--)
                {
                        for(int k= i+1; k >= i; k--)
                        {
                                suma += (mat->data[i][k])* (x->data[k][0]);
                        }
                        x->data[i][0] = (b->data[i][0] - suma)/ (mat->data[i][i]);
                        suma = 0;
                }
				return 0;
}
