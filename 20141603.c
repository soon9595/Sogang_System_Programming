
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "20141603.h"
char* rtrim(char* s) {
	char t[90];
	char *end;
	strcpy(t, s); 
	end = t + strlen(t) - 1;
	while (end != t && isspace(*end))
		end--;
	*(end + 1) = '\0';
	s = t;
	return s;
}
//terminate blank in the right
char* ltrim(char *s) {
	char* begin;
	begin = s;

	while (*begin != '\0') {
		if (isspace(*begin))
			begin++;
		else {
			s = begin;
			break;
		}
	}
	return s;
}
// terminate blank in the left
char* trim(char *s) {
	return rtrim(ltrim(s));
}
// terminate blank in the left and right
int FindValidDumpInput(char *str)
{
	int i;
	int dflag = 0; // flag for the finding valid input 
	int len;
	int lens, lene,leni;
	int bflag = 0; // flag for the blank between the hexadecimal numbers
	char start[30];
	char end[30];
	char imm[30];
	char junk[30];
	// strings for sscanf 
	sscanf(str, "%s %[^\n]", junk, start);
	strcpy(start, trim(start));
	len = strlen(start);
	for (i = 0; i < len; i++)
	{
		if (start[i] == ',')
			dflag = 3;
		else
			dflag = 2;
	}
	// if there is ',' , dflag =3 , if not dflag = 2
	if (dflag == 2)
	{
		lens = strlen(start);
		for (i = 0; i < lens; i++)
		{
			if ((start[i] <= '9'&&start[i] >= '0') || (start[i] <= 'F'&&start[i] >= 'A') || (start[i] <= 'f'&&start[i] >= 'a'))
				continue;   // if the character is number or alphabet a to f, A to F
			else if (start[i] == ' ' || start[i] == '\t')
			{
				bflag = -1;
				break;
			}   //if there is blank between the hexadeciaml numbers like 2 3, make the bflag = -1
			else
			{
				if (start[i] == ',')
				{
					dflag = 3;
					break;
				}
				else
					bflag = -1;
				break;
			}

		}
		if (bflag == -1)
		{
			return -1;
		}
	}
	// for the dump start and case that dump start, which is not valid Input
	if (dflag == 3)
	{
		sscanf(str, "%s %[^,] %*c %[^\n]", junk, start, end);
		lens = strlen(start);
		lene = strlen(end);
		for (i = 0; i < lens; i++)
		{
			if ((start[i] <= '9'&&start[i] >= '0') || (start[i] <= 'F'&&start[i] >= 'A') || (start[i] <= 'f'&&start[i] >= 'a'))
				continue;			// if the character is number or alphabet a to f, A to F
			else if (start[i] == ' ' || start[i] == '\t')
			{
				bflag = -1;
				break;
			}   //if there is blank between the hexadeciaml numbers like 2 3, make the bflag = -1
			else
			{
				bflag = -1;
				break;
			}

		}

		if (bflag == -1)
		{
			return -1;
		}
		for (i = 0; i < lene; i++)
		{
			if ((end[i] <= '9'&&end[i] >= '0') || (end[i] <= 'F'&&end[i] >= 'A')|| (end[i] <= 'f'&&end[i] >= 'a'))
				continue;	// if the character is number or alphabet a to f, A to F 
			else if (end[i] == ' ' || end[i] == '\t')
			{
				bflag = -1;
				break;
			}			 //if there is blank between the hexadeciaml numbers like 2 3, make the bflag = -1
			else
			{
				if (end[i] == ',')
				{
		
					dflag = 4;  // in case of fill
					break;
				}
				bflag = -1;
				break;
			}
		}

		if (bflag == -1)
		{
			
			return -1;
		}
	}  //for the dump start,end and edit 
	if (dflag == 4) 
	{
		sscanf(str, "%s %[^,] %*c %[^,] %*c %[^\n]", junk, start, end, imm);
		lens = strlen(start);
		lene = strlen(end);
		leni = strlen(imm);
		for (i = 0; i < lens; i++)
		{
			if ((start[i] <= '9'&&start[i] >= '0') || (start[i] <= 'F'&&start[i] >= 'A')||(start[i]<='f'&&start[i]>='a'))
				continue;		// if the character is number or alphabet a to f, A to F 	
			else if (start[i] == ' ' || start[i] == '\t')
			{
				bflag = -1;
				break;
			}				 //if there is blank between the hexadeciaml numbers like 2 3, make the bflag = -1
			else
			{
				bflag = -1;
				break;
			}

		}

		if (bflag == -1)
		{
			return -1;
		}
		for (i = 0; i < lene; i++)
		{
			if ((end[i] <= '9'&&end[i] >= '0') || (end[i] <= 'F'&&end[i] >= 'A')||(end[i]<='f'&&end[i]>='a'))
				continue;			// if the character is number or alphabet a to f, A to F
			else if (end[i] == ' ' || end[i] == '\t')
			{
				bflag = -1;
				break;
			}				//if there is blank between the hexadeciaml numbers like 2 3, make the bflag = -1
			else
			{
				bflag = -1;
				break;
			}
		}
		for (i = 0; i < leni; i++)
		{
			if ((imm[i] <= '9'&&imm[i] >= '0') || (imm[i] <= 'F'&&imm[i] >= 'A')||(imm[i]<='f'&&imm[i]>='a'))
				continue;		// if the character is number or alphabet a to f, A to F
			else if (imm[i] == ' ' || imm[i] == '\t')
			{
				bflag = -1;
				break;
			}				//if there is blank between the hexadeciaml numbers like 2 3, make the bflag = -1
			else
			{
				bflag = -1;
				break;
			}
		}

		if (bflag == -1)
		{
			return -1;
		}
		else
			return 4;
	}
	else if (dflag == 2)
		return 2;
	else if (dflag == 3)
		return 3;
	else
		return -1;

}
// find the valid input and if it is valid, return proper flag . if not, return -1
void help()
{
	printf("h[elp]\n");
	printf("d[ir]\n");
	printf("q[uit]\n");
	printf("hi[story]\n");
	printf("du[mp] [start , end]\n");
	printf("e[dit] address, value\n");
	printf("f[ill] start , end, value\n");
	printf("reset\n");
	printf("opcode mnemonic\n");
	printf("opcodelist\n");
}
// function for printing the available commands
void dir()
{
	DIR *di = NULL;
	struct dirent *din = NULL;
	struct stat dimo;
	di = opendir(".");
	for (;;)
	{
		din = readdir(di);                  // to the opendir one, read the first one, after we recall the readdir, it will read next one each time.
		if (din == NULL)break;
		lstat(din->d_name, &dimo);            //returns information about the link
		printf("%s", din->d_name);
		if (S_ISDIR(dimo.st_mode))printf("/");                  // distinguish whether it is a directory file . if directroy put /
		else if (dimo.st_mode & S_IXUSR)printf("*");             // if file put *
		printf("\t");
	}
	printf("\n");
}
// function for printing existing file in the directory
void MakeHistory(Node **hs, char *str)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	strcpy(temp->name, str);
	temp->link = NULL;
	Node* tmp;
	if ((*hs) == NULL)
		(*hs) = temp;
	// if history node is empty, make the temp node directly link to it
	else {
		for (tmp = (*hs); tmp->link != NULL; tmp = tmp->link);
		tmp->link = temp;
	} 
	// if there is any existing node, put temp node at the end
}
//function for make the array of the effective command by using linked list
void PrintHistory(Node *hs, int cnt)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	for (temp = hs->link; temp != NULL; temp = temp->link) {
		printf("%d : %s\n", cnt, temp->name);
		cnt++;

	}
	free(temp);
}
// function for printing the commands that is in the history node
int Dump(unsigned char **Memory,char *str,int spoint,int end)
{
	int memv;  // variable to show memory address
	int i, j;
	int srow, erow, scol,ecol;   //variables for the row and col number of the startpoint and the endpoint
	int epoint;
	int enddot;
	int startid = 0;
	if (spoint < 0 || spoint > 1048575)
	{
		printf("This is not available range!\n");
		return -1;
	}
	// if the startpoint is not in the available range, print the error message
	else
	{
		if (end == -1)
		{
			epoint = spoint + 159;

		} // in case of dump, dump %x
		else
			epoint = end; // in case of dump %x,%x
		if (end > 1048575) {
			printf("This is not available range!\n");
			return -1;
		}
		// if the endpoint is bigger than existing, print error message
		else {
			startid = epoint + 1;   // next start will be epoint+1 
			srow = spoint / 16;
			scol = spoint % 16;
			if (epoint > 1048575)
				epoint = 1048575;
			erow = epoint / 16;
			ecol = epoint % 16;
			// find the col and row of the startpoint, also endpoint 
			memv = srow * 16;			
			for (i = srow; i < erow + 1; i++)
			{
				if (i == srow)
				{
					if (srow == erow)
						enddot = ecol;   // if the srow and erow are the same, enddot will be ecol
					else 
						enddot = 15;     // if srow!=erow ,  enddot should be the end of the line
					printf("%05X  ", memv);
					memv += 16;
					for (j = 0; j < scol; j++)
						printf("    ");
					for (j = scol; j < enddot + 1; j++)
					{
						printf("%02X  ", Memory[i][j]);
					}
					printf("	;");
					for (j = 0; j < scol; j++)
						printf(".");
					for (j = scol; j < enddot+1; j++)
					{
						if (32 <= Memory[i][j] && Memory[i][j] <= 126)
							printf("%c", Memory[i][j]);
						else
							printf(".");
					}   // if it is in the range, print the character if it is in available range
					for (j = enddot + 1; j < 16;j++)
						printf(".");
					// if it is not in the range , print it '.'
				}
				else if (i == erow)
				{
					printf("%05X  ", memv);
					memv += 16;
					for (j = 0; j < ecol + 1; j++)
					{
						printf("%02X  ", Memory[i][j]);
					}
					for (j = ecol + 1; j < 16; j++)
						printf("    ");
					printf("	;");
					for (j = 0; j < ecol + 1; j++)
					{
						if (32 <= Memory[i][j] && Memory[i][j] <= 126)
							printf("%c", Memory[i][j]);
						else
							printf(".");
					}		// if it is in the range, print the character if it is in available range
					for (j = ecol + 1; j < 16; j++)
						printf(".");			// if it is not in the range , print it '.'
				}
				else
				{
					printf("%05X  ", memv);
					memv += 16;
					for (j = 0; j < 16; j++)
					{
						printf("%02X  ", Memory[i][j]);
					}
					printf("	;");
					for (j = 0; j < 16; j++)
					{
						if (32 <= Memory[i][j] && Memory[i][j] <= 126)
							printf("%c", Memory[i][j]);
						else
							printf(".");
					}
				}		// if it is in the range, print the character if it is in available range
				printf("\n");
			}

		}
		return startid;
	}
}
// function that is used in the case of dump, dump %x, and dump %x,%x.
// use range to print appropriate characters
// print error message if startpoint or the endpoint is not in the available range.
void EditMemory(unsigned char **Memory, int address, int value)
{
	int Tarrow, Tarcol;  //Target address's row and col
	if (value < 0 || value > 255)
	{
		printf("This value is not in available range!\n");
		return;
	}
	if (address < 0 || address > 1048575)
	{
		printf("Address is not in available range!\n");
		return;
	}
	Tarrow= address / 16;
	Tarcol = address % 16;
	Memory[Tarrow][Tarcol] = value;

}
//function for edit value in the target address
//print error message if the value or the target address is not in the range.
void fill(unsigned char **Memory, int startA, int endA, int value)
{
	int srow, scol;
	int erow, ecol;
	int enddot;
	int i, j;
	//int tmp, val;
	if (startA < 0 || 1048575 < startA)//error input
	{
		printf("Startpoint is not in available range!\n");
		return;
	}
	if (endA < 0 || 1048575 < endA)
	{
		printf("Endpoint is not in available range!\n");
		return;
	}
	if (endA < startA)
	{
		printf("Startpoint should be smaller than the Endpoint!\n");
		return;
	}
	if (value < 0 || 255 < value)
	{
		printf("Value is not in available range!\n");
		return;
	}
	srow = startA / 16;
	scol = startA % 16;
	erow = endA / 16;
	ecol = endA % 16;
	// find the row and the col of the startpoint and the endpoint
	for (i = srow; i < erow + 1; i++)
	{
		if (i == srow)
		{
			if (srow == erow)
				enddot = ecol;     // if srow==erow , enddot should be the ecol
			else
				enddot = 15;        // if not, we should print the end of the line so enddot is 15
			for (j = scol; j < enddot + 1; j++)
			{
				Memory[i][j] = value;
			}
		// fill the value in the memory

	}
	else if (i == erow)
	{
		for (j = 0; j < ecol + 1; j++)
		{
			Memory[i][j] = value;
		}
		// fill the value in the memory
	}
	else {
		for(j=0;j<16;j++)
			Memory[i][j] = value;
	}			//fill the value in the memory
}


}
//function for fill value in the given range of the address
//print error message if value or startpoint or endpoint is not in available address
//print error message if startpoint is bigger than the endpoint
int hash_function(char *s)
{
	int i, sum;
	for (i = 0, sum = 0; i <strlen(s); i++)
	{
		sum += s[i];
	}
	return sum % 20;
}
//function for the hash
void OpcodeInput(hashtable **ht)
{
	FILE *fp = fopen("opcode.txt", "r");
	char tmpmneo[20];
	char tmpname[20];
	char tmpvalue[20];
	hashtable *temp, *head;
	int i;
	int idx;
	if (fp == NULL)
	{
		printf("There is no opcode.txt!!\n");
		return;
	}
	// Print Error message if there is no such opcode.
	else
	{
		for (i = 0; i < 20; i++)
		{
			ht[i] = NULL;
		}
		//make the head of the hashtable NULL
		while (fscanf(fp,"%s %s %s",tmpvalue,tmpmneo,tmpname)!=EOF) // do fscanf until there is nothing.
		{
			temp = (hashtable*)malloc(sizeof(hashtable));
			temp->next = NULL;
			strcpy(temp->mneo, tmpmneo);
			strcpy(temp->name, tmpname);
			sscanf(tmpvalue, "%x", &temp->value);
			idx = hash_function(temp->mneo);
			//fill the tempnode by the data given by the file
			if (ht[idx] == NULL)
			{
				ht[idx] = temp;
			}
			// put tempnode at the front of the idx
			else
			{
				head = ht[idx];
				for (;;)
				{
					if (head->next == NULL)break;
					head = head->next;
				}
				head->next = temp;
			}
			// if there exist node int the front, put the newnode(temp) in the back.
		}

	}
	fclose(fp);
}
//function for make the opcode hash table by using linked list
//put the hash struct in the appropriate position
void Opcodelist_print(hashtable** ht)
{
	hashtable* temp;//pointer for searching hash table
	int i;//index
	temp = (hashtable*)malloc(sizeof(hashtable));
	for (i = 0; i<20; i++)//printing the hash table
	{
		printf("%d : ", i);
		for (temp = ht[i]; temp != NULL; temp = temp->next)
		{
			
			printf("[%s, %X]", temp->mneo, temp->value);

			if (temp->next != NULL)
				printf(" -> ");
		}
		printf("\n");
	}
}
//function for printing the existing opcodes in the hash table
int FindOpPrint(char* command, hashtable** ht)
{
	int index;//index of hash table
	char tmpname[100];//string of inputing opcode
	char tmpmeno[100];//string of inputing mnemonic
	int flag = 0;
	hashtable* temp;//pointer for searching hash table
	index = 0;
	sscanf(command, "%s%s", tmpname, tmpmeno);
	index = hash_function(tmpmeno);
	temp = ht[index];
	for (temp = ht[index]; temp != NULL; temp = temp->next)
	{
		if (strcmp(temp->mneo, tmpmeno) == 0)
		{
			flag = 1;
			break;
		}
	}
	// search in the hash if there is same name of integer
	if (flag == 0)
	{
		return 0;
	}
	// if there is no such name, return 0 for the failure
	else {
		printf("opcode is %X\n", temp->value);
		return 1;
	}
	// if there is such name, return 1 for the success
}
//function that finds the opcode from the input command
// if there is same thing in hash table, print. if not, return 0
int main(void)
{
	int i, j;
	int len;
	int cnt = 0;
	int dstart=0;
	int epoint;
	int spoint;
	int addr;  //for edit
	int value; // for edit and fill
	int startA, endA; //  address for fill
	int opflag;    // flag for the opcode -> if true return 1, else return 0
	char *command;    // char string to put input without blanks
	char *input;      // input string
	Node *hs;         //Node for histroy
	int flag=0;         
	unsigned char **Memory;       //Memory
	char junk[45];                // use in sscanf for the mneomonics
	char stp[45];                 // use in sscanf for the first string
	char edp[45];                 // use in sscanf for the middle string in fill, end string in edit and dump 
	char valp[45];                // use in sscanf for the end string in fill
	hashtable *ht[20];            // hash for the mneomonics
	hs = (Node*)malloc(sizeof(Node));
	hs->link = NULL;
	
	
	Memory = (unsigned char**)calloc(sizeof(unsigned char*),65536);
	for (i = 0; i < 65536; i++)
		Memory[i] = (unsigned char*)calloc(sizeof(unsigned char),16);
	 // memory and the strings memory allocation
	OpcodeInput(ht);
	// function execution for the opcode 
	while (1)
	{
		printf("sicsim>");
		command = (char*)malloc(sizeof(char) * 90);
		input = (char*)malloc(sizeof(char) * 90);
		fgets(input, 90, stdin);
		len = strlen(input);
		input[len - 1] = '\0';                             // because \n is put after fgets, change it into NULL
		for (i = 0; i < len; i++)
		{
			if (input[i] != ' '&&input[i] != '\t')
				break;
		}
		if (i == len)
			printf("Input Error\n");
		// if there is string that only have blank, print error message.
		else
		{
			strcpy(command, trim(input));    //terminate existing blanks in the left side and the right side.
			len = strlen(command);
			if (len > 90 || len <= 0) {
				printf("Input Error!\n");
			}
			// if too long or no input, print error message.
			else {
				if (!strcmp(command, "quit") || !strcmp(command, "q"))   // if quit, free all dynamic things
				{
					free(input);
					free(command);
					for (i = 0; i < 65536; i++)
						free(Memory[i]);
					free(Memory);
					free(hs);
					break;
				}
				else if (!strcmp(command, "dir") || !strcmp(command, "d"))   
				{
					MakeHistory(&hs, command);
					dir();
					free(input);
					free(command);
				}
				else if (!strcmp(command, "help") || !strcmp(command, "h"))
				{
					MakeHistory(&hs, command);
					free(input);
					free(command);
					help();

				}
				else if (!strcmp(command, "history") || !strcmp(command, "hi"))
				{
					if (hs->link == NULL)
						MakeHistory(&hs, command);   // If history node is empty, just put the command in the node. Not execute printing
					else {
						MakeHistory(&hs, command);
						cnt = 0;
						PrintHistory(hs, cnt);
					} // if there exists node in the history node, print all commands
					free(input);
					free(command);
				}
				else if (!strcmp(command, "dump") || !strcmp(command, "du"))
				{
					MakeHistory(&hs, command);
					if (dstart > 1048575)
						dstart = 0;
					dstart = Dump(Memory, command, dstart, -1);
					free(input);
					free(command);
				}
				else if ((command[0] == 'd' && command[1] == 'u' && (command[2] == ' ' || command[2] == '\t')) || (command[0] == 'd' && command[1] == 'u' && command[2] == 'm' && command[3] == 'p' && (command[4] == ' '||command[4]=='\t')))
				{

					flag = FindValidDumpInput(command);   // by flag, determine error or the case.
					if (flag == -1)
						printf("This is not valid Input\n");    // if flag==-1 means something wrong in input. print error message
					else if (flag == 2)		//flag 2 means the case dump %x
					{
						MakeHistory(&hs, command);
						sscanf(command, "%s %[^\n]", junk, stp);
						sscanf(stp, "%x", &spoint);
						dstart = Dump(Memory, command, spoint, -1);
						if (dstart > 1048575)
							dstart = 0;
					}
					else if (flag == 3)   // flag 3 means the case dump %x,%x
					{

						sscanf(command, "%s %[^,] %*c %[^\n]", junk, stp, edp);
						sscanf(stp, "%x", &spoint);
						sscanf(edp, "%x", &epoint);
						if (spoint > epoint)
						{
							printf("Not available range!\n");
						}
						else {
							MakeHistory(&hs, command);
							dstart= Dump(Memory, command, spoint, epoint);
							if (dstart > 1048575)
								dstart = 0;
						}
						free(input);
						free(command);

					}
					else
						printf("Input Error!!\n");
				}
				else if ((command[0] == 'e' && (command[1] == ' ' || command[1] == '\t')) || (command[0] == 'e' && command[1] == 'd' && command[2] == 'i' && command[3] == 't' && (command[4] == ' ' || command[4] == '\t')))
				{
					flag = FindValidDumpInput(command);  // find the valid form for edit
					if (flag == 3)
					{
						MakeHistory(&hs, command);
						sscanf(command, "%s %[^,] %*c %[^\n]", junk, stp, edp);
						sscanf(stp, "%x", &addr);
						sscanf(edp, "%x", &value);
						EditMemory(Memory, addr, value);
					}
					else
						printf("Input Error!!\n");
					free(input);
					free(command);
				}
				else if ((command[0] == 'f' && command[1] == ' ') || (command[0] == 'f' && command[1] == 'i' && command[2] == 'l' && command[3] == 'l' && (command[4] == ' '||command[4]=='\t')))//if "f" or "fill" mnemonic , 
				{
					flag = FindValidDumpInput(command);   // find the valid form for fill
					if (flag == 4)
					{
						sscanf(command, "%s %[^,] %*c %[^,] %*c %[^\n]", junk, stp, edp,valp);
						sscanf(stp, "%x", &startA);
						sscanf(edp, "%x", &endA);
						sscanf(valp, "%x", &value);
						fill(Memory, startA, endA, value);
						MakeHistory(&hs, command);
					}
					else
						printf("This is not valid fill input form!!\n");
					free(input);
					free(command);
				}
				else if (strcmp("reset", command) == 0)   //make all memory to 0
				{
					MakeHistory(&hs, command);
					for (i = 0; i < 65536; i++)
						for (j = 0; j < 16; j++)
							Memory[i][j] = 0;
					free(input);
					free(command);
			
				}
				else if (command[0] == 'o' && command[1] == 'p' && command[2] == 'c' && command[3] == 'o' && command[4]=='d' && command[5]=='e'&&(command[6]==' '||command[6]=='\t'))
				{
					opflag = FindOpPrint(command,ht);
					if (opflag == 0) {
						printf("There is no such mnemonic in the opcodelist!\n");
					}
					else
						MakeHistory(&hs, command);
					free(input);
					free(command);
				}
				// print opcode if there is same name
				else if (!strcmp(command, "opcodelist"))
				{
					Opcodelist_print(ht);
					MakeHistory(&hs, command);
					free(input);
					free(command);
				}
				// print opcodelist
				else
				{
					printf("There is no such command!\n");
					free(input);
					free(command);
				}
				// if Wrong command, print error
			}
		}
	}
	return 0;
}
