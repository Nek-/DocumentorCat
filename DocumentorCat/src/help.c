 #include <getopt.h>
 
 void Help(int argc,char** argv){
 	
 	const char* optstring = ":h";
  	const struct option lopts[] = {
		{ "help", no_argument, NULL, 'h' },
		{ NULL, no_argument, NULL, 0 }
  	};

	  int c;
	  int index = -1;

	  while (EOF != (val = getopt_long(nb, tab, optstring, lopts, &index)))
	  {
			char msg[32];

			if (index == -1)
			  sprintf(msg, "short option -%c", val);
			else
			  sprintf(msg, "long option --%s", lopts[index].name);

			switch (c)
			{
				  case 'h':
					printf("\t\tHelp for Noobs\n");
					printf("Utiliser une synthaxe comme dans les exemple suivant pour lancer docmycode:\n");
					printf("- user@pc:~$ docmycode fichier1.c fichier2.c main.c \n");
					printf("- user@pc:~$ docmycode /chemin/vers/mon/projet/ \n");
					printf("- user@pc:/chemin/vers/mon/projet/$ docmycode \n");

					exit(0);

					break;
				  default:
					printf("Not an option.\n");
					exit(0);

					break;
			}
	  }
}
