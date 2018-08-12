#include <stdio.h>
#include <time.h>

int i=0;
// int *i;
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
	//int h = 0;
	//i = &h;
	
	for(int k = 0; k<100; k++){
		t1=clock();
		for(int j = 0; j<nbIterations; j++){
			i = inc3(i);	
			//i++
			//inc1()
			//inc2(i) need to make i a pointer and let it point to h, like in
		}
		t2=clock();
		elapsed = timediff(t1,t2);
		printf("%ld\n",elapsed);
	}
//	printf("h: %d\n", h);
}
