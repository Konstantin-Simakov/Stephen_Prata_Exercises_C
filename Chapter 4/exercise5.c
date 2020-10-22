/* exercise5.c -- Chapter 4 */
#include <stdio.h>

#define BYTE_BIT 8			/* bit amount in one byte */

int main (void)
{
	float v_mbit_sec;
	float s_file_size_mbyte;
	float t_download_file;

	/* request and input: */
	printf("Enter the download speed in megabits per second:\n");
	scanf("%f", &v_mbit_sec);
	printf("Enter the file size in megabytes:\n");
	scanf("%f", &s_file_size_mbyte);

	t_download_file = s_file_size_mbyte * BYTE_BIT / v_mbit_sec;

	printf("With a download speed of %.2f megabites per one second "
		"a %.2f megabyte file is downloaded in %.2f second (s).\n", 
		v_mbit_sec, s_file_size_mbyte, t_download_file);

	return 0;
}