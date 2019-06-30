#!/usr/bin/python
#-*- coding: utf-8 -*-

from sys import stdin, stdout

while True:
	str1 = stdin.readline().strip()
        #input 
	if str1 == "":
		break
        #if NULL, break
	word = str1.split()
        #seperate the string
        #keyword == lower alphabet
	for i in range(0, len(word)-1):
		stdout.write(word[i]+' '+word[i+1]+"\t"+str(1)+"\n")

