// exercise5_head.h

#define LEN 20
#define GRADES 3			// for 3 possible grades
#define CSIZE 4				// the number of structures in the structure array

struct name {
	char fname[LEN];
	char lname[LEN];
};

struct student {
	struct name sname;		// student name
	float grade[GRADES];	// grade - one grade, GRADES - total number of all grades
	float average;			// for average total number of grades
};

int init_struct_arr(struct student group[], int n);
void output_struct_arr(const struct student group[], int n);
