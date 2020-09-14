//SEFA ENES ERGİN-sefaenesergin@gmail.com
//malloc ve realloc kullanımına örnek
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sayi,toplam=0,ekstra;
    printf("Kaç adet sayı gireceksiniz? \n");
    scanf("%d",&sayi);
    int *dizi=(int*)malloc(sizeof(int)*sayi);
    //pointerlarda cast edilmelidir.
    printf("Lütfen dizinin elemanlarını giriniz...");
    for (int i=0; i<sayi;i++) {
        printf("\nDizi[%d]",i);
        scanf("%d",&dizi[i]);
        //&dizi[i] yerine Pointer aritmetiği ile (dizi+i)'de yazılabilir
    }
    for (int i=0; i<sayi; i++) {
        toplam+=*(dizi+i); //'*' sembolü ile o adresteki veriyi aldık.
    }
    printf("\nToplam= %d",toplam);
    //Asagidaki satırlarda diziye sonradan 2 eleman daha ekleyeceğiz.
    
    printf("\nDiziye kaç eleman daha eklemek istiyorsunuz?");
    scanf("%d",&ekstra);
    
    dizi=(int*)realloc(dizi,(sayi+ekstra)*sizeof(int));
    
    for (int i=sayi; i<ekstra+sayi;i++) {
        printf("\nDizi[%d]",i);
        scanf("%d",&dizi[i]);
    }
    
    printf("--- Yeni Toplam hesabı----\n");
    toplam=0;
    for (int i=0; i<sayi+ekstra; i++) {
        toplam+=*(dizi+i); //'*' sembolü ile o adresteki veriyi aldık.
    }
    printf("\n Yeni Toplam= %d",toplam);
    
    return 0;
}
