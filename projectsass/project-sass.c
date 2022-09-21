#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Structure Save Product
struct medication{
  int  Code;
  char Name[30];
  int Quantity;
  float Price;
};
struct medication T_product[100];
struct medication T_order[1];
/////////////////////////////////////////////////////////////
//Structure save product sold
struct Sold{
  char Name[20];
  int sold;
  float price;
  int day,month,year;
};
struct Sold T_sold[100];
////////////////////////////////////////////////////////////

int j,i;


void order_by(int i , int j){
  T_order[0]=T_product[i];
  T_product[i]=T_product[j];
  T_product[j]=T_order[0];
}


void get_Data(int i,float price_TTC){
   printf("##--Product Number %d--\n",i+1);
   printf("--------------------------------------\n");
   printf("Name Product      : %s \n"   ,T_product[i].Name);
   printf("Quantity Product  : %d \n"   ,T_product[i].Quantity);
   printf("Product Price     : %.2f$ \n",T_product[i].Price);
   printf("Price(TTC)        : %.2f$ \n",price_TTC);
   printf("------------------------------------\n");
}



int count_pro=0;
void Add(){
  int n;
  printf("-----------------------------------------------\n");
  printf("\##--------------Add Product-----------------##\n");
  printf("-----------------------------------------------\n");
  printf("//->Enter How Mush Product  you want to add ");
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    printf("##---Product Number : %d \n",i);
    printf("Code Product :");
    scanf("%d",&T_product[count_pro].Code);
    printf("Name Product :");
    scanf("%s",&T_product[count_pro].Name);
    printf("Quantity :");
    scanf("%d",&T_product[count_pro].Quantity);
    printf("Price($) :");
    scanf("%f",&T_product[count_pro].Price);
    count_pro++;
}}
void Display_Pro(){
    int choose;
    int or_code , or_quantity , or_price;
    char or_name[20];
    float price_TTC;
    printf("\t##-------------------------------------------##\n");
    printf("\t##--------------Display Product--------------##\n");
    printf("\t##-------------------------------------------##\n");
    do{
     printf("Enter (2) Order By Alphabitic Or (1) Order By Price\n");
     scanf("%d",&choose);
    }while(choose!=2 && choose!=1);
    if(choose==2){
        //Order By Alphabitique Croissent
        for(i=0;i<count_pro;i++){
            for(j=i+1;j<count_pro;j++){
                if(strcmp(T_product[i].Name,T_product[j].Name) > 0){
                    order_by(i,j);
                }
            }
        }
        for(i=0;i<count_pro;i++){
            if(T_product[i].Quantity==0){
                continue;
            }else{
                price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
                get_Data(i,price_TTC);
            }
        }
    }else if(choose==1){
        //Order By Price decroissent
        for(int i=0;i<count_pro;i++){
            for(int j=i+1;j<count_pro;j++){
                if(T_product[i].Price < T_product[j].Price){
                    order_by(i,j);
                }
            }
        }
        for(i=0;i<count_pro;i++){
          if(T_product[i].Quantity==0){
            continue;
          }else{
              price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
              get_Data(i,price_TTC);
          }
        }
     }

}
void Search_Pro(){
int choose,code,quantity;
  float price_TTC;
  do{
     printf("Search (1) by Code Or (2)  By Quantity\n");
     scanf("%d",&choose);
    }while(choose!=2 && choose!=1);
  if(choose==1){
     printf("#-------search by Code------------#\n");
     printf("#---------------------------------# \n");
     printf("Code :");
     scanf("%d",&code);
     for(i=0;i<count_pro;i++){
        if(code==T_product[i].Code){
           price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
           get_Data(i,price_TTC);
           //count_err++;
        }
     }
  }else if(choose==2){
     printf("\n #-------search by quantity------------#");
     printf("#----------------------------------------# \n");
   scanf("%d",&quantity);
   for(i=0;i<count_pro;i++){
   if(quantity==T_product[i].Quantity){
      price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
      get_Data(i,price_TTC);
    }
   }
  }
}
/////////////////////////////////////////////////////////////
int count_sold=0;
int code_edit;


void Edit_Qty(){
 int sold;//variable for sold product
 printf("Enter Code Product :");
 scanf("%d",&code_edit);
 printf("\n");
 int qty_old=old_quantity();
 printf("Old Quantitty: %d \n",qty_old);

 for(i=0;i<count_pro;i++){
    if(code_edit==T_product[i].Code){
      printf("New Quantity :");
      scanf("%d",&T_product[i].Quantity);
      if(qty_old > T_product[i].Quantity){
        sold=qty_old - T_product[i].Quantity;
        //Save data in table structur Sold;
        time_t t;
        time(&t);
        struct tm *time=localtime(&t);
        T_sold[count_sold].day=time->tm_mday;
        T_sold[count_sold].month=time->tm_mon +1;
        T_sold[count_sold].year=time->tm_year + 1900;
        T_sold[count_sold].sold=sold;
        strcpy(T_sold[count_sold].Name,T_product[i].Name);
        T_sold[count_sold].price=T_product[i].Price;
        count_sold++;
      }
    }
  }
}
int old_quantity(){
    int old_qty;
    for(int i=0;i<count_pro;i++){
        if(code_edit==T_product[i].Code){
            old_qty=T_product[i].Quantity;
        }
    }
    return old_qty;
}
/////////////////////////////////////////////////////////////////
void Delete_Pro(){
    int code,index;
    printf("Enter Code Product :");
    scanf("%d",&code);
    for(int i=0;i<count_pro;i++){
        if(code==T_product[i].Code){
            index=i;
            for(i=index;i<count_pro;i++){
                T_product[i]=T_product[i+1];
            }
            count_pro--;
            printf("##--SUccess Delete This Product ! ##");
            break;
        }

    }
  /*for (int i=0;i<count_pro;i++)  {
    printf("%s\n",T_product[i].Name);*/
  //}
}
///////////////////////////////////////////////////////////////////////////////////////////
void Pro_Qty_3(){
    float price_TTC;
        for(i=0;i<count_pro;i++){
          if(T_product[i].Quantity <3){
            if(T_product[i].Quantity==0){
                continue;
            }else{
                price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
                get_Data(i,price_TTC);
            }
          }
        }
}
void Income(){
   int i;
   printf("count_sold %d",count_sold);
   for(i=0;i<count_sold;i++){
    printf("Name: %s \n",T_sold[i].Name);
    printf("Sold: %d \n",T_sold[i].sold);
    printf("Price: %.2f$ \n",T_sold[i].price);
    printf("Date : %d/%d/%d \n",T_sold[i].day,T_sold[i].month,T_sold[i].year);
    printf("------------------------------------------------\n");
  }
}

void Statistique(){
  float  min, max;
  float total=0;
  int qty_total=0;
  float moyen;

  for(i=0;i<count_sold;i++){
    total+=T_sold[i].price*T_sold[i].sold;
    qty_total+=T_sold[i].sold;
  }
  printf("total of the day is: %.2f\n", total);
  moyen = total / qty_total;
  printf("moyen of the day is: %.2f\n", moyen);

  min = T_sold[0].price;
  for(i=1;i<count_sold;i++){
    if(T_sold[i].price<min) min = T_sold[i].price;
  }
  printf("le min est:   %.2f$\n",min);
  max = T_sold[0].price;
  for(i=1;i<count_sold;i++){
    if(T_sold[i].price>max) max = T_sold[i].price;
  }
  printf("le max est:   %.2f$",max);
}


int main(){
	 int choose;
 do{
    printf("\n----------------MENU-----------------\n");
    printf("\-01--Add Products\n");
    printf("\-02--Display Products\n");
    printf("\-03--Search Product\n");
    printf("\-04--Edit Quantity Products\n");
    printf("\-05--Delete Product\n");
    printf("\-06--Display Product Quantity < 3\n");
    printf("\-07--Income\n");
    printf("\-08--Statistique\n");
    printf("\-0--Exit\n\n");
    printf("Enter Your Choose ");
    scanf("%d",&choose);
    switch(choose){
    case 1 :system("cls");
       Add();
    break;
    case 2 :system("cls");
       Display_Pro();
    break;
    case 3 :system("cls");
       Search_Pro();
    break;
    case 4 :system("cls");
       Edit_Qty();
    break;
    case 5 :system("cls");
       Delete_Pro();
    break;
    case 6 :system("cls");
       Pro_Qty_3();
    break;
    case 7 :system("cls");
       Income();
    break;
    case 8 :system("cls");
       Statistique();
    break;
    case 0 :system("cls");
    break;
    default:system("cls"); printf("Error You need to choose 1 or 2,3,4,5,6,7,8");

  }
 }while(choose!=0);




 return 0;
}
