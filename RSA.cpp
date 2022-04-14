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
	printf("---------------------------RSA算法------------------------------\n");
	printf("(1)选择两个大素数p、q, 这里令p=%d, q=%d.\n", p, q);
	printf("(2)计算n=pq=%d, 以及欧拉函数euler=(p-1)(q-1)=%d.\n", n, euler);
	printf("(3)随机选择一个(1,euler)范围内的正整数e, 使最大公约数gcd(e,euler)=1, 这实际中应尽可能大, 这里e=%d.\n", e);
	printf("(4)计算e对于euler的模反元素d, 这里d=%d.\n", d);
	printf("(5)公钥:(e,n), 这里是(%d,%d).\n(6)私钥d, 这里是%d.\n", e, n, d);
	printf("------------------------数据的加密过程-------------------------\n");
	int x;
	printf("请输入x的值:");
	scanf("%d", &x);
	int temp = pow(x, e);
	int y = temp % n;
	printf("y=%d\n", y);
	printf("------------------------数据的解密过程-------------------------\n");
	temp = pow(y, d);
	int x1 = temp % n;
	printf("x=%d\n", x1);
	if(x1 == x) printf("解密成功\n");
	return 0;
}
