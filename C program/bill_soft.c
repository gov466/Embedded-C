#include<stdio.h>
int main()
{
	char fud_name;
	int price,qty;
	printf("enter the dish name: ");
	scanf("%s",&fud_name);
	printf("enter the price : ");
	scanf("%d",&price);
	printf("enter the quantity : ");
	scanf("%d",&qty);
	int sum= qty*price;
	printf("%d",sum);
	float hst = 13%sum;
	printf("%f",hst);
	float total= hst+sum;\
	printf("%f",hst);

	printf("\n     Mr Jones\n");
	printf("  1850 Ellesmere Rd\n");
	printf("Scarborough, ONT, M1H 2V5\n");
	printf("===========================\n");

	printf("===========================\n");

		printf("SALE(Here)");
	printf("===========================\n");
	
	printf("subtotal = %f", total);
	printf("HST= %f", hst);
	printf("TOTAL = %f", total);


}
