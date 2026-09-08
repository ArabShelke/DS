#include <stdio.h>

#define MAX 100

/* ---------- Simple Queue ---------- */

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

void displayQueue()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}


/* ---------- Circular Queue ---------- */

int cqueue[MAX];
int cfront = -1, crear = -1;

void circularAdd()
{
    int value;

    if ((crear + 1) % MAX == cfront)
    {
        printf("Circular Queue Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (cfront == -1)
        cfront = 0;

    crear = (crear + 1) % MAX;
    cqueue[crear] = value;

    printf("Element inserted successfully.\n");
}

void circularDelete()
{
    if (cfront == -1)
    {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", cqueue[cfront]);

    if (cfront == crear)
    {
        cfront = crear = -1;
    }
    else
    {
        cfront = (cfront + 1) % MAX;
    }
}

void circularDisplay()
{
    int i;

    if (cfront == -1)
    {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Circular Queue: ");

    i = cfront;

    while (1)
    {
        printf("%d ", cqueue[i]);

        if (i == crear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}


/* ---------- Input Restricted Deque ---------- */

int ideque[MAX];
int ifront = -1, irear = -1;

void insertRear()
{
    int value;

    if (irear == MAX - 1)
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (ifront == -1)
        ifront = 0;

    irear++;
    ideque[irear] = value;

    printf("Element inserted at rear.\n");
}

void deleteFront()
{
    if (ifront == -1 || ifront > irear)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted from front: %d\n", ideque[ifront]);
    ifront++;

    if (ifront > irear)
        ifront = irear = -1;
}

void deleteRear()
{
    if (ifront == -1 || ifront > irear)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted from rear: %d\n", ideque[irear]);
    irear--;

    if (ifront > irear)
        ifront = irear = -1;
}

void inputRestrictedDisplay()
{
    int i;

    if (ifront == -1)
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque: ");

    for (i = ifront; i <= irear; i++)
        printf("%d ", ideque[i]);

    printf("\n");
}


/* ---------- Output Restricted Deque ---------- */

int odeque[MAX];
int ofront = -1, orear = -1;

void outputInsertFront()
{
    int value, i;

    if (ofront == 0)
    {
        printf("Cannot insert at front!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (ofront == -1)
    {
        ofront = orear = 0;
        odeque[ofront] = value;
    }
    else
    {
        for (i = orear; i >= ofront; i--)
            odeque[i + 1] = odeque[i];

        odeque[ofront] = value;
        orear++;
    }

    printf("Element inserted at front.\n");
}

void outputInsertRear()
{
    int value;

    if (orear == MAX - 1)
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (ofront == -1)
        ofront = 0;

    orear++;
    odeque[orear] = value;

    printf("Element inserted at rear.\n");
}

void outputDeleteFront()
{
    if (ofront == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", odeque[ofront]);
    ofront++;

    if (ofront > orear)
        ofront = orear = -1;
}

void outputRestrictedDisplay()
{
    int i;

    if (ofront == -1)
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque: ");

    for (i = ofront; i <= orear; i++)
        printf("%d ", odeque[i]);

    printf("\n");
}


/* ---------- Josephus Problem ---------- */

void josephus()
{
    int n, k;
    int people[MAX];
    int front = 0, rear;
    int count, index, i;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter step value: ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0 || n > MAX)
    {
        printf("Invalid input!\n");
        return;
    }

    for (i = 0; i < n; i++)
        people[i] = i + 1;

    rear = n - 1;
    index = 0;

    printf("Elimination order: ");

    count = n;

    while (count > 1)
    {
        index = (index + k - 1) % count;

        printf("%d ", people[index]);

        for (i = index; i < count - 1; i++)
            people[i] = people[i + 1];

        count--;
    }

    printf("\nSurvivor: %d\n", people[0]);
}


/* ---------- Main Menu ---------- */

int main()
{
    int choice, subchoice;

    do
    {
        printf("\n========== QUEUE IMPLEMENTATION ==========\n");
        printf("1. Simple / Linear Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Input Restricted Deque\n");
        printf("4. Output Restricted Deque\n");
        printf("5. Josephus Problem\n");
        printf("6. Exit\n");
        printf("==========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                do
                {
                    printf("\n--- Simple Queue ---\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &subchoice);

                    switch (subchoice)
                    {
                        case 1:
                            enqueue();
                            break;

                        case 2:
                            dequeue();
                            break;

                        case 3:
                            displayQueue();
                            break;

                        case 4:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (subchoice != 4);

                break;


            case 2:

                do
                {
                    printf("\n--- Circular Queue ---\n");
                    printf("1. Addq\n");
                    printf("2. Delq\n");
                    printf("3. Display\n");
                    printf("4. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &subchoice);

                    switch (subchoice)
                    {
                        case 1:
                            circularAdd();
                            break;

                        case 2:
                            circularDelete();
                            break;

                        case 3:
                            circularDisplay();
                            break;

                        case 4:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (subchoice != 4);

                break;


            case 3:

                do
                {
                    printf("\n--- Input Restricted Deque ---\n");
                    printf("1. Insert at Rear\n");
                    printf("2. Delete from Front\n");
                    printf("3. Delete from Rear\n");
                    printf("4. Display\n");
                    printf("5. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &subchoice);

                    switch (subchoice)
                    {
                        case 1:
                            insertRear();
                            break;

                        case 2:
                            deleteFront();
                            break;

                        case 3:
                            deleteRear();
                            break;

                        case 4:
                            inputRestrictedDisplay();
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (subchoice != 5);

                break;


            case 4:

                do
                {
                    printf("\n--- Output Restricted Deque ---\n");
                    printf("1. Insert at Front\n");
                    printf("2. Insert at Rear\n");
                    printf("3. Delete from Front\n");
                    printf("4. Display\n");
                    printf("5. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &subchoice);

                    switch (subchoice)
                    {
                        case 1:
                            outputInsertFront();
                            break;

                        case 2:
                            outputInsertRear();
                            break;

                        case 3:
                            outputDeleteFront();
                            break;

                        case 4:
                            outputRestrictedDisplay();
                            break;

                        case 5:
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }

                } while (subchoice != 5);

                break;


            case 5:
                josephus();
                break;


            case 6:
                printf("\nProgram Ended.\n");
                break;


            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}