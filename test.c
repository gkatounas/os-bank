//#include "list.h"
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void command(char *,hashtable **,int);



int main(int argc, char ** argv){
	int pos1=0,counter=0,pos2=0,flag1=0,flag2=0,size=1;
	size_t ii=0;
	FILE * p=NULL;
	char * str1=NULL,*str2;
	for(counter=0;counter<argc;counter++) printf("%s\n",argv[counter]);
	for(counter=0;counter<argc;counter++){
		if(strcmp(argv[counter],"-b")==0){ 
			flag1=1;
			pos1=counter+1;
		}
		if(strcmp(argv[counter],"-o")==0){
			flag2=1;
			pos2=counter+1;
		}
	}
	printf("argc=%d\n",argc);
	//return -10;
	if(argc<pos1+1){
		printf("size for hashtable not given at all!\n");
		return -1;
	}
	size=atoi(argv[pos1]);
	if(flag1==0){
		printf("size for hashtable not given!\n");
		return -1;
	}
	if(size<=0){
		printf("wrong size given for hashtable!\n");
		return -1;
	}
	hashtable * hs=init(size);
	if(flag2==1){
		if(argc<pos2+1) printf("there isn't an input file!\n");
		else if(strcmp(argv[pos2],"-b")==0) printf("there isn't an input file!\n");
		p=fopen(argv[pos2],"r+");
		if(p==NULL) printf("input file is not existing!\n");
		else if(p!=NULL){
			printf("the program will execute commands from the file %s\n",argv[pos2]);
			while(getline(&str1,&ii,p)!=-1){
				printf("%s",str1);
				command(str1,&hs,size);
			}
		}
		if(p!=NULL) fclose(p);
	}
	free(str1);
	/*printf("commands:\n");
	printf("createnodes <id1> <id2> ... <idn>\n");
	printf("deletenodes <id1> <id2> ... <idn>\n");
	printf("addtran <id1> <id2> <amount>\n");
	printf("deltran <id1> <id2> \n");
	printf("lookup  in|out|sum <id>\n");
	printf("triangle <id> <amount>\n");
	printf("conn <id1> <id2>\n");
	printf("allcycles <id>\n");
	printf("traceflow <id> <depth>\n");
	printf("bye\n");
	printf("print\n");
	printf("give a command!\n");
	//printf("%p\n",hs);
	//if(hs==NULL)
	//hs=init(size);
	getline(&str1,&ii,stdin);
	while(strcmp(str1,"quit\n")!=0){
		command(str1,&hs,size);
		printf("give a command!\n");
		getline(&str1,&ii,stdin);
		printf("%s",str1);
	}
	free(str1);*/
	/*for(counter=0;counter<10;counter++) createh(hs,counter);
	for(counter=0;counter<size;counter++) print2(hs->table[counter]);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	addtran(hs,9,4,1000000000);
	addtran(hs,9,4,1000000000);
	addtran(hs,9,16,1000000000);
	addtran(hs,1,9,1000000000);
	addtran(hs,121,9,1);
	addtran(hs,5,4,1000000000);
	addtran(hs,14,12,1000000000);
	addtran(hs,9,9,1000000000);
	addtran(hs,10,4,10);
	addtran(hs,2,10,1000000000);
	addtran(hs,169,4,1000000000);
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(counter=0;counter<size;counter++) print3(hs->table[counter]);*/
	//printall(hs);
	//deleteh(hs);
	//for(counter=0;counter<size;counter++) print2(hs->table[counter]);
	/*for(counter=0;counter<size;counter++) deletel(hs->table[counter]);
	free(hs->table);
	free(hs);*/
	//printall(hs);
	if(hs!=NULL)
		deleteall(&hs);
	return 0;
}



void command(char * str,hashtable **h,int size){
	char * temp;
	char * token;
	temp=str;
	if((*h)==NULL) (*h)=init(size);
	/* get the first token */
	token = strtok(str," ");
	if(strcmp(token,"createnodes")==0){
		int id;
		token = strtok(NULL," \n");
		while(token!=NULL){
			//printf("%s\n",token); 
			id=atoi(token);
			token = strtok(NULL," \n");
			if(id>9999999 || id<1000000) printf("%d is an invalid id!\n",id);
			else createh(*h,id);
		}
	}
	else if(strcmp(token,"delnodes")==0){
		//printf("%s\n",token);
		int id;
		token = strtok(NULL," \n");
		while(token!=NULL){
			//printf("%s\n",token);
			id=atoi(token);
			token = strtok(NULL," \n");
			if(id>9999999 || id<1000000) printf("%d is an invalid id!\n",id);
			else delnode(*h,id);
		}
	}
	else if(strcmp(token,"addtran")==0){
		int id,id2;
		//printf("%s\n",token);
		token = strtok(NULL," \n");
		id=atoi(token);
		if(id>9999999 || id<1000000) printf("%d is an invalid id!\n",id);
		else{
			token = strtok(NULL," \n");
			id2=atoi(token);
			if(id>9999999 || id2<1000000) printf("%d is an invalid id!\n",id2);
			else{
				token = strtok(NULL," \n");
				if(atoi(token)>0) addtran(*h,id,id2,atoi(token));
				else printf("wrong command! you didn't give a valid amount\n");
			}
		}
	}
	else if(strcmp(token,"deltran")==0){
		int id,id2;
		//printf("%s\n",token);
		token = strtok(NULL," \n");
		id=atoi(token);
		if(id>9999999 || id<1000000) printf("%d is an invalid id!\n",id);
		else{
			token = strtok(NULL," \n");
			id2=atoi(token);
			if(id>9999999 || id2<1000000) printf("%d is an invalid id!\n",id2);
			else deltran(*h,id,id2);
		}
	}
	else if(strcmp(token,"lookup")==0){
		//printf("%s\n",token);
		token = strtok(NULL," \n");
		char * token2;
		if((strcmp(token,"in")==0) || (strcmp(token,"out")==0) || (strcmp(token,"sum")==0)){
			token2 = strtok(NULL," \n");
			if(atoi(token2)>9999999 || atoi(token2)<1000000) printf("invalid id!\n");
			else lookup(*h,token,atoi(token2));
		}
		else printf("wrong command!\n");
	}
	else if(strcmp(token,"triangle")==0){
		//printf("%s\n",token);
		token=strtok(NULL," \n");
		char * token2;
		if(atoi(token)>9999999 || atoi(token)<1000000) printf("invalid id!\n");
		else{
			token2=strtok(NULL," \n");
			if(atoi(token2)>0) {
				printf("kati\n");
				triangle(*h,atoi(token),atoi(token2));			
			}
			else printf("wrong command!\n");
		}
		
	}
	else if(strcmp(token,"conn")==0){
		int id,id2;
		printf("%s\n",token);
		token = strtok(NULL," \n");
		id=atoi(token);
		if(id>9999999 || id<1000000) printf("%d is an invalid id!\n",id);
		else{
			token = strtok(NULL," \n");
			id2=atoi(token);
			if(id>9999999 || id2<1000000) printf("%d is an invalid id!\n",id2);
			else connh(*h,id,id2);
		}
	}
	else if(strcmp(token,"allcycles")==0){
		//printf("%s\n",token);
		token=strtok(NULL," \n");
		if(atoi(token)>9999999 || atoi(token)<1000000) printf("invalid id!\n");
		//else allcycles(h,atoi(token));
		
	}
	else if(strcmp(token,"traceflow")==0){
		//printf("%s\n",token);
		token=strtok(NULL," \n");
		char * token2;
		if(atoi(token)>9999999 || atoi(token)<1000000) printf("invalid id!\n");
		else{
			token2=strtok(NULL," \n");
			if(atoi(token2)>0) {
//				traceflow(h,atoi(token),atoi(token2));
				printf("kati\n");			
			}
			else printf("wrong command!\n");
		}
	}
	else if(strcmp(token,"bye\n")==0){
		/*printf("%s",token);
		int counter;
		//deleteall();
		for(counter=0;counter<h->size;counter++) deletel(h->table[counter]);
		free(h->table);
		free(h);*/
		deleteall(h);
	}
	else if(strcmp(token,"bye")==0){
		//printf("%s\n",token);
		/*int counter;
		//deleteall();
		for(counter=0;counter<h->size;counter++) deletel(h->table[counter]);
		free(h->table);
		free(h);*/
		deleteall(h);
	}
	else if(strcmp(token,"print\n")==0){
		//printf("%s",token);
		printall(*h);
	}
	else if(strcmp(token,"print")==0){
		//printf("%s\n",token);
		printall(*h);
	}
	else printf("UNKOWN COMMAND!\n");
}
































