-----------natrix mul---
/*
 * standard includes
 */
	#include <stdio.h>
	#include <stdlib.h>
/*
 *  includes for GSL components
 *  	- use double precision
 */
	#include <gsl/gsl_vector_double.h>
	#include <gsl/gsl_matrix_double.h>
	#include <gsl/gsl_rng.h>
	#include <gsl/gsl_randist.h>

/*
 * FUNCTIONS
 */

/*
 * simple Fibonacci sequence generator function, using recursion
 */
size_t fib(size_t k)
{
	if (k==0)
	{
		return 0;
	}
	else if (k==1)
	{
		return 1;
	}
	else /* k >= 2 */
	{
		return fib(k-1) + fib(k-2);
	}
}
gsl_matrix *embt_mm(const gsl_matrix *U,const gsl_matrix *V, size_t N)
{
	gsl_matrix *W=gsl_matrix_calloc(N,N);
	double sum=0;
	for (size_t i=0;i!=N;i++)
	{
		for(size_t j=0;j!=N;j++)
		{
			for (size_t k=0;k!=N;k++)
			{
				sum=sum+gsl_matrix_get(U,i,k)*gsl_matrix_get(V,k,j);
			}
			gsl_matrix_set(W,i,j,(double)sum);
			sum=0;
		}
	}
	return W;
}

gsl_matrix *embt_apb(gsl_vector *u, gsl_vector *v,size_t N)
{
	gsl_vector *w=gsl_vector_calloc(N);
	gsl_vector_add(w,u);
	gsl_vector_add(w,v);
	return w;
}

gsl_matrix *embt_m_print(const gsl_matrix *U, size_t N)
{
	for (size_t i = 0; i != N; ++i)
	{
		for (size_t j=0;j!=N;j++)
		{
			printf("%0.2f\t",gsl_matrix_get(U, i, j));
		}
		printf("\n");
	}
}
gsl_matrix *embt_v_print(const gsl_vector *u, size_t N)
{
	for (int i = 0; i != N; ++i)
	{
		printf("%0.2f\n",gsl_vector_get(u, i));
	}
}
int main()
{
	/*
	 * INITIALIZE PARAMETERS
	 */
		/* vectors parameters */
		size_t		N=3; /* index type, vector sizes */
		gsl_vector *a = gsl_vector_alloc(N); /* allocate vector from heap of size N */
		gsl_vector *b = gsl_vector_alloc(N); /* allocate vector from heap of size N */
		gsl_vector *c = gsl_vector_calloc(N); /* allocate vector of size N but initialize entries to zero */

		/* random number generator parameters */
		const gsl_rng_type *T;
		gsl_rng *r; /* handle for our random number generator */

		/* matrix parameters */
		gsl_matrix *A = gsl_matrix_alloc(N,N);
		gsl_matrix *B = gsl_matrix_alloc(N,N);
		gsl_matrix *C = gsl_matrix_calloc(N,N);

	/*
	 * SET UP RANDOM NUMBER GENERATION
	 */
		gsl_rng_env_setup();
		T = gsl_rng_default;
		r = gsl_rng_alloc(T);

	/*
	 *  VECTOR OPERATIONS
	 */
		/* set the vector elements */
		for (size_t i = 0; i != N; ++i)
		{
			gsl_vector_set(a, i, fib(i)); /* set element i of vector a to Fibonacci number i */
			gsl_vector_set(b, i, gsl_ran_flat(r,-1.0,+1.0)); /* set element of vector b to random number */
		}

		/* c = a + b */
		c=embt_apb(a,b,N); /* c += a */
		//gsl_vector_add(c, b); /* c += b */

		/* print results */

		int sum=0;
	/*	MATRIX OPERATIONS */
		for (size_t i=0;i!=N;i++)
			for (size_t j=0;j!=N;j++)
			{
				//size_t x=j+(i*N);
				gsl_matrix_set(A,i,j,(double)fib(j+i*N));
				gsl_matrix_set(B,i,j,gsl_ran_flat(r,-100,+100));
			}
		//gsl_matrix_mul_elements(C, A); /* c += a */
		//gsl_matrix_mul_elements(C, B); /* c += b */
		C=embt_mm(A,B,N);

		printf("a= \n");embt_v_print(a,N);
		printf("b= \n");embt_v_print(b,N);
		printf("c= \n");embt_v_print(c,N);
		printf("A= \n");embt_m_print(A,N);
		printf("B= \n");embt_m_print(B,N);
		printf("C= \n");embt_m_print(C,N);

	/* de-allocate memory */
	gsl_vector_free(a);
	gsl_vector_free(b);
	gsl_vector_free(c);
	gsl_matrix_free(A);
	gsl_matrix_free(B);
	gsl_matrix_free(C);
	return EXIT_SUCCESS;
}
