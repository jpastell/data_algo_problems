#include <algorithm>
#include <iostream>
#include <array>

using namespace std;


int string_pattern(char *text, char * pattern)
{
	size_t text_l = strlen(text);
	size_t pattern_l = strlen(pattern);


	size_t delta_l = text_l - pattern_l;

	for(size_t t_i = 0; t_i < delta_l; t_i++)
	{
		size_t match = 0;
		for(size_t p_i = 0; p_i < pattern_l; p_i++)
		{
			if(pattern[p_i] == text[t_i+p_i]) match++;
			else break;
		}

		if(match == pattern_l){
			cout << "Found " << endl;
			return t_i;
		}
	}
	return -1;
}


int main ()
{


	char text[] = "meyebalaquemetrae";
	char pattern[] = "traefsfsrseresrse";
	string_pattern(text, pattern);




	return 0;
}