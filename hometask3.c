#include <stdio.h>
#include <math.h>

int distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int gcd(int x, int y) {
    while(x != y){
        if(x > y) 
            x -= y;
        else 
            y -= x;
    }
    return x;
}

int reverse(int x) {
    int input = 0;
    while (x != 0) {
        input = input*10 + x%10;
        x = x/10;
    }
    return input;
}

int simpleQ(int entry) {
    int res, int i;
    for (i = 1; i < entry; i++){
        if (entry % i == 0){
            res = i;
        }
    }
    if (res > 1){
        return 1;
    }
    else{
        return 0;

    }
}

int minofthree(double x, double y, double z){
    return min(min(x, y), min(y, z));
}

long int factorial(long int n) {
	long int res;
	if (n == 0 || n == 1) 
	    return 1;
	res = n*factorial(n - 1);
	printf("\nfactorial(%ld) = %ld * factorial(%ld)", n, n, n-1);
	return res;
}

int count_spaces(char* argv) {
	int count = 0;
	while (argv[0] != '\0') {
		if (argv[0] == ' ') count++;
		argv++;
	}
	
	return count;
	}

int main() {
    return 0;
}
