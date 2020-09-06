#include <bits/stdc++.h>
#define ll long long
//Implementation of BST
using namespace std;
class Node{
   
        int val;
        Node * left;
        Node * right;
        public:
        Node(){
           left = NULL;
           right = NULL;
        }
        Node * newNode(int val){
            Node * a = new Node();
            a->val = val;
            a->left = NULL;
            a->right = NULL;
            return a;
        }
        void setleft(Node* a){
            this->left = a;
        }
        void setright(Node * a){
            this->right = a;
        }
        Node* getleft(){
            return left;
        }
        Node* getright(){
            return right;
        }
        int getval(){
            return val;
        }
};

class BST{
    public:
        void insert(Node *N,Node* I){
            if(N == NULL){
                N = I;
            }
            if(I==NULL){
                return ;
            }
            if((N->getval()) > (I->getval()) ){
                if(N->getleft() == NULL){
                    N->setleft(I) ;
                    return;
                }
                insert(N->getleft(),I);
            }
            if((N->getval()) < (I->getval())){
                if(N->getright() == NULL){
                    N->setright(I);
                }
                insert(N->getright(),I);
            }
            return ;
        }
        int max(int a,int b){
            return a>b?a:b;
        }
        void del(Node* N,int val){
            if(N->getval() == val){
                Node * t = N->getleft();
                N = N->getright();
                insert(N,t);
                return;
                
            }
           if(N->getval() > val){
               if(N->getleft()->getval() == val){
                Node*t = (N->getleft())->getleft();
                N->setleft( N->getleft()->getright());
                insert(N,t);
                return;
               }
               del(N->getleft(),val);
           }
           else if(N->getval() < val){
               if((N->getright())->getval() == val){
                   Node *t = (N->getright())->getleft();
                   N->setright((N->getright())->getright()) ;
                   insert(N,t);
                   return;
               }
               del(N->getright(),val);
           }
        }
        void inorder(Node * N,int index,int i=1){
            if(N == NULL){
                return;
            }
            
            inorder(N->getleft(),index,i+1);
            if(i == index){
                cout<<N->getval()<<" ";
            }
            inorder(N->getright(),index,i+1);
        }
        // void inorder(Node * N,int index,int i=1){
        //     if(N == NULL){
        //         return;
        //     }
            
        //     inorder(N->getleft(),index,i+1);
        //     if(i == index){
        //         cout<<N->getval()<<" ";
        //         res = 1;
        //     }
        //     inorder(N->getright(),index,i+1);
        // }
        int height(Node * N,int i=0,int mx = 0){
            
            if(N==NULL){
                return max(i,mx);
            }
            mx = height(N->getleft(),i+1,mx);
            mx = height(N->getright(),i+1,mx);
            return max(i,mx);
        }
        void leaf(Node *N){
            if(N->getleft()==NULL && N->getright()==NULL){
                cout<<N->getval()<<" ";
                return;
            }
            if(N->getleft()!=NULL)
                leaf(N->getleft());
            if(N->getright()!=NULL)
                leaf(N->getright());
        }
        // void bulkInsertion(int *a[],int n,Node* root){
            
        //     for(int i=0;i<n;i++){
        //         Node * t = newNode(a[i]);
        //         insert(root,t);
        //     }
        // }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	BST b1;
	Node n1;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Node *root = n1.newNode(a[0]);
    Node *a1 = NULL;
    for(int i=1;i<n;i++){
        a1 = n1.newNode(a[i]);
        b1.insert(root,a1);
    }
    int h = b1.height(root);
    int i=1;
    while(i<=h){
        b1.inorder(root,i);
        cout<<"\n";
        i++;
    }
    
    // cout<<h<<"\n";
	return 0;
}

