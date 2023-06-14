#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

double wtime() 
 { 
 	struct timeval t; 
	gettimeofday(&t,NULL);
 	return (double)t.tv_sec + (double)t.tv_usec * 1E-6; 
} 

int getrand(int min, int max){
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void merge_sort(uint32_t *inArr, unsigned int left, unsigned int right)
{
    if (left == right) {
        return;
    }

    unsigned int middle = left + (right - left) / 2;

    merge_sort(inArr, left, middle);
    merge_sort(inArr, middle + 1, right);

    unsigned currentLeft = left;
    unsigned currentRight = middle + 1;

    int tmpArr[right + 1];

    for (int i = 0; i < (right - left) + 1; i++) {
        if ((inArr[currentLeft] < inArr[currentRight] && currentLeft <= middle) || currentRight > right) {
            tmpArr[i] = inArr[currentLeft];
            currentLeft++;
        } else {
            tmpArr[i] = inArr[currentRight];
            currentRight++;
        }
    }

    for (int i = 0; i < (right - left) + 1; i++) {
        inArr[i + left] = tmpArr[i];
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n;
    int *inArr;
    scanf("%d", &n);
    inArr = (int*)malloc(n*sizeof(int));
    for (int x=0; x<n; x++) inArr[x] = getrand(0, 100000);
    double t1=wtime();
    //printArray(inArr, n);
    merge_sort(inArr,0,n-1);
    printf("Sorted array: \n");
    //printArray(inArr, n);
    double t2=wtime();
    printf("t1=%.6lf, t2=%.6lf\n",t1, t2);
    printf("t2-t1=%.6lf\n",t2-t1);
    
    return 0;
}

