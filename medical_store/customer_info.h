#include<string.h>
// customer information
struct customerInfo{

int cust_id;
char cust_name[60];
char city[60];
char mob_no[11];
char email[60];

};
struct customerInfo custInfo;
FILE *ptr;
// --------------------------------------------------- customer  entry-------------------------------------------------------------
void cust_entry()
{
    ptr=fopen("CustInfo.text","a+");
    printf("Enter customer id\n");
    scanf("%d",&custInfo.cust_id);
    printf("Enter customer name\n");
    scanf("%s",&custInfo.cust_name);
    printf("Enter customer city\n");
    scanf("%s",&custInfo.city);
    printf("Enter customer mobile number\n");
    scanf("%s",&custInfo.mob_no);
    printf("Enter customer email\n");
    scanf("%s",custInfo.email);
    fprintf(ptr,"%d\t%s\t%s\t%s\t%s\n",custInfo.cust_id,custInfo.cust_name,custInfo.city,custInfo.mob_no,custInfo.email);
    fclose(ptr);

}


//----------------------------------------------- customer display information--------------------------------------------------------
void cust_list()
{
    ptr=fopen("CustInfo.text","a+");
    printf("List All Customer Information\n");

    while(fscanf(ptr,"%d %s %s %s %s",&custInfo.cust_id,&custInfo.cust_name,&custInfo.city,&custInfo.mob_no,&custInfo.email)!=EOF){
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%s\t%s\t%s\n",custInfo.cust_id,custInfo.cust_name,custInfo.city,custInfo.mob_no,custInfo.email);
    }
        printf("----------------------------------------------------------------------------------------------------------\n");
        fclose(ptr);
}


//-------------------------------------------------- customer search info--------------------------------------------------------------
cust_search(){

 printf("1.search customer id\n2.search customer name\n");
 int choice;
 ptr=fopen("CustInfo.text","a+");
 printf("Enter choice search customer\n");
 scanf("%d",&choice);
 switch(choice){

 case 1:
     {
     int cid,flag=0;
     //search by customer id
     printf("Enter id for search\n");
     scanf("%d",&cid);
     while(fscanf(ptr,"%d %s %s %s %s",&custInfo.cust_id, &custInfo.cust_name, &custInfo.city, &custInfo.mob_no, &custInfo.email)!=EOF){
        if(custInfo.cust_id==cid){
            flag=1;
            break;
        }
     }
     if(flag){
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("Customer Information\n");
        printf("%d \t%s \t%s \t%s \t%s\n",custInfo.cust_id,custInfo.cust_name,custInfo.city,custInfo.mob_no,custInfo.email);
        printf("----------------------------------------------------------------------------------------------------------\n");
     }else{
     printf("Customer not found\n");
     }
     fclose(ptr);
     }
     break;

 case 2:
     {
    char Cname[60];
    int flag2=0;
    //search by customer name
    printf("Enter name for search\n");
    scanf("%s",&Cname);
    while(fscanf(ptr,"%d %s %s %s %s",&custInfo.cust_id,&custInfo.cust_name,&custInfo.city,&custInfo.mob_no,&custInfo.email)!=EOF){
        if(strcmp(custInfo.cust_name,Cname)==0){
            flag2=1;
            break;
        }
    }
    if(flag2){
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("Customer Information\n");
        printf("%d \t%s \t%s \t%s \t%s\n",custInfo.cust_id,custInfo.cust_name,custInfo.city,custInfo.mob_no,custInfo.email);
        printf("----------------------------------------------------------------------------------------------------------\n");
     }else{
     printf("Customer not found\n");
     }
     fclose(ptr);
     }
     break;
  }

}



// ----------------------------------------update customer info------------------------------------------------------------------

cust_update(){

     FILE *temp;
     ptr=fopen("CustInfo.text","r+");
     temp=fopen("Cust.text","w");

     int cstId,flag=0;
     printf("Enter id for update\n");
     scanf("%d",&cstId);

     while(fscanf(ptr,"%d %s %s %s %s",&custInfo.cust_id, custInfo.cust_name, custInfo.city, custInfo.mob_no, custInfo.email)!=EOF){
        if(custInfo.cust_id==cstId){
        flag=1;

        printf("Customer Information Update\n");
        printf("1.all information\n2.name\n3.city\n4.mobile number\n5.email\n");
        int choice;
        printf("What you want update\n");
        scanf("%d",&choice);
        switch(choice){

    case 1:
        {
        printf("Enter new name\n");
        scanf("%s",&custInfo.cust_name);
        printf("Enter new city\n");
        scanf("%s",custInfo.city);
        printf("Enter new mobile number\n");
        scanf("%s",custInfo.mob_no);
        printf("Enter new email\n");
        scanf("%s",custInfo.email);
        }
        break;

    case 2:
        {
        printf("Enter new name\n");
        scanf("%s",custInfo.cust_name);
        }
        break;

    case 3:
        {
        printf("Enter new city\n");
        scanf("%s",custInfo.city);
        }
        break;

    case 4:
        {
        printf("Enter new mobile number\n");
        scanf("%s",custInfo.mob_no);
        }
        break;

    case 5:
        {
        printf("Enter new email\n");
        scanf("%s",custInfo.email);
        }
        break;

    default:
        printf("Not Updated\n");
        flag=0;
        }

     }
        fprintf(temp,"%d\t%s\t%s\t%s\t%s\n",custInfo.cust_id,custInfo.cust_name,custInfo.city,custInfo.mob_no,custInfo.email);

  }
  fclose(ptr);
  fclose(temp);
  if(flag){
    remove("CustInfo.text"); //remove original file
    rename("Cust.text","CustInfo.text"); //rename temporary file to original file
    printf("Updated Successfully.......\n\n");
  }else{
  remove("Cust.text");// remove temporary file
  printf("Customer not found\n\n");
  }
}




// main function customer information
void customer()
{

    int choice;
    do{
        printf("\n1.Add Customer Entry\n");
        printf("2.View Customer List\n");
        printf("3.Search Customer\n");
        printf("4.Update Customer Information\n\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
      case 1:
           cust_entry();
           break;

      case 2:
        cust_list();
        break;

      case 3:
        cust_search();
        break;

      case 4:
        cust_update();
        break;

      default:
        printf("Wrong choice\n");

        }
    }while(choice!=0);




}








