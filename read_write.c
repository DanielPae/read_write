#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
	int rand = open("/dev/random", O_RDONLY);
	int arr[10];
	int i = 0;
	read(rand, arr, sizeof(arr));
	printf("original array:\n");
	for(; i < 10; i++){
		printf("index %d: %d\n", i, arr[i]);
	}
	int temp = open("temp", O_CREAT, 0644);
	if (temp == -1){
		temp = open("./temp", O_RDWR);
	}	
	write(temp, arr, sizeof(arr));
	int new[10];
	read(temp, new, sizeof(new));
	i = 0;
	printf("\nnew array:\n");
	for(; i < 10; i++){
		printf("index %d: %d\n", i, arr[i]);
	}

	
}

