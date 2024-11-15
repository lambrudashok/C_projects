
#include<stdio.h>
#include "customer_info.h"
#include "medicine.h"
#include "supplier_info.h"
#include "billing.h"
#include "about.h"
#include "exit.h"

int main()
{
    int choice;
    printf("%c%c %c WELCOME TO MEDICINE STORE !!!! %c %c%c",16,16,2,2,17,17);

    do{
        printf("\n\n1.Customer Information\n");
        printf("2.Medicine\n");
        printf("3.Supplier Information\n");
        printf("4.Billing\n");
        printf("5.About\n");
        printf("6.Exit\n\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){

    case 1:
        customer();
        break;

    case 2:
        medicine();
        break;


    case 3:
        supplier();
        break;

    case 4:
        bill();
        break;

    case 5:
        about();
        break;

    case 6:
        exit();
        break;
        }


    }while(choice!=6);
}
