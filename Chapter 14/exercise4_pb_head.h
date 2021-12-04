// exercise4_pb_head.h

#define LEN 20
#define MEMBERS 5

struct full_name {
	char fname[LEN];
	char lname[LEN];
	char patronymic[LEN];
};

// social security card
struct ssc {
	int num;
	struct full_name name;
};

int init_struct_arr(struct ssc * date, int n);
void output_struct(struct ssc date);
