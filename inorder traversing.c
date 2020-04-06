#include<stdio.h>
#include<stdlib.h>
#define in int
struct aNode
{
int data;
struct aNode* left;
struct aNode* right;
};
struct bNode
{
struct bNode *t;
struct bNode *next;
};
void push(struct bNode** top_ref, struct aNode *t);
struct aNode *pop(struct bNode** top_ref);
in isEmpty(struct bNode *top);

void inOrder(struct aNode *root)
{
struct aNode *current = root;
struct bNode *s = NULL;
in done = 0;

while (!done)
{

	if(current != NULL)
	{
	push(&s, current);
	current = current->left;
	}
	else
	{
	if (!isEmpty(s))
	{
		current = pop(&s);
		printf("%d ", current->data);
		current = current->right;
	}
	else
		done = 1;
	}
}
}
void push(struct bNode** top_ref, struct aNode *t)
{

struct bNode* new_aNode =
			(struct sNode*) malloc(sizeof(struct bNode));

if(new_aNode == NULL)
{
	printf("Stack Overflow \n");
	getchar();
	exit(0);
}

new_aNode->t = t;

new_aNode->next = (*top_ref);

(*top_ref) = new_aNode;
}

in isEmpty(struct bNode *top)
{
return (top == NULL)? 1 : 0;
}

struct aNode *pop(struct bNode** top_ref)
{
struct aNode *res;
struct bNode *top;

if(isEmpty(*top_ref))
{
	printf("Stack Underflow \n");
	getchar();
	exit(0);
}
else
{
	top = *top_ref;
	res = top->t;
	*top_ref = top->next;
	free(top);
	return res;
}
}

struct aNode* newtNode(int data)
{
struct aNode* aNode = (struct aNode*)
					malloc(sizeof(struct aNode));
aNode->data = data;
aNode->left = NULL;
aNode->right = NULL;

return(aNode);
}

int main()
{

struct aNode *root = newaNode(1);
root->left	 = newaNode(2);
root->right	 = newaNode(3);
root->left->left = newaNode(4);
root->left->right = newaNode(5);

inOrder(root);

getchar();
return 0;
}
