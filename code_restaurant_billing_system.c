#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100       
#define TAX_RATE 0.08      


struct Order {
    char itemName[30];
    float price;
    int quantity;
    float totalPrice;
};

int main() {
   
    char menuItems[][30] = {
        "Burger", "Pizza", "Pasta", "Fries", "Coke", "Coffee"
    };

    float menuPrices[] = {
        5.99, 8.49, 7.25, 2.99, 1.50, 2.00
    };

    int totalMenuItems = 6;
    struct Order orders[MAX_ITEMS];
    int orderCount = 0;

    int choice, qty;

    printf("=============== WELCOME TO C RESTAURANT ===============\n");
    printf("------------------------ MENU --------------------------\n");

    
    for (int i = 0; i < totalMenuItems; i++) {
        printf("%d. %-10s   Rs%.2f\n", i + 1, menuItems[i], menuPrices[i]);
    }

    printf("--------------------------------------------------------\n");

   
    while (1) {
        printf("\nEnter the item number (0 to finish ordering): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;  
        }

        if (choice < 1 || choice > totalMenuItems) {
            printf("Invalid choice! Please choose a number from the menu.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        
        strcpy(orders[orderCount].itemName, menuItems[choice - 1]);
        orders[orderCount].price = menuPrices[choice - 1];
        orders[orderCount].quantity = qty;
        orders[orderCount].totalPrice = qty * menuPrices[choice - 1];

        orderCount++;

        printf("Added %d x %s to order (Subtotal: Rs%.2f)\n",
               qty,
               menuItems[choice - 1],
               qty * menuPrices[choice - 1]);
    }

    
    float subtotal = 0;
    for (int i = 0; i < orderCount; i++) {
        subtotal += orders[i].totalPrice;
    }

    float tax = subtotal * TAX_RATE;
    float finalTotal = subtotal + tax;

    
    printf("\n====================== BILL SUMMARY ======================\n");
    printf("%-15s %-10s %-10s %-10s\n", "Item", "Price", "Qty", "Total");

    for (int i = 0; i < orderCount; i++) {
        printf("%-15s Rs%-9.2f %-10d Rs%-10.2f\n",
               orders[i].itemName,
               orders[i].price,
               orders[i].quantity,
               orders[i].totalPrice);
    }

    printf("-----------------------------------------------------------\n");
    printf("Subtotal:                         Rs%.2f\n", subtotal);
    printf("Tax (8%%):                         Rs%.2f\n", tax);
    printf("TOTAL:                            Rs%.2f\n", finalTotal);
    printf("===========================================================\n");
    printf("Thank you for dining with us! Have a great day!\n");

    return 0;
}
