/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Auchan
 *
 * Created on 27 octobre 2018, 15:22
 */

#include <stdio.h>
#include <stdlib.h>
#include "automate.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE * f=fopen("automate.txt","r");
     lire_lts(f);
    
    
    return (EXIT_SUCCESS);
}

