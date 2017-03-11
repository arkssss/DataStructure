#include "NArray.h"


bool InitArray(Array & A,int dim,...){
	
	if(dim<1 || dim>MAX_ARRAY_SIZE) return false;
	A.dim=dim;
	A.bounds=(int *)malloc(dim * sizeof(int));
	//����ά�ȳ��ȵĻ���ַ 
	if(!A.bounds) return false;
	va_list ap;
	va_start(ap,dim);
	int ElemTotal=1;
	//����A.base�Ļ���ַ�Ĵ�С 
	for(int i=0;i<dim;i++){
		A.bounds[i]=va_arg(ap,int);
		if(A.bounds<0) return false;
		ElemTotal*= A.bounds[i];		
	}
	A.base=(ElemType *) malloc(ElemTotal*sizeof(ElemType));
	//��������ַ 
	if(!A.base) return false;
	A.constants=(int *) malloc(dim*sizeof(int));	
	//����Ci����ַ 
	if(!A.constants) return false;
	A.constants[dim-1]=1;
	for(int i=dim-2;i>=0;i--){
		A.constants[i]=A.constants[i+1]*A.bounds[i];
	}
	return true;
} 


bool Locate(Array A,va_list ap,int addr){
	addr=0;
	int ind=va_arg(ap,int);
	for(int i=0;i<A.dim;i++){
		if(ind<0 || ind>=A.bounds[i]) return false;
		addr+=A.constants[i]*ind;
	}
	
	return true;	
}

bool Value(Array A,ElemType &e ,...){
	if(!A.base){
	cout<<"Array does not exist!";
	return false;
	} 
	va_list ap;
	va_start(ap,e);
	int addr;
	if(!Locate(A,ap,addr)) return false;
	e=*(A.base+addr);
	va_end(ap);
	return true;
}

bool Assign(Array &A,ElemType e,...){
	if(!A.base){
	cout<<"Array does not exist!";
	return false;
	} 
	va_list ap;
	va_start(ap,e);	
	int addr;
	if(!Locate(A,ap,addr)) return false;
	*(A.base+addr)=e;
	va_end(ap);	
	return true;
	
}

bool Destory(Array &A){
	
	if(!A.base) return false; 
	free(A.base); A.base=NULL;

	if(!A.bounds) return false; 
	free(A.bounds); A.bounds=NULL;
	
	if(!A.constants) return false; 
	free(A.constants); A.constants=NULL;

	
}















