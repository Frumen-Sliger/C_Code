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
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	Matrix *p = head;
	while (p->down != NULL)
	p = p -> down;
	p -> down = temp;
}

Matrix addelemDown(int data, Matrix *head)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	Matrix *p = head;
	while (p->down != NULL)
	p = p -> down;
	p -> down = temp;
}

void mPrint(Matrix *lst, int Row)
{
	Matrix *r, *d;
	r = lst;
	d = r;
	int i;
	for(i =0; i <Row; i++)
	{
		do 
		{
			printf("%d ", r->data);
			r = r->right;
		} while (r != NULL); 
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
	mInit(5);
	addelemRight(5, &MatrixMain);
	addelemDown(5, &MatrixMain);
	printf("%d %d \n%d\n", &MatrixMain.data, &MatrixMain.right->data, &MatrixMain.down->data);
	mPrint(&MatrixMain, 2);
}
