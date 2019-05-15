#include <stdio.h>
#include <stdlib.h>
//#include "list.h"
#include "hashtable.h"
#include <string.h>


hashtable * init(int s){
	int i;
	hashtable * temp=malloc(sizeof(hashtable));
	temp->table=malloc(s*sizeof(list));
	for(i=0;i<s;i++)
		temp->table[i]=NULL;
	temp->size=s;
	return temp;	
}

void deleteh(hashtable * h){
	int i;
	for(int i=0;i<h->size;i++){
		if(h->table[i]!=NULL)
			deletel(h->table[i]);
	}
	free(h->table);
	free(h);

}

void createh(hashtable * h, int i){
	list * temp=h->table[i%(h->size)];
	if(temp==NULL) add(&(h->table[i%(h->size)]),create(i));
	else if(searchl(h->table[i%(h->size)],i)==1) printf("node with id %d already exists!\n",i);
	else add(&(h->table[i%(h->size)]),create(i));
}



void addtran(hashtable *h,int id1,int id2,int am){
	if(searchl(h->table[id1%(h->size)],id1)==0) printf("node with id %d isn't existing!\n",id1);
	else if(searchl(h->table[id2%(h->size)],id2)==0) printf("node with id %d isn't existing!\n",id2);
	else connect(searchl2(h->table[id1%(h->size)],id1),searchl2(h->table[id2%(h->size)],id2),am);
}

void deltran(hashtable *h,int id1,int id2){
	if(searchl(h->table[id1%(h->size)],id1)==0) printf("node with id %d isn't existing!\n",id1);
	else if(searchl(h->table[id2%(h->size)],id2)==0) printf("node with id %d isn't existing!\n",id2);
	else del(searchl2(h->table[id1%(h->size)],id1),searchl2(h->table[id2%(h->size)],id2));
}

void printall(hashtable *h){
	int counter=0;
	if(h!=NULL) {
		for(counter=0;counter<h->size;counter++) {
			if(h->table[counter]!=NULL) {
				print3(h->table[counter]);
			}
		}
	}
}

void delnode(hashtable *h,int id){
	if(searchl(h->table[id%(h->size)],id)==0) printf("node with id %d isn't existing!\n",id);
	else{
		int temp;
		int i;
		for(i=0;i<(h->size);i++){
			temp=deleten(h->table[i],id);
			if(temp!=0){
				break;
			}
		}
		if(temp==0){
			graph_node * ptr=searchl2(h->table[id%(h->size)],id);
			if(ptr->gl==NULL || ptr->gl->gn==NULL) {
				printf("node with ID %d is deleted\n",id);
				//print2(h->table[id%(h->size)]);
				deleteone(&(h->table[id%(h->size)]),id);
				free(ptr);
			}
			else printf("node with id %d is still invovled in money transfers!\n",ptr->id);
		}
	}
}

void deleteall(hashtable **h){
	int counter;
	if((*h)!=NULL){
		for(counter=0;counter<(*h)->size;counter++) deletel((*h)->table[counter]);
		free((*h)->table);
		free(*h);
	}
	(*h)=NULL;
}

int lookup(hashtable *h,char * str, int i){
	graph_node *g=searchl2(h->table[i%(h->size)],i);
	graphlist * temp=g->gl;
	if(g!=NULL){
		if(strcmp(str,"out")==0){
			int out=0;
			//temp=g->gl->next;
			while(temp!=NULL){
				out=temp->ammount+out;
				temp=temp->next;
			}
			printf("node with id %d is sending %d money to others\n",i,out);
		}
		else if(strcmp(str,"in")==0){
			int counter;
			int inv=0;
			for(counter=0;counter<h->size;counter++){
				inv=inv+in(h->table[counter],i);
			}
			printf("money reicived for node with id %d =%d\n",i,inv);

		}
		else if(strcmp(str,"sum")==0){
			int out=0;
			//temp=g->gl->next;
			while(temp!=NULL){
				out=temp->ammount+out;
				temp=temp->next;
			}
			int inv=0;
			int counter;
			for(counter=0;counter<h->size;counter++){
				inv=inv+in(h->table[counter],i);
			}
			printf("for node with id %d money sent - money recieved=%d\n",i,out-inv);
		}
		else printf("wrong arg given!\n");
	}
}

void triangle(hashtable *h,int i,int k){
	int counter;
	//for(counter=0;counter<h->size;counter++){
	tr(searchl2(h->table[i%(h->size)],i),k);


}

void connh(hashtable *h,int id1,int id2){
	list *l;
	conn(searchl2(h->table[id1%(h->size)],id1),searchl2(h->table[id2%(h->size)],id2),l);
	printf("no!\n");
}









































