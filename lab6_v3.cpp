#include <iostream>
using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
};

typedef struct node nd;

struct header
{
    int count;
    int size;
    node *front;
    node *rear;
};

typedef struct header hnd;

hnd *GR_create_queue(int maxSize)
{
    hnd *h = (hnd *)malloc(sizeof(hnd));
    h->count = 0;
    h->size = maxSize;
    h->front = NULL;
    h->rear = NULL;
    return h;
}

hnd *GR_insert(hnd *iptr, int value)
{
    if (iptr->count == iptr->size)
    {
        cout << "Queue is full. Cannot insert " << value << endl;
        return iptr;
    }

    nd *new_d = (nd *)malloc(sizeof(nd));
    new_d->info = value;
    new_d->next = NULL;
    new_d->prev = NULL;

    if (iptr->front == NULL && iptr->rear == NULL)
    {
        iptr->front = new_d;
        iptr->rear = new_d;
    }
    else
    {
        new_d->prev = iptr->rear;
        iptr->rear->next = new_d;
        iptr->rear = new_d;
    }

    iptr->count++;
    return (iptr);
}

hnd *GR_delete(hnd *iptr)
{
    if (iptr->front == NULL && iptr->rear == NULL)
    {
        cout << "Empty queue" << endl;
        return iptr;
    }
    nd *ptr = iptr->front;
    if (iptr->front == iptr->rear)
    {
        iptr->front = NULL;
        iptr->rear = NULL;
    }
    else
    {
        iptr->front = ptr->next;
        iptr->front->prev = NULL;
    }

    free(ptr);
    iptr->count--;

    return iptr;
}

void GR_search(hnd *iptr, int value)
{
    if (iptr->front == NULL && iptr->rear == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }

    hnd *bq = GR_create_queue(iptr->size);
    bool found = false;
    int pos = 1;

    while (iptr->front != NULL)
    {
        int data = iptr->front->info;
        iptr = GR_delete(iptr);
        bq = GR_insert(bq, data);

        if (data == value && !found)
        {
            cout << "Found " << value << " at position " << pos << endl;
            found = true;
        }
        pos++;
    }

    while (bq->front != NULL)
    {
        int data = bq->front->info;
        bq = GR_delete(bq);
        iptr = GR_insert(iptr, data);
    }

    if (!found)
    {
        cout << value << " not found in the queue" << endl;
    }
}

void GR_update(hnd *iptr, int oldval, int newval)
{
    if (iptr->front == NULL && iptr->rear == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }

    hnd *bq = GR_create_queue(iptr->size);
    bool found = false;

    while (iptr->front != NULL)
    {
        int data = iptr->front->info;
        iptr = GR_delete(iptr);

        if (data == oldval && !found)
        {
            cout << "Updated " << oldval << " to " << newval << endl;
            data = newval;
            found = true;
        }
        bq = GR_insert(bq, data);
    }

    while (bq->front != NULL)
    {
        int data = bq->front->info;
        bq = GR_delete(bq);
        iptr = GR_insert(iptr, data);
    }

    if (!found)
    {
        cout << oldval << " not found in the queue" << endl;
    }
}

void GR_traversal(hnd *iptr)
{
    if (iptr->front == NULL && iptr->rear == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }
    else
    {
        cout << "Queue: ";
        nd *ptr = iptr->front;

        while (ptr != NULL)
        {
            cout << ptr->info << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    cout << "Total node = " << iptr->count << endl;
    return;
}

int main()
{
    int maxSize;
    cout << "Enter maximum size of the queue: ";
    cin >> maxSize;

    hnd *Q = GR_create_queue(maxSize);
    int choice, value, oldval, newval;

    do
    {
        cout << endl
        << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Update" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;

        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value:";
            cin >> value;
            Q = GR_insert(Q, value);
            GR_traversal(Q);
            break;

        case 2:
            Q = GR_delete(Q);
            GR_traversal(Q);
            break;

        case 3:
            cout << "Enter value to search:";
            cin >> value;
            GR_search(Q, value);
            GR_traversal(Q);
            break;

        case 4:
            cout << "Enter value to be updated:";
            cin >> oldval;
            cout << "Enter new value:";
            cin >> newval;
            GR_update(Q, oldval, newval);
            GR_traversal(Q);
            break;

        case 5:
            GR_traversal(Q);
            break;

        case 6:
            cout << "Exiting";
            return 0;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 6);
}