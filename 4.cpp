#include<iostream>
using namespace std;

// square pattern
/*
int main(){
    int r,c;
    cout<<"enter number of rows and column : ";
    cin>>r>>c;
    //  for(int i=1;i<=r;i++){
    //     for(int j=65;j<=c+65&&j<=90;j++)
    //     cout<<(char)j<<" ";
    //     cout<<"\n";
    //   }
   for(int i=0;i<r;i++){
       char ch= 'A';
       for(int j=0;j<c;j++){
           cout<<ch<<" ";
           ch+=1;
        }
        cout<<"\n";
    }
    return 0;
}*/

//square pattern num
/*
int main(){
    int r,c;
    cout<< "enter number of rows and column : ";
    cin >> r >> c;
    int n=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<n<<" ";
            n+=1;
        }
        cout<<"\n";
    }
    return 0;
}
*/


/*
int main(){
    int n=0;
    cout<<"enter number of line of pattern : ";
    cin>>n;
    int num=n;
    for(int i=0;i<n;i++){
        //for(int j=0;j<=i;j++,num+=1)  //5
        for(int j=i;j>=0;j--)  // 4
        //cout << "*"<<" "; // star pattern            1
        //cout <<i+1<<" "; // number pattern with i+1  2
        //cout<<j+1<<" ";  //number pattern with j+1   3 
        cout<<j+1<<" ";  // reverse printing         4
        //cout<<num+1<<" ";// floyd's triangle     5
        cout<<"\n";
    }
    return 0;
}
*/

/*
int main(){
    int n=0;
    cout<<"enter number of line of pattern : ";
    cin>>n;
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++)
        cout<<i<<" ";
        cout <<"\n";
    }
    return 0;
}
*/

// inverted triangle pattern
/*
int main(){
    int n=0;
    cout<<"enter number of lines : ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++) cout<< " ";
        for(int j=0;j<n-i;j++) cout << i+1 ;
        cout<<"\n";
        
    }
        return 0;
}
*/


// pyramid pattern
/*
int main(){
    int n=0;
    cout<<"enter number of line : ";
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-(i+1);j++)cout<<" ";//space printing logic
        for(int j=0;j<i+1;j++)cout<<j+1;//1st set of number
        for(int j=i;j>0;j--)cout<<j;//second set of number
        cout <<"\n";
    }
    return 0;
}
*/

//hollow diamond pattern
/*
int main(){
    int n;
    cout<<"enter number of line : ";
    cin>>n;
    // top part 
    for(int i=0;i<n;i++){
        for(int j=0;j<n-(i+1);j++)cout<<" "; // first set of space
        cout<<"*";
        if(i!=0){
            for(int j=0;j<2*i-1;j++)cout<<" ";
            cout<<"*";
        }
        cout<<"\n";
    }
    //bottom part
    for(int i=0;i<n-1;i++){
        for(int j=0;j<i+1;j++)cout<<" ";
        cout<<"*";
        if(i!=n-2){
            for(int j=0;j<2*(n-i)-5;j++)cout<<" ";
            cout<<"*";
        }
        cout<<"\n";
    }
    
    return 0;
}

*/


//butterfly pattern
/*
int main(){
    int n;
    cout<<"enter number of line : ";
    cin>>n;
    //top part
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++)cout<<"*";//star
        for(int j=0;j<n-i-1;j++)cout<<" ";//space
        for(int j=0;j<n-i-1;j++)cout<<" ";//star 
        for(int j=0;j<i+1;j++)cout<<"*";//space
        cout<<"\n";
    }
    // bottom part
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--)cout<<"*";//star
        for(int j=n-i;j<n;j++)cout<<" ";//space
        for(int j=n-i;j<n;j++)cout<<" ";//space
        for(int j=n-i;j>0;j--)cout<<"*";//star
        cout<<"\n";
    }
    return 0;
}
*/
