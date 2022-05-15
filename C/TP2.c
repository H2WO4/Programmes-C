void dynInput(char* out)
{
	char* p = out;
	char c;
	while (c = getchar())
		*p++ = c;
	*p = '\0';
}

int main()
{
	char* input = malloc(sizeof(char) * 100);
	dynInput(input);
	
	return 0;
}