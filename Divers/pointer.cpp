#include <iostream>
#include <stdio.h>
#include <string>

std::string u = "a";

int main() {
	int ptr[2];
	*ptr = 42;
	*(ptr+1) = 12;
	printf("%d\n", *ptr );
	printf("%d\n", ptr[1]);
	printf("%p\n", ptr);
	printf("%p\n", ptr+1);
	char* c;
	int* i;
	size_t* s;
	float* f;
	bool* b;
	long* l;
	for (int p = 0; p < 15; p++) {
		printf("%p%s%p%s%p%s%p%s%p%s%p%s%p\n", c+p,"||", i+p,"||", s+p,"||", f+p,"||", b+p,"||", l+p, "||", &u+p);
	}
} 