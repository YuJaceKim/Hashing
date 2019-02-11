#include <stdio.h>
#include <string.h>

#define KEY 10

char ht[KEY][KEY] = { 0, }; // �ؽ����̺� 10ĭ

int transform(char *key) {
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}

int hash_function(char *key) {
	return transform(key) & KEY;
}

void AddValue (char *eng, char *kor) {
	int ht_in = 0; // �ؽ����̺� ���� ��ȣ

	ht_in = hash_function(eng);

	strcpy(ht[ht_in], eng);	
	
}

char GetValue (char eng) {
	int ht_in;

	ht_in = hash_function(eng); // KEY��ŭ ���������� -> hashtable number

	if (!ht[ht_in]) {
		return "������ ����";
	}
	else {
		return ht[ht_in];
	}
}


int main (int argv, char *argc[]) {


	AddValue("apple", "���");
	AddValue("orange", "������");
	AddValue("pineapple", "���ξ���");

	printf("apple = %s\n", GetValue("apple"));
	printf("orange = %s\n", GetValue("orange"));
	printf("melon = %s\n", GetValue("melon"));

	AddValue("apple", "�ɱ�");
	printf("apple = %s\n", GetValue("apple"));

	// apple = ���
	// orange = ������
	// melon = ������ ����
	// apple = �ɱ�

}