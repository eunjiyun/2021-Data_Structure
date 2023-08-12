//6
//#include<iostream>
//using namespace std;
//class person_arr
//{
//public:
//	string name;
//	int age;
//	string id;
//	int team;
//	int score;
//};
//person_arr who[20] = { {"Lee JY",17,"jylee",5,83},{"Yoon JH",55,"wulong",5,66},{"Song IH",18,"ihsong",5,17}, {"Kong KS",43,"kskong",5,42},
//{"Chang JW",24,"jwc",2,54},{"Lee HG",44,"hgl",7,78},{"Lee YH",42,"louis",7,32}, {"Ko HJ",47,"hjko",7,22},
//{"Kim JK",42,"doublepar",13,82},{"Oh WS",55,"oh",13,46},{"Lim CJ",29,"scjlim",13,15}, {"Kim YS",55,"kimys",13,66},
//{"Kim YS",52,"ysjun",13,93},{"Lee DH",46,"dustin",9,73},{"Jung NH",42,"nhjung",8,29}, {"Jin HS",33,"hsjin",8,82},
//{"Kim KC",17,"ken",8,27},{"Sung WJ",22,"wjsung",15,32},{"Lee JY",64,"jay",15,73}, {"Kim YS",55,"yes",15,60} };
//class person_link
//{
//public:
//	string name;
//	int age;
//	string id;
//	int team;
//	int score;
//	person_link* link;
//};
//person_link* linked(person_link* head);
//void printAll(person_link* head);
//void SearchByID_List(person_link* head, string id);
//int main()
//{
//	person_link* head = nullptr;
//	head = linked(head);
//	string id;
//	printAll(head);
//
//	cout << "id: ";
//	cin >> id;
//	SearchByID_List(head, id);
//	return 0;
//}
//person_link* linked(person_link* head)
//{
//	for (int i = 0; i < 20; ++i)
//	{
//		person_link* champ = new person_link;
//		champ->name = who[i].name;
//		champ->age = who[i].age;
//		champ->id = who[i].id;
//		champ->team = who[i].team;
//		champ->score = who[i].score;
//
//		if (head == NULL)
//		{
//			head = champ;
//			//head->link = champ;
//		}
//		else
//		{
//			champ->link = head->link;
//			head->link = champ;
//			head = champ;
//		}
//	}
//	return head;
//}
//void printAll(person_link* head)
//{
//	person_link* champ = nullptr;
//
//	for (champ = head->link; champ != head; champ = champ->link)
//	{
//		cout << "name: " << champ->name << endl;
//		cout << "age: " << champ->age << endl;
//		cout << "id: " << champ->id << endl;
//		cout << "team: " << champ->team << endl;
//		cout << "score: " << champ->score << endl << endl;
//	}
//		cout << "name: " << champ->name << endl;
//		cout << "age: " << champ->age << endl;
//		cout << "id: " << champ->id << endl;
//		cout << "team: " << champ->team << endl;
//		cout << "score: " << champ->score << endl << endl;
//}






//7
#include<iostream>
using namespace std;
class person_arr
{
public:
	string name;
	int age;
	string id;
	int team;
	int score;
};
person_arr who[20] = { {"Lee JY",17,"jylee",5,83},{"Yoon JH",55,"wulong",5,66},{"Song IH",18,"ihsong",5,17}, {"Kong KS",43,"kskong",5,42},
{"Chang JW",24,"jwc",2,54},{"Lee HG",44,"hgl",7,78},{"Lee YH",42,"louis",7,32}, {"Ko HJ",47,"hjko",7,22},
{"Kim JK",42,"doublepar",13,82},{"Oh WS",55,"oh",13,46},{"Lim CJ",29,"scjlim",13,15}, {"Kim YS",55,"kimys",13,66},
{"Kim YS",52,"ysjun",13,93},{"Lee DH",46,"dustin",9,73},{"Jung NH",42,"nhjung",8,29}, {"Jin HS",33,"hsjin",8,82},
{"Kim KC",17,"ken",8,27},{"Sung WJ",22,"wjsung",15,32},{"Lee JY",64,"jay",15,73}, {"Kim YS",55,"yes",15,60} };
int length = 20;
class person_link
{
public:
	string name;
	int age;
	string id;
	int team;
	int score;
	person_link* link;
};
person_link* linked(person_link* head);
void printAll(person_link* head);
void SearchByID_List(person_link* head, string id);
person_link* InsertSpecial_List(person_link* head, string input_id);
int main()
{
	string id;
	int choose = 0;
	person_link* head = nullptr;
	head = linked(head);
	printAll(head);

	while (choose != 11)
	{
		cout << "11.종료" << endl;
		cout << "9.계속" << endl;
		cout << "choose: ";
		cin >> choose;
		if (choose == 9)
		{
			cout << "id: ";
			cin >> id;
			head = InsertSpecial_List(head, id);
		}
		else if (choose == 8)
		{
			cout << "id: ";
			cin >> id;
			head = InsertSpecial_List(head, id);
		}
		else if (choose == 1)
			break;
	}
	return 0;
}
person_link* linked(person_link* head)
{
	for (int i = 0; i < 20; ++i)
	{
		person_link* champ = new person_link;
		champ->name = who[i].name;
		champ->age = who[i].age;
		champ->id = who[i].id;
		champ->team = who[i].team;
		champ->score = who[i].score;

		if (head == NULL)
		{
			head = champ;
			head->link = champ;
		}
		else
		{
			champ->link = head->link;
			head->link = champ;
			head = champ;
		}
	}
	return head;
}
void printAll(person_link* head)
{
	person_link* champ = nullptr;

	for (champ = head->link; champ != head; champ = champ->link)
	{
		cout << endl << "name: " << champ->name << endl;
		cout << "age: " << champ->age << endl;
		cout << "id: " << champ->id << endl;
		cout << "team: " << champ->team << endl;
		cout << "score: " << champ->score << endl << endl;
	}
	cout << endl << "name: " << champ->name << endl;
	cout << "age: " << champ->age << endl;
	cout << "id: " << champ->id << endl;
	cout << "team: " << champ->team << endl;
	cout << "score: " << champ->score << endl << endl;
}
void SearchByID_List(person_link* head, string id)
{
	person_link* champ = nullptr;

	for (champ = head->link; champ != head; champ = champ->link)
	{
		if (champ->id == id)
		{
			cout << "name: " << champ->name << endl;
			cout << "age: " << champ->age << endl;
			cout << "id: " << champ->id << endl;
			cout << "team: " << champ->team << endl;
			cout << "score: " << champ->score << endl << endl;
		}
	}
	if (champ->id == id)
	{
		cout << "name: " << champ->name << endl;
		cout << "age: " << champ->age << endl;
		cout << "id: " << champ->id << endl;
		cout << "team: " << champ->team << endl;
		cout << "score: " << champ->score << endl << endl;
	}
}
person_link* InsertSpecial_List(person_link* head, string input_id)
{

	int count = 0;


	person_link* champ = new person_link;
	person_link* i = nullptr;
	person_link* pre = nullptr;

	cout << "name: ";
	cin >> champ->name;
	cout << "age: ";
	cin >> champ->age;
	cout << "id: ";
	cin >> champ->id;
	cout << "team: ";
	cin >> champ->team;
	cout << "score: ";
	cin >> champ->score;

	for (i = head->link; i != head; i = i->link)
	{
		if (i->id == champ->id)
		{
			cout << "이미 존재하는 id입니다." << endl;
			printAll(head);
			return head;
		}
	}
	if (i->id == champ->id)
	{
		cout << "이미 존재하는 id입니다." << endl;
		printAll(head);
		return head;
	}
	for (i = head->link; i != head; i = i->link)
	{
		if (i->id == input_id)
		{
			for (pre = i; pre->link != i; pre = pre->link)
			{
			}
			champ->link = pre->link;
			pre->link = champ;
			++length;
			//break;
			printAll(head);
			return head;
		}
		else
			++count;
	}
	if (i->id == input_id)
	{
		for (pre = i; pre->link != i; pre = pre->link)
		{
		}
		champ->link = pre->link;
		pre->link = champ;
		++length;
		//break;
		printAll(head);
		return head;
	}
	else
		++count;

	if (count == length)
	{
		cout << "맨뒤에 입력합니다." << endl;
		champ->link = head->link;
		head->link = champ;
		head = champ;
		++length;
		printAll(head);
		return head;
	}
	/*printAll(head);
	return head;*/
}
void SearchByID_List(person_link* head, string id)
{
	person_link* champ = nullptr;

	for (champ = head->link; champ != head; champ = champ->link)
	{
		if (champ->id == id)
		{
			cout << "name: " << champ->name << endl;
			cout << "age: " << champ->age << endl;
			cout << "id: " << champ->id << endl;
			cout << "team: " << champ->team << endl;
			cout << "score: " << champ->score << endl << endl;
		}
	}
	if (champ->id == id)
	{
		cout << "name: " << champ->name << endl;
		cout << "age: " << champ->age << endl;
		cout << "id: " << champ->id << endl;
		cout << "team: " << champ->team << endl;
		cout << "score: " << champ->score << endl << endl;
	}
}