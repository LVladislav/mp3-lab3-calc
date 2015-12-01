#pragma once
#include <iostream>
using namespace std;
#define MemSize 30

class TStack
{
private:
	int *pMem;
	int Size; // размер стека
	int Top; // верхушка стека
public:
	TStack(); // конструктор по умолчанию
	TStack(int n); // инициализирующий конструктор
	TStack(const TStack &s); // конструктор копирования
	~TStack();

	bool IsFull(void) const; // проверка переполнения
	bool IsEmpty(void) const; // проверка пустоты

	void Push(const int Val); // положить элемент в стек
	int Peek(void) const; // посмотреть элемент  вверхушке стека
	int Pop(void); // извлечь значение с верхушки стека
};