#include <stdio.h>
#include <stdlib.h>
#include "vetor_util.h"

int buscaSequencial (int * vetor , int n , int elemento)
{

    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == elemento)
        {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int *vetor, int n, int elemento)
{
    int right = n;
    int left = 0;
    int middle = (left + (right - 1)) / 2;

    if (elemento == vetor[middle])
    {
        return middle;
    }
    else if (elemento < vetor[middle])
    {
        for (int i = middle - 1; i >= 0; i--)
        {
            if (vetor[i] == elemento)
                return i;
        }
    }
    else if (elemento > vetor[middle])
    {
        for (int i = middle + 1; i < right; i++)
        {
            if (vetor[i] == elemento)
            {
                return i;
            }
        }
    }

    return -1;
}

int* intercalaVetoresOrdenados (int* nums1 , int nums1Tam , int* nums2 , int nums2Tam){

    int *vetorf = malloc ((nums1Tam + nums2Tam) * sizeof (int)); 
    int cont = 0;

    if (nums1Tam != 0 && nums2Tam != 0){
        for(int i = 0; i < (nums1Tam + nums2Tam);i++){
        int x = 0,y = 0;
        if(nums1[i] < nums2[i]) y = 1;
        else if(nums2[i] < nums1[i]) x = 1;

            vetorf[cont + x] = nums1[i];
            vetorf[cont + y] = nums2[i];
            cont+=2;
        }
    }

    else if (nums1Tam == 0 && nums2Tam != 0){
        for(int j = 0; j < (nums1Tam + nums2Tam); j++){
            vetorf[cont] = nums2[j];
            cont++;
        }
    }

    else if (nums1Tam != 0 && nums2Tam == 0){
        for(int i = 0; i < (nums1Tam + nums2Tam);i++){
            vetorf[cont] = nums1[i];
            cont++;
        }
    }
 
    return vetorf;
}

int comparaVetores(int *nums1, int *nums2, int nums1Tam, int nums2Tam){
    int n;
    int count = 0;

    if (nums1Tam == nums2Tam)
        n = nums1Tam;
    else
        return 0;

    for (int i = 0; i < n; i++)
    {
        if (nums1[i] == nums2[i])
            count++;
    }

    if (count == n){
        return 1;
    }
    else{
        return 0;
    }
}