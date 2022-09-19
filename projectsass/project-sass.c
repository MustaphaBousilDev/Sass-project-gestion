#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct medication{
  int  Code;
  char Name[30];
  int Quantity;
  float Price;
};
struct medication T_product[100];


struct Sold{
  char Name[20];
  int sold;
  float price;
  int h,m,s;

};
struct Sold T_sold[100];
int count_pro=0;
void Add(){
  int n,i;
  printf("\t##--------------Add Product--------------##\n");
  printf("Enter How Mush you want to add ");
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    printf("##---Product Number : %d \n",i);
    printf("Code :");
    scanf("%d",&T_product[count_pro].Code);
    printf("Name :");
    scanf("%s",&T_product[count_pro].Name);
    printf("Quantity :");
    scanf("%d",&T_product[count_pro].Quantity);
    printf("Price :");
    scanf("%f",&T_product[count_pro].Price);
    count_pro++;
}}
void Display_Pro(){
	    int i,n,j;
    float price_TTC;
    char c[100];int t;
    printf("\t##--------------Display Product--------------##\n");
    do{
     printf("Enter (2) Order By Alphabitic Or (1) Order By Price\n");
     scanf("%d",&n);
    }while(n!=2 && n!=1);
    if(n==2){
        //Order By Alphabitique
        for(i=0;i<count_pro;i++){
            for(j=i+1;j<count_pro;j++){
                if(strcmp(T_product[i].Name,T_product[j].Name) > 0){
                    strcpy(c,T_product[i].Name);
                    strcpy(T_product[i].Name,T_product[j].Name);
                    strcpy(T_product[j].Name,c);
                }
            }
        }
        for(i=0;i<count_pro;i++){
        printf("##--Product Number \n",i);
        printf("Name : %s \n",T_product[i].Name);
        printf("Quantity : %d \n",T_product[i].Quantity);
        printf("Price : %.2f$ \n",T_product[i].Price);
        price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
        printf("Price(TTC) : %.2f$ \n",price_TTC);
        printf("------------------------------------\n");
        }

    }else if(n==1){
        //Order By Price
        for(int i=0;i<count_pro;i++){
            for(int j=i+1;j<count_pro;j++){
                if(T_product[i].Price < T_product[j].Price){
                    t=T_product[i].Price;
                    T_product[i].Price=T_product[j].Price;
                    T_product[j].Price=t;
                }
            }
        }
        for(i=0;i<count_pro;i++){
        printf("##--Product Number \n",i);
        printf("Name : %s \n",T_product[i].Name);
        printf("Quantity : %d \n",T_product[i].Quantity);
        printf("Price : %.2f$ \n",T_product[i].Price);
        price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
        printf("Price(TTC) : %.2f$ \n",price_TTC);
        printf("------------------------------------\n");
        }
     }

}
void Search_Pro(){
int n,i,code,quantity;
  float price_TTC;
  do{
     printf("Search (1) Order By Code Or (2) Order By Quantity\n");
     scanf("%d",&n);
    }while(n!=2 && n!=1);
  if(n==1){
     printf("Enter Code Product : ");
     scanf("%d",&code);
     for(i=0;i<count_pro;i++){
        if(code==T_product[i].Code){
           printf("Name : %s \n",T_product[i].Name);
           printf("Quantity : %d \n",T_product[i].Quantity);
           printf("Price : %.2f$\n",T_product[i].Price);
           price_TTC=T_product[i].Price + 0.15*T_product[i].Price;
           printf("Price(TTC) : %.2f $ \n",price_TTC);
        }
     }
  }else if(n==2){
     printf("\nsearch by quantity: ");
   scanf("%d",&quantity);
   for(i=0;i<count_pro;i++){
   if(quantity==T_product[i].Quantity){
   printf("%s\n",T_product[i].Name);
    printf("price of product: %.2f$ \n", T_product[i].Price);
    price_TTC = T_product[i].Price + 0.15*T_product[i].Price;
    printf("price (TTC) of product: %.2f$ \n", price_TTC);
    printf("\n---------------------------------------\n");

    }
   }
  }
}
void Edit_Qty(){

}
void Delete_Pro(){

}
void Pro_Qty_3(){

}
void Income(){

}

void Statistique(){

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
