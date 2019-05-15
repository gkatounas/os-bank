#include "list.h"

typedef struct hashtable{
	int size;
	list ** table;
}hashtable;

hashtable * init(int);
void deleteh(hashtable *);
void createh(hashtable *,int);
void addtran(hashtable *,int,int,int);
void deltran(hashtable *,int,int);
void printall(hashtable*);
void delnode(hashtable *,int);
void deleteall(hashtable **);
int lookup(hashtable *,char *,int);
void triangle(hashtable *,int,int);
void connh(hashtable *h,int id1,int id2);
