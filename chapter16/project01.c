#include <stdio.h>
#include <stdbool.h>

struct dialing_code {
	char *country;
	int code;
};

const struct dialing_code country_codes[] = {
	{"Argentina", 54},
	{"Bangladesh", 889},
	{"Brazil", 55},
	{"Burma (Myanmar)", 95},
	{"China", 86},
	{"Colombia", 57},
	{"Congo, Dem. Rep. of", 243},
	{"Egypt", 20},
	{"Ethiopia", 251},
	{"France", 33},
	{"Germany", 49},
	{"India", 91},
	{"Indonesia", 62},
	{"Iran", 98},
	{"Italy", 39},
	{"Japan", 81},
	{"Mexico", 52},
	{"Nigeria", 234},
	{"Pakistan", 92},
	{"Philippines", 63},
	{"Poland", 48},
	{"Russia", 7},
	{"South Africa", 27},
	{"South Korea", 82},
	{"Spain", 34},
	{"Sudan", 249},
	{"Thailand", 66},
	{"Turkey", 90},
	{"Ukraine", 380},
	{"United Kingdom", 44},
	{"United States", 1},
	{"Vietnam", 84},
};

const size_t num_country = sizeof(country_codes) / sizeof(country_codes[0]);

int main(void)
{
	bool code_found = false;
	int code, index;

	printf("Enter an international dialing code: ");
	scanf("%d", &code);

	for (size_t i = 0; i < num_country; i++) {
		if (code == country_codes[i].code) {
			code_found = true;
			index = i;
			break;
		}
	}

	if (code_found) {
		printf("Country: %s\n", country_codes[index].country);

		return 0;
	} else {
		printf("Error: no corresponding country code\n");

		return 1;
	}
}
