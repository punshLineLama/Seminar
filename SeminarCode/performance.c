#include <stdio.h>
#include <time.h>

int i=0;
long long nbIterations = 2000000000;

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}



void inc1(){
	i++;
}

void inc2(int *i){
	(*i)++;
	//printf("i is: %d \n", *i);
}

int inc3(int i){
	return ++i;
}

int main(){
	clock_t t1, t2;
	long elapsed;
	//int *i;
	int h = 0;
	//i = &h;
	
	for(int k = 0; k<100; k++){
		t1=clock();
		for(int j = 0; j<nbIterations; j++){
			i = inc3(i);	
		}
		t2=clock();
		elapsed = timediff(t1,t2);
		printf("%ld\n",elapsed);
	}
//	printf("h: %d\n", h);
}
