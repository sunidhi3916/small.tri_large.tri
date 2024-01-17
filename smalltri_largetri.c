#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
 float *area;
 area=malloc(n*sizeof(float));
 float p,t;
 for(int i=0;i<n;i++)
 {
     
     p=(float)(tr[i].a+tr[i].b+tr[i].c)/2;
     
     t=(float)p*(p-(tr[i].a))*(p-(tr[i].b))*(p-(tr[i].c));
     area[i]=(float)sqrt(t);
 }
 //sorting
 int i,j,min;
 triangle temp;
float s;
 for(i=0;i<n;i++)
 {
     min=i;
     for(j=i+1;j<n;j++)
     {
         if(area[min]>area[j])
         {
             min=j;
         }
         
     }
     s=area[i];
     area[i]=area[min];
     area[min]=s;
     
     temp=tr[i];
     tr[i]=tr[min];
     tr[min]=temp;
 }
 
}

int main()
{
	int n;
    printf("enter the number of triangles\n");
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
    printf("enter the parameters of the triangle\n");
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("after sorting of area the triangles are listed as\n");
	for (int i = 0; i < n; i++)
     {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}