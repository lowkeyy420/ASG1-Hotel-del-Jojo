#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer *createNewCustomer(char ID[],char name[],int age,char causeOfDeath[],char restingPlace[],int deathYear,char roomId[]){
    struct Customer *temp = (Customer*)malloc(sizeof(Customer));
    strcpy(temp->ID,ID);
    strcpy(temp->name,name);
    temp->age = age;
    strcpy(temp->causeOfDeath,causeOfDeath);
    strcpy(temp->restingPlace,restingPlace);
    temp->deathYear = deathYear;
    strcpy(temp->roomId,roomId);

    return temp;
}

void newCustomer(){
    // No validation yet meogre
    clrscr();
    char ID[255];
    char name[255];
    int age;
    char causeOfDeath[255];
    char restingPlace[255];
    int deathYear;
    char roomId[255];
    printf("Input ID: ");
    scanf("%s", ID); getchar();

    printf("Input Name: ");
    scanf("%[^\n]", name);getchar();

    printf("Input Age: ");
    scanf("%d", &age);getchar();

    printf("Input Cause Of Death: ");
    scanf("%[^\n]", causeOfDeath);getchar();
    
    printf("Input Resting Place: ");
    scanf("%[^\n]", restingPlace);getchar();

    printf("Input Death Year: ");
    scanf("%d", &deathYear);getchar();

    printf("Input Room ID: ");
    scanf("%s", roomId);getchar();

    struct Customer *temp = createNewCustomer(ID,name,age,causeOfDeath,restingPlace,deathYear,roomId);
    listC[totalCustomer] = temp;
    totalCustomer++;
    FILE *fp = fopen("../customer/customer_data.txt", "a");
    fprintf(fp, "%s,%s,%d,%s,%s,%d,%s\n", ID ,name, age,causeOfDeath,restingPlace,deathYear,roomId);
    fclose(fp);

    printf("Successfully Added !\nPress enter to continue..."); getchar();

}

void viewCustomer(){
    int i = 0;
    bool check = false;
    clrscr();
    while(listC[i]){
    printf("\n===================\n");
    printf("|| Customer #%.3d ||\n", i+1);
    printf("===================\n");
    printf("Id : %s\n", listC[i]->ID); 
    printf("Name : %s\n", listC[i]->name);
    printf("Age : %d\n", listC[i]->age);
    printf("Cause Of Death : %s\n", listC[i]->causeOfDeath);
    printf("Resting Place : %s\n", listC[i]->restingPlace);
    printf("Death Year : %d\n", listC[i]->deathYear);
    printf("\nRoom ID : %s\n", listC[i]->roomId);
    
    for (int j = 0; j < totalRoom; j++)
    {
        if(getRoom(listC[i]->roomId) == getRoom(listR[j]->roomId)){
            printf("Room Name: %s\n", listR[j]->roomName);
            printf("Room Price : %d\n", listR[j]->roomPrice);
            check = true;
            break;
        }
    }
    
    if (!check) printf("--no room description yet--\n");

        check = false;
        i++;
    }

    printf("\nPress enter to continue..."); getchar();
}

void updateCustomer(){
    clrscr();
    char ID[255], newRoomID[255];
    bool exists = false, roomValid = false;
    int idx = 0;
    while(true){
        printf("Input CustomerID to update : ");
        scanf("%[^\n]" , ID); getchar();
        for (int i = 0; i < totalCustomer; i++)
        {
            if(!strcmp(listC[i]->ID,ID)){
                exists = true;
                idx = i;
                break;
            } 
        }
        if(exists) break;
    }
    
    while(true){
        printf("Input Another Room ID (0 to exit): ");
        scanf("%[^\n]" , newRoomID); getchar();
        if(!strcmp(newRoomID,listC[idx]->roomId)){
            printf("Do not input the same room!\nPlease input another room..\n");
            continue;
        }
        else {
            for (int j = 0; j < totalCustomer; j++)
            {
                if(!strcmp(listC[j]->roomId,newRoomID)){
                    roomValid = true;
                    break;
                }
            }
            for (int j = 0; j < totalRoom; j++)
            {
                if(!strcmp(listR[j]->roomId,newRoomID)){
                    roomValid = true;
                    break;
                }
            }
            
            if (roomValid || !strcmp(newRoomID,"0")) break;
        }
    }

    if (!strcmp(newRoomID,"0")) return;

    strcpy(listC[idx]->roomId,newRoomID);
    printf("Successfully Updated !\nPress enter to continue...");
    getchar();
    updateFileCustomer();
}

void deleteCustomer(){  //all good now
    clrscr();
    char ID[255];
    bool exists = false;
    int idx = 0;
    
    printf("Input CustomerID to delete : ");
    scanf("%[^\n]" , ID); getchar();
    for (int i = 0; i < totalCustomer; i++)
    {
        if(!strcmp(listC[i]->ID,ID)){
            exists = true;
            idx = i;
            break;
        }
        exists = false;
    }
    if(exists) {
        free(listC[idx]);
        listC[idx] = NULL;
        for (idx; idx < totalCustomer; idx++)
        {
            listC[idx] = listC[idx+1];
        }
        totalCustomer--;
        
        printf("Successfully Deleted !\nPress enter to continue...");
        getchar();
        updateFileCustomer();
    }
    else {
        printf("No Customer with that ID exists..."); getchar();
        return;
    }

}

#endif 