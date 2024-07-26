#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//˫������ڵ�ṹ��
typedef struct Node//��ʾ˫������Ľڵ㣬ÿ���ڵ����������Ա
{
	int data;//�洢�ڵ������
	struct Node* prev;//ָ��ǰһ���ڵ��ָ��
	struct Node* next;//ָ����һ���ڵ��ָ��
}Node;

//˫������ṹ��
typedef struct DoublyLinkedList//��ʾ˫��������������Ա
{
	Node* head;//ָ������ͷ�ڵ��ָ��
	int count;//�洢�����еĽڵ�����
}DoublyLinkedList;

void initList(DoublyLinkedList* list);//��ʼ������
Node* createNode(int data);//�����½ڵ�
void insertAtHead(DoublyLinkedList* list, int data);//������ͷ������ڵ�
void insertAtTail(DoublyLinkedList* list, int data);//������β������ڵ�
void insertAtPosition(DoublyLinkedList* list, int data, int position);//��ָ����λ�ò���ڵ�
void printList(DoublyLinkedList* list);//�����������
void reversePrintList(DoublyLinkedList* list);//�����������
Node* searchNode(DoublyLinkedList* list, int key);//���ҽڵ�
void deleteNode(DoublyLinkedList* list, Node* delNode);//ɾ���ڵ�
void mergeLists(DoublyLinkedList* list1, DoublyLinkedList* list2);//�ϲ���������
void sortList(DoublyLinkedList* list);//��������
void reverseList(DoublyLinkedList* list);//��������
void splitList(DoublyLinkedList* list, int position, DoublyLinkedList* newList);//�ָ�����
Node* getNodeAt(DoublyLinkedList* list, int index);//ͨ���������ʽڵ�
int* toArray(DoublyLinkedList* list);//����ת����
void fromArray(DoublyLinkedList* list, int* array, int size);//�����鹹������
void saveListToFile(DoublyLinkedList* list, const char* filename);//���������ļ�����
void loadListFromFile(DoublyLinkedList* list, const char* filename);//���ļ��м�������
DoublyLinkedList* coloneList(DoublyLinkedList* list);//��¡����
int hasDouplicates(DoublyLinkedList* list);//��������Ƿ����ظ��ڵ�
void removeDouplicates(DoublyLinkedList* list);//ɾ���������ظ��Ľڵ�

void freeList(DoublyLinkedList* list);//�ͷ�����