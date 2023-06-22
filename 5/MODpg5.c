#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//MODIFIED by Shivansh Jaiswal
char op[2],arg1[5],arg2[5],result[5],line[50]; 
void main(){
	FILE *fp1,*fp2;
	fp1=fopen("MODinput.txt","r"); 
	fp2=fopen("output.txt","w");
	
	while(fgets(line, sizeof(line), fp1) != NULL){ 
        	line[strcspn(line, "\n")] = '\0';
		
		int count=sscanf(line,"%s = %s%s%s",result,arg1,op,arg2); 
		
		if(count==4){
			if(strcmp(op,"+")==0){
				fprintf(fp2,"\nMOV r0,%s",arg1); 
				fprintf(fp2,"\nADD r0,%s",arg2); 			
				fprintf(fp2,"\nMOV %s,r0\n",result);
			}
			else if(strcmp(op,"*")==0){
				fprintf(fp2,"\nMOV r0,%s",arg1); 
				fprintf(fp2,"\nMUL r0,%s",arg2); 
				fprintf(fp2,"\nMOV %s,r0\n",result);
			}
			else if(strcmp(op,"-")==0){
				fprintf(fp2,"\nMOV r0,%s",arg1); 
				fprintf(fp2,"\nSUB r0,%s",arg2); 
				fprintf(fp2,"\nMOV %s,r0\n",result);
			}
			else if(strcmp(op,"/")==0){
				fprintf(fp2,"\nMOV r0,%s",arg1); 
				fprintf(fp2,"\nDIV r0,%s",arg2); 
				fprintf(fp2,"\nMOV %s,r0\n",result);
			}
		}
		else if(count==3){
			fprintf(fp2,"\nMOV r0,%s",op);
			fprintf(fp2,"\nNEG r0");
			fprintf(fp2,"\nMOV %s,r0\n",result);
		}
		else if(count==2){
			fprintf(fp2,"\nMOV r0,%s",arg1);
			fprintf(fp2,"\nMOV %s,r0\n",result);
		}
	}
	fclose(fp1);
	fclose(fp2); 
}
