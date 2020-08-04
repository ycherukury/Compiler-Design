#include<ctype.h>
#include<string.h>
#include"3AC.h"


char st[100][10];
int top=0;
char i_[2]="0";
char temp[2]="t";

void push(char *s)
{
    
    //printf("\nin push \n");
   // printf("\n %s pushed \n",s);
    strcpy(st[++top],s);
}

//void codegen()
void codegen()
{
    strcpy(temp,"t");
    strcat(temp,i_);

    FILE *fptr = fopen("3AC_output.txt", "w"); // write only 
    fprintf(fptr, "in codegen\n %s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]); // write to file 
    fclose(fptr);

    //printf("in codegen\n %s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);

    //insert_to_quadruple();
    top-=2;
    strcpy(st[top],temp);
    i_[0]++;
}

// void codegen_umin()
// {
// strcpy(temp,"t");
// strcat(temp,i_);
// printf("in codegen_umin \n %s = -%s\n",temp,st[top]);
// top--;
// strcpy(st[top],temp);
// i_[0]++;
// }

//void codegen_assign()
void codegen_assign()
{

printf("I'm here in codegen\n\n");
FILE *fptr = fopen("3AC_output.txt", "w"); // write only 
fprintf(fptr,"in codegen_assign\n %s = %s\n",st[top-2],st[top]);
fclose(fptr);

//printf("in codegen_assign\n %s = %s\n",st[top-2],st[top]);
top-=2;
}
