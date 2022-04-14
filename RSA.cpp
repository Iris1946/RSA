#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int gcd (int a, int b) {
	return !b ? a : gcd(b, a % b);
}

bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	int p, q, euler, e, d = -1, n;
	while(d == -1) {
		srand((unsigned)time(NULL));
    	p = rand() % 15, q = rand() % 15;
    	while(isPrime(p) == false) p = rand() % 15;
    	while(isPrime(q) == false) q = rand() % 15;
		n = p * q;
		euler = (p - 1) * (q - 1);
		while(gcd(e, euler) != 1) e = rand() % 10;
		for(int i = 1; i < 15; i++) {
			if((e * i - 1) % euler == 0 && i != e) {
				d = i;
				break;
			}
		}
	}
	printf("---------------------------RSA�㷨------------------------------\n");
	printf("(1)ѡ������������p��q, ������p=%d, q=%d.\n", p, q);
	printf("(2)����n=pq=%d, �Լ�ŷ������euler=(p-1)(q-1)=%d.\n", n, euler);
	printf("(3)���ѡ��һ��(1,euler)��Χ�ڵ�������e, ʹ���Լ��gcd(e,euler)=1, ��ʵ����Ӧ�����ܴ�, ����e=%d.\n", e);
	printf("(4)����e����euler��ģ��Ԫ��d, ����d=%d.\n", d);
	printf("(5)��Կ:(e,n), ������(%d,%d).\n(6)˽Կd, ������%d.\n", e, n, d);
	printf("------------------------���ݵļ��ܹ���-------------------------\n");
	int x;
	printf("������x��ֵ:");
	scanf("%d", &x);
	int temp = pow(x, e);
	int y = temp % n;
	printf("y=%d\n", y);
	printf("------------------------���ݵĽ��ܹ���-------------------------\n");
	temp = pow(y, d);
	int x1 = temp % n;
	printf("x=%d\n", x1);
	if(x1 == x) printf("���ܳɹ�\n");
	return 0;
}
