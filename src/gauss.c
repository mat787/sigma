#include "gauss.h"
#include <stdio.h>
#include <math.h>

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
				int index_max = j;
				int wartosc_max =workMat->data[index_max][j];
        		        for(i = j+1; i<n; i++)
                                {
                                        if (fabs(workMat->data[i][j]) > wartosc_max )
                                                wartosc_max = workMat->data[i][j], index_max = i;
                                }
                                if (!workMat->data[j][index_max])
				{
					printf("return j = %d\n", j);
                                        return j;
				}
                                if (index_max != j)
                                {
					printf("swap %d, %d\n", j, index_max);
                                	//swap_rows(workMat,j,index_max);
                                }
				

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
// zwolnienie macierzy rozszerzone
printToScreen(workMat);
printToScreen(mat);
printToScreen(b);

			freeMatrix(workMat);
			return 0;
		} else printf("Nie udalo sie utworzyc macierzy rozszerzonej\n");
	} else printf("Macierz nie jest kwadratowa\n");
	return -1;

}

