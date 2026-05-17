/**
*
* @author Anıl Sarıaslan anil.sariaslan@ogr.sakarya.edu.tr
* @since 14.05.2026
* <p>
* Programın başlangıç noktasıdır. Komut satırı argümanlarını kontrol eder.
* </p>
*/

#include <stdio.h>
#include <string.h>
#include "arsiv.h"
#include "utils.h"
#include "dosya.h"

#define MAX_DOSYA_SAYISI 32

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        kullanimYazdir();
        return 1;
    }

    if (strcmp(argv[1], "-b") == 0) {
        char *dosyalar[MAX_DOSYA_SAYISI];
        int dosyaSayisi = 0;
        char *arsivAdi = "a.sau";

        if (argc < 3) {
            printf("Arsivlenecek dosya girilmedi!\n");
            kullanimYazdir();
            return 1;
        }

        for (i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-o") == 0) {
                if (i + 1 < argc) {
                    arsivAdi = argv[i + 1];
                    i++;
                } else {
                    printf("-o parametresinden sonra arsiv dosyasi adi girilmelidir!\n");
                    return 1;
                }
            } else {
                if (dosyaSayisi >= MAX_DOSYA_SAYISI) {
                    printf("En fazla 32 giris dosyasi verilebilir!\n");
                    return 1;
                }

                dosyalar[dosyaSayisi] = argv[i];
                dosyaSayisi++;
            }
        }

        if (dosyaSayisi == 0) {
            printf("Arsivlenecek dosya girilmedi!\n");
            return 1;
        }

        printf("-b modu secildi.\n");
printf("Arsiv adi: %s\n", arsivAdi);
printf("Dosya sayisi: %d\n", dosyaSayisi);

for (i = 0; i < dosyaSayisi; i++) {
    printf("Dosya %d: %s\n", i + 1, dosyalar[i]);
}

if (!dosyalariKontrolEt(dosyalar, dosyaSayisi)) {
    return 1;
}

arsivOlustur(dosyalar, dosyaSayisi, arsivAdi);

        arsivOlustur(dosyalar, dosyaSayisi, arsivAdi);
    }
    else if (strcmp(argv[1], "-a") == 0) {
        char *arsivAdi;
        char *hedefDizin = NULL;

        if (argc < 3) {
            printf("Arsiv dosyasi girilmedi!\n");
            kullanimYazdir();
            return 1;
        }

        if (argc > 4) {
            printf("-a parametresinden sonra en fazla 2 parametre girilebilir!\n");
            return 1;
        }

        arsivAdi = argv[2];

        if (argc == 4) {
            hedefDizin = argv[3];
        }

        printf("-a modu secildi.\n");
        printf("Arsiv adi: %s\n", arsivAdi);

        if (hedefDizin != NULL) {
            printf("Hedef dizin: %s\n", hedefDizin);
        } else {
            printf("Hedef dizin belirtilmedi. Dosyalar mevcut dizine acilacak.\n");
        }

        arsivAc(arsivAdi, hedefDizin);
    }
    else {
        printf("Hatali parametre girdiniz!\n");
        kullanimYazdir();
        return 1;
    }

    return 0;
}