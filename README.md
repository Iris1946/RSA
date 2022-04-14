 ## RSA算法

**1. 选择两个大素数`p`、`q`。**

代码思路：为简化后续计算，随机生成两个`< 15`的数，判断是否为`素数`。如果不是，则重新生成。

```C++
srand((unsigned)time(NULL));
p = rand() % 15, q = rand() % 15;
while(isPrime(p) == false) p = rand() % 15;
while(isPrime(q) == false) q = rand() % 15;
```

`isprime()`函数【判断是否为素数】如下：

```C++
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
```

**2. 计算`n = p * q`，以及欧拉函数`Euler(n) = (p - 1) * (q - 1)`。**

```
n = p * q;
euler = (p - 1) * (q - 1);
```

**3. 随机选择一个`(1, Euler(n))`范围内的正整数`e`，使最大公约数`gcd(e, Euler(n)) = 1`。**

代码思路：为简化后续计算，随机生成一个`< 10`的数，判断是否满足最大公约数的条件。若不能，则重新生成。

```C++
while(gcd(e, euler) != 1) e = rand() % 10;
```

**4. 计算`e`对于`Euler(n)`的模反元素`d`。**

"模反函数"就是指一个整数`d`，可以使`ed`被`Euler(n)`除的余数为`1`。即`(ed - 1) % Euler(n) = 0 `。

代码思路：为简化后续计算，仅计算`< 15`的模反函数`d`，使其满足上述条件。

```C++
for(int i = 1; i < 15; i++) {
	if((e * i - 1) % euler == 0 && i != e) {
		d = i;
		break;
	}
}
```

**5. 公钥和私钥的计算结果：**

一次随机生成的**公钥**为`(7, 14)`；私钥为`1`。

运行代码如下：

```C++
#include <iostream>
#include <ctime>
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
	return 0;
}
```

## 加密和解密过程

**加密过程：**

代码思路：输入一个数据`x`为作为明文，计算`y = (x ^ e) % n`作为输出的密文数字。

```C++
printf("------------------------数据的加密过程-------------------------\n");
int x;
printf("请输入x的值:");
scanf("%d", &x);
int temp = pow(x, e);
int y = temp % n;
printf("y=%d\n", y);
```

**解密过程：**

代码思路：利用密文数字`y`解密还原到明文数字`x`，使得`x = (y ^ d) % n`。如果明文数字`x`与输入相同，则说明“解密成功”。

```C++
printf("------------------------数据的解密过程-------------------------\n");
temp = pow(y, d);
int x1 = temp % n;
printf("x=%d\n", x1);
if(x1 == x) printf("解密成功\n");
```

## 完整代码与结果

```C++
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
```

### Input:

```C++
12
```

### Output:

首先，一次随机生成的**公钥**为`(7, 14)`；私钥为`1`。

当输入明文数字`x `为`12`时，输出密文数字`y`为`12`。还原到明文数字`x`仍为`12`，解密成功。
