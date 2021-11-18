/* exercise4.c -- uses Queue interface 		*/
/* 			 	  compile along with exercise4_support.c */
#include <stdio.h>
#include <stdlib.h>				/* for rand(), srand(), RAND_MAX	*/
#include <time.h>				/* for time() 						*/
#include <stdbool.h>			/* for bool, true, false			*/
#include "exercise4.h"

#define MIN_PER_HR 60.0			/* constant of double type!			*/

bool new_customer(double x);	/* have a new customer? 			*/
Item customer_time(long when);	/* setting of customer parameters 	*/

int main(void)
{
	Queue line1, line2;
	Item temp;					/* data about a new customer 										*/
	long sum_line1 = 0;			/* cumulative queue1 length 										*/
	long sum_line2 = 0;			/* cumulative queue2 length 										*/
	int wait_time1 = 0;			/* time (from 1 to 3) in minutes until the kiosk1 is empty 			*/
	int wait_time2 = 0;			/* time (from 1 to 3) in minutes until the kiosk2 is empty 			*/
	long line_wait1 = 0;		/* cumulative time in the queue1 									*/
	long line_wait2 = 0;		/* cumulative time in the queue2									*/
	long served1 = 0;			/* number of customers served during the modelling (queue1) 		*/
	long served2 = 0;			/* number of customers served during the modelling (queue2)			*/
	
	int hours;					/* number of modelling hours 										*/
	int per_hour;				/* average number of arrival customers per hour 					*/
	double min_per_cust;		/* average time between customer arrivals 							*/
	long cycle, cycle_limit;	/* counter and limit value of the loop 								*/
	long turn_aways = 0;		/* number of rejections due to a full queue 						*/
	long customers = 0;			/* number of customers joining the queue 							*/

	initialize_queue(&line1);
	initialize_queue(&line2);
	srand((unsigned int) time(0));			/* random seed of the rand() function */
	
	puts("Case study: consulting kiosk.");

	puts("Enter modelling duration in hours:");
	scanf("%d", &hours);
	cycle_limit = MIN_PER_HR * hours;

	puts("Enter the average number of arrival customers per 1 hour:");
	scanf("%d", &per_hour);
	min_per_cust = MIN_PER_HR / per_hour;

	for (cycle = 1; cycle <= cycle_limit; cycle++)
	{
		if (new_customer(min_per_cust))
		{
			if (queue_is_full(&line1) && queue_is_full(&line2))
				turn_aways++;
			else
			{
				customers++;
				temp = customer_time(cycle);

				/* None of the queues should be empty! */
				if (queue_is_empty(&line1))
					en_queue(&line1, temp);
				else if (queue_is_empty(&line2))
					en_queue(&line2, temp);
				else
				{
					if (!queue_is_full(&line1))
						en_queue(&line1, temp);
					else
						en_queue(&line2, temp);
				}
			}
		}


		/* Get information about each line. */

		if (0 == wait_time1 && !queue_is_empty(&line1))
		{
			de_queue(&temp, &line1);
			served1++;
			wait_time1 = temp.process_time;
			line_wait1 += cycle - temp.arrive;
		}
		if (wait_time1 > 0)
			wait_time1--;

		if (0 == wait_time2 && !queue_is_empty(&line2))
		{
			de_queue(&temp, &line2);
			served2++;
			wait_time2 = temp.process_time;
			line_wait2 += cycle - temp.arrive;
		}
		if (wait_time2 > 0)
			wait_time2--;
		
		sum_line1 += queue_item_count(&line1);
		sum_line2 += queue_item_count(&line2);
	}

	/* Displays information about each line separately. */
	if (customers > 0)
	{
		printf("%20s: %ld\n", "accepted customers", customers);
		printf("%20s: %ld\n", "served customers", served1 + served2);
		printf("%20s: %ld\n", "rejection", turn_aways);
		printf("%20s: %.2f\n", "average queue1 length", 
			(double) sum_line1 / cycle_limit);
		printf("%20s: %.2f\n", "average queue2 length", 
			(double) sum_line2 / cycle_limit);
		printf("%20s: %.2f min\n", "average wait time for line 1", 
			(double) line_wait1 / served1);
		printf("%20s: %.2f min\n", "average wait time for line 2", 
			(double) line_wait2 / served2);
	}
	else
		puts("There are no customers!");

	empty_the_queue(&line1);
	empty_the_queue(&line2);
	puts("The program has been completed.");
	
	return 0;
}

/* x is the average time between arrival of customers in minutes */
/* returns true if customer appears during this minute (cycle) */
bool new_customer(double x)
{
	bool is_here;

	if ((rand() * x / RAND_MAX) < 1)
		is_here = true;
	else
		is_here = false;

	return is_here;
}

/* when is the customer's arrival time 						*/
/* the function returns structure Item with arrival time 	*/
/* set to when and served time 								*/
/* set to random value from the range from 1 to 3 			*/
Item customer_time(long when)
{
	Item cust;

	cust.process_time = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
