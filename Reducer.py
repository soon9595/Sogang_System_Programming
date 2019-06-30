#!/usr/bin/python
from sys import stdin, stdout
lib = {}
while True:
	str1 = stdin.readline().strip()
        #input one line
	if str1 == "":
		break
        #if NULL, break
	word, cnt = str1.split('\t')
        #bring keyword and count
	if( word in lib ):
		lib[word] +=  int(cnt);
	else:
		lib[word] = int(cnt);
            #compute count
keylist = lib.keys()
keylist.sort()
#sort the key
for i in keylist:
	stdout.write(i+"\t"+str(lib[i])+"\n")
