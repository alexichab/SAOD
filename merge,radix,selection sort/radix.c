#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

 double wtime() 
 { 
 	struct timeval t; 
	gettimeofday(&t,NULL);
 	return (double)t.tv_sec + (double)t.tv_usec * 1E-6; 
} 

int getrand(int min, int max){
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max) max = array[i];
    return max;
}


void countingSort(int array[], int size, int place) {
    int output[size + 1];
    int max = (array[0] / place) % 10;  
    for (int i = 1; i < size; i++) {
        if (((array[i] / place) % 10) > max) max = array[i];
    }
    int count[max + 1]; 
    for (int i = 0; i < max; ++i) count[i] = 0; 

    for (int i = 0; i < size; i++) count[(array[i] / place) % 10]++;
    

    for (int i = 1; i < 10; i++) count[i] += count[i - 1]; 

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }   
    for (int i = 0; i < size; i++) array[i] = output[i];
}

void radixsort(int array[], int size) {

    int max = getMax(array, size);  

    for (int place = 1; max / place > 0; place *= 10) countingSort(array, size, place);
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int *array;
    scanf("%d", &n);
    array = (int*)malloc(n*sizeof(int));
    for (int x=0; x<n; x++) array[x] = getrand(0, 100000);
    double t1=wtime();
   // for (int i=0; i<n; i++) printf("%d\n",array[i]);
    //clock_t t;	
    //t = clock();
    radixsort(array, n);
    double t2=wtime();
    printf("t1=%.6lf, t2=%.6lf\n",t1, t2);
    printf("t2-t1=%.6lf\n",t2-t1);
    //t = clock()-t;
    //double time_taken =((double)t)/CLOCKS_PER_SEC;
    //printf("Time:%f\n",time_taken);  
    
   //for (int i=0; i<n; i++) printf("%d\n",array[i]);
     
    //printArray(array, n);
}
