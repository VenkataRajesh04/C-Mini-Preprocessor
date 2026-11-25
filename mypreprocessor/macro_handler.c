#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct macro
{
    char name[30];
    char arg[30];
    char value[100];
    int type;
};

void macro_handler(FILE *fp, FILE *out)
{
    char line[200];
    char temp[200];
    char argument[50];
    char *p, *q, *r;
    struct macro m[20];
    int count = 0;
    int i, j, k, len;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strncmp(line, "#define ", 8) == 0)
        {
            p = line + 8;
            i = 0;

            while (isalnum(*p) || *p == '_')
                m[count].name[i++] = *p++;

            m[count].name[i] = '\0';

            m[count].type = 0;
            m[count].arg[0] = '\0';

            if (*p == '(')
            {
                m[count].type = 1;
                p++;

                while (isspace(*p))
                    p++;

                i = 0;

                while (isalnum(*p) || *p == '_')
                    m[count].arg[i++] = *p++;

                m[count].arg[i] = '\0';

                while (*p != ')' && *p != '\0')
                    p++;

                if (*p == ')')
                    p++;
            }

            while (isspace(*p))
                p++;

            strcpy(m[count].value, p);
            m[count].value[strcspn(m[count].value, "\n")] = '\0';

            count++;
            continue;
        }

        p = line;

        while (*p)
        {
            if (isalpha(*p) || *p == '_')
            {
                q = p;

                while (isalnum(*q) || *q == '_')
                    q++;

                len = q - p;
                k = -1;

                for (j = 0; j < count; j++)
                {
                    if (strlen(m[j].name) == len &&
                        strncmp(p, m[j].name, len) == 0)
                    {
                        k = j;
                        break;
                    }
                }

                if (k == -1)
                {
                    fwrite(p, 1, len, out);
                    p = q;
                    continue;
                }

                if (m[k].type == 0)
                {
                    fputs(m[k].value, out);
                    p = q;
                }
                else
                {
                    r = q;

                    while (isspace(*r))
                        r++;

                    if (*r != '(')
                    {
                        fwrite(p, 1, len, out);
                        p = q;
                        continue;
                    }

                    r++;
                    i = 0;

                    while (*r != ')' && *r != '\0')
                        argument[i++] = *r++;

                    argument[i] = '\0';

                    if (*r == ')')
                        r++;

                    q = m[k].value;
                    i = 0;

                    while (*q)
                    {
                        if (isalpha(*q) || *q == '_')
                        {
                            temp[i] = '\0';
                            j = 0;

                            while (isalnum(*q) || *q == '_')
                            {
                                temp[j++] = *q++;
                            }

                            temp[j] = '\0';

                            if (strcmp(temp, m[k].arg) == 0)
                            {
                                fputs(argument, out);
                            }
                            else
                            {
                                fputs(temp, out);
                            }
                        }
                        else
                        {
                            fputc(*q++, out);
                        }
                    }

                    p = r;
                }
            }
            else
            {
                fputc(*p, out);
                p++;
            }
        }
    }
}
/*
#include <stdio.h>
#include <string.h>

void macro_handler(FILE *fp, FILE *out)
{
    char line[100];
    char name[20] = "";
    char value[20] = "";
    char *p, *q;

    while (fgets(line, 100, fp) != NULL)
    {
        if (sscanf(line, "#define %s %s", name, value) == 2)
        {
            continue;
        }

        p = strstr(line, name);

        if (p != NULL && name[0] != '\0')
        {
            q = line;

            while (q < p)
            {
                fputc(*q, out);
                q++;
            }

            fputs(value, out);
            fputs(p + strlen(name), out);
        }
        else
        {
            fputs(line, out);
        }
    }
}
*/
