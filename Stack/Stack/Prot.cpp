#include "Prot.h"
#include "TStack.h"
bool OPZ(char *str, char out[])
{
	char *znak = "+-*/";
	int Prior[] = { 1, 1, 2, 2 };
	    //• ^    высокий
		//• *, / средний
		//• +,-  низкий
		//• ()   самый низкий
	TStack Op;
	int i = 0;
	int j = 0;
	if (strlen(str) < 3) //проверяем, что в строке должно быть как минимум 2 числа и операция
	{
		return false;
	}
	if (strchr(znak, str[0])) // проверка того, что нулевой элемент не может быть знаком
	{ // поиск знака в строке str[];
		return false;
	}

	while (str[i] != NULL)
	{
		if (isdigit(str[i])) //isdigit() -  проверяет, является ли сивол цифрой
		{
			out[j] = str[i]; //засунули число в выходную строку
			j++;
		}
		else if (strchr(znak, str[i])) //проверяет наличие символа str[i] в строке знак
		{
			if (strchr(znak, str[i - 1])) //проверка на 2 знака подряд
			{
				return false;
			}

			if (!(Op.IsEmpty())) // если в стеке что то есть, то .....
			{
				int P1 = Prior[strchr(znak, str[i]) - znak]; // индекс в приоритете определяется как разность  2-х указателей
				int P2 = Prior[strchr(znak, Op.Peek()) - znak]; // смотрим приоритет операции на вершине стека

				if (P1 <= P2)
				{
					out[j] = Op.Pop(); // выталкиваем верхний элемент стека в выходную строку
					j++;
				}
			}
			Op.Push(str[i]); //помещаем в стек 
		}
		else
		{
			return false;
		}
		i++;
	}
	while (!(Op.IsEmpty()))
	{
		out[j] = Op.Pop(); //берем из стека верхний символ и добавляем в строку
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
		if (isdigit(out[i])) //isdigit() -  проверяет, является ли сивол цифрой
		{
			Op.Push(out[i]); // помещаем в стек 
		}
		else
		{
			int a, b;
			a = Op.Pop() - '0'; // выбираем операнды из стека
			b = Op.Pop() - '0'; // и вычитаем 0 для преобразования из символов число
			switch (out[i]) //выполняем вычисления
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
	return Op.Pop(); // возвращет результат вычислений
}
