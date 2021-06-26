/* exercise7_head_version2.h */

/* max values for font id and font size accordingly */
#define MAX1			0xFF
#define MAX2			0x7F

/* masks -- for clean of the bits */
#define MASK_ID 		0xFF			/* == MAX1 */
#define MASK_SIZE		0x7F00
#define MASK_ALIGN		0x30000
#define MASK_BOLD		0x40000
#define MASK_ITALIC		0x80000
#define MASK_UNDER		0x100000

/* bit position for left shift */
#define MULT_ID			0
#define MULT_SIZE 		8
#define MULT_ALIGN		16
#define MULT_BOLD		18
#define MULT_ITALIC		19
#define MULT_UNDER		20

void eatline (void);
char show_menu (void);
char show_menu_2 (void);
unsigned font_id_change (unsigned);
unsigned size_change (unsigned);
unsigned align_change (unsigned);
unsigned bold (unsigned);
unsigned italic (unsigned);
unsigned underline (unsigned);
void output (const unsigned);
unsigned init (unsigned);
