# include <stdio.h>

int row;


int menu(void){
	int choice;
	printf("Welcome to ABC Mobile Phone\n");
	printf("------MENU-----\n");
	printf("Please choose an action:\n");
	printf("1.Load data from text file.\n");
	printf("2.Order data from based on phone quantity.\n");
	printf("3.Update dphone quantity for a store.\n");
	printf("4.View ordered phone quantity of a store.\n");
	printf("5.Find the cheapest price of a phone type.\n");
	printf("6.Compare two stores to find different phone types.\n");
	printf("7.Compare two stores to find common phone types.\n");
	printf("8.View total quantity of each phone type.\n");
	printf("9.Update text file.\n");
	printf("10.Quit.\n");
	printf("Your choice:");
	scanf("%d",&choice);
	
	return choice;
}


int readata(int a[][100]){
	FILE *fp=fopen("phonedata.txt","r");
	int i=0,j=0;
	while(!feof(fp)){
		fscanf(fp,"%d %d %d %d ",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		i++;
	}
	
	fclose(fp);
	return i;
}


void selsort(int a[][100],int row){
		int mindx,i=0,j,temp1,key,temp2,temp3;
		mindx=i;
		
		for(i=0;i<row;i++){
			mindx=i;
			for(j=i+1;j<row;j++){
				if(a[mindx][2]>a[j][2]){
					mindx=j;
				}
			}
			
			
			key=a[mindx][2];
			while(mindx>i){
				a[mindx][2]=a[mindx-1][2];
				mindx--;
			}
			a[i][2]=key;
			
		
	} 		
	
	printf("Sortdarray based on phone quantity\n");
		for(i=0;i<row;i++){
			for(j=0;j<4;j++){
				printf("%d	",a[i][j]);
			}
			printf("\n");
		}
	
	}
	

void updatequantityarr(int a[][100],int row,int newq,int sid,int phonetyp){
	int i,j;
	
	for(i=0;i<row;i++){
		if(a[i][0]==sid){
			if(a[i][1]==phonetyp){
				a[i][2]=newq;
			}
		}	
	}
	
}


void uquantity(int a[][100],int row){
	int sid,phn,newq,i;
	printf("Enter store id,phone type and new quantity:");
	scanf("%d %d %d",&sid,&phn,&newq);
	updatequantityarr(a,row,newq,sid,phn);
	printf("\nQuantity is updated.\n");
		
	
}


void bublesort(int a[][100],int row){
	int sid,i,temp,b[32][2],j=0,k,flag=1;
	printf("Enter a store id:");
	scanf("%d",&sid);

	for(i=0;i<row;i++){						//array b holds the phone quantity and prices of the chosen store id's//
		if(a[i][0]==sid){
			b[j][0]=a[i][2];				
			b[j][1]=a[i][3];
			j++;
		}
	}
	
	printf("\n");
	
	for(i=0;i<=j;i++){
		for(k=1;k<j-i;k++){
			if(b[k-1][0] > b[k][0]){
				temp=b[k][0];
				b[k][0]=b[k-1][0];
				b[k-1][0]=temp;
				
				temp=b[k][1];
				b[k][1]=b[k-1][0];
				b[k-1][1]=temp;
			}
		}
	}
	
	
	
	printf("Ordered phone quantities and prices are:\n");
	for(i=0;i<j;i++){
		printf("%d	%d\n",b[i][0],b[i][1]);
	}	
	
}


void cheapestore(int a[][100],int row){
	int i,j,phon,min=9999,price;
	
	printf("Enter phone type to find the cheapest store:");
	scanf("%d",&phon);
	for(i=0;i<row;i++){
		if(a[i][1]==phon){
			if(min>a[i][3]){
				min=a[i][0];
				price=a[i][3];
			}
		}
	}
	printf("\nThe cheapest store that has phone type %d is %d.(price is %d)\n",phon,min,price);
	
}


void comparediff(int a[][100],int row){
	int id1,id2,comp[32],i,j,k=0,n,b1[32],counter1=0,b2[32],counter2=0,counter3=0;
	printf("Enter two store id two compare:");
	scanf("%d %d",&id1,&id2);
	
	printf("\n");
	for(i=0;i<row;i++){
		if(a[i][0]==id1){
			b1[counter1]=a[i][1];
			counter1++;
		}
		else if(a[i][0]==id2){
			b2[counter2]=a[i][1];
			counter2++;
		}	
	}
	
	for(i=0;i<counter1;i++){
		for(j=0;j<counter2;j++){
			if(b1[i]!=b2[j]){
				counter3++;
			}
			if(counter3==counter1){
				comp[k]=b1[i];
				k++;
			}
		}
		counter3=0;
	}
	
	if(k==0){
		printf("%d store has all the phone types that %d store has.\n",id1,id2);
	}
	
	else{
		printf("Phone types that are avaliable in %d and not %d is:\n",id1,id2);
		for(i=0;i<k;i++){
			printf("%d ",comp[i]);
		}
	}
	
}


void comparecommon(int a[][100],int row){
	
	int c[32],i,j,id1,id2,k=0;
	
	printf("Enter two store id is to compare to find the common phone types:");
	scanf("%d %d",&id1,&id2);
	

	
	for(i=0;i<row;i++){
		if(a[i][0]==id1){
			for(j=0;j<row;j++){
				if(a[j][0]==id2){
					if(a[i][1]==a[j][1]){
						c[k]=a[i][1];
						k++;
					}
				}
			}
		}
	}
	

	
	
	printf("Common phone types are:\n");
	for(i=0;i<k;i++){
		printf("%d ",c[i]);
	}
	printf("\n");
}


void totalphonetyp(int a[][100],int row){
	int i,j,counter[2][8];
														//first row holds phonetypes,second row holds how many phones we got in our stores.//

	for(i=0;i<8;i++){						
		counter[0][i]=i+1;
		counter[1][i]=0;
	}
	
	for(i=0;i<row;i++){
		for(j=0;j<8;j++){
			if(a[i][1]==counter[0][j]){
				counter[1][j]++;
			}
		}
	}
	
	printf("Total quantities of the phone types are:\n");
	
	for(i=0;i<2;i++){
		for(j=0;j<8;j++){
			printf("%d ",counter[i][j]);
		}
		printf("\n");
	}
	
	
}


void updatefile(int a[][100],int row){
	FILE *fp=fopen("phonedata.txt","w");
	int i,j;
	
	for(i=0;i<row;i++){
		fprintf(fp,"%d	%d	%d	%d",a[i][0],a[i][1],a[i][2],a[i][3]);
		fprintf(fp,"\n");
	}
	printf("Phonedata.txt file is updated.\n");
	
}


void menupref(int choice,int a[][100]){
		int i,j;
		switch(choice){
			case 1:
				readata(a);
				printf("Data is read from text file!\n");
				break;
			case 2:
				selsort(a,row);
				break;
			case 3:
				uquantity(a,row);
				break;
			case 4:
				bublesort(a,row);
				break;
			case 5:
				cheapestore(a,row);
				break;
			case 6:
				comparediff(a,row);
				break;
			case 7:
				comparecommon(a,row);
				break;
			case 8:
				totalphonetyp(a,row);
				break;
			case 9:
				updatefile(a,row);
				break;
				
		}
}


int main(void){
	
	int choice,a[100][100],i=1,j=0;
	int *p1;
	
	FILE *fp;
	
	row=readata(a);
	

	do{
		printf("\n");
		choice=menu();
		menupref(choice,a);
		
	}while(choice!=10);
	
	
	return 0;
}