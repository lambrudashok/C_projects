
#include<string.h>

//           medicine information
//--------------------------------------------- medicine entry-------------------------------------
void medi_entry()
{
    int id,rack,cabnit,quantity;
    float cost;
    char medi_name[50],unit[50],pur_date[12],exp_date[12],manu_date[12],comp_name[12],supp_name[12];
                        // perches date    expire date   manufacturing date  company name   supplier name
    FILE *mptr;
    mptr=fopen("MedicineInfo.text","a+");

    printf("Enter medicine id\n");
    scanf("%d",&id);
    printf("Enter medicine name\n");
    scanf("%s",medi_name);
    printf("Enter rack no\n");
    scanf("%d",&rack);
    printf("Enter cabinet\n");
    scanf("%d",&cabnit);
    printf("Enter quantity\n");
    scanf("%d",&quantity);
    printf("Enter unit\n");
    scanf("%s",&unit);
    printf("Enter cost\n");
    scanf("%f",&cost);
    printf("Enter perches date\n");
    scanf("%s",&pur_date);
    printf("Enter expire date\n");
    scanf("%s",&exp_date);
    printf("Enter manufacturing date\n");
    scanf("%s",&manu_date);
    printf("Enter company\n");
    scanf("%s",&comp_name);
    printf("Enter supplier\n");
    scanf("%s",&supp_name);

    fprintf(mptr,"%d\t%s\t%d\t%d\t%d\t%s\t%f\t%s\t%s\t%s\t%s\t%s\n", id, medi_name, rack, cabnit, quantity, unit, cost, pur_date, exp_date, manu_date, comp_name, supp_name);
    fclose(mptr);
}


// -------------------------------------display  medicine  stock--------------------------------------

void stock()
{
    FILE *mptr;

    int id,rack,cabnit,quantity;
    float cost;
    char medi_name[50],unit[50],pur_date[12],exp_date[12],manu_date[12],comp_name[12],supp_name[12];

    mptr=fopen("MedicineInfo.text","a+");
    printf("Display All Medicine Information\n");

    while(fscanf(mptr,"%d %s %d %d %d %s %f %s %s %s %s %s",&id, medi_name, &rack, &cabnit, &quantity, unit, &cost, pur_date, exp_date, manu_date, comp_name, supp_name)!=EOF){
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf(" id :%d \t medicine name :%s \t rack :%d \t cabnit :%d \t quantity :%d \t unit :%s \n cost :%f \t expire date :%s \t company name :%s\n",id, medi_name, rack, cabnit, quantity, unit, cost, exp_date, comp_name);
    }
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        fclose(mptr);
}




//------------------------------------------------- search medicine------------------------------------
void medi_search()
{
    FILE *mptr;
    mptr=fopen("MedicineInfo.text","a+");//open medicine file
    int id,rack,cabnit,quantity;
    float cost;
    char medi_name[50],unit[50],pur_date[12],exp_date[12],manu_date[12],comp_name[12],supp_name[12];

    char Cname[50];
    int flag=0;
    // search by medicine name
    printf("Enter Medicine Name For Search\n");
    scanf("%s",Cname);

    while(fscanf(mptr,"%d %s %d %d %d %s %f %s %s %s %s %s",&id, medi_name, &rack, &cabnit, &quantity, unit, &cost, pur_date, exp_date, manu_date, comp_name, supp_name)!=EOF){
        if(strcmp(medi_name,Cname)==0){
            flag=1;
            break;
        }
    }
    if(flag){
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf("Medicine Information\n");
         printf(" id :%d \t medicine name :%s \t rack :%d \t cabnit :%d \t quantity :%d \t unit :%s \n cost :%f \t expire date :%s \t company name :%s\n",id, medi_name, rack, cabnit, quantity, unit, cost, exp_date, comp_name);
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
     }else{
     printf("Medicine not found\n");
     }
     fclose(mptr);

}


//---------------------------------------------------------update medicine stock-------------------------------------------------------


void update_stock()
{

    int id,rack,cabnit,quantity;
    float cost;
    char medi_name[50],unit[50],pur_date[12],exp_date[12],manu_date[12],comp_name[12],supp_name[12];

    FILE *mptr;
    FILE *mtemp;
    mptr=fopen("MedicineInfo.text","r+");
    mtemp=fopen("Med.text","w");

     int Cid,flag=0;
     printf("Enter id for update\n");
     scanf("%d",&Cid);

     while(fscanf(mptr,"%d %s %d %d %d %s %f %s %s %s %s %s",&id, medi_name, &rack, &cabnit, &quantity, unit, &cost, pur_date, exp_date, manu_date, comp_name, supp_name)!=EOF){
        if(id==Cid){
        flag=1;
        printf("Medicine Update Information\n");
        printf("1.rack\n2.cabnit\n3.quantity\n4.cost\n5.supplier name\n");
        int choice;
        printf("What you want update\n");
        scanf("%d",&choice);
        switch(choice){


    case 1:
        {
        printf("Enter new rack\n");
        scanf("%d",&rack);
        }
        break;

    case 2:
        {
        printf("Enter new cabnit\n");
        scanf("%d",&cabnit);
        }
        break;

    case 3:
        {
        printf("Enter new quantity\n");
        scanf("%d",&quantity);
        }
        break;

    case 4:
        {
        printf("Enter new cost\n");
        scanf("%f",&cost);
        }
        break;

    case 5:
        {
        printf("Enter new supplier name\n");
        scanf("%s",&supp_name);
        }
        break;

    default:
        printf("Not Updated\n");
        flag=0;
        }

     }
    fprintf(mtemp,"%d\t%s\t%d\t%d\t%d\t%s\t%f\t%s\t%s\t%s\t%s\t%s\n", id, medi_name, rack, cabnit, quantity, unit, cost, pur_date, exp_date, manu_date, comp_name, supp_name);

  }
  fclose(mptr);
  fclose(mtemp);
  if(flag){
    remove("MedicineInfo.text"); //remove original file
    rename("Med.text","MedicineInfo.text"); //rename temporary file to original file
    printf("Updated Successfully.......\n\n");
  }else{
  remove("Med.text");
  printf("Customer not found\n\n");
  }


}


// main medicine method
int medicine(){

    int choice;
 do{

    printf("\n1.Add Medicine\n");
    printf("2.Display Medicine Stock\n");
    printf("3.Search Medicine\n");
    printf("4.Update Medicine Information\n");

    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        medi_entry();
        break;

    case 2:
        stock();
        break;

    case 3:
        medi_search();
        break;

    case 4:
        update_stock();
        break;

    default:
    printf("Wrong choice\n");

     }

  }while(choice!=0);


}
