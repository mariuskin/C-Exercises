/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Vytas
 *
 * Created on 27 avril 2016, 07:37
 */

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int * make_copy(int * tab, int k){
    int * tab2 = (int*)malloc(k*sizeof(int));
    for (int i = 0 ; i < k; i++){
        tab2[i] = tab[i];
    }
    
    return tab2;
}

bool prime_number(int n) {

    int c = 2;

    for (c = 2; c <= n - 1; c++) {
        if (n % c == 0) {
            return false;
            break;
        }
    }
    if (c == n)
        return true;
}

void print_tab(int * tab, int k) {

    for (int i = 0; i < k; i++) {
        printf("tab[%d]=%d ", i, tab[i]);
    }

}

int * ivedamas_skaiciu_masyvas(int * k) {

    int l;
    int m;

    printf("Kiek skaiciu norite ivesti?\n");
    scanf("%d", &l);

    int * tab = (int*) malloc(l * sizeof (int));

    printf("iveskite skaicius\n");

    for (int i = 0; i < l; i++) {
        scanf("%d", &m);
        tab[i] = m;
    }
    *k = l;
    printf("\n");

    return tab;
}

int get_random_number() {
    srand(time(NULL));
    int r = rand();
    return r;

}

void swap_content(int * tab, int i, int j) {

    int temp;

    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;

}

int kiekis_pirmuju_skaiciu(int * tab, int k){
    int count = 0;
    for(int i = 0; i < k; i++){
        if(prime_number(tab[i])){
            count++;
        }
    }
    return count;
}

void pateikti_pirminius_skaicius_mazejimo_tvarka(int * tab, int k){
    int count = 0;
    int n = kiekis_pirmuju_skaiciu(tab, k);
    int * tab2 = (int *)malloc(n*sizeof(int));
    
    for (int i = 0; i < k; i++){
      if(prime_number(tab[i])){
          tab2[count] = tab[i];
          count++;
      }  
    }
    
    print_tab(tab2, n);
    
}




void surusiuoti_didejimo_tvarka(int * tab, int k){
   
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (tab[i] > tab[j]) {
                swap_content(tab, i, j);
            }
        }
    }
}

void surusiuoti_mazejimo_tvarka(int * tab, int k){
    
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (tab[i] < tab[j]) {
                swap_content(tab, i, j);
            }
        }
    }
    
}

void masyvas_didejimo_tvarka(int * tab, int k) {

    int tab2[k];

    for (int i = 0; i < k; i++) {
        tab2[i] = tab[i];
    }

    surusiuoti_didejimo_tvarka(tab2, k);
    print_tab(tab2, k);

}

int find_max(int* tab, int k){
    int max = tab[0];
    for (int i = 0; i<k; i++){
        if (max < tab[i]){
            max = tab[i];
        }
    }
}


void pateikti_masyva_su_nesikartuojanciais_skaiciais(int * tab, int k){
    
    int * tab3;
    int count = 1;
    bool idetas;
    int tab2[k];
    tab2[0] = tab[0];
    
    for (int i = 0; i < k-1; i++){
        for (int j = 0; j<count; j++){
            
            if (tab[i] == tab2[j]){  
                idetas = true;
            }
        }
        
        if (idetas){
            idetas = false;
        }else{
            tab2[count] = tab[i];
            count++;
        }
        
    }
    printf("%d\n", count);
    print_tab(tab2, count);
    tab3 = make_copy(tab2, count);
    surusiuoti_didejimo_tvarka(tab3, count);
    print_tab(tab3, count);
    
}

void skaiciai_itervale_a_b_pateikti_mazejimo_tvarka(int * tab, int k){
    
    surusiuoti_mazejimo_tvarka(tab, k);
    
    int a, b;
    int count = 0;
    printf("Iveskite 'a'\n");
    scanf("%d", &a);
    printf("Iveskite 'b'\n");
    scanf("%d", &b);
    
    for(int i = 0; i < k; i++ ){
        if (tab[i] >= a && tab[i] <= b){
            printf("%d ", tab[i]);
            count++;
        }
    }
    
    printf("\nIntervalui [%d;%d] priklausanciu skaiciu yra: %d\n", a, b, count);
    
}

void k_didziausiu_masyvo_skaiciu(int * tab, int k){
    
    int kiekis;
    surusiuoti_mazejimo_tvarka(tab, k);
    
    printf("Iveskite kieki!\n");
    scanf("%d", &kiekis);
    
    for(int i = 0; i<kiekis; i++){
        printf("%d ", tab[i]);
    }
    
}

void masyvu_sankirta(int * tab, int k, int * tab2, int k2){
    
    int count = 0;
    int * tab3 = (int*)malloc(k*k2*sizeof(int));
    
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k2; j++){
            if(tab[i] == tab2[j]){
                tab3[count] = tab[i];
                count++;
            }
        }
    }
    
    //print_tab(tab3,count);
    pateikti_masyva_su_nesikartuojanciais_skaiciais(tab3, count);
}

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {


    int * tab;
    int * tab2;
    
    int k;
    int k2;


    tab = ivedamas_skaiciu_masyvas(&k);
    tab2 = ivedamas_skaiciu_masyvas(&k2);
    
    
    
    //pateikti_masyva_su_nesikartuojanciais_skaiciais(tab, k);
    //skaiciai_itervale_a_b_pateikti_mazejimo_tvarka(tab, k);
    //k_didziausiu_masyvo_skaiciu(tab, k);
    masyvu_sankirta(tab,k,tab2,k2);
    
    
    system("pause");

    return 0;
}

