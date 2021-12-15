#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customer.h"

struct Room
{
    char roomID[10];
    char roomName[20];
    int roomPrice[10];
};

struct Customer{
    char ID[255];
    char name[255];
    int age;
    char causeOfDeath[255];
    char restingPlace[255];
    int deathYear;
    Room r;
};

void newCustomer(){
    struct Customer cus;
    scanf("%s", cus.ID); getchar();
    scanf("%[^\n]", cus.name);getchar();
    scanf("%d", &cus.age);getchar();
    scanf("%[^\n]", cus.causeOfDeath);getchar();
    scanf("%[^\n]", cus.restingPlace);getchar();
    scanf("%d", &cus.deathYear);getchar();
    scanf("%s", &cus.r.roomID);getchar();

    FILE *fp = fopen("../customer/customer_data.txt", "a");
    fprintf(fp, "%s,%s,%d,%s,%s,%d,%s\n", cus.ID ,cus.name, cus.age,cus.causeOfDeath,cus.restingPlace,cus.deathYear,cus.r.roomID);
    fclose(fp);
}

void viewCustomer(){
    FILE *fp = fopen("../customer/customer_data.txt", "r");
    struct Customer cus;
    while(fscanf(fp, "%s,%[^,],%d,%[^,],%[^,],%d,%s\n", cus.ID ,cus.name, &cus.age,cus.causeOfDeath,cus.restingPlace,&cus.deathYear,cus.r.roomID) != EOF){
    printf("%s,", cus.ID); 
    printf("%s,", cus.name);
    printf("%d,", cus.age);
    printf("%s,", cus.causeOfDeath);
    printf("%s,", cus.restingPlace);
    printf("%d,", cus.deathYear);
    printf("%s\n", cus.r.roomID);
    printf("\n");
    }
}


void clrscr()
{
    system("@cls||clear");
}


int main(){
    int choice;
    do{
        clrscr();
        puts("Hotel del jojo");
        puts("1. Add new customer");
        puts("2. Read data");
        puts("3. Update data");
        puts("4. Remove data");
        puts("5. exit");
        printf("\nChoice [1-5] >> ");
        scanf("%d", &choice); getchar();
        switch(choice){
            case 1:{
                newCustomer();
                break;
            }
            case 2:{
                viewCustomer();
                getchar();
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
        }
    }while(choice != 5);
    return 0;
}