#include <string.h>

#include "title.h"

void title_repeat(const char *s, int n, bool withReturn)
{
    title_repeatStream(stdout, s, n, withReturn);
}

void title_repeatStream(FILE *fd, const char *s, int n, bool withReturn)
{
    for (int i = 0; i < n; i++)
        fprintf(fd, "%s", s);
    if (withReturn)
        fprintf(fd, "\n");
}


void title_print(const char *title)
{
    title_printStream(stdout, title);
}

void  title_printStream(FILE *fd, const char *title)
{
    const int LINE_LENGTH = 75;
    int titleLength = strlen(title);

    fprintf(fd, "\n");
    title_repeatStream(fd, "=", LINE_LENGTH, true);
    fprintf(fd, "= %s", title);
    title_repeatStream(fd, " ", LINE_LENGTH - titleLength - 4, false);
    fprintf(fd, " =\n");
    title_repeatStream(fd, "=", LINE_LENGTH, true);
}
