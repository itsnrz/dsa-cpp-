#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isValid(vector<int>&b,int p,int bno,int maxallow){
	int pan=1,size=0;
    for(int i=0;i<bno;i++){
		if(b[i]>maxallow)return false;
		if((size+b[i])<=maxallow)size+=b[i];
		else{
			pan++;
			size=b[i];
		}
	}
	return pan>p?false:true;
}
int minTime(vector<int>&b,int p){// b is array of size of boards , p is number of painter
     int bno=b.size(),st=0,e=0,sum=0,mid=0,ans=-1;// bno stores number of boards
     if(p>bno)return -1;
	 for(int i=0;i<bno;i++)sum+=b[i];
	 e=sum;// we  have made a range from st to e which contain possible times to paint
	 st = *max_element(b.begin(), b.end());
	 while(st<=e){
		mid=st+(e-st)/2;
		if(isValid(b,p,bno,mid)){//if mid can be valid ans store it and move to left
          ans=mid;
		  e=mid-1;
		}else{
			st=mid+1;
		}
	 }
	 return ans;
}
int main() {
    int n, p, dummy;
    cout<<"enter number of boards and painters : ";
    cin >> n >> p ;
    vector<int> boards(n);
    cout<<"enter size of boards : ";
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    cout <<"minimum time to paint  is : " << minTime(boards, p) << endl;

    return 0;
}