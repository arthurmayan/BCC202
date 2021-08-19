#include <stdio.h>
#include <stdlib.h>
#include "vetor_util.h"

int main(){
    int n;
    scanf("%d", &n);

    int vector[20];
    scanf("%d", &vector);

    int element;
    scanf("%d", &element);

    printf("%d \n", buscaSequencial(vector , n , element));





    int vector1[20];
    scanf("%d", &vector1);

    int n1;
    scanf("%d", &n1);

    int element1;
    scanf("%d", &element1);

    printf("%d \n", buscaBinaria(vector1, n1, element1));




    int nums1[20];
    scanf("%d", &nums1);

    int nums1Tam;
    scanf("%d", &nums1Tam);;

    int nums2[20];
    scanf("%d", &nums2);

    int nums2Tam;
    scanf("%d", &nums2Tam);

    int vectorLenght = nums1Tam + nums2Tam;

    int *vectorMaster = intercalaVetoresOrdenados(nums1, nums1Tam, nums2, nums2Tam);

    for(int i = 0; i < vectorLenght; i++){
        printf("%d ", vectorMaster[i]);
    }
    printf("\n");

   


    int nums3[20];
    scanf("%d", &nums3);

    int nums3Tam;
    scanf("%d", &nums3Tam);;

    int nums4[20];
    scanf("%d", &nums4);

    int nums4Tam;
    scanf("%d", &nums4Tam);

    printf("%d \n", comparaVetores (nums3 ,nums4 , nums3Tam, nums4Tam));

    free(vectorMaster);
    return 0;
}