int reverse(int x) {
	int cnt = 0;
	const int N = 10;
	int num[N];
	int m = x;
	int n;
	int y = 0;
	while (m != 0) {
		n = m % 10;
		m = m / 10;
		y *= 10;
		// 这里进行粗越界处理
		// 忽略了y+=n可能越界情况，认为只有y*=10是越界主要部分
		if (y % 10 != 0)
			return 0;
		y += n;
	}
	return y;
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	//下面完全是copy了reverse函数
	int cnt = 0;
	const int N = 10;
	int num[N];
	int m = x;
	int n;
	int y = 0;
	while (m != 0) {
		n = m % 10;
		m = m / 10;
		y *= 10;
		// 这里进行粗越界处理
		// 忽略了y+=n可能越界情况，认为只有y*=10是越界主要部分
		if (y % 10 != 0)
			return 0;
		y += n;
	}
	return y==x;
}

int main7() {
	int x=1;
	int y = reverse(x);
	return 0;
}