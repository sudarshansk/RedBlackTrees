#include <stdio.h>

struct NODE{
	int data;
	struct NODE *lptr;
	struct NODE *rptr;
	struct NODE *parent;
	int color;
	//red=0,black=1,double black=2
};

typedef struct NODE node;

void display(node *root){

}
void insert_node(node *root){

}
void delete_node(node *root){


}
int main(){
	int choice;
	node *root = NULL;

	printf("\nRED BLACK TREE\n");

	printf("Menu : \n 1. Insert a node \n 2. Delete a node \n enter your choice : ");
	scanf("%d",&choice);

	switch(choice){
		case 1: insert_node(root);
				break;
		case 2: delete_node(root);
				break;
		default: return 0;
	}
	return 0;
}