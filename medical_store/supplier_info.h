#include<string.h>
// supplier information
// ---------------------------------------------------logic for supplier  entry-------------------------------------------------------------
void supp_entry()
{
    FILE *sptr;

    int supp_id;
    char supp_name[50],mob_no[12],city[40],email[50];

    sptr=fopen("SupplierInfo.text","a+");

    printf("Enter supplier id\n");
    scanf("%d",&supp_id);
    printf("Enter supplier name\n");
    scanf("%s",&supp_name);
    printf("Enter supplier city\n");
    scanf("%s",&city);
    printf("Enter supplier mobile number\n");
    scanf("%s",&mob_no);
    printf("Enter supplier email\n");
    scanf("%s",&email);

    fprintf(sptr,"%d\t%s\t%s\t%s\t%s\n",supp_id, supp_name,city, mob_no, email);
    fclose(sptr);

}


//----------------------------------------------- logic for supplier display information--------------------------------------------------------
void supp_list()
{
    FILE *sptr;

    int supp_id;
    char supp_name[50],mob_no[12],city[40],email[50];

    sptr=fopen("SupplierInfo.text","a+");
    printf("List All supplier Information\n");

    while(fscanf(sptr,"%d %s %s %s %s",&supp_id, &supp_name, &city, &mob_no, &email)!=EOF){
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%s\t%s\t%s\n",supp_id, supp_name, city, mob_no, email);
    }
        printf("----------------------------------------------------------------------------------------------------------\n");
        fclose(sptr);
}


//-------------------------------------------------- logic for supplier search info--------------------------------------------------------------
supp_search(){

  FILE *sptr;

  int supp_id;
  char supp_name[50],mob_no[12],city[40],email[50];

  printf("1.search supplier id\n2.search supplier name\n");
  int choice;
  sptr=fopen("SupplierInfo.text","a+");
  printf("Enter choice search supplier\n");
  scanf("%d",&choice);
  switch(choice){

 case 1:
     {
     int sid,flag=0;
     printf("Enter id for search\n");
     scanf("%d",&sid);
     while(fscanf(sptr,"%d %s %s %s %s",&supp_id, &supp_name, &city, &mob_no, &email)!=EOF){
        if(supp_id==sid){
            flag=1;
            break;
        }
     }
     if(flag){
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("supplier Information\n");
        printf("%d \t%s \t%s \t%s \t%s\n", supp_id, supp_name, city, mob_no, email);
        printf("----------------------------------------------------------------------------------------------------------\n");
     }else{
     printf("supplier not found\n");
     }
     fclose(sptr);
     }
     break;

 case 2:
     {
    char Sname[60];
    int flag2=0;
    printf("Enter name for search\n");
    scanf("%s",&Sname);
    while(fscanf(sptr,"%d %s %s %s %s",&supp_id, &supp_name, &city, &mob_no, &email)!=EOF){
        if(strcmp(supp_name,Sname)==0){
            flag2=1;
            break;
        }
    }
    if(flag2){
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("Supplier Information\n");
        printf("%d \t%s \t%s \t%s \t%s\n", supp_id, supp_name, city, mob_no, email);
        printf("----------------------------------------------------------------------------------------------------------\n");
     }else{
     printf("supplier not found\n");
     }
     fclose(sptr);
     }
     break;
  }

}



// ----------------------------------------logic for update supplier info------------------------------------------------------------------

supp_update(){

     FILE *sptr;
     FILE *stemp;

     int supp_id;
     char supp_name[50],mob_no[12],city[40],email[50];

     sptr=fopen("SupplierInfo.text","r+");
     stemp=fopen("Supp.text","w");

     int spId,flag=0;
     printf("Enter id for update\n");
     scanf("%d",&spId);

     while(fscanf(sptr,"%d %s %s %s %s",&supp_id, &supp_name, &city, &mob_no, &email)!=EOF){
        if(supp_id==spId){
        flag=1;

        printf("Supplier Information Update\n");
        printf("1.all information\n2.name\n3.city\n4.mobile number\n5.email\n");
        int choice;
        printf("What you want update\n");
        scanf("%d",&choice);
        switch(choice){

    case 1:
        {
        printf("Enter new name\n");
        scanf("%s",supp_name);
        printf("Enter new city\n");
        scanf("%s",city);
        printf("Enter new mobile number\n");
        scanf("%s",mob_no);
        printf("Enter new email\n");
        scanf("%s",email);
        }
        break;

    case 2:
        {
        printf("Enter new name\n");
        scanf("%s",supp_name);
        }
        break;

    case 3:
        {
        printf("Enter new city\n");
        scanf("%s",city);
        }
        break;

    case 4:
        {
        printf("Enter new mobile number\n");
        scanf("%s",mob_no);
        }
        break;

    case 5:
        {
        printf("Enter new email\n");
        scanf("%s",email);
        }
        break;

    default:
        printf("Not Updated\n");
        flag=0;
        }

     }
        fprintf(stemp,"%d\t%s\t%s\t%s\t%s\n",supp_id, supp_name,city, mob_no, email);

  }
  fclose(sptr);
  fclose(stemp);
  if(flag){
    remove("SupplierInfo.text"); //remove original file
    rename("Supp.text","SupplierInfo.text"); //rename temporary file to original file
    printf("Updated Successfully.......\n\n");
  }else{
  remove("Supp.text");
  printf("Supplier not found\n\n");
  }
}




// main function supplier information
void supplier()
{

    int choice;
    do{
        printf("\n1.Add supplier Entry\n");
        printf("2.View supplier List\n");
        printf("3.Search supplier\n");
        printf("4.Update supplier Information\n\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
      case 1:
           supp_entry();
           break;

      case 2:
        supp_list();
        break;

      case 3:
        supp_search();
        break;

      case 4:
        supp_update();
        break;

      default:
        printf("Wrong choice\n");

        }
    }while(choice!=0);




}









