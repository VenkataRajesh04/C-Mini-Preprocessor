#include <stdio.h>
#include <string.h>

void file_inclusion(FILE *fp, FILE *out)
{
    char line[200];
    char filename[100];
    char *p, *start, *end;
    FILE *inc;
    int len;

    while (fgets(line, 200, fp) != NULL)
    {
        p = strstr(line, "#include");

        if (p != NULL)
        {
            p += 8;

            while (*p == ' ')
                p++;

            if (*p == '"' || *p == '<')
            {
                if (*p == '"')
                    end = strchr(p + 1, '"');
                else
                    end = strchr(p + 1, '>');

                if (end != NULL)
                {
                    start = p + 1;
                    len = end - start;

                    strncpy(filename, start, len);
                    filename[len] = '\0';

                    inc = fopen(filename, "r");

                    if (inc != NULL)
                    {
                        while (fgets(line, 200, inc) != NULL)
                        {
                            fputs(line, out);
                        }

                        fclose(inc);
                    }
                    else
                    {
                        fputs(line, out);
                    }

                    continue;
                }
            }
        }

        fputs(line, out);
    }
}
