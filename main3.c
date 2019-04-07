#include <unistd.h>
#include <stdlib.h> //only system(clear)

#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#define _EXFUN(name, proto) name proto
int _EXFUN(printf, (const char *__restrict, ...)
_ATTRIBUTE ((__format__ (__printf__, 1, 2))));

typedef struct dlist //Structure information
{
	int data;
	struct dlist *right;
	struct dlist *down;
} Matrix;

Matrix * mInit(int data)//Initialization of Structure
{
	Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
	
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	return(temp);
}

Matrix addelemRight(int data, Matrix *head) //Adding element to Right
{
	Matrix *temp, *r; //init temp elem
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	//Setting data
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	
	//Adding elem to Matrix
	r = head;
	
	while (r->right != NULL)
	{r = r -> right;}
	r -> right = temp;
}

Matrix addelemDown(int data, Matrix *head) //Adding element to Down
{
	Matrix *temp, *d; //init temp elem
	temp = (Matrix*)malloc(sizeof(Matrix));
	
	//Setting data
	temp -> data = data;
	temp -> right = NULL;
	temp -> down = NULL;
	
	//Adding elem to Matrix
	d = head; 
	while (d->down != NULL)
	{d = d -> down;}
	d -> down = temp;
}

void mPrint(Matrix *lst, int Row) //Outputs All Matrix Elements
{								  //Prints full row, then step lower
	Matrix *r, *d;
	d = lst;
	int i;
	for(i =0; i <Row; i++) //By row count
	{//printf("D1\n"); //Debug
		for (r = d; r != NULL; r = r->right)//Out full row
		{
			printf("%d ", r->data);
			//printf("D1\n"); //Debug
		}
		d = d->down;//Step lower
		if (d != NULL)
		{
			r = d;
		}
		//printf(" row done\n");//debug
		printf("\n");
	}
}

void main() 
{
	system("@cls||clear"); // Clear the console
	
	Matrix *MatrixMain;
	MatrixMain = mInit(1); //Create the Matrix struct
	
	Matrix *temp = MatrixMain;
	addelemRight(1, MatrixMain);
	addelemRight(1, MatrixMain);
	addelemRight(1, MatrixMain);
	
	addelemDown(1, MatrixMain);
	temp = temp->down;
	
	addelemRight(1, temp);
	addelemRight(1, temp);
	addelemRight(1, temp);
	
	addelemDown(1, MatrixMain);
	temp = temp->down;
	
	addelemRight(1, temp);
	addelemRight(1, temp);
	addelemRight(1, temp);
	
	addelemDown(1, MatrixMain);
	temp = temp->down;
	
	addelemRight(1, temp);
	addelemRight(1, temp);
	addelemRight(1, temp);
	
	/* - Matrix view - *\
	
		 |1 1 1 1|
		 |1 1 1 1|
		 |1 1 1 1|
		 |1 1 1 1|
	
	\*                 */
	mPrint(MatrixMain, 4);
}
