/* exercise6_head.h */
#include <stdbool.h>					/* for bool, true, false */

struct font {
	unsigned id 			: 8;
	unsigned size			: 7;
	unsigned 			: 1;		/* aggregate -- up to 16 bits */
	unsigned align			: 2;
	bool bold			: 1;
	bool italic			: 1;
	bool underline			: 1;
	unsigned 			: 11;		/* aggregate -- up to 32 bits -- unsigned int rigth side is achieved */
};

#define MAX1	0xFF					/* == (256 - 1) == 255 */
#define MAX2	0x7F					/* == (128 - 1) == 127 */

void eatline (void);
char show_menu (void);
char show_menu_2 (void);
void font_id_change (struct font *);
void size_change (struct font *);
void align_change (struct font *);
void bold (struct font *);
void italic (struct font *);
void underline (struct font *);
void output_st (const struct font *);
