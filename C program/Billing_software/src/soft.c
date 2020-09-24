/*
 * soft.c
 *
 *  Created on: Sep. 23, 2020
 *      Author: govind
 */

/*
 * soft.c
 *
 *  Created on: Sep. 23, 2020
 *      Author: govind
 */
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
int main()
{
	char fud_name[20];
	int price,qty;
	printf("enter the dish name: ");
	//fgets(fud_name, sizeof(fud_name), stdin);
	gets(fud_name);
	printf("enter the price : ");
	scanf("%d",&price);
	printf("enter the quantity : ");
	scanf("%d",&qty);
	float sum= qty*price;
//	printf("%f",sum);
	float hst = ((13*sum)/100);
//	printf("%f",hst);
	float total= hst+sum;\
//	printf("%f",hst);



	printf("\n\t     Mr Jones\n");
	printf("\t1850 Ellesmere Rd\n");
	printf("     Scarborough, ONT, M1H 2V5\n");
	printf("\t  (416)439-8600\n");
	printf("==================================\n");

	printf("==================================\n");

		printf("\t    SALE(Here)\n");
	printf("==================================\n");
	printf("Qty\tProduct\t      Price     Sum\n");
	printf("%d\t%s     %d\t %.2f\n",qty,fud_name,price,sum);

	printf("Subtotal =  %.2f \n", sum);
	printf("HST      =  %.2f\n", hst);
	printf("TOTAL    =  %.2f\n", total);


}





