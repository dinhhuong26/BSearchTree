#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;
struct Node {
	int data;
	Node* Rnode, * Lnode;
 };
typedef Node* BsearchTree;
typedef Node* Pnode;

void khoitao (BsearchTree &A){
	A = NULL;
}

void Insert(BsearchTree& A, int k) {
	Pnode P = new Node;
	P->data = k;
	if (A == NULL) {
		P->Lnode = NULL;
		P->Rnode = NULL;
		A = P;
	}
	else {
		if (k < A->data) {
			Insert(A->Lnode, k);
		}
		else {
			Insert(A->Rnode, k);
		}
	}
}

void print(BsearchTree A, int a){
	if(a==A->data){
	   if(A->Lnode!=NULL){
	   	cout<<setw(5)<<A->Lnode->data;
	   }
	   else{
	   	cout<<setw(5)<<"x";
	   }
	   cout<<" <-- "<<setw(3)<<a<<" --> ";
	   if(A->Rnode!=NULL){
	   	cout<<A ->Rnode ->data;
	   }
	   else{
	   	cout<<"x";
	   }
	   cout<<endl;
	}
	else if(a<A->data){
		print(A->Lnode,a);
	}
	else{
		print(A->Rnode,a);
	}
	
}
void duyettruoc(BsearchTree A){
	if(A==NULL){
		return;
	}
	cout<<"    "<<A->data;
	duyettruoc(A->Lnode);
	duyettruoc(A->Rnode);
}
void duyetsau(BsearchTree A){
	if(A==NULL){
		return;
	}
	duyetsau(A->Lnode);
	duyetsau(A->Rnode);
	cout<<"    "<<A->data;
}
void duyetgiua(BsearchTree A){
	if(A==NULL){
		return;
	}
	duyetgiua(A->Lnode);
	cout<<"    "<<A->data;
	duyetgiua(A->Rnode);
}
int main(){
	int n;
	BsearchTree A;
	khoitao(A);
	cout<<"nhap so phan tu: ";
	cin>>n;
	int *b = new int[n];
	for(int i =0; i<n;i++){
		cout<<"a["<<i<<"]= ";
		cin>>b[i];
	}
	for(int i =0; i<n;i++){
		Insert(A,b[i]);
	}
	cout<<"Cay nhi phan tim kiem"<<endl;
	for(int i =0; i<n;i++){
		print(A,b[i]);
	}
	cout<<endl<<"duyet truoc: "<<endl;
	duyettruoc(A);
	cout<<endl<<"duyet sau: "<<endl;
	duyetsau(A);
	cout<<endl<<"duyet giua: "<<endl;
	duyetgiua(A);
}
