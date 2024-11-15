//header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// book store using linked list
int count=0;
struct Book_store{

 int id;
 char book_name[90];
 char author_name[70];
 char publish[70];
 int price;
 struct Book_store *next;
};

struct Book_store *head=NULL;
//--------------------------------------------------- 1 .book adding to store---------------------------
void bookInsert(){
  if(head==NULL){
    count++;
    // create variable pointer and store first book information on it
    head=(struct Book_store*)malloc(sizeof(Book_store));
    printf("\n\nAdd book information\n");
    printf("Enter book id\n");
    scanf("%d",&head->id);
    printf("Enter book name\n");
    scanf("%s",&head->book_name);
    printf("Enter author name\n");
    scanf("%s",&head->author_name);
    printf("Enter publisher\n");
    scanf("%s",&head->publish);
    printf("Enter book price\n");
    scanf("%d",&head->price);
    count++;
    head->next=NULL;

   }else{
      // create another book information and store in temp variable
       struct Book_store *temp,*temp1,*search1,*sea1,*sea2,*pri1,*pri2;
       temp=(struct Book_store*)malloc(sizeof(Book_store));
       temp1=head;
       while(temp1!=NULL){
           if(temp1->next==NULL){
             printf("Add book %d information\n",count);
             printf("Enter book id\n");
             scanf("%d",&temp->id);
             printf("Enter book name\n");
             scanf("%s",&temp->book_name);
             printf("Enter author name\n");
             scanf("%s",&temp->author_name);
             printf("Enter publisher\n");
             scanf("%s",&temp->publish);
             printf("Enter book price\n");
             scanf("%d",&temp->price);
             count++;
             temp->next=NULL;
             temp1->next=temp;
             break;
           }else{
             temp1=temp1->next;
           }
       }

    }
}

//--------------------------- --------------------------2. book information display------------------------------------------------

void bookDisplay(){
    int countD=0;
if(head==NULL){
    printf("Book Store Empty\n");
}else{
 struct Book_store *temp;
 temp=head;
 countD++;
 printf("------------------------------------------------------------------------------------------------------------------------\n");
 while(temp!=NULL){

       printf("book %d information\n\n",countD);
       printf("Id :%d\t",temp->id);
       printf("Book Name :%s\t",temp->book_name);
       printf("Author Name :%s\t",temp->author_name);
       printf("publisher :%s\t",temp->publish);
       printf("price :%d\n",temp->price);
       printf("------------------------------------------------------------------------------------------------------------------------\n");
       temp=temp->next;
     countD++;
 }
}
}

// ---------------------------------------- 3. search book by id or name or author--------------------------------------
void searchBook(){

 int Uid,Uchoice,flag=0;
 char Uname[50],Uauthor[50];
 if(head==NULL){
    printf("Book store are empty\n\n");
 }else{
 printf("search methods\n");
 printf("1.Id\n2.name\n3.author name\n");
 scanf("%d",&Uchoice);
 // switch case for search book in store
      switch(Uchoice){

         case 1:
             // id search case
         printf("Enter ID For Search \n");
         scanf("%d",&Uid);
         struct Book_store *temp;
         temp=head;
         while(temp!=NULL){
            if(temp->id==Uid){
                printf("----------------------------------------------------------------------------------------------------\n");
                printf("book information\n\n");
                printf("Id :%d\t",temp->id);
                printf("Book Name :%s\t",temp->book_name);
                printf("Author Name :%s\t",temp->author_name);
                printf("publisher :%s\t",temp->publish);
                printf("price :%d\n",temp->price);
                printf("----------------------------------------------------------------------------------------------------\n");
                flag=1;
                temp=temp->next;
            }else{
            temp=temp->next;
            }
         }
         if(flag==0){
            printf("Book not available in store\n");
         }
         break;


         case 2:
             // book name search case
            printf("Enter Book Name For Search\n");
            scanf("%s",&Uname);
            struct Book_store *temp1;
            temp1=head;

         while(temp1!=NULL){
            if(strcmp(temp1->book_name,Uname)==0){
                printf("----------------------------------------------------------------------------------------------------\n");
                printf("book information\n\n");
                printf("Id :%d\t",temp1->id);
                printf("Book Name :%s\t",temp1->book_name);
                printf("Author Name :%s\t",temp1->author_name);
                printf("publisher :%s\t",temp1->publish);
                printf("price :%d\n",temp1->price);
                printf("----------------------------------------------------------------------------------------------------\n");
                flag=1;
                temp1=temp1->next;
            }else{
            temp1=temp1->next;
            }
         }
         if(flag==0){
            printf("Book not available in store\n");
         }
         break;

         case 3:
             // author name search case
            printf("Enter Book Author Name For Search\n");
            scanf("%s",&Uauthor);
            struct Book_store *temp2;
         temp2=head;

         while(temp2!=NULL){
            if(strcmp(temp2->author_name,Uauthor)==0){
                printf("----------------------------------------------------------------------------------------------------\n");
                printf("book information\n\n");
                printf("Id :%d\t",temp2->id);
                printf("Book Name :%s\t",temp2->book_name);
                printf("Author Name :%s\t",temp2->author_name);
                printf("publisher :%s\t",temp2->publish);
                printf("price :%d\n",temp2->price);
                printf("----------------------------------------------------------------------------------------------------\n");
                flag=1;
                temp2=temp2->next;
            }else{
            temp2=temp2->next;
            }
         }
         if(flag==0){
            printf("Book not available in store\n");
         }
         break;

         default:
            printf("please select correct method for search\n");

      }
 }
}

//--------------------------------- ------------------------------------4 .delete book by id----------------------------------------------------

void deleteBook(){
    int Bid,flag=0;
    printf("Enter Book Id\n");
    scanf("%d",&Bid);
    struct Book_store *temp,*temp1,*temp2;
    if(head==NULL){
        printf("Book Store Are Empty\n");
    }else if(head->next==NULL){
               if(head->id==Bid){
               printf("----------------------------------------------------------------------------------\n");
               printf("Deleted Book\n\n");
               printf("Id :%d\t",head->id);
               printf("Book Name :%s\t",head->book_name);
               printf("Author Name :%s\t",head->author_name);
               printf("publisher :%s\t",head->publish);
               printf("price :%d\n",head->price);
               count=0;
               printf("----------------------------------------------------------------------------------\n");
               flag=1;
               free(head);
               head=NULL;
               }

    }else if(head->id==Bid){
        struct Book_store *btemp;
        printf("----------------------------------------------------------------------------------\n");
        printf("Deleted Book\n\n");
        printf("Id :%d\t",head->id);
        printf("Book Name :%s\t",head->book_name);
        printf("Book price :%d\n",head->price);
        count--;
        printf("----------------------------------------------------------------------------------\n");

        btemp=head;
        flag=1;
        head=head->next;
        btemp->next=NULL;
        free(btemp);
        btemp=NULL;

    }else{
    temp=head;
    while(temp!=NULL){

        if(temp->id==Bid){
                printf("----------------------------------------------------------------------------------\n");
                printf("Deleted Book\n\n");
                printf("Id :%d\t",temp->id);
                printf("Book Name :%s\t",temp->book_name);
                printf("Author Name :%s\t",temp->author_name);
                printf("publisher :%s\t",temp->publish);
                printf("price :%d\n",temp->price);
                count--;
                printf("----------------------------------------------------------------------------------\n");
                flag=1;
                temp2=temp;
                temp=temp->next;
                temp1->next=temp;
                temp2->next=NULL;
                free(temp2);
                temp2=NULL;
        }else{
         temp1=temp;
        temp=temp->next;

        }
    }
    }
    if(flag!=0){
        printf("Deleted Successfully\n\n");
    }else{
    printf("Book not available in store\n\n");
    }
}

//-------------------------------------------------- 5 .update book info by using id -----------------------------------------------

void updateBook(){
    int Uid,flag=0;
    struct Book_store *temp;
  if(head==NULL){
    printf("Book store are empty\n\n");
  }else{
      printf("Enter book Id\n");
      scanf("%d",&Uid);
    temp=head;
    while(temp!=NULL){
        if(temp->id==Uid){
            printf("Update New Book in store\n");
            printf("Enter new id\n");
            scanf("%d",&temp->id);
            printf("Enter New Book name\n");
            scanf("%s",&temp->book_name);
            printf("Enter Author name\n");
            scanf("%s",&temp->author_name);
            printf("Enter publisher\n");
            scanf("%s",&temp->publish);
            printf("Enter book price\n");
            scanf("%d",&temp->price);
            flag=1;
            break;
        }else{
        temp=temp->next;
        }
    }
    if(flag!=0){
        printf("Update Successfully\n\n");
    }else{
        printf("book not available in store\n\n");

    }

  }

}
//------------------------------------------------------6. count the book author wise ---------------------

void countBooksAuthor()
{
    if(head==NULL){
        printf("Book store empty\n");
    }else{

     int Uchoice;
    printf(" 1. Enter author name and count books\n");
    printf(" 2. count all authors books in store\n");
    printf("Enter your choice\n");
    scanf("%d",&Uchoice);

    switch(Uchoice){

     case 1:
       {
       int bookcount=0,flag=0;
       char Uautor[50];
       struct Book_store *temp;
       temp=head;
       printf("Enter Author Name\n");
       scanf("%s",&Uautor);
       while(temp!=NULL){
        if(strcmp(temp->author_name,Uautor)==0){
            if(bookcount==0){
            printf("--------------------------------------------------------------------------------------\n");
                }
            printf("book name :%s\n",temp->book_name);
            printf("--------------------------------------------------------------------------------------\n");
            bookcount++;
            flag=1;
            temp=temp->next;
        }else{
            temp=temp->next;
        }
       }
       if(flag!=0){
        printf("Total %s author books available : %d\n\n",Uautor,bookcount);
       }else{
       printf("%s author books not available\n\n",Uautor);
       }
       }
    break;

  case 2:

 {

    int flag=0;
    int beforeflag=0;
    int AutheCount=0;
    struct Book_store *temp1,*beforetemp,*AutSearch;
    temp1=head;
     while(temp1!=NULL){
         beforetemp=head;
         AutSearch=temp1;
         AutheCount=0;
         flag=0;
         beforeflag=0;

         while(beforetemp!=temp1){
            if(strcmp(temp1->author_name,beforetemp->author_name)==0 ){
              beforeflag=1;
              break;
          }else{
             beforetemp=beforetemp->next;
          }

         }// beforetemp
         if(beforeflag!=1){

            while(AutSearch!=NULL){
            if(strcmp(AutSearch->author_name,temp1->author_name)==0){
                AutheCount++;
                flag=1;
                AutSearch=AutSearch->next;
            }else{
            AutSearch=AutSearch->next;
            }
         }//search
            printf("author name : %s \t books : %d\n",temp1->author_name,AutheCount);
         }
          temp1=temp1->next;

     }//temp1


     }
     break;
    }

}

}
//-----------------------------------------------------7. count the book price wise-----------------

void countBookPrice()
{

    if(head==NULL){
        printf("Book Store Empty\n");
    }else{
        int UseChoice;
        printf("1. Enter book price and count books\n");
        printf("2 .Count all price books in store\n");
        printf("Enter choice\n");
        scanf("%d",&UseChoice);

        switch(UseChoice){

    case 1:
         {
        int bookCount=0,Uprice,flag=0;
        struct Book_store *temp;
        temp=head;
        printf("Enter book price\n");
        scanf("%d",&Uprice);
        while(temp!=NULL){
            if(temp->price==Uprice){
                bookCount++;
                if(bookCount==1){
                printf("-----------------------------------------------------------------------------------\n");
                }
                printf("%d .book name :%s\t price :%d\n",bookCount,temp->book_name,temp->price);
                printf("-----------------------------------------------------------------------------------\n");
                flag=1;
                temp=temp->next;
            }else{
            temp=temp->next;
            }
        }
        if(flag!=0){
            printf("Total %d price books available in store : %d \n\n",Uprice,bookCount);
        }else{
        printf("%d price books not available\n\n",Uprice);
        }
        }
        break;


    case 2:
        {
            //Count all price books in store
    int flag=0;
    int countPrice=0;
    struct Book_store *temp,*nextSearchtemp,*beforeSearchtemp;
    temp=head;

     while(temp!=NULL){

         beforeSearchtemp=head;
         nextSearchtemp=temp;
         flag=0;
         countPrice=0;

         while(beforeSearchtemp!=temp){
                if(temp->price==beforeSearchtemp->price){
                    flag=1;
                    break;
                }else{
                beforeSearchtemp=beforeSearchtemp->next;
                }
         }//beforeSearchtemp

         if(flag!=1){

            while(nextSearchtemp!=NULL){
                if(nextSearchtemp->price==temp->price){
                   countPrice++;
                   nextSearchtemp=nextSearchtemp->next;
                }else{
                nextSearchtemp=nextSearchtemp->next;
                }
            }// nextSearchtemp
             printf("book price : %d \t books : %d\n",temp->price,countPrice);
         }


          temp=temp->next;

     }//temp

        }
        break;

        }// switch case

    }
}


// ---------------------------------------------------8.count book publication wise --------------------------

void countBookPublication()
{
    if(head==NULL){
        printf("Book store empty\n");
    }else{
    int choice;
    printf("1. Enter publication and count books\n");
    printf("2. count all publication books in store\n");
    scanf("%d",&choice);

    switch(choice){

case 1:
    {
    int bookCount=0,flag=0;
    char publication[50];
    printf("Enter book publication name\n");
    scanf("%s",&publication);
    struct Book_store *temp;
    temp=head;
    while(temp!=NULL){
        if(strcmp(temp->publish,publication)==0){
            if(bookCount==0){
            printf("-----------------------------------------------------------------------------------\n");
            }
            bookCount++;
            printf("%d. book name :%s\t publication : %s \t price :%d\n",bookCount,temp->book_name,temp->publish,temp->price);
            printf("-----------------------------------------------------------------------------------\n");
            flag=1;
            temp=temp->next;
        }else{
            temp=temp->next;
        }
    }
    if(flag!=0){
        printf("Total %s publication books available : %d\n\n",publication,bookCount);
    }else{
    printf("%s publication books not available\n\n",publication);
    }
    }
    break;

case 2:
    {
    // count all publication books in store
    int flag=0,countPublication=0;
    struct Book_store *temp,*nextSearchtemp,*beforeSearchtemp;
    temp=head;

     while(temp!=NULL){

         beforeSearchtemp=head;
         nextSearchtemp=temp;
         flag=0;
         countPublication=0;

         while(beforeSearchtemp!=temp){
            if(strcmp(beforeSearchtemp->publish,temp->publish)==0 ){
              flag=1;
              break;
          }else{
             beforeSearchtemp=beforeSearchtemp->next;
          }

         }//beforeSearchtemp
         if(flag!=1){

            while(nextSearchtemp!=NULL){
                if(strcmp(temp->publish,nextSearchtemp->publish)==0){
                    countPublication++;
                    nextSearchtemp=nextSearchtemp->next;
                }else{
                 nextSearchtemp=nextSearchtemp->next;
                }
            }//nextSearchtemp

            printf("publication name : %s \t books : %d\n",temp->publish,countPublication);
         }

        temp=temp->next;
     }// temp


    }
    break;

    }

    }
}


// ----------------------------------------------9. arrange authors names as per book count by using descending order-----------------

void arrangeAuthorPerBook()
{


   if(head==NULL){
        printf("Book store empty\n");
    }else{

    struct Book_store *sizeTemp,*temp,*preSearch,*nextSearch;
    sizeTemp=head;  // sizeTemp pointer for count size of BookStore
    int size=0;
    while(sizeTemp!=NULL){     // we count size
        size++;
        sizeTemp=sizeTemp->next;
    }

    struct AuthorInfo{
       char nameAuthor[50];       // we create structure for store Author name and book count
       int countAut;
     };
     AuthorInfo storeBookAutherInfo[size];  // we declare structure array  of book store

    int c=0,flag=0;
    int countAuther=0;

    temp=head;

     while(temp!=NULL){ // traverse all book store linkedlist

         preSearch=head;
         nextSearch=temp;
         flag=0;
         countAuther=0;

         while(preSearch!=temp){  // preSearch pointer for search previous author name
            if(strcmp(temp->author_name,preSearch->author_name)==0 ){  // if found then skip this author
              flag=1;
              break;
          }else{
             preSearch=preSearch->next;
          }
         }//preSearch

         if(flag!=1){          // if not found previous author then count books

            while(nextSearch!=NULL){

            if(strcmp(temp->author_name,nextSearch->author_name)==0){
                countAuther++;                     // count Author book
                nextSearch=nextSearch->next;
            }else{
            nextSearch=nextSearch->next;
            }
            }//nextSearch

            strcpy(storeBookAutherInfo[c].nameAuthor,temp->author_name);  // store auther name to structor
            storeBookAutherInfo[c].countAut=countAuther;             // store author book count
            c++;
         }
         temp=temp->next;

     }// temp

     // we sort author name based on book count descending order
     for(int i=0;i<c;i++){
       for(int j=i+1;j<c;j++){
         if(storeBookAutherInfo[i].countAut<storeBookAutherInfo[j].countAut){
            struct AuthorInfo storeTempInfo=storeBookAutherInfo[i];
            storeBookAutherInfo[i]=storeBookAutherInfo[j];
            storeBookAutherInfo[j]=storeTempInfo;
        }
       }
     }

     // display author name descending order
     for(int i=0;i<c;i++){
        printf("Author name :%s\tBooks :%d\n",storeBookAutherInfo[i].nameAuthor,storeBookAutherInfo[i].countAut);
     }

}

}


int main()
{
    int choice;
    printf("%c%c %c%c WELCOME TO MY BOOK STORE !!!! %c%c %c%c",16,16,2,3,2,3,17,17);

    do{
     printf("\n\n1.Add New Book in Store\n");
     printf("2.Display Book Information\n");
     printf("3.Search Book By Id or Name or Author\n");
     printf("4.Delete Book By Id\n");
     printf("5.Update Book Information By Using Id\n");
     printf("6.Author Wise Books Count\n");
     printf("7.Price Wise Books Count\n");
     printf("8.Publication Wise Books Count\n");
     printf("9.arrange authors names as per book count by using descending order\n");
     printf("0.Exit\n\n");
     printf("Enter your choice\n");
     scanf("%d",&choice);

     switch(choice){

     case 1:
        bookInsert();
        break;

     case 2:
        bookDisplay();
        break;

     case 3:
        searchBook();
        break;

     case 4:
        deleteBook();
        break;

     case 5:
         updateBook();
        break;

     case 6:
        countBooksAuthor();
        break;

     case 7:
        countBookPrice();
        break;

     case 8:
        countBookPublication();
        break;

     case 9:
        arrangeAuthorPerBook();
        break;

     default:
        printf("Wrong Choice\n\n");
     }// switch case


    }while(choice!=0);
    printf(" %c THANKS FOR VISITING... %c \n\n",2,2);

    return 0;

}// main method

