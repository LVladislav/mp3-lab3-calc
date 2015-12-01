#pragma once
#include <iostream>
using namespace std;
#define MemSize 30

class TStack
{
private:
	int *pMem;
	int Size; // ������ �����
	int Top; // �������� �����
public:
	TStack(); // ����������� �� ���������
	TStack(int n); // ���������������� �����������
	TStack(const TStack &s); // ����������� �����������
	~TStack();

	bool IsFull(void) const; // �������� ������������
	bool IsEmpty(void) const; // �������� �������

	void Push(const int Val); // �������� ������� � ����
	int Peek(void) const; // ���������� �������  ��������� �����
	int Pop(void); // ������� �������� � �������� �����
};