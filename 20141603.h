#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<sys/stat.h>
#include<dirent.h>
typedef struct Break_Point {
	int address;
	struct Break_Point *next;
}bp;
typedef struct BP_BOX {
	int num;
	bp *bpoint;
}bpbox;
typedef struct Reference_table
{
	char refname[10];
	int refnum;
	int address;
}reftab;
typedef struct External_symbol_table
{
	int address;
	char exname[10];
}extab;
typedef struct ControlSection_Table{
	char csname[20];
	int length;
	int address;
	int Dnum;
	int Rnum;
	extab *D;
	reftab *R;
	struct ControlSection_Table *next;
}cstab;
typedef struct symbol_table {					
	char symbol[10];
	int locc;
	struct symbol_table* link;
}symtab;
typedef struct node{
	int cnt;
	char name[90];
	struct node *link;
}Node;
typedef struct hash // hash table °ø°£
{
	char mneo[100];
	int value;
	char name[100];
	struct hash *next;
}hashtable;
char* rtrim(char* s);
char* ltrim(char *s);
char* trim(char *s);
void help();
int FindValidDumpInput(char *str);
void dir();
void MakeHistory(Node **hs, char *str);
void PrintHistory(Node *hs, int cnt);
int Dump(unsigned char **Memory, char *str, int spoint, int end);
void EditMemory(unsigned char **Memory, int address, int value);
void fill(unsigned char **Memory, int startA, int endA, int value);
int hash_function(char *s);
void OpcodeInput(hashtable **ht);
void Opcodelist_print(hashtable** ht);
int FindOpPrint(char *command,hashtable **ht);
int findrighthex(char *str);
int finddirect (char *str);
int findopcode (char *str, hashtable **temp, hashtable *ht[20]);
int findregi (char *str);
int findsymbol (char *str, symtab **insisymhead);
int findcomma (char *str1, char *str2, char *str3, char *str);
int xregiuse (char *str1, char *str2, char *str3);
int Makeobject (char *command, int *length, int *bv, hashtable *ht[20]);
void fillstringzero(char *str);
int FinishObject (char *fn, int *bv, int *length, hashtable *ht[20]);
int PrintSymtab();
int PrintType(char* Input_change);
int finderrorinobj(char *filename);
int loaderone(char *filename);
int findref(char *str, int *value, char plus);
int loadertwo(char *filename, int dic);
void printload();
void makebreakpoint(int bpval);
void printbreakpoint();
void clearbreakpoint();