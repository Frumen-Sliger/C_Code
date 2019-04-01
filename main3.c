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

Matrix *mInit(int data, int e)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	return(temp);
	e = 1;
}

Matrix addelemRight(int data, Matrix *head, int e)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	Matrix *r = head;
	while (r->right != NULL)
	{
		r = r -> right;
	}
	r -> right = temp;
	e++;
}

Matrix addelemDown(int data, Matrix *head, int e)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	Matrix *d = head;
	while (d->down != NULL)
	{
		d = d -> down;
	}
	d -> down = temp;
	e++;
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
	int Elem = 0;
	mInit(5, Elem);
	addelemRight(5, &MatrixMain, Elem);
	addelemDown(5, &MatrixMain, Elem);
	
	printf("%d \n", Elem);
	mPrint(&MatrixMain, 2);
}
