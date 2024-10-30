
	
	
#include <stdio.h>
int main(){
    int satirtop; 
    int sutuntop;
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
     
        scanf("%d",&arr[i][j]);
        }
    	}
    for(int i=0;i<5;i++){
        satirtop=0;
        for(int j=0;j<5;j++){
            satirtop+=arr[i][j];
        		}
        for(int z=0;z<5;z++){
            arr[z][i]+=satirtop;
        	}
    		}
    for(int i=0;i<5;i++){
        sutuntop=0;
        for(int j=0;j<5;j++){
            sutuntop+=arr[j][i];
        }
        for(int z=0;z<5;z++){
            arr[i][z]+=sutuntop;
        }
    }
  
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

	
	

	

