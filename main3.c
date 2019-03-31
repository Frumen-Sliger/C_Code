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

Matrix *init(int data)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	return(temp);
}

Matrix addelem(int data, Matrix *head)
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	Matrix *p = head;
	while (p->right != NULL)
	p = p -> right;
	p -> right = temp;
	
	p = head;
	while (p->down != NULL)
	p = p -> down;
	p -> down = temp;
}


void mInit(int i)
{	//Установка значений матрицы

	init(i);
}

void main() 
{
	system("@cls||clear"); // Clear the console
	Matrix MatrixMain; //Create the Matrix struct
	mInit(0);
	addelem(1, &MatrixMain);
	addelem(2, &MatrixMain);
}
