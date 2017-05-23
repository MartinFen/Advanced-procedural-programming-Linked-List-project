#include <stdio.h>
#include <stdlib.h>
//------------------------------------Variable Declarations-----------------------------------------------------------------------------

//------------------------------------Structure Declarations----------------------------------------------------------------------------
struct Login
{
	char Username[7];
	char Password[7];
};
struct Date
{
	char day[3];
	char month[3];
	char year[5];
};

struct Employee
{
	int ID;
	char Name[30];
	char Address[50];
	char Department[20];
	char Date[30];
	char AnnualSalary[20];
	char EmailAddress[50];
	struct Employee *next;
};

//---------------------------------------Function Declarations--------------------------------------------------------------------------
int Menu();
void Add(struct Employee *head);
void List(struct Employee *head);
void Search(struct Employee *head, int num);
void Updateid(struct Employee *head, int num);
void Updatename(struct Employee *head, char myname);
void Read(struct Employee *head);
void Delete(struct Employee **head, int num);
void Loginfunc();

int main()//---------------------------Main-------------------------------------------------------------------------------------------------
{
	int num=0;
	int MenuChoice = 0;
	char myname=NULL;
	int choose=0;
	char strBuffer[8000 + 1];
	
	/*struct Login Employee[3], Log;

	printf("\nPlease enter your Username: ");
	scanf("%s", Log.Username);
	printf("\nPlease enter your Password: ");
	scanf("%s", Log.Password);

	fflush(stdin);

	FILE *ptr;
	ptr = fopen("login.dat", "r");
	if (ptr == NULL)
	{
		printf("Can not open the file\n");
		exit(0);
	}

	for (int i = 0; i < 3; i++)
	{
		sscanf(ptr, "%s %s\n", Employee[i].Username, Employee[i].Password);
	}
	
	for (int i = 0; i < 3; i++)
	{
		if ((strcmp(Employee[i].Username, Log.Username) == 0) && (strcmp(Employee[i].Username, Log.Password) == 0))
		{
			printf("\nWelcome ");
		}

	}*/
	



	struct Employee *head; 
	struct Employee *read;
	//struct Login *log;
	
	//log = (struct Login*)malloc(sizeof(struct Login));
	
	//Loginfunc(log);
	
	head = (struct Employee*)malloc(sizeof(struct Employee));//assign memory to linked list;	
	read = (struct Employee*)malloc(sizeof(struct Employee));

	read->next = NULL;//SET UP LINKED LIST
	head = read;
	
	FILE *fptr;
	fptr = fopen("employee.dat", "r");
	
	if (fptr == NULL)
	{
		printf("\nCould not open the File");
		system("Pause");
		exit(0);
	}

	while (!feof(fptr))
	{
		fgets(strBuffer, 8000, fptr);
		fflush(stdin);

		sscanf(strBuffer, "%d %s %s %s %s %s %s\n",
			&read->ID,
			read->Name,
			read->Address,
			read->Department,
			read->Date,
			read->AnnualSalary,
			read->EmailAddress);
		fflush(stdin);

		printf("%d %s %s %s %s %s %s\n",
			read->ID,
			read->Name,
			read->Address,
			read->Department,
			read->Date,
			read->AnnualSalary,
			read->EmailAddress);
		fflush(stdin);

		read->next = (struct Employee*)malloc(sizeof(struct Employee));//at the end of the linked list it adds the new employee node
		read = read->next;
		read->next = NULL;
	}

	fclose(fptr);

	system("Pause");

	//Read(head);
	
	do
	{
		switch (MenuChoice = Menu())
		{
			case 1:
			{
				Add(head);
				break;
			}
			case 2:
			{
				List(head);
				break;
			}
			case 3:
			{
				fflush(stdin);
				printf("Enter the Employee number: ");
				scanf("%d", &num);
				Search(head, num);//
				break;
			}
			case 4:
			{
				
				printf("\n:Update Employee by ID(1) or Name(2) ");
				scanf("%d", &choose);

				while (choose < 3)
				{
					switch (choose)
					{
						case 1:
						{
							fflush(stdin);
							printf("Enter the Employee number: ");
							scanf("%d", &num);
							Updateid(head, num);
							break;

						}
						case 2:
						{
							fflush(stdin);
							printf("\nEnter the Employee name:  ");
							scanf("%s", myname);
							Updatename(head, myname);
							break;
						}
					}
				}
			}
			
			case 5:
			{
				fflush(stdin);
				printf("Enter the Employee number: ");
				scanf("%d", &num);
				Delete(&head, num);
				break;
			}
			case 6:
			{
				break;
			}
			case 7:
			{
				break;
			}
			case 8:
			{
				exit(0);
				break;
			}
			default:
			{
				printf("\nInvalid Selection");
				break;
			}
		}
	} while (MenuChoice < 8);

	system("Pause");
	printf("\n\n\n");
	return(0);
}



//---------------------------Functions--------------------------------------------------------------------------------------------------
void Delete(struct Employee **head,int num)//int num
{	
	struct Employee *Current;
	struct Employee *Previous;

	Previous = NULL;
	Current = *head;
	
	while (Current != NULL)
	{
		Previous = Current; 
		
		Current = Current->next;
		
		if (Current->ID == num)
		{
			if (Previous == NULL)
			{
				*head = Current->next;
			}
			else
			{
				Previous->next = Current->next;
			}

			free(Current);
			return;
		} 
		else 
		{
			printf("\nEmployee is not in database\n\n");
			return;
		}
	}
}

int Menu()
{
	int Choice = 0;

	do{
		
		printf("1. Add\n");
		printf("2. Show\n");
		printf("3. Search\n");
		printf("4. Update\n"); // Write a Function for this
		printf("5. Delete\n");
		printf("6. \n");
		printf("7. \n");
		printf("8. Exit\n\n\n\t\tSELECTION = ");

		fflush(stdin);

		scanf("%d", &Choice);
		fflush(stdin);
	} 
	while (Choice < 0 || Choice > 8);
	
	return(Choice);	
}

void Add(struct Employee *head)
{	
	
	struct Employee *temp;
	
	while (head->next != NULL)
	{
		head = head->next;//keeps searching through linked list linearly while the next node is not null
	}
	
	temp = (struct Employee*)malloc(sizeof(struct Employee));

	fflush(stdin);
	printf("\nEnter a new Id for employee: ");//enter in the details of the employee
	fflush(stdin);
	scanf("%d", &temp->ID);

	if (temp->ID <= head->ID)
	{
		if (temp->ID == head->ID)
		{
			printf("\nEmployee already in database\n");
			system("Pause");
			return;
		}
		else 
		{	
			if (temp->ID <= head->ID)
			{
				while (temp->ID <= head->ID)
				{
					temp->ID++;
				}
			}
		}
	}

	printf("\nEnter a new name for employee: ");
	fflush(stdin);
	scanf("%s", temp->Name);

	printf("\nEnter a new address for employee: ");
	fflush(stdin);
	scanf("%s", temp->Address);

	printf("\nEnter a new department for employee: ");
	fflush(stdin);
	scanf("%s", temp->Department);

	printf("\nEnter a new join date for employee: ");
	fflush(stdin);
	scanf("%s", temp->Date);
	
	printf("\nEnter a new salary for employee: ");
	fflush(stdin);
	scanf("%s", temp->AnnualSalary);

	do
	{
		printf("\nEnter a new email for employee: ");
		printf("\nDon't forget to add @ and .com\n ");
		fflush(stdin);
		scanf("%s", temp->EmailAddress);
	} while (!strrchr(temp->EmailAddress, '@') && !strrchr(temp->EmailAddress, '.com'));
	

	/*fptr = fopen("employee.dat", "a");

	if (fptr == NULL)
	{
		printf("\nCould not open the File");
		system("Pause");
		return;
	}
	
	
	fprintf(fptr, "%d %s %s %s %s %s %s\n",
	newEmployee->ID,
	newEmployee->Name,
	newEmployee->Address,
	newEmployee->Department,
	newEmployee->DateofJoining,
	newEmployee->AnnualSalary,
	newEmployee->EmailAddress);
		
	fclose(fptr);*/
	
	temp->next = NULL;//at the end of the linked list it adds the new employee node
	head->next = temp;
}

void List(struct Employee *head)
{

	while (head != NULL)
	{
		printf("employees details \n%d \n%s \n%s \n%s \n%s \n%s \n%s\n\n", head->ID, head->Name, head->Address,
			head->Department, head->Date,head->AnnualSalary, head->EmailAddress);
		
		head = head->next;
	}
	system("pause");
}

void Search(struct Employee *head, int num)
{
	
	while (head != NULL)
	{
		if (head->ID == num)
		{
			printf("\n\nEmployees details %d %s \n\n", head->ID, head->Name);
			num = 0;
			return;
		}
		head = head->next;
		
	}
	printf("\nData not found\n\n");
}

void Updateid(struct Employee *head, int num)
{

		while (head != NULL)
		{
			if (head->ID == num)
			{
				printf("\n\nUpdate details for: \n\t%d \n\t%s: ",head->ID,head->Name);
				
				printf("\nEnter a new address for employee: ");
				fflush(stdin);
				scanf("%s", head->Address);

				printf("\nEnter a new department for employee: ");
				fflush(stdin);
				scanf("%s", head->Department);

				printf("\nEnter a new join date for employee: ");
				fflush(stdin);
				scanf("%s", head->Date);

				printf("\nEnter a new salary for employee: ");
				fflush(stdin);
				scanf("%s", &head->AnnualSalary);

				printf("\nEnter a new email for employee: ");
				fflush(stdin);
				scanf("%s", head->EmailAddress);
				
				num = 0;
				return;
			}
			head = head->next;
		}
		printf("\nData not found\n");
		system("pause");
}

void Updatename(struct Employee *head, char myname)
{

	while (head != NULL)
	{
		if ((strcmp(head->Name, myname) == 30))
		{
			printf("\n\nUpdate details for: \n%d \n%s: ", head->ID, head->Name);

			printf("\nEnter a new address for employee: ");
			fflush(stdin);
			scanf("%s", head->Address);

			printf("\nEnter a new department for employee: ");
			fflush(stdin);
			scanf("%s", head->Department);

			printf("\nEnter a new join date for employee: ");
			fflush(stdin);
			scanf("%s", head->Date);

			printf("\nEnter a new salary for employee: ");
			fflush(stdin);
			scanf("%s", &head->AnnualSalary);

			printf("\nEnter a new email for employee: ");
			fflush(stdin);
			scanf("%s", head->EmailAddress);

			char myname = NULL;
			return;
		}
		head = head->next;
	}
	printf("\nData not found\n");
	system("pause");
}


