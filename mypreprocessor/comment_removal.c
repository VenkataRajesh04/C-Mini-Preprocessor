#include<stdio.h>
#include"comment_removal.h"
void remove_comments(FILE *fp,FILE *out)
{
char ch,next;
while((ch=fgetc(fp))!=-1)
    {
        if(ch=='/')
        {
            next=fgetc(fp);

            // Single line comment
            if(next=='/')
            {
                while((ch=fgetc(fp))!=-1 && ch!='\n');
                if(ch=='\n')
                    fputc('\n', out);
            }

            // Multi-line comment
            else if(next=='*')
            {
                while((ch=fgetc(fp))!=-1)
                {
                    if(ch=='\n')
                        fputc('\n',out);
                    if(ch=='*')
                    {
                        next=fgetc(fp);
                        if (next=='/')
                            break;
                        if(next==-1)
                            break;
                        ungetc(next,fp);
                    }
                }
            }

            // Normal division operator
            else
            {
                fputc(ch,out);
                if(next!=-1)
                    ungetc(next,fp);
            }
        }
        else
        {
            fputc(ch,out);
        }
    }
}
