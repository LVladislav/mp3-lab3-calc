#include "Prot.h"
#include "TStack.h"
bool OPZ(char *str, char out[])
{
	char *znak = "+-*/";
	int Prior[] = { 1, 1, 2, 2 };
	    //� ^    �������
		//� *, / �������
		//� +,-  ������
		//� ()   ����� ������
	TStack Op;
	int i = 0;
	int j = 0;
	if (strlen(str) < 3) //���������, ��� � ������ ������ ���� ��� ������� 2 ����� � ��������
	{
		return false;
	}
	if (strchr(znak, str[0])) // �������� ����, ��� ������� ������� �� ����� ���� ������
	{ // ����� ����� � ������ str[];
		return false;
	}

	while (str[i] != NULL)
	{
		if (isdigit(str[i])) //isdigit() -  ���������, �������� �� ����� ������
		{
			out[j] = str[i]; //�������� ����� � �������� ������
			j++;
		}
		else if (strchr(znak, str[i])) //��������� ������� ������� str[i] � ������ ����
		{
			if (strchr(znak, str[i - 1])) //�������� �� 2 ����� ������
			{
				return false;
			}

			if (!(Op.IsEmpty())) // ���� � ����� ��� �� ����, �� .....
			{
				int P1 = Prior[strchr(znak, str[i]) - znak]; // ������ � ���������� ������������ ��� ��������  2-� ����������
				int P2 = Prior[strchr(znak, Op.Peek()) - znak]; // ������� ��������� �������� �� ������� �����

				if (P1 <= P2)
				{
					out[j] = Op.Pop(); // ����������� ������� ������� ����� � �������� ������
					j++;
				}
			}
			Op.Push(str[i]); //�������� � ���� 
		}
		else
		{
			return false;
		}
		i++;
	}
	while (!(Op.IsEmpty()))
	{
		out[j] = Op.Pop(); //����� �� ����� ������� ������ � ��������� � ������
		j++;
	}
	out[j] = 0;
	return true;
}


int Calc(char out[])
{
	TStack Op;
	int i = 0;
	while (out[i] != NULL)
	{
		if (isdigit(out[i])) //isdigit() -  ���������, �������� �� ����� ������
		{
			Op.Push(out[i]); // �������� � ���� 
		}
		else
		{
			int a, b;
			a = Op.Pop() - '0'; // �������� �������� �� �����
			b = Op.Pop() - '0'; // � �������� 0 ��� �������������� �� �������� �����
			switch (out[i]) //��������� ����������
			{
			case '+':
				Op.Push(b + a);
				break;
			case '-':
				Op.Push(b - a);
				break;
			case '*':
				Op.Push(b * a);
				break;
			case '/':
				Op.Push(b / a);
				break;
			default:
				break;
			}
		}
		i++;
	}
	return Op.Pop(); // ��������� ��������� ����������
}
