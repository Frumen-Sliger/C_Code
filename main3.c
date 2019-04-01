#include <unistd.h>
#include <stdlib.h> //only system(clear)

#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#define _EXFUN(name, proto) name proto
int _EXFUN(printf, (const char *__restrict, ...)
_ATTRIBUTE ((__format__ (__printf__, 1, 2))));

typedef struct dlist
{
	int data;
	struct dlist *right;
	struct dlist *down;
} Matrix;

Matrix *mInit(int data)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	return(temp);
}

Matrix addelemRight(int data, Matrix *head)
{
	Matrix *temp, *r; 
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	head->right = temp;
	head->down = NULL;
	
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	r = head;
	while (r->right != NULL)
	r = r -> right;
	r -> right = temp;
	
}

Matrix addelemDown(int data, Matrix *head)
{
	Matrix *temp, *d; 
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	head->right = NULL;
	head->down = temp;
	
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	d = head;
	while (d->down != NULL)
	d = d -> down;
	d -> down = temp;
	
}

void mPrint(Matrix *lst, int Row)
{
	Matrix *r, *d;
	d = lst;
	int i;
	for(i =0; i <Row; i++)
	{
		for (r = d; r != NULL; r = r->right)
		{
			printf("%d ", r->data);
		}
		d = d->down;
		if (d != NULL)
		{
			r = d;
		}
		printf("\n");
	}
}

void main() 
{
	system("@cls||clear"); // Clear the console
	Matrix MatrixMain; //Create the Matrix struct
	//int Elem = 0;
	mInit(5);
	addelemRight(5, &MatrixMain);
	addelemDown(5, &MatrixMain);
	
	mPrint(&MatrixMain, 2);
}
