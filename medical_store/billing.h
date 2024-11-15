
    struct Billing{
    int billno,medi_qty;
    float medi_rate;
    char medicine_name[50],cname[50],DayMonthYear[15];
    };
    struct Billing b[20];
    FILE *billptr;
    int ret=0,retw=0,count=0;
    float total=0;
     //billing information
 void bill(){


    // declare for billing

    // declare for medicine
    FILE *ptr,*temp;
    int id,rack,cabnit,quantity;
    float cost;
    char medi_name[50],unit[50],pur_date[12],exp_date[12],manu_date[12],comp_name[12],supp_name[12];


    ptr=fopen("MedicineInfo.text","r+"); // open medicine file
    int flag=0;

    if(ret){
    printf("Enter another medicine name\n");
    scanf("%s",b[count].medicine_name);
    printf("Enter another quantity\n");
    scanf("%d",&b[count].medi_qty);
    }else{

    printf("Enter bill no\n");
    scanf("%d",&b[count].billno);
    printf("Enter Customer name\n");
    scanf("%s",b[count].cname);
    printf("Enter Day , month ,year\n");
    scanf("%s",b[count].DayMonthYear);
    printf("Enter medicine name\n");
    scanf("%s",b[count].medicine_name);
    printf("Enter quantity\n");
    scanf("%d",&b[count].medi_qty);
    }
    // check quantity and medicine name available or not
    while(fscanf(ptr,"%d %s %d %d %d %s %f %s %s %s %s %s",&id, medi_name, &rack, &cabnit, &quantity, unit, &cost, pur_date, exp_date, manu_date, comp_name, supp_name)!=EOF){
        if((b[count].medi_qty<=quantity)&&(strcmp(b[count].medicine_name,medi_name)==0)){
            flag=1;
            b[count].medi_rate=cost*b[count].medi_qty;
            float per;
            per=b[count].medi_rate/10;
            total=b[count].medi_rate+per+total;
            fclose(ptr);
            break;
        }
    }
    fclose(ptr);

      // medicine quantity decrease
      int flag2=0;
    ptr=fopen("MedicineInfo.text","r+"); // open medicine file
    temp=fopen("med.text","w");
     if(flag){
     while(fscanf(ptr,"%d %s %d %d %d %s %f %s %s %s %s %s",&id, medi_name, &rack, &cabnit, &quantity, unit, &cost, pur_date, exp_date, manu_date, comp_name, supp_name)!=EOF){
        if(strcmp(b[count].medicine_name,medi_name)==0){
            quantity=quantity-b[count].medi_qty;
            flag2=1;
        }

        fprintf(temp,"%d \t %s \t %d \t %d \t %d \t %s \t %f \t %s \t %s \t %s \t %s \t %s\n",id, medi_name, rack, cabnit, quantity, unit, cost, pur_date, exp_date, manu_date, comp_name, supp_name);
    }
     }
     fclose(ptr);
     fclose(temp);
     if(flag2){
       remove("MedicineInfo.text"); //remove original file
       rename("med.text","MedicineInfo.text"); //rename temporary file to original file
     }else{
       remove("med.text");
       printf("Not Found\n\n");
     }
     // store bill info
     // billing information entry save
     if(flag){
        billptr=fopen("BillInfo.text","a+");// open billing file
        fprintf(billptr,"%d \t %s \t %s \t %d \t %f \t %s\n",b[count].billno, b[count].medicine_name, b[count].cname, b[count].medi_qty, total, b[count].DayMonthYear);
        fclose(billptr);
     }
//     //-------------------------------
    int c;
    printf("If we have bye another medicine\n");
    printf("press 1 otherwise 0\n");
    scanf("%d",&c);
    if(c){
        count++;
        ret=1;
       return bill();
    }

  if(flag){


  if(ret){

     int i;
     // entry multiple medicine bill
     for(i=0;i<=count;i++){
        if(i<=0){
        billptr=fopen("CustomerBillInfo.text","w+");// open billing file
        fprintf(billptr,"%d \t %s \t %s \t %d \t %s\n",b[i].billno, b[i].medicine_name, b[i].cname, b[i].medi_qty,b[i].DayMonthYear);
        }else{
        fprintf(billptr,"%s \t %d \n",b[i].medicine_name, b[i].medi_qty);

        }
   }
       fprintf(billptr,"%f \n",total);
       fclose(billptr);

       // display customer multiple medicine bill
       for(i=0;i<=count;i++){
        if(i<=0){
        printf("Bill No :%d \t Customer name :%s  \t Medicine name :%s \t Medicine bye :%d \t Date :%s\n",b[i].billno, b[i].cname,  b[i].medicine_name, b[i].medi_qty,b[i].DayMonthYear);
        }else{
        printf("Medicine name :%s \t Medicine bye :%d \n",b[i].medicine_name, b[i].medi_qty);

        }
   }
       printf("----------------------------------------------------------------------------------------------------------\n");
       printf("Total bill :%f \n",total);
       total=0;


    }else{
        // entry bill customer info
        billptr=fopen("CustomerBillInfo.text","w+");// open billing file
        fprintf(billptr,"%d \t %s \t %s \t %d \t %f \t %s\n",b[count].billno, b[count].medicine_name, b[count].cname, b[count].medi_qty, total, b[count].DayMonthYear);
        fclose(billptr);

        // display bill info
       printf("Billing slip\n");
       printf("----------------------------------------------------------------------------------------------------------\n");
       printf("Bill No :%d \t Medicine name :%s \t Customer name :%s \n Medicine bye :%d \t total bill :%f \t Date :%s\n",b[count].billno, b[count].medicine_name, b[count].cname, b[count].medi_qty, total, b[count].DayMonthYear);
       printf("----------------------------------------------------------------------------------------------------------\n");
       total=0;
    }

  }
   else{
     printf("quantity not found\n");
      }

}
