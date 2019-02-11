#include <stdio.h>
#include <string.h>

#define KEY 10

char ht[KEY][KEY] = { 0, }; // 해시테이블 10칸

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
	int ht_in = 0; // 해시테이블에 넣을 번호

	ht_in = hash_function(eng);

	strcpy(ht[ht_in], eng);	
	
}

char GetValue (char eng) {
	int ht_in;

	ht_in = hash_function(eng); // KEY만큼 나머지연산 -> hashtable number

	if (!ht[ht_in]) {
		return "사전에 없음";
	}
	else {
		return ht[ht_in];
	}
}


int main (int argv, char *argc[]) {


	AddValue("apple", "사과");
	AddValue("orange", "오렌지");
	AddValue("pineapple", "파인애플");

	printf("apple = %s\n", GetValue("apple"));
	printf("orange = %s\n", GetValue("orange"));
	printf("melon = %s\n", GetValue("melon"));

	AddValue("apple", "능금");
	printf("apple = %s\n", GetValue("apple"));

	// apple = 사과
	// orange = 오렌지
	// melon = 사전에 없음
	// apple = 능금

}