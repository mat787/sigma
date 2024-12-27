#include "gauss.h"
#include <stdio.h>
#

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b)
{
	int i,j,k,c;
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
//eliminacja gaussa
        		for(j = 0; j < n; j++)
        		{
        		        for(i = 0; i < n; i++)
        		        {
                		        if(i>j)
                	        	{
						if (workMat->data[j][j] == 0.0)
						{
							printf("Dzielenie przez 0\n");
							freeMatrix(workMat);
							return 1;
						}
						
                	                	c = workMat->data[i][j]/workMat->data[j][j];
	
	                                	for(k=0; k<=n; k++)
	                                	{
	                                	        workMat->data[i][k] = workMat->data[i][k]-c*workMat->data[j][k];
	                                	}
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

