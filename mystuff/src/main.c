#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <stdio.h>
#include "debugScreen.h"

#define printf psvDebugScreenPrintf
double calculate(double x, char oper, double y){
    char add = '+';
    char substract = '-';
    char multiply = '*';
    char divide = '/';
    double result = 0.0;

    if(oper == add)
        return (x + y);
    
    else 
        if(oper == substract)
            return (x - y);
        else 
            if(oper == multiply)
                return (x * y);
            else
                 if(oper == divide)
                    return (x / y);
                else
                    return 0; 
    
}

int main(int argc, char *arg[]){
    
    double x,y,result;
    x = 0.0;
    y = 0.0;
    result = 0.0;
    char oper = '+';

    psvDebugScreenInit();
    printf("Calculator Console Application!\n Please enter the operation to perform. Format: a+b | a-b | a*b | a/b");
    while(1){
        sceKernelDelayThread(10*1000000);
        scanf("%lf", "%c", "%lf", x, oper, y);
        result = calculate(x, oper, y);
        printf("Result is: %lf", result);
        
    }
        
    sceKernelExitProcess(0);
    return 0;
}

