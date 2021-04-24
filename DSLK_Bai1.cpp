#include<iostream>
using namespace std;

//Khởi tạo

struct Node
{
	int data;
	Node* next;
};

Node* CreateNode(int init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;    
	return node;
}

struct LinkedList
{
	Node* head;
	Node* tail;
};

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

//a.	Thêm một nút vào đầu danh sách, vào cuối danh sách liên kết đơn. Xuát danh sách đã nhập.

void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}

void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}


//b.	Đếm số nút trong danh sách liên kết đơn.
int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

//c.	Tìm một nút có thành phần dữ liệu bằng X
Node* Search(LinkedList l, int x)
{
	Node* node = l.head;
	while (node != NULL && node->data != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

//d.	Xoá 1 nút đầu, cuối danh sách liên kết đơn.
int RemoveHead(LinkedList& l, int& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;      
		l.head = node->next;
		delete node;        
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

//e.	Hãy sắp xếp danh sách liên kết đơn giảm dần theo thành thành phần dữ liệu.








//Sắp xếp tăng dần

void SortList(LinkedList &list)
{

 for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext)
 {
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
  {
    if(pTmp->data>pTmp2->data)
     {
       int tmp=pTmp->data;
       pTmp->data=pTmp2->data;
       pTmp2->data=tmp;
     }
  }
 }
}




int main(){
    //Tạo node
    LinkedList list;
    CreateList(list);

    //Thêm nút
    Node* node;
	for (auto i = 1; i <= 10; i++)
	{
		node = CreateNode(i);
		// Thêm vào đầu
		AddHead(list, node);
		// Thêm vào cuối
		AddTail(list, node);
	}

    //Đếm nút
    int len = Length(list);
	cout << "Do dai: " << len << endl;

    //Tìm nút dữ liệu bằng X
    int x;
    cout<<"nhap du lieu X:";
    cin>>x;
    Node* searchX = Search(list, x);
	if (searchX != NULL)
		cout << "Co du lieu bang X" << endl;
	else
		cout << "Khong thay du lieu bang X" << endl;


    /*Xóa nút đầu
    res = RemoveHead(list, x);
	if (res)
	{
		cout << "Du lieu can xoa: " << x << endl;
		cout << "Danh sach da xoa nut dau: ";
		PrintList(list);
		cout << endl;
	}
	else
		cout << "Khong co gi de xoa" << endl;

*/

	//Chèn nút và sắp xếp tăng dần
	Node* node;
	for (auto i = 1; i <= 10; i++)
	{
		node = CreateNode(i);
		// Thêm vào đầu
		AddHead(list, node);
		//Sắp xếp 
		SortList(list);
	}


}


