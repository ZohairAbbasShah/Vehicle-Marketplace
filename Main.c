#include <stdio.h>
#include "vehicle.h"

/* Menu for the admin */
void adminMenu(void) {
    int choice;

    do {
        printf("\n=========================================\n");
        printf("  ADMIN PANEL\n");
        printf("=========================================\n");
        printf("  [1] Show all ads\n");
        printf("  [2] Delete any ad\n");
        printf("  [3] Statistics\n");
        printf("  [0] Back\n");
        printf("-----------------------------------------\n");
        choice = readRange("Enter choice: ", 0, 3);

        switch (choice) {
            case 1: showAllAds();     break;
            case 2: adminDeleteAd();  break;
            case 3: showStatistics(); break;
            case 0: printf("\nLeft admin panel.\n"); break;
        }
    } while (choice != 0);
}

int main(void) {
    int choice;

    do {
        printf("\n=========================================\n");
        printf("        VEHICLE MARKETPLACE\n");
        printf("     Buy and sell vehicles easily\n");
        printf("=========================================\n");
        printf("  --- Buy ---\n");
        printf("  [1] Browse vehicles for sale\n");
        printf("  [2] Search / filter vehicles\n");
        printf("  --- Sell ---\n");
        printf("  [3] Post a vehicle for sale\n");
        printf("  [4] My ads\n");
        printf("  [5] Edit my ad\n");
        printf("  [6] Delete my ad\n");
        printf("  [7] Mark my ad as sold\n");
        printf("  [8] My favorites\n");
        printf("  --- Admin ---\n");
        printf("  [9] Admin panel\n");
        printf("  [0] Exit\n");
        printf("-----------------------------------------\n");
        choice = readRange("Enter choice: ", 0, 9);

        switch (choice) {
            case 1: browseAds();     break;
            case 2: searchAds();     break;
            case 3: postAd();        break;
            case 4: showMyAds();     break;
            case 5: editAd();        break;
            case 6: deleteAd();      break;
            case 7: markSold();      break;
            case 8: favoritesMenu(); break;
            case 9:
                if (adminLogin()) {
                    adminMenu();
                }
                break;
            case 0: printf("\nGoodbye!\n"); break;
        }
    } while (choice != 0);

    return 0;
}