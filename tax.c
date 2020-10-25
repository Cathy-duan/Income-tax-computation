#include<stdio.h>
#include <math.h>

/*Mengyue Duan
 * First, I let people enter Filing status,number of dependents, adjusted gross dependents, itemized deduction and federal tax deduction. They I try to find taxable income. Finally I print out the tax*/

int main(void){
	int integer;
	int number;
	int income;
	int itemized;
	int federal;
	int deduction;
	int bracket;
	
	

	printf("Enter 1-4 for filing status\n1.Single\n2.Married filing jointly\n3.Married filing separately\n4.Head of family\n");
	printf("What is your choice? ");
	scanf("%d",&integer);
	if(integer!=1 && integer !=2 && integer !=3 && integer !=4)
	{
		printf("Filing status must be 1-4.\n");
			return 1;

	}

	
	printf("Enter number of dependents: ");
	scanf("%d",&number);

	if(number<0)
	{
		number=0;

	}
	
	printf("Enter adjusted gross income: ");
	scanf("%d",&income);

	if(income<0)
	{
		income =0;
	}

	printf("Enter itemized deduction: ");
	scanf("%d",&itemized);

	if(itemized<0)
	{
		itemized = 0;
	}

	printf("Enter federal tax deduction: ");
	scanf("%d",&federal);
	if(federal<0)
	{
		federal =0;
	}

	if(integer==1)
	{
		if((income>=0)&&(income<=20499))
		{
			deduction = 2500;
		}
		else if((income>=20500)&&(income<=29999))
		{
			bracket=(income-20500)/500+1;
			deduction = 2500-25*bracket;
		}
		else
		{
			deduction = 2000;
		}
	}

	if(integer== 2)
	{
		if((income>=0)&& (income<=20499))
		{
			deduction = 7500;
		}
		else if ((income>=20500)&&(income<=29999))
		{
			bracket=(income-20500)/500+1;
			deduction = 7500-175*bracket;
		}
		else
		{
			deduction =4000;
		}
	}	
	
	if(integer ==3)
	{
		if((income >= 0)&&(income <=10249))
		{
			deduction =3750;
		}
		else if((income>=10250)&&(income<=14999))
		{
			bracket = (income-10250)/250+1;
			deduction = 3750 - 88*bracket;
		}
		else
		{
			deduction = 2000;
		}
	}

	if(integer ==4)
	{
		if((income>=0)&&(income<=20499))
		{
			deduction= 4700;
		}
		else if((income>=20500)&&(income<=29999))
		{
			bracket = (income - 20500)/500+1;
			deduction = 4700 - 135*bracket;
		}
		else
		{
			deduction = 2000;
		}
	}
	int personal;


	if(integer == 1||integer==3)
	{
		personal = 1500;
	}

	if(integer==2||integer ==4)
	{
		personal =3000;
	}
	int dependent;

	if((income>=0)&&(income<=20000))
	{
		dependent =1000;
	}
	else if((income>=20001)&&(income<=100000))
	{
		dependent =500;
	}
	else
	{
		dependent = 300;
	}
	
	printf("Standard deduction=%d\n",deduction);
	printf("Personal exemption=%d\n",personal);
	printf("Dependent exemption=%d\n",dependent*number);

	int taxableincome;
	if(deduction>=itemized)
	{
	taxableincome = income-federal-personal-dependent*number-deduction;
	}
	else
	{
		taxableincome = income-federal-personal-dependent*number-itemized;
	}

	if(taxableincome<0)
	{
		taxableincome=0;
	}
	printf("Taxable=%d\n",taxableincome);
	
	double tax;
	if(integer==1||integer==3||integer==4)
	{
		if((taxableincome>=0)&&(taxableincome<=500))
				{tax=taxableincome*0.02;}
		else if((taxableincome>500)&&(taxableincome<=3000))
		{
			tax=500*0.02+(taxableincome-500)*0.04;
		}
		else
		{
			tax=500*0.02+2500*0.04+(taxableincome-3000)*0.05;
		}
	}
	if(integer == 2)
	{
		if((taxableincome>=0)&&(taxableincome<=1000))
		{
			tax=taxableincome*0.02;
		}
		else if((taxableincome>1000)&&(taxableincome<=6000))
		{
			tax=1000*0.02+(taxableincome-1000)*0.04;
		}
		else
		{
			tax=1000*0.02+5000*0.04+(taxableincome-6000)*0.05;
		}
	}
	
	int taxnew;
	taxnew = (int)round (tax);
	printf("Tax is %d",taxnew);

				
	return 0;
}
