#include<iostream>
#include<fstream>
using namespace std;
class diction
{
public:
	char word[20];
	diction* link;
};
diction* init(diction* head, char word[]);//1번
diction* deleteAll(diction* head, char str[]);//2번
diction* insert(diction* head, char str[], char str2[]);//3번
void print(diction* head);//4번
int main()
{
	ifstream Word("words.txt");
	char word[20];
	char str[20];
	char str2[20];
	diction* head = NULL;
	int choose = 0;

	if (Word.is_open())
	{
		while (!Word.eof())
		{
			Word >> word;
			head = init(head, word);
		}
		Word.close();
	}
	while (choose != 1)
	{
		cout << endl << endl << "1.종료" << endl;
		cout << "2.삭제" << endl;
		cout << "3.삽입" << endl;
		cout << "4.출력" << endl;
		cout << "choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			break;
		case 2:
			cout << "삭제할 문자열: ";
			cin >> str;
			head = deleteAll(head, str);
			break;
		case 3:
			cout << "str1: ";
			cin >> str;
			cout << "str2: ";
			cin >> str2;
			head = insert(head, str, str2);
			break;
		case 4:
			print(head);
			break;
		default:
			break;
		}
	}
	return 0;
}
diction* init(diction* head, char word[])//1번
{
	diction* node = new diction;
	strcpy_s(node->word, 20, word);
	diction* pre = NULL;

	if (head == NULL)
	{
		head = node;
		node->link = NULL;
	}
	else
	{
		for (pre = head; pre->link != NULL; pre = pre->link)
		{
		}
		node->link = pre->link;
		pre->link = node;
	}
	return head;
}
diction* deleteAll(diction* head, char str[])//2번
{
	int h = 0;
	int count = 0;
	diction* i = NULL;
	diction* pre = NULL;

	for (int j = 0; j < 20; ++j)
	{
		if (str[j] != NULL)
			++count;
		else
			break;
	}
	for (i = head; i != NULL; )
	{
		for (h = 0; h < count; ++h)
		{
			if (str[h] == i->word[h])
				continue;
			else
				break;
		}
		if (h == count)
		{
			diction* removed = new diction;
			if (i == head)
			{
				removed = head;
				head = head->link;
			}
			else
			{
				for (pre = head; pre->link != i; pre = pre->link)
				{
				}
				removed = pre->link;
				pre->link = removed->link;
			}
			i = i->link;
			delete removed;
		}
		else
			i = i->link;
	}
	return head;
}
diction* insert(diction* head, char str[], char str2[])//3번
{
	diction* pre = NULL;
	bool exist = false;

	for (diction* i = head; i != NULL; i = i->link)
	{
		if (strcmp(i->word, str) == 0)
		{
			cout << "이미 있는 단어입니다." << endl;
			return head;
		}
	}
	for (diction* i = head; i != NULL; i = i->link)
	{
		if (strcmp(i->word, str2) == 0)
		{
			diction* node = new diction;
			strcpy_s(node->word, 20, str);
			exist = true;
			if (i == head)
			{
				node->link = head;
				head = node;
			}
			else
			{
				for (pre = head; pre->link != i; pre = pre->link)
				{
				}
				node->link = pre->link;
				pre->link = node;
			}
		}
	}
	if (exist == false)
	{
		diction* node = new diction;
		strcpy_s(node->word, 20, str);
		for (pre = head; pre->link != NULL; pre = pre->link)
		{
		}
		node->link = pre->link;
		pre->link = node;
	}
	return head;
}
void print(diction* head)//4번
{
	int count = 0;

	for (diction* i = head; i != NULL; i = i->link)
	{
		cout << i->word << endl;
		++count;
	}
	cout << count << endl;
}