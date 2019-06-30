import requests
from bs4 import BeautifulSoup
visited = [] #list for visited address
furl="http://cspro.sogang.ac.kr/~gr120170213/" #variable for making descendant address
f1=open("URL.txt",'w')    #open file to write visited URL
def get(root,visited):
            if root in visited:
                return   #if already visited,not execute
            else:               #if not visited,execute
                pass
                try:
                    r=requests.get(root) #request url address
                except:     #if url address is not valid, return 
                        return
                if (r.status_code!=200):
                    return                  #if the case of not found, return
                visited.append(root)         #add url
                b=BeautifulSoup(r.content,'html.parser')
                f1.writelines(root+"\n")  #add url to visited 
                num=len(visited)
                f2=open('Output_%04d.txt'%(num),'w')          #open the output file to write
                f2.writelines(b.text)
                for link in b.find_all('a'):
                        des=link['href']
                        if des!="":   #if attribute ="" means present web site
                                a="#"
                                if des[0]=="#": #means present web so pass
                                        pass
                                else:
                                        if des[0]=="?": #means present web so pass
                                                pass
                                        else:
                                            if des[0:4]=="http":   
                                                        word=des.split("/")   #take last address use split
                                                        wordlen=len(word)
                                                        des2=word[wordlen-1]
                                                        if des2!="":
                                                                if des2[0]=="#":
                                                                        pass
                                                                else:
                                                                    if des2[0]=="?":
                                                                        pass
                                                                    else:
                                                                        if des2=="notfound.html":
                                                                            pass
                                                                        else:   #if valid address, recursively call
                                                                            f2.close()
                                                                            get(des,visited)
                                            else:
                                                        if des=="notfound.html":  #in case of not found, pass
                                                                pass
                                                        else:     #in valid case                            
                                                            descendant=furl+des
                                                            f2.close()
                                                            get(descendant,visited) #visit URL and do it recursively.
rootpage = "http://cspro.sogang.ac.kr/~gr120170213/index.html"
get(rootpage,visited)
f1.close()
