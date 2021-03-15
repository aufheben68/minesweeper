#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <stdbool.h>
#include <time.h>

void enarksiPaixnidiou();
void emfanisiArxikisOthonis();
int * epilogiDiastasewnVomvwn();
char * gemismaTabloDedomenwn(char ** arr, int a, int b, int c);
char * gemismaTabloEmfanisis(char ** arr2, int a, int b);
char * sugkrisiTablo(char ** arr, char ** arr2, int a, int b, int c, int d);
int sunthikiHttas(char ** arr2, int a, int b, int c, int d);
void emfanisiTablo(char ** arr, int a, int b);
int  elegkseInt();

int main(int argc, char **argv){
	enarksiPaixnidiou();
    return 0;
}

void enarksiPaixnidiou(){
	int* arithmoi;
	int i;
	char kinisi[5];
	int arithmosX,arithmosY;
	int htta = 0;
	int niki = 0;
	
	emfanisiArxikisOthonis();
	
	arithmoi = epilogiDiastasewnVomvwn();
	
	char *arr[arithmoi[0]];
	for (i=0; i<arithmoi[0]; i++){
         arr[i] = (char *)malloc(arithmoi[1] * sizeof(char)); 
	}
	
	*arr = gemismaTabloDedomenwn(arr, arithmoi[0], arithmoi[1], arithmoi[2]);
	
	char **arr2 = (char **)malloc(arithmoi[0] * sizeof(char *)); 
  	for (i=0; i<arithmoi[1]; i++){
         arr2[i] = (char *)malloc(arithmoi[1] * sizeof(char)); 
	}
	
	*arr2 = gemismaTabloEmfanisis(arr2, arithmoi[0], arithmoi[1]);

	do{
		emfanisiTablo(arr2,arithmoi[0],arithmoi[1]);
		printf("\n\n");
		do{
			printf("Please give coordinate on x axis(positive integer greater than 1 and less than %d):\n",arithmoi[0]);
			arithmosX = elegkseInt();
		}while(arithmosX<1 || arithmosX>arithmoi[0]);
		do{
			printf("Please give coordinate on y axis(positive integer greater than 1 and less than %d):\n",arithmoi[1]);
			arithmosY = elegkseInt();
		}while(arithmosY<1 || arithmosY>arithmoi[1]);
		system("cls");
		*arr2 = sugkrisiTablo(arr, arr2, arithmoi[0], arithmoi[1], arithmosX, arithmosY);
		htta = sunthikiHttas(arr, arithmoi[0], arithmoi[1], arithmosX, arithmosY);
		niki = sunthikiNikis(arr2, arithmoi[0], arithmoi[1], arithmoi[2]);
	}while(htta == 0 && niki == 0);		
}

void emfanisiArxikisOthonis(){
	char gramma[10];
	//system ("chcp 1253");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("            ____                                                     ____					         ");
    printf("          /\\   \\                                                   /\\   \\					       \n");
    printf("          /  \\___\\                                                 /  \\___\\				       \n");
    printf("         _\\  / __/_                                               _\\  / __/_			               \n");
    printf("        /\\ \\/_/\\   \\            M I N E S W E E P E R            /\\ \\/_/\\   \\			       \n");
    printf("       /  \\__/  \\___\\                                           /  \\__/  \\___\\			       \n");
    printf("      _\\  /  \\  / __/_                                         _\\  /  \\  / __/_			           \n");
    printf("     /\\ \\/___/\\/_/\\   \\                                       /\\ \\/___/\\/_/\\   \\			   \n");
   	printf("    /  \\___\\    /  \\___\\                                     /  \\___\\    /  \\___\\			   \n");
    printf("   _\\  /   /_  _\\__/ __/_                                   _\\  /   /_  _\\__/ __/_			       \n");
 	printf("  /\\ \\/___/  \\/\\   \\/\\   \\                                 /\\ \\/___/  \\/\\   \\/\\   \\      \n");
	printf(" /  \\___\\ \\___\\ \\___\\ \\___\\          Powered by           /  \\___\\ \\___\\ \\___\\ \\___\\   \n");
	printf(" \\  /   / /   / /   / /   /                aufheben68     \\  /   / /   / /   / /   /			       \n");
	printf("  \\/___/\\/___/\\/___/\\/___/                                 \\/___/\\/___/\\/___/\\/___/            \n"); 
	printf("------------------------------------------------------------------------------------------\n");
	printf("Please enter a letter or number to continue\n");
	scanf("%s",gramma);
	system("cls");
}

int * epilogiDiastasewnVomvwn(){
	int arithmosM, arithmosN, arithmosVomvwn, arithmosPinaka, i;
	int * arithmoi = malloc(sizeof(int)*3);
	do{
		printf("Please pick the number of lines the table is going to have(positive integer greater than 5 and less than 29):\n");
		arithmosM = elegkseInt();
	}while(arithmosM<5 || arithmosM>29);
	system("cls");
	printf("Lines: %d are stored.\n", arithmosM);
	do{
		printf("Please pick the number of columns the table is going to have(positive integer greater than 5 and less than 29):\n");
		arithmosN = elegkseInt();
	}while(arithmosN<5 || arithmosN>29);
	system("cls");
	printf("Columns: %d are stored.\n", arithmosN);
	arithmosPinaka = arithmosM * arithmosN - 1;
	do{
		printf("Please pick the number of bombs the table is going to have(the number must be \nat least even with 1 and less or even with %d):", arithmosPinaka);
		arithmosVomvwn = elegkseInt();
	}while(arithmosVomvwn<1 || arithmosVomvwn>arithmosPinaka);
	system("cls");
	arithmoi[0] = arithmosM;
	arithmoi[1] = arithmosN;
	arithmoi[2] = arithmosVomvwn;
	return arithmoi;
}

int elegkseInt(){
	int num;
	char term;
	fflush(stdin);
	if(scanf("%d%c", &num, &term) != 2 || term != '\n'){
		return 0;
	}else{
    	return num;
	}
}


void emfanisiTablo(char ** arr, int a, int b){
    int row = a;
	int col = b;
    int i, j;
    printf("Symbols of the board:\n");
    printf("* -> closed cell\n");
    printf("# -> bomb\n");
    printf("1,2,3,4,5,6 -> number of bombs surrounding a cell\n");
    printf("*****In order to win you have to open all cells, but the ones containing bombs!!*****\n");
    printf("Board of minesweeper:\n\n");
    for (i = 0; i < row; i++){
    	printf("%2d  ",i+1);
        
       for (j = 0; j < col; j++){
          if(j==0){
          	printf("| %c |",arr[i][j]);
		  }else{
          	printf(" %c |", arr[i][j]);
		  }
      }
      printf("\n");
    }
    printf("\n");
    for(i = 0; i < col; i++){
    	if(i==0){
    		printf("      %d ",i+1);
    	}else if(i<10 && i!=0){
    		printf("  %d ",i+1);
		}else{
			printf(" %d ",i+1);
		}
	}
}


char * gemismaTabloDedomenwn(char ** arr, int a, int b,int c){
    int row = a;
	int col = b;
	int arithmosVomvwn = c;
	int r1,r2;
	int thesi1,thesi2;
	int counter;
	int i, j;
	srand(time(NULL));
    
    for (i = 0; i < row; i++){
       for (j = 0; j < col; j++){
          arr[i][j] = '*';    
      }
    }    
    
    for (i = 0; i<arithmosVomvwn; i++){
			r1 = (rand() % row-1) + 1; 
	    	r2 = (rand() % col) + 1;
	    	if(arr[r1][r2] == '#'){
	    				do{
							r1 = (rand() % row) ; 
						    r2 = (rand() % col) ;
						}while(arr[r1][r2] == '#');
						srand(time(NULL));
						arr[r1][r2] = '#';  					
			}else{
				arr[r1][r2] = '#';
			}
	}
	
	for (i = 0; i < row; i++){
       for (j = 0; j < col; j++){
       	counter = 0;
       	
       	if(arr[i][j+1]=='#' && arr[i][j]=='*'){
		  	counter++;
		}
		
		if(arr[i][j-1]=='#' && arr[i][j]=='*'){
		  	counter++;
		}
		
		if(arr[i+1][j]=='#' && arr[i][j]=='*'){
		  counter++;
		}
		if(i!=0){
			if(arr[i-1][j]=='#' && arr[i][j]=='*'){
			  counter++;
			}
			
			if(arr[i-1][j-1]=='#' && arr[i][j]=='*'){
			  	counter++;
			}
			
			if((arr[i-1][j+1]=='#' && arr[i][j]=='*')){
			  	counter++;
			}
		}	

		if((arr[i+1][j-1]=='#' && arr[i][j]=='*') ){
		  	counter++;
		}
	
		if((arr[i+1][j+1]=='#' && arr[i][j]=='*')){
		  	counter++;
		}
		if(counter>0){
		   arr[i][j] = counter + '0' ;
		}
		if(arr[i][j] == '*'){
			arr[i][j] = ' ';
		}
      }
    }  

	return * arr; 
}

char * gemismaTabloEmfanisis(char ** arr2,int a,int b){
	int row = a;
	int col = b;
	int i, j;
    
    for (i = 0; i < row; i++){
       for (j = 0; j < col; j++){
          arr2[i][j] = '*';    
      }
    } 
    
	return *arr2;
}


char * sugkrisiTablo(char ** arr, char ** arr2, int a, int b, int c, int d){
	int row = a;
	int col = b;
	int arithmosX = c - 1;
	int arithmosY = d - 1;
	int i, j;
	if(arr[arithmosX][arithmosY]==' '){
		arr2[arithmosX][arithmosY]=' ';
	}else if(isdigit(arr[arithmosX][arithmosY])){
		arr2[arithmosX][arithmosY]=arr[arithmosX][arithmosY];
	}else if(arr[arithmosX][arithmosY]=='#'){
		arr2[arithmosX][arithmosY]='#';
	}
	
	return *arr2;
}

int sunthikiHttas(char ** arr2, int a, int b, int c, int d){
	int row = a;
	int col = b;
	int arithmosX = c;
	int arithmosY = d;
	int i, j;
    
    if(arr2[c-1][d-1] == '#'){
        printf("Y O U   L O S T! Thanks for playing minesweeper :D \n");
        return 1;
	}else{
		return 0;
	}  
} 

int sunthikiNikis(char ** arr2, int a, int b, int e){
	int row = a;
	int col = b;
	int i,j;
	int counter = 0;
	int arithmosVomvwn = e; 
	
	for (i = 0; i < row; i++){
       for (j = 0; j < col; j++){
          if(arr2[i][j] == '*'){
          	counter++;
		  }    
        }
    }
	
	if(counter == arithmosVomvwn){
		printf("C O N G R A T S, you have won!!!!\n");
		return 1;	
	}else{
		return 0;
	} 
	
}


