#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,prior,size;
	struct node *l,*r,*p;
};
typedef node* pnode;
int sz(pnode t){
	return t?t->size:0;
}
void upd_sz(pnode t){
	if(t)t->size=sz(t->l)+1+sz(t->r);
}

void refresh(pnode &t){
	if(!t)
		return;
		upd_sz(t);
	if(t->l)
		t->l->p = t;
	if(t->r)
		t->r->p=t;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
	if(!t)return void(l=r=NULL);
	int curr_pos = add + sz(t->l);
	if(curr_pos<=pos)  // "<=" . element at pos goes to left subtree(l)
		split(t->r,t->r,r,pos,curr_pos+1),l=t;
	else
		split(t->l,l,t->l,pos,add),r=t;
	refresh(l);
	refresh(r);
	refresh(t);
	upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r) {//l->leftarray,r->rightarray,t->resulting array
	if(!l || !r) {
		refresh(l) ; refresh(r);
		t = l?l:r;
	}
	else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
	else    merge(r->l,l,r->l),t=r;
	refresh(l) ; refresh(r);
	refresh(t);
	upd_sz(t);
}
pnode init(int val){
	pnode temp = new node();
	temp->val = val;
	temp->l=temp->r=temp->p = NULL;
	temp->prior= rand();
	temp->size=1;
	return temp;
}
void show(pnode t){
	if(!t)
		return;
	show(t->l);
	printf("%d\n",t->val);
	//show(t->l);
	show(t->r);
}
const int size = 1e5 + 9;
pnode A[size];
pnode root;
int main(){
	srand(time(NULL));
	int t;
	cin>>t;
	int pos = 0;
	int cnt = 0;
	while(t--){
		char c;
		cin>>c;
		if(c=='O'){
			int x;
			cin>>x;
			x--;
			pnode temp = A[x];
		 int sum = sz(temp->l);
			while(temp!=root){
				pnode t = temp->p;
				if(temp==t->r)
					sum += sz(t->l)+1;
				temp = t;
			}
			int sum2 = pos - sum - 1;
			pnode l,r,r1;
			//cout<<sum<<" "<<pos<<" "<<sum2<<endl;
//			show(root);
	//		cout<<endl;
			split(root,l,r,sum-1);
		//	show(l);
	//		cout<<endl;
	//		show(r);
		//	cout<<endl;
			printf("%d\n",min(sum2,sum));
			split(r,r1,r,0);
	//		show(l);
		//	cout << endl;
	//		show(r);
		//	cout << endl;
			
			merge(root,r,l);
		//	show(root);
	//		cout << endl;
			pos--;
		}
		else{
			if(c=='F'){
				if(root==NULL){
					root = init(pos);
					A[cnt++] = root;
				}
				else{
					pnode temp = init(pos);
					A[cnt++] = temp;
					merge(root,temp,root);
				}
			}
			else{
				if(root==NULL){
					root = init(pos);
					A[cnt++] = root;
				}
				else{
					pnode temp = init(pos);
					A[cnt++] = temp;
					merge(root,root,temp);
				}
			}
			pos++;
		}
	}
}
