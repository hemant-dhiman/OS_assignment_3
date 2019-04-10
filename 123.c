#include<stdio.h>
#include<Math.h>
int main(){
	int disc[5000];
	//initializing given memory
	for(int i=0; i<5000;i++){
		disc[i] = 0;
	}
	int current_pointer = 143;
	int previous_pointer = 125;
	//given data
	int disc1[9];
	disc1[0] = 86;
	disc1[1] = 1470;
	disc1[2] = 913;
	disc1[3] = 1774;
	disc1[4] = 948;
	disc1[5] = 1509;
	disc1[6] = 1022;
	disc1[7] = 1750;
	disc1[8] = 130;
	int length = sizeof(disc1)/sizeof(current_pointer);//calculate the size of given data
	//bubble sort
	for(int i = 0 ;i<length;i++){
		for(int j = 0;j<length-1;j++){
			if(disc1[j] > disc1[j+1]){
				int temp = disc1[j];
				disc1[j] = disc1[j+1];
				disc1[j+1] = temp;
			}
		}
	}
	//map this given data to memory
	for(int i = current_pointer;i<(length+current_pointer);i++){
		disc[i] = disc1[i-current_pointer];
	}
	printf("\t----USING SCAN disc-scheduling Algorithm----\n\nSERVICE ORDER:- 143->");
	for(int i = current_pointer;i<(length+current_pointer);i++){
		printf(" , %d",disc[i]);
	}
	printf("\nStarting pointer 143 and length of given data: %d\n",length);
	//using fifo (first come first serve)
	int total_distance = current_pointer - disc[current_pointer];
	//printf("length of given data: %d\n",total_distance);
	printf("\n\nMOVEMENT ORDER:- %d",current_pointer - disc[current_pointer]);
	for(int i = current_pointer+1 ; i<(length+current_pointer) ; i++){
		int _current_pointer = i;
		int _previous_pointer = i+1;
		printf(" + %d",abs(disc[_current_pointer]-disc[_current_pointer-1]));
		total_distance += abs(disc[_current_pointer]-disc[_current_pointer-1]);
	}
	printf("\nTotal movement(Distance) of data: %d\n",total_distance);
	return 0;
}