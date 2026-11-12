#include <stdio.h>
#include <string.h>
#include "vehicle.h"

/* Asks for the admin password. Returns 1 if correct, 0 if wrong. */
int adminLogin(void) {
    char password[30];

    printf("\nAdmin password: ");
    readText(password, 30);

    if (strcmp(password, ADMIN_PASSWORD) != 0) {
        printf("[!] Wrong password.\n");
        return 0;
    }
    return 1;
}

/* Admin sees every ad, including sold ones */
void showAllAds(void) {
    struct Ad list[MAX_ADS];
    int count, i;

    count = loadAds(list);

    printf("\n===== ALL ADS =====");
    printAdHeader();

    for (i = 0; i < count; i++) {
        printAdRow(list[i]);
    }

    if (count == 0) {
        printf("No ads yet.\n");
    } else {
        printf("\nTotal: %d\n", count);
    }
}

/* Admin can remove any ad (for example a fake one) */
void adminDeleteAd(void) {
    struct Ad list[MAX_ADS];
    int count, i, j, adId;

    count = loadAds(list);

    printf("\n===== DELETE ANY AD =====\n");
    adId = readRange("Enter Ad ID (0 = back): ", 0, 1000000);
    if (adId == 0) {
        return;
    }

    for (i = 0; i < count; i++) {
        if (list[i].adId == adId) {
            for (j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            saveAds(list, count);
            removeAdFavorites(adId);

            printf("\n[OK] Ad deleted.\n");
            return;
        }
    }

    printf("[!] Ad not found.\n");
}

void showStatistics(void) {
    struct Ad ads[MAX_ADS];
    struct Favorite favs[MAX_FAV];
    int adCount, favCount;
    int i, active = 0, sold = 0;
    double total = 0;

    adCount  = loadAds(ads);
    favCount = loadFavorites(favs);

    for (i = 0; i < adCount; i++) {
        if (ads[i].status == AD_ACTIVE) {
            active++;
            total = total + ads[i].price;
        } else {
            sold++;
        }
    }

    printf("\n===== STATISTICS =====\n");
    printf("Total ads          : %d\n", adCount);
    printf("Ads for sale       : %d\n", active);
    printf("Vehicles sold      : %d\n", sold);
    if (active > 0) {
        printf("Average price      : Rs %.0f\n", total / active);
    }
    printf("Favorites saved    : %d\n", favCount);
}