#ifndef ROOM_H
#define ROOM_H

struct Room *createNewRoom(char roomId[], char roomName[], int roomPrice){
    struct Room *temp = (Room*)malloc(sizeof(Room));
    strcpy(temp->roomId,roomId);
    strcpy(temp->roomName,roomName);
    temp->roomPrice = roomPrice;

    return temp;
}


#endif // ! ROOM_H