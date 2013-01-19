#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "lexer.h"
#include "utils.h"

    wchar_t *str_request = L"#include <stdio.h>\n\
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
\n\
int main()\n\
{\n\
    printf(\"Hello !\");\n\
    return 0;\n\
}\n\
\n\
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

/**
 * \file      main.c
 * \author    HappyTeam
 * \version   1.0
 * \date      7/01/2012
 * \brief     Fonctionnement principal
 *
 */

int main(int argc, char** argv)
{
	List* file = NULL;
 	Help(argc,argv);
 	if( argc == 1){
 			file = ReadDirectory(".",file);
 	}
 	
 	else if( argc == 2){
 		if(test_file(argv[1]){}
 			file = add_file(file,argv[1],NULL);
 		else{
 			file = ReadDirectory(argv[1],file);
 		}
 	}
 	
 	else{
 		int i =1;
 		int k = 1;
 		while (i < argc ){
 			if ( test_file(argv[i])
 				file = add_file(file,argv[i],NULL);
 			i++;
 		}
 		
 	}
    return 0;
}
