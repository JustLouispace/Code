#include <iostream>

using namespace std;

#define NO_OF_CHARS 256

bool areAnagram(char* str1, char* str2)
{	
	int count[NO_OF_CHARS] = {0};
	int i;
	for (i = 0; str1[i] && str2[i]; i++) {
		count[str1[i]]++;
		count[str2[i]]--;
	}

	if (str1[i] || str2[i]){
		return false;
	}

	for (i = 0; i < NO_OF_CHARS; i++){
		if (count[i])
			return false;
		}
	return true;
}

int main()
{
    // True
	char str1[] = "CARE";
	char str2[] = "RACE";
    // char str1[] = "PART";
    // char str2[] = "TRAP";
    // char str1[] = "LISTEN";
    // char str2[] = "SILENT";

    // False
    // char str1[] = "ZXCVBNM";
    // char str2[] = "ASDFGHJ";
	// char str1[] = "zxcvbnm";
	// char str2[] = "ZXCVBNM";
	// char str1[] = "ahda";
	// char str2[] = "bbhb";
	// char str1[] = "AHDA";
	// char str2[] = "BBHB";

	if (areAnagram(str1, str2))
		cout << str1 << " & " << str2 << " are anagram" << endl;
	else
		cout << str1 << " & " << str2 << " are not anagram" << endl;

	return 0;
}
