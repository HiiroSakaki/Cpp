# define MAXVAL 100
# define STEP 10
#define	XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>


/*
 * array_random_fill(array, len, maxval): fill array with random values
 * maxval is the maximum random value
 */
static inline
void array_random_fill(int array[], size_t len, int maxval)
{
  for (size_t i = 0; i < len; ++i)
    array[i] = random() % maxval;
}
 
/*
 * array_sorted_fill(array, len, step): fill array with sorted value
 * step is the difference between values
 */
static inline
void array_sorted_fill(int array[], size_t len, int step)
{
  int cur = 0;
  for (size_t i = 0; i < len; ++i, cur += step)
    array[i] = cur;
}
 
/*
 * array_reverse_sorted_fill(array, len, step): fill array with values in
 * reverse order
 * step is the difference between values
 */
static inline
void array_reverse_sorted_fill(int array[], size_t len, int step)
{
  int cur = (len - 1) * step;
  for (size_t i = 0; i < len; ++i, cur -= step)
    array[i] = cur;
}

static inline
int array_random_sorted_fill(int array[], size_t len, int maxstep)
{
  int cur = 0;
  for (size_t i = 0; i < len; ++i) {
    int step = 1 + random() % maxstep;
    cur += step;
    array[i] = cur;
  }
  return cur;
}

/*
 * int_len(int x): number of decimal digit
 */
static inline
int int_len(int x)
{
  int len = 0;
  for (; x > 0; x /= 10)
    len += 1;
  return len;
}
 
/*
 * array_print(array, len): print the array
 */
static inline
void array_print(int array[], size_t len, int maxval)
{
  int line = 0;
  int intlen = int_len(maxval);
  for (size_t i = 0; i < len; ++i) {
    if (line > 72) {
      printf("|\n");
      line = 0;
    }
    line += printf("| %*d ", intlen, array[i]);
  }
  printf("|\n");
}

/*
 * In all following functions parameters array and len are defined as:
 * array: an integer array
 * len: the length of the array, must be greater than 0
 */
 
/*
 * min and max value
 */
 
/*
 * array_min(array, len): returns min value of array
 */
int array_min(int array[], size_t len)
{
  int min = array[0];
  for (size_t i = 0; i < len; i++) {
  	if (array[i] < min) {
  		min = array[i];
  	}
  }
  return min;
}
 
/*
 * array_max(array, len): returns max value of array
 */
int array_max(int array[], size_t len)
{
  int max = array[0];
  for (size_t i = 0; i < len; i++){
  	if (array[i] > max) {
  		max = array[i];
  	}
  }
  return max;
}
 
/*
 * min and max index
 */
 
/*
 * array_min_index(array, len): returns the index of the min value of array
 */
size_t array_min_index(int array[], size_t len)
{
  size_t index = 0;
  int min = array[0];
  for (size_t i = 0; i < len; i++){
  	if (array[i] < min) {
  		min = array[i];
  		index = i;
  	}
  }
  return index;
}
 
/*
 * array_max_index(array, len): returns the index of the max value of array
 */
size_t array_max_index(int array[], size_t len)
{
  size_t index = 0;
  int max = array[0];
  for (size_t i = 0; i < len; i++){
  	if (array[i] > max) {
  		max = array[i];
  		index = i;
  	}
  }
  return index;
}

/*
 * In all following functions parameters array and len are defined as:
 * array: an integer array
 * len: the length of the array, must be greater than 0
 */
 
/*
 * searching for value
 */
 
/*
 * array_find(array, len, x): returns the position of x in array or len if not
 * present
 */
size_t array_find(int array[], size_t len, int x)
{
 for (size_t i = 0; i < len; i++) {
 	if (array[i] == x)
 		return i;
 }
 return len;
}
 
/*
 * array_bin_search(array, len, x): search in a sorted array using binary search
 * returns the position of x, or the expected position of x if not present
 */
size_t array_bin_search(int array[], size_t len, int x)
{
	size_t g = 0;
	size_t d = len;
	size_t mid;
	while (d > g) {
		mid = g + (d-g)/2;
		if (x <= array[mid]) {
			d = mid;
		}
		else {
			g = mid + 1;
		}
	}
	return d;
}
 
/*
 * Tests
 */
 
 
/*
 * Test functions
 */
 
/*
 * min value tests
 */
void test_min(int array[], size_t len)
{
  int min;
  printf("*** Test min value search ***\n");
 
  printf("**** Sorted array ****\n");
  array_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  min = array_min(array, len);
  printf("  array_min: %d\t(should be %d)\n", min, array[0]);
 
  printf("**** Reverse sorted array ****\n");
  array_reverse_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  min = array_min(array, len);
  printf("  array_min: %d\t(should be %d)\n", min, array[len - 1]);
 
  printf("**** Random array ****\n");
  array_random_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  min = array_min(array, len);
  printf("  array_min: %d\n", min);
}
 
/*
 * max value tests
 */
void test_max(int array[], size_t len)
{
  int max;
  printf("*** Test max value search ***\n");
 
  printf("**** Sorted array ****\n");
  array_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  max = array_max(array, len);
  printf("  array_max: %d\t(should be %d)\n", max, array[len - 1]);
 
  printf("**** Reverse sorted array ****\n");
  array_reverse_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  max = array_max(array, len);
  printf("  array_max: %d\t(should be %d)\n", max, array[0]);
 
  printf("**** Random array ****\n");
  array_random_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  max = array_max(array, len);
  printf("  array_max: %d\n", max);
}
 
 
/*
 * min index test
 */
void test_min_index(int array[], size_t len)
{
  size_t min;
  printf("*** Test min value index search ***\n");
 
  printf("**** Sorted array ****\n");
  array_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  min = array_min_index(array, len);
  printf("  array_min_index: array[%zu] = %d\n", min, array[min]);
 
  printf("**** Reverse sorted array ****\n");
  array_reverse_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  min = array_min_index(array, len);
  printf("  array_min_index: array[%zu] = %d\n", min, array[min]);
 
  printf("**** Random array ****\n");
  array_random_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  min = array_min_index(array, len);
  printf("  array_min_index: array[%zu] = %d\n", min, array[min]);
}
 
/*
 * max index test
 */
void test_max_index(int array[], size_t len)
{
  size_t max;
  printf("*** Test max value index search ***\n");
 
  printf("**** Sorted array ****\n");
  array_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  max = array_max_index(array, len);
  printf("  array_max_index: array[%zu] = %d\n", max, array[max]);
 
  printf("**** Reverse sorted array ****\n");
  array_reverse_sorted_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  max = array_max_index(array, len);
  printf("  array_max_index: array[%zu] = %d\n", max, array[max]);
 
  printf("**** Random array ****\n");
  array_random_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  max = array_max_index(array, len);
  printf("  array_max_index: array[%zu] = %d\n", max, array[max]);
}

typedef size_t (*search_fun)(int *, size_t, int);
 
static inline
void search_help(search_fun fun, int array[], size_t len, int x)
{
  printf("  searching %d: ", x);
  size_t i = fun(array, len, x);
  if (i < len)
    printf("array[%zu] = %d\n", i, array[i]);
  else
    printf("not found (%zu)\n", i);
}
 
static
void test_search(int array[], size_t len)
{
  int x;
 
  printf("*** Test value search ***\n");
  printf("**** Sorted array ****\n");
  array_sorted_fill(array, len, STEP);
  array_print(array, len, (len - 1) * STEP);
  x = array[0];
  search_help(array_find, array, len, x);
  x = array[len - 1];
  search_help(array_find, array, len, x);
  x = array[random() % len];
  search_help(array_find, array, len, x);
  x = len * STEP;
  search_help(array_find, array, len, x);
 
 
  printf("**** Reverse sorted array ****\n");
  array_reverse_sorted_fill(array, len, STEP);
  array_print(array, len, (len - 1) * STEP);
  x = array[0];
  search_help(array_find, array, len, x);
  x = array[len - 1];
  search_help(array_find, array, len, x);
  x = array[random() % len];
  search_help(array_find, array, len, x);
  x = len * STEP;
  search_help(array_find, array, len, x);
 
  printf("**** Random array ****\n");
  array_random_fill(array, len, MAXVAL);
  array_print(array, len, MAXVAL);
  x = array[0];
  search_help(array_find, array, len, x);
  x = array[len - 1];
  search_help(array_find, array, len, x);
  x = array[random() % len];
  search_help(array_find, array, len, x);
  x = random() % (MAXVAL * 2);
  search_help(array_find, array, len, x);
 
}
 
static
void test_bin_search(int array[], size_t len)
{
  int x;
 
  printf("*** Test value binary search ***\n");
 
  printf("  founded index may not contain searched value\n");
 
  printf("**** Basic sorted array ****\n");
  array_sorted_fill(array, len, STEP);
  array_print(array, len, (len - 1) * STEP);
  x = array[0];
  search_help(array_bin_search, array, len, x);
  x = array[len - 1];
  search_help(array_bin_search, array, len, x);
  x = array[random() % len];
  search_help(array_bin_search, array, len, x);
  x = len * STEP;
  search_help(array_bin_search, array, len, x);
 
  printf("**** Basic sorted array ****\n");
  int maxval = array_random_sorted_fill(array, len, STEP);
  array_print(array, len, maxval);
  x = array[0];
  search_help(array_bin_search, array, len, x);
  x = array[len - 1];
  search_help(array_bin_search, array, len, x);
  x = array[random() % len];
  search_help(array_bin_search, array, len, x);
  x = random() % (maxval * 2);
  search_help(array_bin_search, array, len, x);
 
}

int main(){
	int* array = new int[10];
	size_t len = 10;
	
	test_min(array, len);
  	printf("\n");
 	
  	test_max(array, len);
 	 printf("\n");
 
  	test_min_index(array, len);
  	printf("\n");
 
  	test_max_index(array, len);
  	printf("\n");
	
	test_search(array, len);
	printf("\n");
	
	test_bin_search(array, len);
  	printf("\n");
	
	delete [] array;	
	return 0;
}
