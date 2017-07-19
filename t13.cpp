int romanToInt(char* s) {
	int num[20];
	int cnt = 0;
	while (*s != '\0') {
		switch (*s) {
		case 'I':
			num[cnt++] = 1;
			break;
		case 'V':
			num[cnt++] = 5;
			break;
		case 'X':
			num[cnt++] = 10;
			break;
		case 'L':
			num[cnt++] = 50;
			break;
		case 'C':
			num[cnt++] = 100;
			break;
		case 'D':
			num[cnt++] = 500;
			break;
		case 'M':
			num[cnt++] = 1000;
			break;
		}
		s++;
	}
	int sum = num[0];
	// ����˼���ǣ��ȼ��ϣ����ֺ�һ����ǰһ���󣬾Ͱ�ǰ��ļ�ȥ������
	// �����Ӵ�����Լ򻯴����������ٱ߽��߼��ж�
	for (int i = 1; i < cnt; i++) {
		sum += num[i];
		if (num[i-1] < num[i]) {
			sum -= num[i-1]*2;
		}
		
	}
	return sum;
}

int main13() {
	char s[] = "IV";
	int x = romanToInt(s);
	return 0;
}