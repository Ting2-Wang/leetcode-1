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
		// ������д�Խ�紦��
		// ������y+=n����Խ���������Ϊֻ��y*=10��Խ����Ҫ����
		if (y % 10 != 0)
			return 0;
		y += n;
	}
	return y;
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	//������ȫ��copy��reverse����
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
		// ������д�Խ�紦��
		// ������y+=n����Խ���������Ϊֻ��y*=10��Խ����Ҫ����
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