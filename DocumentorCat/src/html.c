

void html_head(FILE* file, char* name){
	fprintf(file,"<html>\n" 
	"<head>\n"
	" <title>DocMyCode</title>\n"
	" <link rel=\"stylesheet\" href=\"%s\">\n"
	"</head>\n\n"
	"<body>\n", filename);	
}

void html_bottom(FILE *file){
	fprintf(file,
	"</body>\n"
	"</html>");
}
