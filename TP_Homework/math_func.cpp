# include <err.h>
# include <stdlib.h>
# include <iostream>

unsigned long fact(unsigned long n) {
	unsigned long r {1};
	for (unsigned long i {1}; i <= n; i++) {
		r *= i;
	}
	return r;
}

unsigned long fibo(unsigned long n) {
	
	if (n == 0 || n == 1) {
		return 1;
	}
	unsigned long r = 0;
	r += fibo(n-1) + fibo(n-2);
	return r;
}

unsigned long int_sqrt(unsigned long n) {
	unsigned long x {n};
	while (x > n/x) {
		x = (x + (n/x)) / 2;
	}
	return x;
}

unsigned long digit_number(unsigned long n) {
	unsigned long r {0};
	while (n > 0) {
		n /= 10;
		r++;
	}
	return r;
}

unsigned long binary_digit_number(unsigned long n) {
	unsigned long r {0};
	while (n > 0) {
		n /= 2;
		r++;
	}
	return r;
}

unsigned long power_of_2(unsigned long n) {
	return 1 << n;
}

unsigned long divisor_sum(unsigned long n) {
	unsigned long r = 1;
	for (unsigned long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			r += i + n / i;
		}
	}
	return r;
}
int main(){
	std::cout << fact(5) << std::endl;
	std::cout << fibo(5) << std::endl;
	std::cout << int_sqrt(99) << std::endl;
	std::cout << digit_number(100) << std::endl;
	std::cout << digit_number(99) << std::endl;
	std::cout << binary_digit_number(7) << std::endl;
	std::cout << binary_digit_number(9) << std::endl;
	std::cout << power_of_2(8) << std::endl;
	std::cout << divisor_sum(6) << std::endl;
	return 0;
}