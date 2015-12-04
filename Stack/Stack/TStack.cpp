#include "TStack.h"

TStack::TStack()
{
	Top = -1;
	Size = MemSize;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		pMem[i] = 0;
	}
}

TStack::TStack(int s)
{
	Top = -1;
	Size = s;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		pMem[i] = 0;
	}
}

TStack::~TStack()
{
	delete[]pMem;
}

TStack::TStack(const TStack &s)
{
	Top = s.Top;
	Size = s.Size;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		pMem[i] = s.pMem[i];
	}
}

bool TStack::IsEmpty() const // провекра пустоты
{
	if (Top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TStack::IsFull() const // проверка переполения
{
	if (Top == Size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TStack::Push(int Val)
{
	if (this->IsFull())
	{
		throw "Stack is Full";
	}
	Top++;
	pMem[Top] = Val;
}

int TStack::Peek() const
{
	return pMem[Top];
}


int TStack::Pop()
{
	if (this->IsEmpty())
	{
		throw "Stack is Empty";
	}
	Top--;
	return pMem[Top+1];
}
