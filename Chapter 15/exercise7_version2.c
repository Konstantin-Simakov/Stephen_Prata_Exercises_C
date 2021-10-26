/* exercise7_version2.c -- Chapter 15 */
/* compile with exercise7_support_version2.c */
#include <stdio.h>
#include "exercise7_head_version2.h"		/* for struct template */

int main(void)
{
	unsigned int text = 0;
	char choice;

	text = init(text);

	output(text);
	while ((choice = show_menu()) != 'q')
	{
		switch (choice)
		{
			case 'f': text = font_id_change(text); 
				break;
			case 's': text = size_change(text);
				break;
			case 'a': text = align_change(text);
				break;
			case 'b': text = bold(text);
				break;
			case 'i': text = italic(text);
				break;
			case 'u': text = underline(text);
				break;
			default : puts("Error 1");
		}
		output(text);
	}
	puts("The program has been completed.");
	
	return 0;
}
