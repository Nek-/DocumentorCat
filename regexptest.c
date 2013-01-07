#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main()
{
    int err;
    regex_t preg;
    const char *str_request = "#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <regex.h>\n\
\n\
/**\n\
 * \file      main.c\n\
 * \author    HappyTeam\n\
 * \version   1.0\n\
 * \date      7/01/2012\n\
 * \brief     Fonctionnement principal\n\
 *\n\
 */\n\
\
int main()\n\
{\n\
    printf(\"Hello !\");\n\
    return 0;\n\
}\n\
";
    const char *str_regex = "/\*\*\n[:alnum:,\n]+\*\/";

    /* (1) */
    err = regcomp (&preg, str_regex, REG_NOSUB | REG_EXTENDED);
    if (err == 0)
    {
        int match;

        /* (2) */
        match = regexec (&preg, str_request, 0, NULL, 0);
        /* (3) */
        regfree (&preg);
        /* (4) */
        if (match == 0)
        {
            printf ("%s est une adresse internet valide\n", str_request);
        }
        /* (5) */
        else if (match == REG_NOMATCH)
        {
            printf ("%s n\'est pas une adresse internet valide\n", str_request);
        }
        /* (6) */
        else
        {
            char *text;
            size_t size;

            /* (7) */
            size = regerror (err, &preg, NULL, 0);
            text = malloc (sizeof (*text) * size);
            if (text)
            {
                /* (8) */
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
    puts ("\nPress any key\n");
    return 0;
}
