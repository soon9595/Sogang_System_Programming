#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<sys/stat.h>
#include<dirent.h>
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
int FindValidDumpInput(char *str);
void help();
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
