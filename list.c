#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void add(list ** i,graph_node * value){
	list* new=malloc(sizeof(list));
	new->gn=value;
	new->next=(*i);
	(*i)=new;
}

void print2(list * i){
	list * temp=i;
	while(temp!=NULL){
		printf("%d -> ",temp->gn->id);
		temp=temp->next;
	}
	printf("NULL\n");
}

void print3(list *i){
	list * temp=i;
	while(temp!=NULL){
		if(temp->gn!=NULL){
			print(temp->gn);
			temp=temp->next;
		}
	}
}

void deletel(list *i){
	list *temp=i,*temp2;
	while(temp!=NULL){
		temp2=temp;
		temp=temp->next;
		dn(temp2->gn);
		free(temp2);
	}
}

int searchl(list * l,int i){
	if(l==NULL || l->gn==NULL) return 0;
	if(l->gn->id==i) return 1;
	list * temp=l->next;
	while(temp!=NULL){
		if(temp->gn->id==i) return 1;
		temp=temp->next;
	}
	return 0;

}

graph_node * searchl2(list *l,int i){
	if(l==NULL || l->gn==NULL) return NULL;
	list * temp=l;
	if(l->gn->id==i){ 
		printf("node with id %d found\n",i); 
	}
		return temp->gn;
	while(temp!=NULL){
		if(temp->gn->id==i){
			printf("node with id %d found\n",i); 
			return temp->gn;
		}
		temp=temp->next;
	}
	return NULL;
}


int deleten(list *l,int id){
	int counter=0;
	list * temp=l;
	while(temp!=NULL){
		counter=search(temp->gn,id);
		if(counter!=0){
			printf("node with id %d is still invovled in money transfers!\n",id);
			break;
		}
		else temp=temp->next;
	}
	return counter;

}

void deleteone(list **l,int i){
	list * g=*l;
	list *temp=NULL;
	if(g->gn->id==i){
		*l=(*l)->next;
		g->next=NULL;
		g->gn=NULL;
		free(g);
	}
	else{
		while(g->gn->id!=i){
			temp=g;	
			g=g->next;
		}
		temp->next=g->next;
		g->next=NULL;
		g->gn=NULL;
		free(g);
	}
}

int in(list *l,int id){
	int sum=0;
	list * temp=l;
	while(temp!=NULL){
		sum=sum+search2(temp->gn,id);
		temp=temp->next;
	}
	return sum;
}

void print4(list *l){
	if(l==NULL) return;
	print4(l->next);
	printf("%d->",l->gn->id);

}

void conn(graph_node *start,graph_node *dest,list *l){
	add(&l,start);
	connl(start,dest,&l);
	printf("ty captain obvious\n");
	if(searchl(l,dest->id)==0) printf("there isn't a path from %d to %d\n",start->id,dest->id);
	else {
		print4(l);
		list *temp=l;
		while(temp->next!=NULL) temp=temp->next;
		printf("%d\n",temp->gn->id);
	}
	//deletel(l);
	list *temp;
	while(l!=NULL){
		temp=l->next;
		free(l);
		l=temp;
	}
	//free(temp);
}

void connl(graph_node *start,graph_node *dest,list ** l){
	int g=search(start,dest->id);
	if(g==1){
		add(l,dest);
		return ;
	}
	else{
		if(start->gl!=NULL)	{
			if(searchl(*l,start->gl->gn->id)==0){
				add(l,start->gl->gn);
			}
			else return;
			graphlist * temp=start->gl;
			while(temp!=NULL){
				connl(temp->gn,dest,l);
				temp=temp->next;
			}
		}
	}
}












































