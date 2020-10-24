/*
 * soft.c progam for billing
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


#include<stdio.h>
#include<time.h>
int main()
{
	char fud_name[20], s_name[10];
	int price,qty;
	time_t t;   // not a primitive datatype
    time(&t);
    printf("enter server name: ");
    gets(s_name);
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
	printf("DATE/TIME: %s", ctime(&t));
	printf("STATION #:0.1-2  ");printf("Server #: %s\n",s_name);
	printf("RECIEPT #:001-2-0472\n");
	printf("==================================\n");

		printf("\t    SALE(Here)\n");
	printf("==================================\n");
	printf("Qty\tProduct\t      Price     Sum\n");
	printf("==================================\n");
	for(int i=0;i<5;i++)
	{
	printf("%d\t%s     %d\t %.2f\n",qty,fud_name,price,sum);
	}
	printf("==================================\n");

	printf("Subtotal                    %.2f \n", sum);
	printf("HST                         %.2f\n", hst);
	printf("TOTAL                       %.2f\n", total);
	printf("\n");
	printf("Visa                        %.2f\n", total);
    printf("----------------------------------\n");
    printf("\tCard Transaction Record\n");
    printf("----------------------------------\n");
    printf("DATE/TIME: %s\n", ctime(&t));
    printf("Issuer Name         Visa\n");
    printf("Account No:         3012\n");
    printf("Result:             Captured\n");
    printf("Authorization  No:  460997\n");
    printf("Reference#:         1077967\n");
    printf("Trout ID(Invoice#): 0082542\n\n");
    printf("Amount:                    %.2f\n\n", total);
    printf("Gratuity:   _______________________\n\n");
    printf("Total:      _______________________\n\n");
    printf("Signature X _______________________\n");
    printf("I agree to pay the above amount\n\n");
    printf("----------------------------------\n");
    printf("\t  Store Copy\n\tOrder No: 0472\n");




}





