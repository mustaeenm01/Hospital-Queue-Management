#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure for Patient Details
struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
};

// Queue Array
struct Patient queue[MAX];

// Front and Rear for Queue
int front = -1;
int rear = -1;


// Function to Check Queue Full
int isFull()
{
    if(rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}


// Function to Check Queue Empty
int isEmpty()
{
    if(front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}


// Function to Add Patient
void addPatient()
{
    if(isFull())
    {
        printf("\nQueue is Full!\n");
        return;
    }

    // First Patient
    if(front == -1)
    {
        front = 0;
    }

    rear++;

    printf("\nEnter Patient ID: ");
    scanf("%d", &queue[rear].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", queue[rear].name);

    printf("Enter Patient Age: ");
    scanf("%d", &queue[rear].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", queue[rear].disease);

    printf("\nPatient Added Successfully!\n");
}


// Function to Remove Patient
void removePatient()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nRemoved Patient Details\n");

    printf("ID      : %d\n", queue[front].id);
    printf("Name    : %s\n", queue[front].name);
    printf("Age     : %d\n", queue[front].age);
    printf("Disease : %s\n", queue[front].disease);

    front++;
}


// Function to Display Patients
void displayPatients()
{
    int i;

    if(isEmpty())
    {
        printf("\nNo Patients in Queue!\n");
        return;
    }

    printf("\n========== PATIENT QUEUE ==========\n");

    for(i = front; i <= rear; i++)
    {
        printf("\nPatient Number : %d\n", i - front + 1);

        printf("ID      : %d\n", queue[i].id);
        printf("Name    : %s\n", queue[i].name);
        printf("Age     : %d\n", queue[i].age);
        printf("Disease : %s\n", queue[i].disease);

        printf("-----------------------------------\n");
    }
}


// Function to Search Patient
void searchPatient()
{
    int id;
    int i;
    int found = 0;

    if(isEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nEnter Patient ID to Search: ");
    scanf("%d", &id);

    for(i = front; i <= rear; i++)
    {
        if(queue[i].id == id)
        {
            printf("\nPatient Found!\n");

            printf("ID      : %d\n", queue[i].id);
            printf("Name    : %s\n", queue[i].name);
            printf("Age     : %d\n", queue[i].age);
            printf("Disease : %s\n", queue[i].disease);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nPatient Not Found!\n");
    }
}


// Function for Emergency Patient
void emergencyPatient()
{
    int i;

    if(isFull())
    {
        printf("\nQueue is Full!\n");
        return;
    }

    // First Patient
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;

        // Shift Patients Right
        for(i = rear; i > front; i--)
        {
            queue[i] = queue[i - 1];
        }
    }

    printf("\nEnter Emergency Patient ID: ");
    scanf("%d", &queue[front].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", queue[front].name);

    printf("Enter Patient Age: ");
    scanf("%d", &queue[front].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", queue[front].disease);

    printf("\nEmergency Patient Added Successfully!\n");
}


// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("====================================\n");
        printf("   HOSPITAL QUEUE MANAGEMENT SYSTEM \n");
        printf("====================================\n");

        printf("1. Add Patient\n");
        printf("2. Remove Patient\n");
        printf("3. Display Patients\n");
        printf("4. Search Patient\n");
        printf("5. Emergency Patient\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                removePatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                searchPatient();
                break;

            case 5:
                emergencyPatient();
                break;

            case 6:
                printf("\nProgram Closed Successfully!\n");
                break;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }

    } while(choice != 6);

    return 0;
}
