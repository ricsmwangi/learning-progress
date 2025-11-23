//actually about grammar in C doesn't matter because 
//after a comma, no need for space..
//but here i am ...wondering if am breaking any rules to build something
//which is the natural law that governs the world
//like you can not create something from void .
//you evolve it or transform it 
//anyway lets breake all the grammar and dram to better understanding of C programming 
//then this is accessing a 2D arrays
//ASSIGNMENT:>>>>>>>>is create a program that collects name of student and marks
//                  >>and ND nd it keeps a record in a txt file then displa the content 
//                  >>of the file on the monitor

#include<stdio.h>


int main()
{
    int arr[4][3]={{1,2,3},{2,3,4},{3,4,5},{4,5,6}};
    int i=0, j=0;

    for(int i=0;i<4;i++){
        for (int j=0;j<3;j++){
            printf("arr[%d][%d] = [%d]\n", i, j, arr[i][j]);
        }

    }

    return 0;
}