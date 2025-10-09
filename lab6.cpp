#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int info;
    struct Node *next;
    struct Node *prev;

};
typedef struct Node ND;

struct HNode{
    int count=0;
    struct Node LP;
    struct Node RP;

};
typedef struct HNode HND;

HND *DV_Create(HND *iptr,ND *ptr,int value) {
    if( iptr->Start==NULL)
    {
        ptr=(ND*)malloc(sizeof(ND));
        iptr->Start=ptr;
        ptr->info=value;
        iptr -> count++;
    }
    else{
        ptr=(ND*)malloc(sizeof(ND));
        ptr->info=value;
        iptr->count++;
        ptr->next=NULL;
    }
    return;}
