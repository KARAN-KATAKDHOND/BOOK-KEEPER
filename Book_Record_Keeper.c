#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct books
{
    int bn;
    char auth[50];
    char bkname[100];
    float price;
};
int main(){
    int n;
    int bk, flag = 0;
    int perm;
    printf("Enter Number of books: ");
    scanf("%d", &n);

    struct books b[n];
    for (int i = 0; i < n; i++)
    {
        printf("\n\nEnter Details of Book %d :-", i + 1);
        printf("\nBook Code: ");
        scanf("%d", &b[i].bn);
        printf("\nBook Name: ");
        scanf("%s", &b[i].bkname);
        printf("\nAuthor Name: ");
        scanf("%s", &b[i].auth);
        printf("\nBook Price: ");
        scanf("%f", &b[i].price);
    }
    system("cls");
    
    int x = 0;
    while (x == 0)
    {
        printf("To Search for book press 1: ");
        scanf("%d", &perm);
        if (perm != 1)
        {
            break;
        }
        else if (perm == 1)
        {

            printf("Enter a Book code to srch for from the Data You Entered: ");
            scanf("%d", &bk);
            for (int i = 0; i < n; i++)
            {
                if (bk == b[i].bn)
                {
                    flag = 1;
                    printf("\n\nDetails of Book %d :-", i + 1);
                    printf("\nBook Code: %d ", b[i].bn);
                    printf("\nBook Name: %s ", b[i].bkname);
                    printf("\nAuthor Name: %s", b[i].auth);
                    printf("\nBook Price: %.2f", b[i].price);
                    printf("\n\nTo Exit the program press 0");
                }
            }
            if (flag == 0)
            {
                printf("!!!!No Data Found Regarding the Book Code You Entered!!!");
                printf("\n\n\nTo Exit the program press 0");
            }
            printf("\n\n\n");
        }
        else
        {
            printf("Invalid!!!! Input..................");
        }
    }


    FILE *ptr;
    ptr = fopen("RECORD.txt", "w");
    fprintf(ptr,"Book Code\t\t");
    fprintf(ptr,"Book Name\t\t");
    fprintf(ptr,"Author\t\t");
    fprintf(ptr,"price\t\t");
    
    for(int i=0;i<n;i++){
        fprintf(ptr,"\n\n");
        fprintf(ptr,"%d\t\t\t",b[i].bn);
        fprintf(ptr,"%s\t\t\t",b[i].bkname);
        fprintf(ptr,"%s\t\t",b[i].auth);
        fprintf(ptr,"%.2f\t\t\t",b[i].price);

    }
    fclose(ptr);
    return 0;
}