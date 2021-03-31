#include "interface.h"

#include "book_management.h"
#include "Login_and_register.h"
#include "User.h"
void user_interface(char *name)
{
	while(1)
	{
		printf("(Logged in as:%s)\n", name);
		printf("1. Borrow a book\n");
		printf("2. Return a book\n");
		printf("3. Search for books\n");
		printf("4. Display all books\n");
		printf("5. Log out\n");
		printf("Option:");
		char enter;
		scanf("%c", &enter);
		getchar();
		switch(enter)
		{
			case '1':
			{
				FILE *file;
				file = fopen("user_book.txt", "a");
				fprintf(file, "%s %s %s %s\n", name, "empty", "empty", "empty");
				fclose(file);
				user *temp = init_userbook(file);
				while(strcmp(temp->account, name))
					temp = temp->next;
				printf("\nPlease enter the book name:");
				char string[Max];
				scanf("%s", string);
				getchar();
				borrow_book(temp, string);
				store_books_user(file, temp);
				free_user(temp);
				break;
			}
			case '2':
			{
				FILE *file;
				user *temp = init_userbook(file);
				while(strcmp(temp->account, name))
					temp = temp->next;
				printf("\nPlease enter the book name:");
				char string[Max];
				scanf("%s", string);
				getchar();
				return_book(temp, string);
				store_books_user(file, temp);
				free_user(temp);
				break;
			}
			case '3':
			{
				search_for_book();
				break;
			}
			case '4':
			{
				display_all_books();
				break;
			}
			case '5':return;
			default:
			{
				printf("Invalid inpuit!");
				break;
			}
		}
	}
}

void run_interface()
{
	st = 0;
	while(st == 0)
	{
		printf("Please choose an option:\n");
		printf("1. Register an account\n");
		printf("2. Login\n");
		printf("3. Search for books\n");
		printf("4. Display all books\n");
		printf("5. Quit\n");
		printf("Option:");
		char enter;
		scanf("%c", &enter);
		getchar();
		strcpy(name, "");
		switch(enter)
		{
			case '1':
			{
				Register(name);
				if(strcmp(name, ""))
					user_interface(name);
				break;
			}
			case '2':
			{
				Login(name);
				if(strcmp(name, ""))
				{
					if(!strcmp(name, "library"))
						book_manager();
					else
						user_interface(name);
				}
				break;
			}
			case '3':
			{
				search_for_book();
				break;
			}
			case '4':
			{
				display_all_books();
				break;
			}
			case '5':return;
			default:
			{
				printf("\nInvalid input!\n");
				break;
			}
		}
	}
}