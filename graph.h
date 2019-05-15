
typedef struct graph_node graph_node;

typedef struct graphlist graphlist;

struct graph_node{
	int id;
	graphlist * gl;
};

struct graphlist{
	graph_node * gn;
	int ammount;
	graphlist * next;
};



int getid(graph_node *);
graph_node * create(int);
void print(graph_node *);
void connect(graph_node*,graph_node*,int);
int search(graph_node *,int);
int search2(graph_node *,int);
graph_node * search3(graph_node *,int);
void del(graph_node *, graph_node *);
void dn(graph_node * );
void tr(graph_node *,int);
