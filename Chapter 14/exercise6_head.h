/* exercise6_head.h */

#define LEN 20
#define PLAYERS 10		/* number of players in a softball game -- no more than 10 */

struct player {
	int number;			/* number of player */
	char fname[LEN];
	char lname[LEN];
	int accept;			/* number of balls accepted by a player */
	int hit;			/* number of hits by a player */
	int pass;			/* number of passes by a player */
	int run;			/* number of runs scored */
	float average;		/* average achievement in softball */
};

int init_struct_arr (struct player command[], int num, FILE * fp);
void init_average (struct player command[], int num);
struct player sum_struct_arr (struct player command[], int n);
void sort_ascend (struct player command[], int n);
void output_struct_arr (const struct player command[], int n);
void output_struct_sum (const struct player * psum);
