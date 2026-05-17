/**
*
* @author Anıl Sarıaslan anil.sariaslan@ogr.sakarya.edu.tr
* @since 15.05.2026
* <p>
* dosya kontrol işlemlerine ait yardımcı fonksiyonları içerir.
* </p>
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "dosya.h"

int dosyaVarMi(const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");

    if (dosya == NULL) {
        return 0;
    }

    fclose(dosya);
    return 1;
}

long dosyaBoyutuBul(const char *dosyaAdi) {
    struct stat dosyaBilgisi;

    if (stat(dosyaAdi, &dosyaBilgisi) != 0) {
        return -1;
    }

    return dosyaBilgisi.st_size;
}

int izinleriAl(const char *dosyaAdi) {
    struct stat dosyaBilgisi;

    if (stat(dosyaAdi, &dosyaBilgisi) != 0) {
        return -1;
    }

    return dosyaBilgisi.st_mode & 0777;
}

int metinDosyasiMi(const char *dosyaAdi) {
    FILE *dosya;
    int karakter;

    dosya = fopen(dosyaAdi, "r");

    if (dosya == NULL) {
        return 0;
    }

    while ((karakter = fgetc(dosya)) != EOF) {
        if ((karakter < 32 || karakter > 126) &&
            karakter != '\n' &&
            karakter != '\r' &&
            karakter != '\t') {
            fclose(dosya);
            return 0;
        }
    }

    fclose(dosya);
    return 1;
}

int dosyalariKontrolEt(char *dosyalar[], int dosyaSayisi) {
    int i;
    long toplamBoyut = 0;

    for (i = 0; i < dosyaSayisi; i++) {
        long boyut;

        if (!dosyaVarMi(dosyalar[i])) {
            printf("%s dosyasi bulunamadi!\n", dosyalar[i]);
            return 0;
        }

        if (!metinDosyasiMi(dosyalar[i])) {
            printf("%s giris dosyasinin formati uyumsuzdur!\n", dosyalar[i]);
            return 0;
        }

        boyut = dosyaBoyutuBul(dosyalar[i]);

        if (boyut < 0) {
            printf("%s dosyasinin boyutu okunamadi!\n", dosyalar[i]);
            return 0;
        }

        toplamBoyut += boyut;

        if (toplamBoyut > MAX_TOPLAM_BOYUT) {
            printf("Giris dosyalarinin toplam boyutu 200 MB'i gecemez!\n");
            return 0;
        }
    }

    return 1;
}