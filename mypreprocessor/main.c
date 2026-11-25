#include<stdio.h>
#include<string.h>
#include"comment_removal.h"
#include"file_inclusion.h"
#include"macro_handler.h"
int main(int argc,char **argv)
{
if(argc!=2)
{
printf("Usage:./mypreprocessor inputfile.c\n");
return 1;
}
FILE *fp,*out,*temp1,*temp2;
char outputname[100];
char *dot;
fp=fopen(argv[1],"r");
if(fp==0)
{
printf("File is not Present\n");
return 1;
}
strcpy(outputname, argv[1]);

dot = strrchr(outputname, '.');

if (dot != NULL)
    strcpy(dot, ".i");
else
    strcat(outputname, ".i");
temp1 = fopen("temp1.c","w");
remove_comments(fp,temp1);
fclose(fp);
fclose(temp1);
temp1=fopen("temp1.c","r");
temp2=fopen("temp2.c","w");
file_inclusion(temp1,temp2);
fclose(temp1);
fclose(temp2);
temp2=fopen("temp2.c","r");

out=fopen(outputname,"w");

if(out==NULL)
{
    printf("Cannot create output file\n");
    return 1;
}

macro_handler(temp2,out);

fclose(temp2);
fclose(out);
printf("Preprocessing completed successfully!\n");

/*
file_inclusion(temp,out);
fclose(temp);
fclose(out);
printf("Preprocessing Completed\n");
*/

/*
char ch;
while((ch=fgetc(fp))!=-1)
printf("%c",ch);
fclose(fp);
*/

//printf("Comment removal Completed\n");

return 0;
}

