#include "graph.h"
#include <stdlib.h>
#include <stdio.h>


graph_node * create(int i){
	graph_node * temp=malloc(sizeof(graph_node));
	temp->id=i;
	temp->gl=NULL;
	return temp;
}


void print(graph_node *p){
	printf("id=%d\n",p->id);
	if(p->gl==NULL)
		printf("this node is not sending money to others\n");
	else{
		printf("%d--%d->%d\n",p->id,p->gl->ammount,p->gl->gn->id);
		graphlist * temp=p->gl->next;
		while(temp!=NULL){
			printf("%d--%d->%d\n",p->id,temp->ammount,temp->gn->id);
			temp=temp->next;
		}
	}
	int i=0;
	for(i;i<50;i++) printf("-");
	printf("\n");
}

int search(graph_node * g,int i){
	if(g->gl==NULL) return 0;
	if(g->gl->gn->id==i) return 1;
	graphlist * temp= g->gl->next;
	while(temp!=NULL){
		if(temp->gn->id==i) return 1;
		temp=temp->next;
	}
	return 0;

}

int search2(graph_node * g,int i){
	if(g->gl==NULL) return 0;
	if(g->gl->gn->id==i) return g->gl->ammount;
	graphlist * temp= g->gl->next;
	while(temp!=NULL){
		if(temp->gn->id==i) return temp->ammount;
		temp=temp->next;
	}
	return 0;

}

graph_node * search3(graph_node * g,int i){
	if(g->gl==NULL) return NULL;
	if(g->gl->gn->id==i) return g->gl->gn;
	graphlist * temp= g->gl->next;
	while(temp!=NULL){
		if(temp->gn->id==i) return temp->gn;
		temp=temp->next;
	}
	return NULL;

}


void connect(graph_node * ptr1, graph_node *ptr2,int i){
	graphlist *temp=ptr1->gl;
	if(ptr1->id==ptr2->id) printf("can't connect a node to itself\n");
	else if(search(ptr1,ptr2->id)){
		while(temp->gn!=ptr2){
			temp=temp->next;
		}
		temp->ammount=temp->ammount + i;	
	}
	else
	{
		if(temp==NULL){
			ptr1->gl=malloc(sizeof(graphlist));
			//printf("%d~~>%d\n",ptr1->id,ptr2->id);
			ptr1->gl->gn=ptr2;
			ptr1->gl->ammount=i;
			ptr1->gl->next=NULL;
			//print(ptr1);
		}
		else{
			graphlist *temp2;
			temp2=malloc(sizeof(graphlist));
			temp2->gn=ptr2;
			temp2->ammount=i;
			temp2->next=temp;
			ptr1->gl=temp2;
			temp2=NULL;
			temp=NULL;
		}
	}
}


void del(graph_node * ptr1, graph_node *ptr2){
	if(ptr1->id==ptr2->id) printf("a node is not connected to itself!\n");
	else if(search(ptr1,ptr2->id)==0) printf("node with id:%d is not sending money to the node with id:%d\n",ptr1->id,ptr2->id);
	else{
		//graph_node *temp=search2(ptr1,ptr2->id);
		graphlist * g=ptr1->gl;
		graphlist *temp;
		if(g->gn==ptr2){
			ptr1->gl=g->next;
			g->next=NULL;
			g->gn=NULL;
			free(g);
		}
		else{
			while(g->gn!=ptr2){
				temp=g;
				g=g->next;
			}
			temp->next=g->next;
			g->next=NULL;
			g->gn=NULL;
			free(g);	
		}	
	}
}


void dn(graph_node * g){
	graphlist *temp=g->gl;
	graphlist *temp2=temp;
	while(temp!=NULL){
		free(temp2);
		temp=temp->next;
		temp2=temp;
	}
	//g->gl=NULL;
	//if(g!=NULL)
		free(g);
}

void tr(graph_node * g,int k){
	int flag=0;
	graphlist * temp= g->gl;
	while(temp!=NULL){
		if(temp->ammount>=k){
			graphlist * temp2=temp->gn->gl;
			while(temp2!=NULL){
				if(temp2->ammount>=k){
					graphlist * temp3=temp2->gn->gl;
					while(temp3!=NULL){
						if(temp3->ammount>=k){
							if(temp3->gn->id==g->id){
								flag=1;
								printf("(%d,%d,%d)\n",g->id,temp->gn->id,temp2->gn->id);
							}
						}
						temp3=temp3->next;
					}
				}
				temp2=temp2->next;
			}		
		}
		temp=temp->next;
	}
	if(flag==0) printf("%d is not involved in triangles\n",g->id);
}



























