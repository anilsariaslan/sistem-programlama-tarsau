#ifndef DOSYA_H
#define DOSYA_H

#define MAX_TOPLAM_BOYUT 209715200

int dosyaVarMi(const char *dosyaAdi);
long dosyaBoyutuBul(const char *dosyaAdi);
int izinleriAl(const char *dosyaAdi);
int metinDosyasiMi(const char *dosyaAdi);
int dosyalariKontrolEt(char *dosyalar[], int dosyaSayisi);

#endif