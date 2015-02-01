unsigned char rom[MAX_REAL_BANKS][BANK_SIZE];
unsigned char map[MAX_REAL_BANKS][BANK_SIZE];
char bank_name[MAX_REAL_BANKS][MAX_BANK_NAME_LEN+1];
int  bank_loccnt[NUM_SECTIONS][BANK_MAP_SIZE];
int  bank_page[NUM_SECTIONS][BANK_MAP_SIZE];
int max_zp;		/* higher used address in zero page */
int max_bss;	/* higher used address in ram */
int max_bank;	/* last bank used */
int data_loccnt;	/* data location counter */
int data_size;		/* size of binary output (in bytes) */
int data_level;		/* data output level, must be <= listlevel to be outputed */
int loccnt;	/* location counter */
int bank;	/* current bank */
int bank_base;	/* bank base index */
int rom_limit;	/* bank limit */
int bank_limit;	/* rom max. size in bytes */
int page;	/* page */
int rsbase;	/* .rs counter */
int section;	/* current section: S_ZP, S_BSS, S_CODE or S_DATA */
int section_bank[NUM_SECTIONS];	/* current bank for each section */
int stop_pass;		/* stop the program; set by fatal_error() */
int errcnt;			/* error counter */
struct t_machine *machine;
struct t_symbol  *lablptr;	/* label pointer into symbol table */
struct t_symbol  *glablptr;	/* pointer to the latest defined global label */
struct t_symbol  *lastlabl;	/* last label we have seen */
struct t_symbol  *bank_glabl[NUM_SECTIONS][BANK_MAP_SIZE];	/* latest global symbol for each bank */
void (*opproc)(int *);	/* instruction gen proc */
int  opflg;		/* instruction flags */
int  opval;		/* instruction value */
int  optype;	/* instruction type */
char opext;		/* instruction extension (.l or .h) */
int  pass;		/* pass counter */
char prlnbuf[LINE_BUFFER_SIZE];		/* input line buffer */
char tmplnbuf[LINE_BUFFER_SIZE];	/* temporary line buffer */
int  slnum;				/* source line number counter */
char symbol[SBOLSZ+1];	/* temporary symbol storage.  symbol[0] contains the length of symbol. the actual symbol begins symbol[1] and this string is null-terminated.  thus the max length of symbols is SBOLSZ-1.  */
int undef;				/* undefined symbol in expression flg  */
unsigned int value;		/* operand field value */
int  opvaltab[6][16] = {
   {0x08, 0x08, 0x04, 0x14, 0x14, 0x11, 0x00, 0x10,  // CPX CPY LDX LDY
	0x0C, 0x1C, 0x18, 0x2C, 0x3C, 0x00, 0x00, 0x00},
   {0x00, 0x00, 0x04, 0x14, 0x14, 0x00, 0x00, 0x00,  // ST0 ST1 ST2 TAM TMA
	0x0C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00},
   {0x00, 0x89, 0x24, 0x34, 0x00, 0x00, 0x00, 0x00,  // BIT
	0x2C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
   {0x3A, 0x00, 0xC6, 0xD6, 0x00, 0x00, 0x00, 0x00,  // DEC
	0xCE, 0xDE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
   {0x1A, 0x00, 0xE6, 0xF6, 0x00, 0x00, 0x00, 0x00,  // INC
	0xEE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
   {0x00, 0x00, 0x64, 0x74, 0x00, 0x00, 0x00, 0x00,  // STZ
	0x9C, 0x9E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

