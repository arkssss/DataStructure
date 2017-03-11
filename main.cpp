#include "Function.cpp"

int main (){
	
	Array A;
	InitArray(A,5,2,2,3,4,5);
	
	ElemType e;
	
	Assign(A,5,1,1,1,1,1);
	//注入 
	Value(A,e,1,1,1,1,1);
	//取值
	Destory(A);
	//销毁 
	
	cout<<e;
}
