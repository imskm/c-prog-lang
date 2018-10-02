#include<stdio.h>
#include<assert.h>

/**
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including and optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 throug 9, a through f, and A throug F.
 */

#define SIZE 20

int is_hex_alpha(char c)
{
	switch(c)
	{
		case 'A' :
		case 'a' :
		case 'B' :
		case 'b' :
		case 'C' :
		case 'c' :
		case 'D' :
		case 'd' :
		case 'E' :
		case 'e' :
		case 'F' :
		case 'f' :
			return 1;

		default :
			return 0;
	}
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9')? 1 : 0;
}

int hex_start_index(char s[])
{
	int i = 0;
	while(s[i])
	{
		// if leading space found the skip it
		if(s[i] == ' ' || s[i] == '\t')
		{
			i++;
			continue;
		}
		else if(s[i] == '\n' || s[i] == '\0' || s[i] == EOF)
		{
			i = -1;
			break;
		}

		if(s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		{
			if(s[i + 2] >= '0' && s[i + 2] <= '9')
			{
				i = i + 2;
				break;
			}
			else if((s[i + 2] >= 'A' && s[i + 2] <= 'F') || (s[i + 2] >= 'a' && s[i + 2] <= 'f'))
			{
				i = i + 2;
				break;
			}
		}
		else if(is_digit(s[i]))
			break;
		else if((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'))
			break;
		else
		{
			i = -1;
			break;
		}

		i++;
	}

	return i;
}

int extract_hex(char s[], int start, char ehs[])
{
	int j = 0;

	for(int i = start; i < SIZE && s[i] != ' ' && s[i] != '\n' && s[i] != '\0'; ++i)
	{
		if(!is_digit(s[i]) && !is_hex_alpha(s[i]))
			break;

		ehs[j++] = s[i];
	}
	ehs[j] = '\0';

	return j;
}

int get_alpha_value(char had)
{
	// had = hex alpha digit
	switch(had)
	{
		case 'A' :
		case 'a' :
			return 10;
			
		case 'B' :
		case 'b' :
			return 11;

		case 'C' :
		case 'c' :
			return 12;

		case 'D' :
		case 'd' :
			return 13;

		case 'E' :
		case 'e' :
			return 14;
			
		case 'F' :
		case 'f' :
			return 15;

		// Although this will enver occur but safe to have a default return value
		default :
			return -1;
	}
}

int hex_digit_to_int(char c, int place)
{
	int power = 1, n;
	for(int i = 0; i < place; ++i)
	{
		power *= 16;
	}

	if(c >= '0' && c <= '9')
		n = c - '0';
	else if(is_hex_alpha(c))
		n = get_alpha_value(c);

	return n * power;
}

int hextoint_helper(char ehs[], int len)
{
	int n = 0;
	for(int i = len - 1; i >= 0; --i)
	{
		n += (hex_digit_to_int(ehs[i], len - i - 1));
	}

	return n;
}

int htoi(char s[])
{
	int start = hex_start_index(s);

	assert(start != -1);

	fprintf(stderr, "Start = %d\n", start);

	char ehs[SIZE];  // Extracted hex string
	int len = extract_hex(s, start, ehs);
	
	assert(len != 0);

	fprintf(stderr, "Extracted hex string = %s\n", ehs);

	return hextoint_helper(ehs, len);
}

int main()
{
	char s[SIZE];

	scanf("%s", s);
	printf("%d\n", htoi(s));
	return 0;
}
