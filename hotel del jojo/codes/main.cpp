#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 999
struct Room
{
    char roomId[10];
    char roomName[20];
    int roomPrice;
};

struct Customer{
    char ID[SIZE];
    char name[SIZE];
    int age;
    char causeOfDeath[SIZE];
    char restingPlace[SIZE];
    int deathYear;
    char roomId[SIZE];
};

int totalCustomer = 0, totalRoom = 0;
Customer *listC[SIZE];
Room *listR[SIZE];


void clrscr() {system("@cls||clear");}
int getRoom(char roomId[]){
    int total = 0;
    total += roomId[3] - '0' + (roomId[2] - '0') * 10 + (roomId[1] - '0') * 100;
    return total;
}

#include "customer.h"
#include "room.h"

void loadCustomer(){
    FILE *fp = fopen("../customer/customer_data.txt", "r");
    char ID[SIZE];
    char name[SIZE];
    int age;
    char causeOfDeath[SIZE];
    char restingPlace[SIZE];
    int deathYear;
    char roomId[SIZE];
    struct Customer *cus;
    while(!feof(fp)){
        fscanf(fp, "%[^,],%[^,],%d,%[^,],%[^,],%d,%s\n", ID ,name, &age,causeOfDeath,restingPlace,&deathYear,roomId);
        cus = createNewCustomer(ID,name, age,causeOfDeath,restingPlace,deathYear,roomId);
        listC[totalCustomer] = cus;
        totalCustomer++;
    }
}

void loadRoom(){
    FILE *fp = fopen("../room/room.txt", "r");
    char roomId[SIZE];
    char roomName[SIZE];
    int roomPrice;

    struct Room *room;
    while(!feof(fp)){
        fscanf(fp, "%[^,],%[^,],%d\n" , roomId, roomName, &roomPrice);
        room = createNewRoom(roomId,roomName,roomPrice);
        listR[totalRoom] = room;
        totalRoom++;
    }

    fclose(fp);
}


int main(){
    loadCustomer();
    loadRoom();
    int choice = 0;
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
                break;
            }
            case 3:{
                updateCustomer();
                break;
            }
            case 4:{
                deleteCustomer();
                break;
            }
        }
    }while(choice != 5);
    return 0;
}