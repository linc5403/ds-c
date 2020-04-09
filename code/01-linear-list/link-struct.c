#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char* data; // 字符串
    struct node* next; // 下一个节点
} Node;

void printList(Node* plist) {
    if (plist == NULL) {
        // 传进来的是个空指针，表示list还没有初始化
        printf("plist没有初始化\n");
        return;
    }
    
    // 打印当前节点的data部分，再找到下一个节点，直到没有下一个节点
    while(plist != NULL) {
        printf("%s", plist->data);
        printf("->");
        plist = plist->next;
    }
    
    printf("NULL\n");
}

Node* addAtPos(int pos, char* food, Node* head){
    // pos , food
    // modify list
    // new block
    Node* newNode = malloc(sizeof(Node));
    newNode->data = food;
    if (pos == 0) {
        // 新增的节点在表头
        newNode->next = head;
        return newNode;
    }
    
    Node* temp = head;
    // pos 1 : head->next = newNode;
    // pos 2 : head->next->next = newNode;
    // pos == 2 那么需要偏移1次
    // pos == 3 偏移两次
    while(temp->next != NULL && pos > 1){
        temp = temp->next;
        pos--;
    }
    if (pos > 1) {
        // 插入的位置超过链表的长度，非法输入
        printf("插入的位置超过链表的长度，非法输入\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* delAtPos(int pos, Node* head) {
    if (head == NULL) {
        //空链表
        printf("空链表无法删除任何节点\n");
        return NULL;
    }
    
    if (pos == 0) {
        // 删除头节点
        Node* temp = head->next;
        free(head);
        return temp;
    }
    
    Node* temp = head;
    // 找到pos的上一个节点
    while((pos > 1) && (temp != NULL)) {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL || temp->next == NULL) {
        // 出错啦
        printf("删除的位置超过链表的长度，非法输入\n");
        return head;
    }
    // 删除temp的下一个
    Node* t = temp->next;
    temp->next = t->next;
    free(t);
    return head;
}

int main() {
    // 初始化头结点
    Node* head = NULL; // head表示第一个节点的指针
    printList(head);
    
    // 放鸡蛋
    Node* egg = malloc(sizeof(Node));
    egg->data = "鸡蛋";
    egg->next = NULL;
    
    head = egg;
    
    printList(head);
    
    // 放苹果
    Node* apple = malloc(sizeof(Node));
    apple->data = "苹果";
    apple->next = NULL;
    egg->next = apple;
    //apple->next = egg;
    //head = apple;
    printList(head);
    
    // 放牛奶
    Node* milk = malloc(sizeof(Node));
    milk->data = "牛奶";
    milk->next = NULL;
    apple->next = milk;
    printList(head);
    
    head = addAtPos(3, "花生", head);
    printList(head);
    
    head = delAtPos(4,head);
    printList(head);
}

