#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node ND;
ND *Start;
int DV_Check_Null(ND *ptr){
    if (ptr == NULL)
    return(0);
    else return(1);}
ND *Create(ND *ptr){
        int flag ;
        ND *new_D;
        flag=DV_Check_Null(ptr);
        if (flag==0)
        {
            ptr=(ND *)malloc(sizeof(ND));
            cin >>ptr->info;
            ptr-> next = NULL;
            return(ptr);
        }
        else{
           ptr-> next=(ND *)malloc(sizeof(ND));
           ptr=ptr->next;
           ptr->next=new_D;
           new_D->info=10;
           new_D->next=NULL;
        }
    }
void DV_traversal (ND * ptr)
{
    if (ptr != NULL)
    while(ptr){
        cout<< ptr -> info;
        ptr=ptr->next;
    }
}
ND *DV_Desired_location_inserion(ND *ptr,int value)
{
    ND *New_D;
    ND *prev;
    if(ptr==NULL){
        ptr=(ND *)malloc(sizeof(ND));
        ptr->info=value;
        ptr->next=NULL;
        return(ptr);}
    else {
            while((ptr->info>value)||(ptr->next=NULL))
            {
                prev=ptr;
                ptr=ptr->next;
            }
            if(ptr-> info <value)
            {
                prev->next=New_D;
                New_D->info=value;
                New_D->next=ptr;
                return(NULL);

            }
            
        }

    }
int DV_Desired_location_deletion(ND *ptr, int value)
{
    ND * ptr;
    ND * prev;
    if (ptr == NULL)
    return(0);
    else{
        while(ptr->next!=NULL){
            if(ptr->info==value)
            {
                prev->next=ptr->next;
                delete(ptr);
                return(1);}
                prev=ptr;
                ptr=ptr->next;
                return(0);
            }
        }
    }
int main()
{
    return 0;
}