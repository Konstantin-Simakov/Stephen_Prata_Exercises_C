// support module
void copy_arr (int rs, int cs, double t[rs][cs], 
				const double s[rs][cs])
{
	int i, j;

	for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			t[i][j] = s[i][j];
}

void show_arr (int rs, int cs, const double ar[rs][cs])
{
	int i, j;

	for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			printf("%.2f ", ar[i][j]);
	putchar('\n');
}
