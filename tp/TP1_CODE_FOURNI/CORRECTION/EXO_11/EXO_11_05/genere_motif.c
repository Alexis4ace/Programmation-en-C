#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME_HEADER "motif.h"
#define FILENAME_BODY "motif.c"
#define PROTECTION "MOTIF_H"

const char * dessin[] =
{
    "                                                                      ",
    "   *********  *  *********  ****       ****  ****       ****       *  ",
    " **         ** **         **    *******    **    *******    ******* * ",
    "                                                                      ",
    "                                                                      ",
    "                                                                      ",
    "                                                                      ",
    "   *       *  *  *       *  ****       *     ****       ****       *  ",
    "    *     *   *   *     *   *          *     *          *          *  ",
    "     *   *    *    *   *    **         *     **         *          *  ",
    "      * *     *     * *     *          *     *          *             ",
    "       *      *      *      ****       ****  ****       ****       *  ",
    "                                                                      ",
    "                                                                      ",
    "                                                                      ",
    "    **                                                          **    ",
    "    * *                                                        * *    ",
    "    *  *                                                      *  *    ",
    " ****   *                                                    *   **** ",
    "                                                                      ",
};

#define NX ((int) strlen(dessin[0]))
#define NY ((int) (sizeof(dessin) / sizeof(char *)))


void genereUnX(int x, FILE *fd)
{
    fprintf(fd, "    {");

    int y = NY-1;
    while (true)
    {
        while ((y >= 0) && (dessin[y][x] == ' '))
            y --;
        if (y < 0)
            break;
        fprintf(fd, "{%2d,", NY-y-1);
        while ((y >= 0) && (dessin[y][x] == '*'))
            y --;
        fprintf(fd, "%2d},", NY-1-y-1);
        if (y < 0)
            break;
    }
    fprintf(fd, "{-1,-1}}");
}

void genereTousX()
{
    FILE *fd;
    
    //
    // génération du fichier d'entête
    //
    fd = fopen(FILENAME_HEADER, "w");
    
    fprintf(fd, "/******************\n");
    fprintf(fd, " * fichier header *\n");
    fprintf(fd, " ******************/\n");
    fprintf(fd, "\n");
    fprintf(fd, "#ifndef " PROTECTION "\n");
    fprintf(fd, "#define " PROTECTION "\n");
    fprintf(fd, "\n");
    fprintf(fd, "#include <stdbool.h>\n");
    fprintf(fd, "\n");
    fprintf(fd, "// dimensions du dessin\n");
    fprintf(fd, "#define NX %3d\n", NX);
    fprintf(fd, "#define NY %3d\n", NY);
    fprintf(fd, "\n");
    fprintf(fd, "// param x : abscisse du point (0 <= x < NX)\n");
    fprintf(fd, "// param y : ordonnée du point (0 <= y < NY)\n");
    fprintf(fd, "// return : true si le point est allumé, false sinon\n");
    fprintf(fd, "bool isOn(int x, int y);\n");
    fprintf(fd, "\n");
    fprintf(fd, "#endif\n");
    
    fclose(fd);

    //
    // génération du fichier corps
    //
    fd = fopen(FILENAME_BODY, "w");

    fprintf(fd, "/****************\n");
    fprintf(fd, " * fichier body *\n");
    fprintf(fd, " ****************/\n");
    fprintf(fd, "\n");
    fprintf(fd, "#include \"%s\"\n", FILENAME_HEADER);
    fprintf(fd, "\n");
    fprintf(fd, "typedef struct {\n");
    fprintf(fd, "    int d, f;\n");
    fprintf(fd, "} Couple;\n");
    fprintf(fd, "\n");
    fprintf(fd, "const Couple dessin[NX][NY+1] =\n");
    fprintf(fd, "{\n");
    for (int x = 0; x < NX; x ++)
    {
        genereUnX(x, fd);
        if (x != NX-1)
            fprintf(fd, ",");
        fprintf(fd, "\n");
    }
    fprintf(fd, "};\n");
    fprintf(fd, "\n");
    fprintf(fd, "bool isOn(int x, int y)\n");
    fprintf(fd, "{\n");
    fprintf(fd, "    if ((x < 0) || (x >= NX) || (y < 0) || (y >= NY))\n");
    fprintf(fd, "        return false;\n");
    fprintf(fd, "\n");
    fprintf(fd, "    bool ok = false;\n");
    fprintf(fd, "    int i = 0;\n");
    fprintf(fd, "\n");
    fprintf(fd, "    while ((! ok) && (dessin[x][i].d != -1))\n");
    fprintf(fd, "    {\n");
    fprintf(fd, "        if ((dessin[x][i].d <= y) && (y <= dessin[x][i].f))\n");
    fprintf(fd, "            ok = true;\n");
    fprintf(fd, "        i ++;\n");
    fprintf(fd, "    }\n");
    fprintf(fd, "    return ok;\n");
    fprintf(fd, "}\n");

    fclose(fd);
}

int main()
{
    genereTousX();
    return EXIT_SUCCESS;
}
