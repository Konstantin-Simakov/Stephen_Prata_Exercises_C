// exercise4_pb_support.c
#include <stdio.h>
#include <string.h>	 		// for strchr()
#include "exercise4_head.h"

char * s_gets(char * str, int n)
{
	char * ret_val, * find;

	ret_val = fgets(str, n, stdin);
	if (ret_val != NULL)
	{
		find = strchr(str, '\n');
		if (find != NULL)
			*find = '\0';
		else	// if (find == NULL) <=> '\n' is not found => '\0' will be found
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

int init_struct_arr(struct ssc * date, int n)
{
	int count = 0;

	printf("Enter the first name:\n");
	while (count < n && s_gets(date[count].name.fname, LEN) != NULL && 
		date[count].name.fname[0] != '\0')
	{
		printf("Enter the second name:\n");
		if (s_gets(date[count].name.lname, LEN) == NULL || 
			date[count].name.lname[0] == '\0')
		{
			printf("Incorrect last name entered.\n");
			break;
		}
		printf("Enter the patronymic:\n");
		if (s_gets(date[count].name.patronymic, LEN) == NULL)
		{
			printf("Incorrect patronymic entered.\n");
			break;
		}
		printf("Enter the number of ssc for this person:\n");
		if (scanf("%d", &date[count].num) != 1)
		{
			printf("Incorrect number ssc entered.\n");
			break;
		}
		eatline();

		if (++count < n)
			printf("Enter the next first name:\n");
	}

	return count;
}

void output_struct(struct ssc date)
{
	printf("%s, %s %c%s -- %d\n", date.name.fname, date.name.lname, date.name.patronymic[0], 
		date.name.patronymic[0] != '\0' ? "." : "", 
		date.num);
}
