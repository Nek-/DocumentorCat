#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
/**
 * \file      regexptest.c
 * \author    HappyTeam
 * \version   1.0
 * \date      7/01/2012
 * \brief     Tests des fonctions de regexp
 *
 */

int main()
{
    int err;
    regex_t preg;
    const char *str_request = "#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <regex.h>\n\
\n\
/**\n\
 * \\file      main.c\n\
 * \\author    HappyTeam\n\
 * \\version   1.0\n\
 * \\date      7/01/2012\n\
 * \\brief     Fonctionnement principal\n\
 *\n\
 */\n\
\
int main()\n\
{\n\
    printf(\"Hello !\");\n\
    return 0;\n\
}\n";
    // Tested on http://rubular.com/
    // Expresion who get comments like that:
    /**
     *
     */
    const char *str_regex = "\\/\\*\\*(.*)\\*\\/[[:space:]]+((int|float|double|void|char)\\** [a-zA-Z]+\\((((int|float|double|void|char)\\**[[:space:]]+[a-z])(,[[:space:]]*)?)*\\))";

    /* On commence par compiler notre expression sans l'option REG_NOSUB pour pouvoir récupérer les sous chaîne reconnues */
    err = regcomp (&preg, str_regex, REG_EXTENDED);
    if (err == 0)
    {
        int match;
        size_t nmatch = 0;
        regmatch_t *pmatch = NULL;

        nmatch = preg.re_nsub;
        pmatch = malloc (sizeof (*pmatch) * nmatch);
        if (pmatch)
        {
            /* Grâce à la structure regex_t, on connaît le nombre de sous chaîne attendue, on alloue donc un tableau de taille adéquate pour les stocker */
            match = regexec (&preg, str_request, nmatch, pmatch, 0);
            /* On demande l'analyse de notre chaîne */
            regfree (&preg);
            /* Si la chaîne est reconnue */
            if (match == 0)
            {
                char *site = NULL;
                int start = pmatch[0].rm_so;
                int end = pmatch[0].rm_eo;
                size_t size = end - start;

                site = malloc (sizeof (*site) * (size + 1));
                if (site)
                {
                    strncpy (site, &str_request[start], size);
                    site[size] = '\0';
                    printf ("%s\n", site);
                    free (site);
                }
            }
            /* On récupère les indices de début et de fin de la sous chaîne et on en profite pour calculer sa taille */
            else if (match == REG_NOMATCH)
            {
                printf ("%s n\'est pas une adresse internet valide\n", str_request);
            }
            /* On alloue un espace mémoire suffisant pour stocker notre sous chaîne */
            else
            {
                char *text;
                size_t size;

                /* On copie la chaîne d'origine de l'indice start jusqu'à size caractères */
                size = regerror (err, &preg, NULL, 0);
                text = malloc (sizeof (*text) * size);
                if (text)
                {
                /* Et on n'oublie pas de libérer la mémoire allouée */
                regerror (err, &preg, text, size);
                fprintf (stderr, "%s\n", text);
                free (text);
                }
                else
                {
                fprintf (stderr, "Memoire insuffisante\n");
                exit (EXIT_FAILURE);
                }
            }
        }
        else
        {
            fprintf (stderr, "Memoire insuffisante\n");
            exit (EXIT_FAILURE);
        }
    }
    puts ("\nPress any key\n");
    return 0;
}
