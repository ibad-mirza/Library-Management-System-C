#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct book
{
    int id;
    char title[50];
    char author[50];
    char category[30];
    float price;
    int quantity;
};

struct book library[MAX_BOOKS];
int count = 0;

void addBook()
{
    FILE *fp = fopen("library.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    struct book b;

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    while (getchar() != '\n')
        ;

    printf("Enter Title: ");
    scanf(" %[^\n]", b.title);

    printf("Enter Author: ");
    scanf(" %[^\n]", b.author);

    printf("Enter Category: ");
    scanf(" %[^\n]", b.category);

    printf("Enter Price: ");
    scanf("%f", &b.price);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);
    while (getchar() != '\n')
        ;

    fprintf(fp, "%d,%s,%s,%s,%.2f,%d\n",
            b.id, b.title, b.author, b.category,
            b.price, b.quantity);

    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks()
{
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found. Add some books first.\n");
        return;
    }

    struct book b;
    printf("\n===== Library Books =====\n");

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        printf("ID: %d | Title: %s | Author: %s | Category: %s | Price: %.2f | Quantity: %d\n",
               b.id, b.title, b.author, b.category, b.price, b.quantity);
    }

    printf("=========================\n");

    fclose(fp);
}

void searchBook()
{
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found. Add some books first.\n");
        return;
    }

    int searchId;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchId);
    while (getchar() != '\n')
        ;

    struct book b;
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        if (b.id == searchId)
        {
            printf("\nBook Found!\n");
            printf("ID: %d | Title: %s | Author: %s | Category: %s | Price: %.2f | Quantity: %d\n",
                   b.id, b.title, b.author, b.category, b.price, b.quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(fp);
}

void deleteBook()
{
    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int deleteId;
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteId);
    while (getchar() != '\n')
        ;

    struct book b;
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        if (b.id == deleteId)
        {
            found = 1;
            printf("Book deleted successfully!\n");
            continue;
        }

        fprintf(temp, "%d,%s,%s,%s,%.2f,%d\n",
                b.id, b.title, b.author, b.category,
                b.price, b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
        printf("Book not found!\n");
}
void updateBook()
{
    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("No books found!\n");
        return;
    }

    int updateId;
    printf("Enter Book ID to update: ");
    scanf("%d", &updateId);
    while (getchar() != '\n')
        ;

    struct book b;
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        if (b.id == updateId)
        {
            found = 1;

            printf("\nEnter new Title: ");
            scanf(" %[^\n]", b.title);

            printf("Enter new Author: ");
            scanf(" %[^\n]", b.author);

            printf("Enter new Category: ");
            scanf(" %[^\n]", b.category);

            printf("Enter new Price: ");
            scanf("%f", &b.price);

            printf("Enter new Quantity: ");
            scanf("%d", &b.quantity);

            printf("Book updated successfully!\n");
        }

        fprintf(temp, "%d,%s,%s,%s,%.2f,%d\n",
                b.id, b.title, b.author, b.category,
                b.price, b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
        printf("Book not found!\n");
}
void showOutOfStock()
{
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found.\n");
        return;
    }

    struct book b;
    int found = 0;

    printf("\n===== OUT OF STOCK BOOKS =====\n");

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        if (b.quantity == 0)
        {
            found = 1;
            printf("ID: %d | Title: %s | Author: %s | Category: %s | Price: %.2f\n",
                   b.id, b.title, b.author, b.category, b.price);
        }
    }

    if (!found)
        printf("All books are in stock.\n");

    fclose(fp);
}
void showCheapestBook()
{
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found.\n");
        return;
    }

    struct book b, cheapest;
    int first = 1;

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        if (first || b.price < cheapest.price)
        {
            cheapest = b;
            first = 0;
        }
    }

    fclose(fp);

    if (!first)
    {
        printf("\n===== CHEAPEST BOOK =====\n");
        printf("ID: %d | Title: %s | Price: %.2f | Quantity: %d\n",
               cheapest.id, cheapest.title, cheapest.price, cheapest.quantity);
    }
}
void showMostExpensive()
{
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found.\n");
        return;
    }

    struct book b, expensive;
    int first = 1;

    while (fscanf(fp, "%d,%49[^,],%49[^,],%29[^,],%f,%d",
                  &b.id, b.title, b.author, b.category,
                  &b.price, &b.quantity) == 6)
    {
        if (first || b.price > expensive.price)
        {
            expensive = b;
            first = 0;
        }
    }

    fclose(fp);

    if (!first)
    {
        printf("\n===== MOST EXPENSIVE BOOK =====\n");
        printf("ID: %d | Title: %s | Price: %.2f | Quantity: %d\n",
               expensive.id, expensive.title, expensive.price, expensive.quantity);
    }
}

void printMenu()
{
    printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("1. Add Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Update Book\n");
    printf("6. Show Out-of-Stock Books\n");
    printf("7. Show Cheapest Book\n");
    printf("8. Show Most Expensive Book\n");
    printf("9. Exit\n");
}

int main()
{
    int choice;
    while (1)
    {
        printMenu();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            updateBook();
            break;
        case 6:
            showOutOfStock();
            break;
        case 7:
            showCheapestBook();
            break;
        case 8:
            showMostExpensive();
            break;
        case 9:
            printf("Exiting program... Thanks for using LMS");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
