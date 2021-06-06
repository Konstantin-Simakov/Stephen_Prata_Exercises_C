// exercise3_head.h

#define LEN 40
#define BOOKS 3
#define HYPHEN "--------------"

struct book {
	char title[LEN];
	char author[LEN];
	float value;
};

char * s_gets (char * str, int n);
void eatline (void);
int init_struct_arr (struct book lib[], int n);
void sort_struct_title (struct book lib[], int n);
void sort_struct_value (struct book lib[], int n);
void output_struct_arr (const struct book lib[], int n);
