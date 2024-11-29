#include <iostream>
#include <string>
using namespace std;

struct sanpham{
	string name[100];
	int sl;
};

// Định nghĩa cấu trúc Node (mỗi khách hàng là một node)
struct Node {
    string customerName;    // Tên khách hàng
    string foodName;
    int productCount;       // Số lượng sản phẩm của khách hàng
    int price;
	Node* next;             // Con trỏ trỏ đến node tiếp theo
};

// Định nghĩa hàng đợi
struct Queue {
    Node* front;  // Con trỏ đầu hàng đợi
    Node* rear;   // Con trỏ cuối hàng đợi
};

// Khởi tạo hàng đợi
void initQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

// Hàm kiểm tra hàng đợi rỗng
bool isEmpty(Queue q) {
    return (q.front == nullptr);
}

// Hàm thêm khách hàng vào hàng đợi (enqueue)
void enqueue(Queue& q, string name, string name_pro, int productCount, int price) {
    Node* newNode = new Node;       // Tạo node mới
    newNode->customerName = name;
    newNode->foodName=name_pro;
    newNode->productCount = productCount;
    newNode->price=price;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q.front = newNode;         
        q.rear = newNode;
    } else {
        q.rear->next = newNode;    
        q.rear = newNode;           // Cập nhật node cuối
    }
}

// Hàm in hàng đợi (để kiểm tra)
void printQueue(Queue q) {
    Node* temp = q.front;
    while (temp != nullptr) {
        cout << "Khach hang: " << temp->customerName 
             << ", Ten san pham: " << temp->foodName 
			 << ", So luong san pham: "<< temp->productCount
			 << ", Gia tien: "<<temp->price
			 << ", Tong tien: "<<temp->price*temp->productCount<<endl;
        temp = temp->next;
    }
}
// Hàm loại bỏ khách hàng khỏi hàng đợi (dequeue)
void dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong, khong co khach hang nao de xoa!" << endl;
        return;
    }

    Node* temp = q.front;       // Lưu lại node đầu để xóa
    q.front = q.front->next;    // Di chuyển con trỏ front đến node tiếp theo

    if (q.front == nullptr) {   // Nếu hàng đợi trống sau khi xóa
        q.rear = nullptr;
    }

    delete temp;                // Giải phóng bộ nhớ
//    cout << "Da xoa mot khach hang khoi hang doi." << endl;
}
int main() {
    Queue q;
    initQueue(q);

    // Thêm khách hàng vào hàng đợi
    enqueue(q, "User 1", "Fruit", 5 , 500);
    enqueue(q, "User 2", "Snack", 10 , 10);
    enqueue(q, "User 3", "Rice", 1 , 1000);

    cout << "Danh sach khach hang trong hang doi:" << endl;
    printQueue(q);

    // Loại bỏ khách hàng
	dequeue(q);
    cout << "\nDanh sach sau khi xoa khach hang:" << endl;
    printQueue(q);

    return 0;
}
