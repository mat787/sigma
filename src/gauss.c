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

	if(mat->r != mat->c)
	{
		printf("Macierz nie jest kwadratowa");
		return -1;
	}
	int n = mat->r;
// create augmented matrix
	workMat = createMatrix(n, n+1);
    	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
                        workMat->data[i][j] = mat->data[i][j];
                }
        }
        for (i = 0; i < n; i++)
        {
          workMat->data[i][n] = *b->data[i];
        }
  
printf("start n=%d\n", n);
	for(i = 0; i < n-1; i++)
	{	
        	for(j = 1; j <= n; j++)
        	{
printf("i=%d, j=%d\n", i, j);

//            		if(j > i)
            		{
if (mat->data[i][i] == 0)
 printf("dzielenie przez 0\n");
	 			c = workMat->data[j][i]/workMat->data[i][i];
               			for(k=0; k<=n; k++)
               			{	
printf("j=%d, k=%d\n", j,k);
                    			workMat->data[j][k] = workMat->data[j][k]-c*workMat->data[i][k];
                		}
            		}
        	}
    	}

if (mat->data[n-1][n-1] == 0)                               
 printf("dzielenie przez 0\n");

	*b->data[n-1] = workMat->data[n-1][n]/workMat->data[n-1][n-1];

	return 0;

}

