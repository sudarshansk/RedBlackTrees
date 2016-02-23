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

node* rearrange(node *a, node *b, node *c, node *d){
	b->lptr = a;
	a->parent = b;

	b->rptr = c;
	c->parent = b;

	b->color = 1;
	a->color = 0;
	c->color = 0;

	if(d!=NULL){
		if(d->val>b->val){
			c->lptr = d;
			d->parent = c;
		}
		else{
			a->rptr = d;
			d->parent = a;
		}
	}
	return b;
}
void insert_node(node *root, int val){
	
	node *temp=root,prev,grand,uncle,great_grand,a,b,c,new1;
	int dir,dir2;
	new1 = new_node(val);
	if (root==NULL){
		root = new1;
		root->color=1;
		return;
	}
	while(temp!=NULL){
		if(val > temp->data){
			prev=temp;
			temp = temp->rptr;
			dir2=1;
		}
		else{
			prev=temp;
			temp = temp->lptr;
			dir2=0;
		}
	}
	if(prev->color == 1){
		temp = new1;
		new1->parent = prev;
		return;
	}
	else{
		grand = prev->parent;
		great_grand=grand->parent;
		if(grand->lptr==prev){
			uncle = grand->rptr;	
			dir = 0;
		}
		else{
			uncle = grand->lptr;
			dir = 1;
		}

		if(uncle->color==1){
			//uncle is black
			if(dir==0){
				if(dir2==1){
					a = prev;
					b = new1;
					c = grand;
					grand = rearrange(a,b,c,NULL);
					grand->parent = great_grand;
				}
				else{
					a = new1;
					b = prev;
					c = grand;
					d = prev->rptr;
					grand = rearrange(a,b,c,d);
					grand->parent = great_grand;
				}
			}
			else{
				if(dir2==0){
					a = grand;
					b = new1;
					c = prev;
					grand = rearrange(a,b,c,NULL);
					grand->parent = great_grand;
				}
				else{
					a = grand;
					b = prev;
					c = new1;
					d = prev->lptr;
					grand = rearrange(a,b,c,d);
					grand->parent = great_grand;
				}
			}
			return;
		}
		else{
			//uncle is also red
			if(dir2==0){
				prev->lptr=new1;
			}
			else{
				prev->rptr=new1;
			}
			new1->parent = prev;

			(grand->rptr)->color=1;
			(grand->lptr)->color=1;
			
			grand->color = 0;
			
			
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