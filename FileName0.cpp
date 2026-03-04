#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
typedef struct book {
	char title[30];
	char author[20];
	int price;
}BOOK;
void search_by_price(BOOK* list, int size, int budget) {
	int found = 0;
	BOOK temp;
	for (int i = 0; i < size - 1; i++) {
		int least = i;
		for (int j = i + 1; j < size; j++) {
			if (list[j].price < list[least].price) {
				least = j;
			}
		}
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}

	for (int i = 0; i < size; i++) {
		if (list[i].price <= budget) {
			printf("구매 가능한 책:%s(%s), %d원 \n", list[i].title,list[i].author, list[i].price);
			found = 1;
			
		}
		
	}
	

	if (found == 0) {
		printf("구매 가능한 책이 없습니다.");
	}
}

int main() {
	BOOK b[3] = { 0 };
	int book_budget;
	printf("3권의 제목,저자,가격을 적으시오\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s %s %d", b[i].title, b[i].author, &b[i].price);
	}
	printf("예산을 적으시오:");
	scanf("%d", &book_budget);

	search_by_price(b, 3, book_budget);

	
	return 0;
}