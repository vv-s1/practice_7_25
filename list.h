#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//双向链表节点结构体
typedef struct Node//表示双向链表的节点，每个节点包含三个成员
{
	int data;//存储节点的数据
	struct Node* prev;//指向前一个节点的指针
	struct Node* next;//指向下一个节点的指针
}Node;

//双向链表结构体
typedef struct DoublyLinkedList//表示双链表，包含两个成员
{
	Node* head;//指向链表头节点的指针
	int count;//存储链表中的节点数量
}DoublyLinkedList;

void initList(DoublyLinkedList* list);//初始化链表
Node* createNode(int data);//创建新节点
void insertAtHead(DoublyLinkedList* list, int data);//在链表头部插入节点
void insertAtTail(DoublyLinkedList* list, int data);//在链表尾部插入节点
void insertAtPosition(DoublyLinkedList* list, int data, int position);//在指定的位置插入节点
void printList(DoublyLinkedList* list);//正向遍历链表
void reversePrintList(DoublyLinkedList* list);//反向遍历链表
Node* searchNode(DoublyLinkedList* list, int key);//查找节点
void deleteNode(DoublyLinkedList* list, Node* delNode);//删除节点
void mergeLists(DoublyLinkedList* list1, DoublyLinkedList* list2);//合并两个链表
void sortList(DoublyLinkedList* list);//链表排序
void reverseList(DoublyLinkedList* list);//逆序链表
void splitList(DoublyLinkedList* list, int position, DoublyLinkedList* newList);//分割链表
Node* getNodeAt(DoublyLinkedList* list, int index);//通过索引访问节点
int* toArray(DoublyLinkedList* list);//链表转数组
void fromArray(DoublyLinkedList* list, int* array, int size);//从数组构建链表
void saveListToFile(DoublyLinkedList* list, const char* filename);//保存链表到文件功能
void loadListFromFile(DoublyLinkedList* list, const char* filename);//从文件中加载链表
DoublyLinkedList* coloneList(DoublyLinkedList* list);//克隆链表
int hasDouplicates(DoublyLinkedList* list);//检查链表是否有重复节点
void removeDouplicates(DoublyLinkedList* list);//删除链表中重复的节点

void freeList(DoublyLinkedList* list);//释放链表