#define N_ORTR 9
#include<stack>
typedef enum{ADD,SUB,MUL,DIV,POW,FAC,L_P,R_P,EOE} Operator;
const char pri[N_ORTR][N_OPTR]={
'>','>','<','<','<','<','<','>','>',
'>','>','<','<','<','<','<','>','>',
'>','>','>','>','<','<','<','>','>',
'>','>','>','>','<','<','<','>','>',
'>','>','>','>','>','<','<','>','>',
'>','>','>','>','>','>','<','>','>',
'<','<','<','<','<','<','<','=',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',
'<','<','<','<','<','<','<',' ','=',
};
float evaluate(char *S,char*&RPN)
{
	stack<float> opnd;
	stack<char> optr;
	optr.push('\0');
	while(!optr.empty())
	{
		if(isdigit(*S))
		{
			readNumber(S,opnd);
			append(RPN,opnd.top());
		}else{
			switch(orderBetween(optr.top(),*S))
			{
				case '<':
					optr.push(*S);
					S++;
					break;
				case '=':
					optr.pop();
					S++;
					break;
				case '>':
					char op = optr.top();
					optr.pop();
					append(RPN,op);
					if('!'==op)
					{
						float pOpnd = opnd.top();
						opnd.pop();
						opnd.push(calcu(op,pOpnd));
					}else{
						float pOpnd2 = opnd.top();
						opnd.pop();
						pOpnd1 = opnd.top();
						opnd.pop();
						opnd.push(calcu(pOpnd1,op,pOpnd2));
					}
			}
		}
	}
}
