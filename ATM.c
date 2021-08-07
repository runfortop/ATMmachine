#include <stdio.h>


#define BOOL	    	int
#define ACOUNT_INT  	{{1111,0}, {2222,0}, {3333,0}}
#define MAX_ACOUNT  	3
#define ERROR	    	-100
#define OK	    	100
#define END	     	99
#define	CUSTOM_INFO 	{0, 3, 9999}

typedef enum
{
	INIT_SCREEN,
	INPUT_PIN_NUMBER,
	SELECT_ACOUNT,
	CHOOSE_SERVICE,
	WITHDRAW,
	DEPOSIT,
	BALANCE

}STEP_STATUS;

typedef struct
{
	int selectedAcount;
	int numOfacount;
	int pinNumber;

}CUSTOMER_INFO;

CUSTOMER_INFO customInfo = CUSTOM_INFO;

typedef struct
{
	int acountNum;
	int balance;

}ACOUNT_INFO;


ACOUNT_INFO acountInfo[MAX_ACOUNT] = ACOUNT_INT;


BOOL init_screen()
{
	BOOL ret = 0;

	while (ret != 1 && ret != 2)
	{
		printf("Welcome to ATM machine!\n");
		printf("Please insert card\n");
		printf("1. Yes, 2. NO =>_ ");
		scanf_s("%d", &ret, sizeof(ret));
		rewind(stdin);
	}

	if (ret == 1)
	{
		ret = OK;
	}

	return  ret;
}

BOOL check_pinNum(int pinNum)
{
	BOOL ret = 0;

	if (pinNum == customInfo.pinNumber)
	{
		ret = OK;
	}
	else
	{
		ret = ERROR;
	}

	return ret;
}

BOOL input_pinNum()
{
	BOOL ret = 0;
	int	 pinNum = 0;

	printf("Please enter your pin number\n");
	printf("If you want to quit, enter 99\n");
	printf("num :_");

	scanf_s("%d", &pinNum, sizeof(pinNum));
	rewind(stdin);

	if (pinNum == END)
	{
		ret = END;
		return ret;
	}

	ret = check_pinNum(pinNum);

	return  ret;
}

BOOL select_acount()
{
	int  i = 0;
	int  acount = 0;
	BOOL ret = 0;

	printf("Please Choose your acount\n\n");

	for (i = 0; i < customInfo.numOfacount; i++)
	{
		printf("%d. acount number : %d\n", i + 1, acountInfo[i].acountNum);
	}

	printf("If you want to quit, enter 99\n");
	printf("num :_");
	scanf_s("%d", &acount, sizeof(acount));
	rewind(stdin);

	if (acount == 99)
	{
		ret = END;
		return ret;
	}

	if (acount < 1 || acount > customInfo.numOfacount)
	{
		ret = ERROR;
	}
	else
	{
		customInfo.selectedAcount = acount - 1;
		ret = OK;
	}

	return  ret;
}

int choose_servie()
{
	int ret;
	int choice_num = 0;

	printf("Choose the service you want!\n\n");
	printf("1. Withdraw\n");
	printf("2. Deposit\n");
	printf("3. Balance\n");
	printf("4. End\n");
	printf("num :_");
	scanf_s("%d", &choice_num, sizeof(choice_num));
	rewind(stdin);

	if (choice_num < 1 || choice_num > 4)
	{
		ret = ERROR;
	}
	else
	{
		ret = choice_num;
	}
	
	return ret;
}

int withdraw()
{	
	int ret = 0;
	int selection = 0;
	int amountOfwithdraw = 0;

	printf("Enter the withdrawal amount\n");
	scanf_s("%d", &amountOfwithdraw, sizeof(amountOfwithdraw));
	rewind(stdin);

	if (acountInfo[customInfo.selectedAcount].balance < amountOfwithdraw)
	{
		printf("You do not have enough money in your account.\n");
	}
	else
	{
		acountInfo[customInfo.selectedAcount].balance  = acountInfo[customInfo.selectedAcount].balance - amountOfwithdraw;
		printf("You have withdrawn %d and your new balance is %d\n", amountOfwithdraw, acountInfo[customInfo.selectedAcount].balance);
	}
	 
	while (selection != 1 && selection != 2)
	{
		printf("Do you want to continue another transaction? \n");
		printf("1. Continue, 2. End \n");
		printf("num :_");
		scanf_s("%d", &selection, sizeof(selection));
		rewind(stdin);
	}
	
	ret = selection;

	return ret;
}

int deposit()
{
	int ret = 0;
	int selection = 0;
	int amountOfdeposit = 0;

	printf("Enter the deposit amount\n");
	scanf_s("%d", &amountOfdeposit, sizeof(amountOfdeposit));
	rewind(stdin);

	acountInfo[customInfo.selectedAcount].balance = acountInfo[customInfo.selectedAcount].balance + amountOfdeposit;
	printf("You have deposited %d and your new balance is %d\n", amountOfdeposit, acountInfo[customInfo.selectedAcount].balance);

	while (selection != 1 && selection != 2)
	{
		printf("Do you want to continue another transaction? \n");
		printf("1. Continue, 2. End \n");
		printf("num :_");
		scanf_s("%d", &selection, sizeof(selection));
		rewind(stdin);
	}

	ret = selection;

	return ret;
}

int balance()
{
	int ret = 0;
	int selection = 0;

	printf("Your balance is %d\n", acountInfo[customInfo.selectedAcount].balance);

	while (selection != 1 && selection != 2)
	{
		printf("Do you want to continue another transaction? \n");
		printf("1. Continue, 2. End \n");
		printf("num :_");
		scanf_s("%d", &selection, sizeof(selection));
		rewind(stdin);
	}

	ret = selection;

	return ret;
}

void main()
{
	BOOL  ret = 0;
	STEP_STATUS step_status = INIT_SCREEN;
	


	while (1)
	{
		switch (step_status)
		{
			case INIT_SCREEN:

					ret = init_screen();

					if (ret == OK)
					{
						step_status = INPUT_PIN_NUMBER;
					}

					break;

			case INPUT_PIN_NUMBER:

					ret = input_pinNum();

					if (ret == OK)
					{
						step_status = SELECT_ACOUNT;
					}
					else if (ret == END)
					{
						step_status = INIT_SCREEN;
					}
					else
					{
						printf("Pin number is wrong, please re-enter\n");
					}

					break;

			case SELECT_ACOUNT:

					ret = select_acount();

					if (ret == OK)
					{
						step_status = CHOOSE_SERVICE;
					}
					else if (ret == END)
					{
						step_status = INIT_SCREEN;
					}
					else
					{
						printf("Number is wrong, please re-enter\n");
					}

					break;

			case CHOOSE_SERVICE:
					
					ret = choose_servie();

					if (ret == ERROR)
					{
						printf("Number is wrong, please re-enter\n");
					}
					else
					{
						if (ret == 1)
						{
							step_status = WITHDRAW;
						}
						else if (ret == 2)
						{
							step_status = DEPOSIT;
						}
						else if (ret == 3)
						{
							step_status = BALANCE;
						}
						else if (ret == 4)
						{
							step_status = INIT_SCREEN;
						}
					}

					break;

			case WITHDRAW:

					ret = withdraw();

					if (ret == 1)
					{
						step_status = CHOOSE_SERVICE;
					}
					else
					{
						step_status = INIT_SCREEN;
					}
				
					break;

			case DEPOSIT:

					ret = deposit();

					if (ret == 1)
					{
						step_status = CHOOSE_SERVICE;
					}
					else
					{
						step_status = INIT_SCREEN;
					}
				
					break;

			case BALANCE:

					ret = balance();

					if (ret == 1)
					{
						step_status = CHOOSE_SERVICE;
					}
					else
					{
						step_status = INIT_SCREEN;
					}

					break;
			default:
				;
		}
	}
}
