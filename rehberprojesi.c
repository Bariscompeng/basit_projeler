#include <stdio.h>
#include <string.h> 
#include <ctype.h>

typedef struct{

	char name[20];
	char lastname[20];
	int number[11];
	}record;
	
	
void menu(){

	printf("----------------------------\n");
	printf("*                           *\n");
	printf("------TELEFON REHBERİ---------\n");
	printf("*                            *\n");
	printf("*     1.Telefon ekle         *\n");
	printf("*     2.Telefonları Listele  *\n");
	printf("*     3.Arama Yap            *\n");
	printf("*     4.Çıkış                *\n");
	printf("*                           *\n");
	printf("----------------------------\n");
	
	
	}
int phoneadd(){
	
	record newrecord;
	FILE* fptr;
	fptr=fopen("data.txt","a");
	if(fptr== NULL){
	
		return -1;
		}
	printf("\n\n");
	printf("Isim giriniz (maks 20 karakter):\n");
	scanf("%s",newrecord.name);
	printf("Soyisim giriniz (maks 20 karakter):\n");
	scanf("%s",newrecord.lastname);
	printf("Numara giriniz (maks 11 karakter):\n");
	scanf("%s",newrecord.number);
	fprintf("\n %s %s %s",newrecord.name,newrecord.lastname,newrecord.number);
	fclose(fptr);
	return 0; 
	}

int phonelist(){


	record currentrecord;
	FILE* fptr;
	fptr=fopen("data.txt","r");
	if(fptr==NULL){
		return -1;
		}
	while(!feof(fptr)){
	
		fscanf(fptr,"%s%s%s",currentrecord.name,currentrecord.lastname,currentrecord.number);
		printf("%s\t\t",currentrecord.name);
		printf("%s\t\t",currentrecord.lastname);
		printf("%s\n",currentrecord.number);
		}
		
		fclose(fptr);
		return 0;
		}
		
		
	



int phonesearch(char* ptsearch){

	record currentrecord;
	int i=0;
	FILE* fptr;
	fptr=fopen("data.txt","r");
	if(fptr==NULL){
		return -1;
		}

	
	while(!feof(fptr)){
	
		fscanf(fptr,"%s %s %s",currentrecord.name,currentrecord.lastname,currentrecord.number);
		if(!strcmp(ptsearch,currentrecord.name)){
		printf("%s \t\t\t",currentrecord.name);
		printf("%s \t\t\t",currentrecord.lastname);
		printf("%s \n",currentrecord.number);
		
		i++;
		}
		}
		
		fclose(fptr);
		return i;
		}



int main(){

		int choice=0;
		char searchname[20];
		int searchresult=0;
		menu();
		
		do{
		
			printf("\n\n Seçiminizi giriniz.");
			scanf("%d",&choice);
			
		switch(choice){
		
			case 1: if(phoneadd()==0){
			
				printf("\n Telefon numarası başarılı bir şekilde eklendi.\n");
				}else{
				printf("\n Telefon numarası eklenirken hata oluştu.\n");
				}
					break;
			
			case 2: if(phonelist()==0){
			
				printf("\n Telefon numaraları başarılı bir şekilde eklendi.\n");
				}else{
				
				printf("\n Telefon numaraları listelenirken hata oluştu.\n");
				}
					break;
			
			case 3: 
				printf("\n Arancak ismi giriniz.\n");
				scanf("%s",&searchname);
				searchresult=phonesearch(searchname);
				if(searchresult==0){
				printf("\n Aranan kayıt bulunamadı.\n");
				}else{
				printf("\n Toplam %d kayıt bulundu.",searchresult);
				}
				break;
			case 4: 
				printf("\n cikis yaptiniz.\n");
				return 0;
				break;
			default: printf("\n lütfen 1-4 arasi bir seçim yapiniz.\n");
			
			}
		}while( choice !=4);
		
			return 0;
			}
			









