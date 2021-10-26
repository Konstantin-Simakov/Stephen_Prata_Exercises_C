/* exercise7_head.h */
#include <stdbool.h>

#define LEN 40
#define MAXBKS 10		/* max number of books */
#define SPACE ' '

struct book {			/* the template of the structure book */
	char title[LEN];
	char author[LEN];
	float value;
	int number;
};

int output_from_file_binary(struct book library[], int n, FILE * fp);
char * s_gets(char * str, int n);
void eatline(void);
char action(void);
char choice2(void);
void delete_entry(struct book library[], int count);
void change_entry(struct book library[], int count);
void struct_cpy(struct book * pstruct1, struct book * pstruct2);
void change(struct book * entry, int num);
int add_entry(struct book library[], int count);
void output_to_file(struct book library[], int count, int filecount, FILE * fp);
bool is_empty(struct book * entry);
bool is_empty_arr(struct book library[], int n);
void to_empty(struct book * entry);
int sort_struct_arr(struct book library[], int count);
void output_content(struct book library[], int count);
void set_nums(struct book library[], int count);
