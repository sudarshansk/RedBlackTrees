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

node* new_node(int val){
	node *new1;
	new1->data = val;
	new1->lptr=NULL;
	new1->rptr=NULL;
	new1->parent=NULL;
	new1->color=0;
	return new1;
}
void insert_node(node *root, int val){
	
	node *temp=root;

	if (root==NULL){
		root = new_node(val);
		root->color=1;
		return;
	}
	while(temp!=NULL){
		if(temp->data < val){
			prev=temp;
			temp = temp->rptr;
		}
		else{
			prev=temp;
			temp = temp->lptr;
		}
	}
	if(prev->color == 1){
		temp = new_node(val);
	}
	else{
		grand = prev->parent;
		if(grand->lptr==prev){
			uncle = grand->rptr;	
			dir = 0;
		}
		else{
			uncle = grand->lptr;
			dir = 1;
		}
		if(uncle->color==1){
			//uncle is red
			if(dir==0){
				if(val<prev->data){
					
				}
				else{

				}
			}
			if(dir==1){
				if(val<prev->data){

				}
				else{

				}
			}
		}
		else{
			//uncle is also red
			if(prev->data<val){
				prev->lptr=new_node(val);
			}
			else{
				prev->rptr=new_node(val);
			}
			grand = prev->parent;
			(grand->rptr)->color=1;
			(grand->lptr)->color=1;
			if(grand->color == 1){
				grand->color=0;
				
			}
		}
	}
}
void delete_node(node *root){


}
int main(){
	int choice,val;
	node *root = NULL;

	printf("\nRED BLACK TREE\n");

	printf("Menu : \n 1. Insert a node \n 2. Delete a node \n enter your choice : ");
	scanf("%d",&choice);

	switch(choice){
		case 1: printf("\nenter value of node to be inserted : ");
				scanf("%d",&val);
				insert_node(root,val);
				break;
		case 2: delete_node(root);
				break;
		default: return 0;
	}
	return 0;
}