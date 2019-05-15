#include "graph.h"
typedef struct list {
	graph_node * gn;
	struct list * next;
}list;


void add(list **,graph_node *);
void print2(list *);
void print3(list *);
void deletel(list *);
int searchl(list *,int);
graph_node * searchl2(list *,int);
int deleten(list *,int);
void deleteone(list**,int);
int in(list *,int );
void connl(graph_node *start,graph_node *dest,list ** l);
void conn(graph_node *start,graph_node *dest,list *l);
void print4(list *l);
