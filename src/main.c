/**
*
* @author Anıl Sarıaslan anil.sariaslan@ogr.sakarya.edu.tr
* @since 13.05.2026
* <p>
* Programın başlangıç noktasıdır. Komut satırı argümanlarını kontrol eder.
* </p>
*/

#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        kullanimYazdir();
        return 1;
    }

    if (strcmp(argv[1], "-b") == 0) {
        printf("-b modu secildi. Arsiv olusturma islemi yapilacak.\n");
    }
    else if (strcmp(argv[1], "-a") == 0) {
        printf("-a modu secildi. Arsiv acma islemi yapilacak.\n");
    }
    else {
        printf("Hatali parametre girdiniz!\n");
        kullanimYazdir();
        return 1;
    }

    return 0;
}