# include <stdio.h>
# include <stdlib.h>
 
typedef struct BST {
   int data;
   struct BST *lchild, *rchild;
} node;
 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);
node *findP(node *,int);
 
int main() {
   int choice;
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   root = NULL;
   //clrscr();
 
   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Insert");
      printf("\n2.Search");
      printf("\n3.Recursive Traversals");
      printf("\n4.Find Parent of given value node");
      printf("\n0.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
 
      switch (choice) {
      case 1:
         
            new_node = get_node();
            printf("\nEnter The Element ");
            scanf("%d", &new_node->data);
 
            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);
 
            break;
 
      case 2:
			 printf("\nEnter Element to be searched :");
			 scanf("%d", &key);
	 
			 tmp = search(root, key, &parent);
			 printf("\nParent of node %d is %d", tmp->data, parent->data);
			 break;
 
      case 3:
			 if (root == NULL)
				printf("Tree Is Empty");
			 else {
				printf("\nThe Inorder display : ");
				inorder(root);
				printf("\nThe Preorder display : ");
				preorder(root);
				printf("\nThe Postorder display : ");
				postorder(root);
			}
			
			break;
	   case 4:
					 
			 printf("\nEnter Element whos parent to be searched :");
			 scanf("%d", &key);
			 parent = findP(root,key);
			 printf("\n the Parent Value is : %d",parent->data);
			 
      }
   } while (choice != 0);
   return 1;
}

/*
 Get new Node and initailize lchind and rchild as null
 */
 node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}

/*
 This function is for creating a binary search tree
 */
void insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }
 
   if (new_node->data > root->data) {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
   
}

/*
 This function is for searching the node from
 binary Search Tree
 */
node *search(node *root, int key, node **parent) {
   node *temp;
   temp = root;
   while (temp != NULL) {
      if (temp->data == key) {
         printf("\nThe %d Element is Present", temp->data);
         return temp;
      }
      *parent = temp;
 
      if (temp->data > key)
         temp = temp->lchild;
      else
         temp = temp->rchild;
   }
   return NULL;
}

/*
 This function displays the tree in inorder fashion
 */
void inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d ", temp->data);
      inorder(temp->rchild);
   }
}

/*
 This function displays the tree in preorder fashion
 */
void preorder(node *temp) {
   if (temp != NULL) {
      printf("%d ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}
 
/*
 This function displays the tree in postorder fashion
 */
void postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d ", temp->data);
   }
}

/*It Finds the parent of the node with given value if valu is present
 * else it returns the location to insert the element
 */   
node *findP(node *T,int x){
	if(T==NULL){
		printf("Tree is empty");
		return NULL;
	}
	//else
	if(T->data==x)
		return T;
	
	if(T->data > x)//that is x is in the left side of tree
	{
		if(T->lchild==NULL || T->lchild->data == x)
			return T;
		else
			return findP(T->lchild,x);
	
	}
	if(T->data < x)//that is x is in right side of T
	{
		if(T->rchild==NULL || T->rchild->data == x)
			return T;
		else
			return findP(T->rchild,x);
			
	}
	return NULL;
}

void deleteNode(node **T,int x){

	node *parent;
	node *curr;
	node *succ;
	node *temproot=*T;
	
	//check for Empty tree
	if(temproot == NULL){
		printf("Tree is empty");
		return;
	}
	
	parent = findP(T,x);
	
	if(parent == T){//deleting the root node
			if(T->lchild == NULL and T->rchild == NULL){
				*T=NULL
			}
			else if(T->rchild == NULL){
				
			}
	}
	
	//case 1: Delete the leaf node
	
	
	//case 2: Delete the node having no right child
	
	
	//case 3: Delete a node whos immediate right child is succ
	
	
	//case 4

}
