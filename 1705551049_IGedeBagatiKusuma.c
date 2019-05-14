#include <stdio.h>

double validasi();
void reset();
void hapus_buffer();

int main (){
    int num,i,hasil;
    
    printf("\t\t\t===============================\n");
	printf("\t\t\t||   PROGRAM POLA BILANGAN   ||\n");
	printf("\t\t\t||    I GEDE BAGATI KUSUMA   ||\n");
	printf("\t\t\t||         1705551049        ||\n");
	printf("\t\t\t===============================\n\n");
    printf ("Input =  "); 
	num = validasi();
	
	for(i=1; i<=num; i++){
		hasil=(i+1)*i;
		printf("%d ", hasil);
	}
	reset();
}

double validasi(){ // digunakan untuk validasi input
    double angka;
    char karakter;
    int cek;
    if (scanf("%lf%c",&angka,&karakter)!= 2  || karakter != '\n' || karakter == ','){
        hapus_buffer();
        printf("\nInput invalid! Masukkan angka : ");
        return validasi();
    } else if(angka<0){
    	printf("\nInput invalid! Masukkan angka diatas 0 : ");
        return validasi();
	} else {
        cek = (angka);
        if (cek == angka){
            return angka;
        } else {
            printf("\nInput invalid! Masukkan angka bulat : ");
            return validasi();
        }
    }
}

void reset(){ // berisi pilihan untuk mengulang program atau tidak
    int valid_reset;
    char parameter[1];
    printf("\n\nKembali ke menu awal?[Y/N] ");
    gets(parameter);
    
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        main();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Input Invalid!\n\a");
        reset();
    }
}

void hapus_buffer(){ // untuk clear buffer
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}
