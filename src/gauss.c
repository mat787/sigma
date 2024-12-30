#include "gauss.h"
#include <stdio.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b)
{
	int i,j,k;
	double c;

	Matrix* workMat;
	
        if(mat->r == mat->c)
        {

	        int n = mat->r;
// utworzenie macierzy rozszerzonej
        	workMat = createMatrix(n, n+1);

		if (workMat != NULL)
		{
//przepisanie mat do workmat
        		for (i = 0; i < n; i++)
        		{
        		        for (j = 0; j <= n; j++)
        		        {
        		                workMat->data[i][j] = mat->data[i][j];
        		        }
       			}
//przepisanie b do workmat
        		for (i = 0; i < n; i++)
        		{
        		        workMat->data[i][n] = b->data[i][0];
        		}
// eliminacja Gaussa z pivotem

             		for(i = 0; i < n; i++)
		     	{
				int pivot = i;
                                for(j = i+1; j<n; j++)
                                {
				        if (fabs(workMat->data[j][i]) > fabs(workMat->data[pivot][i]))
                                        {
                                                pivot = j;
                                        }
				}
                                if (workMat->data[i][pivot]==0.0)
                                {
                                        printf("Dzielenie przez 0\n");
                                        freeMatrix(workMat);
                                        return 1;
                                }
                                 if (pivot != i)
                                {
                                      swap_rows(workMat,i,pivot);
                                }
                       		for(j = i+1; j < n; j++)
                                {

                                        c = workMat->data[j][i]/workMat->data[i][i];

                                        for(k=i; k<=n; k++)
                                        {
                                                workMat->data[j][k] -= c*workMat->data[i][k];
                                        }
                                }

			}				
//przepisanie workmat do mat
        		for (i = 0; i < n; i++)
        		{
        		        for (j = 0; j < n; j++)
        		        {
        		                mat->data[i][j] = workMat->data[i][j];
        		        }
        		}
//przepisanie workmat do b
        		for (i = 0; i < n; i++)
        		{
        		        b->data[i][0] = workMat->data[i][n];
        		}
// zwolnienie macierzy rozszerzonej
			freeMatrix(workMat);
			return 0;
		} else printf("Nie udalo sie utworzyc macierzy rozszerzonej\n");
	} else printf("Macierz nie jest kwadratowa\n");
	return -1;

}

