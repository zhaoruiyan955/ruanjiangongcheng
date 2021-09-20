#include<bits/stdc++.h>
#include <fstream>
using namespace std;
int main() {
  vector <char> kkk;
  int find_type;
  int t=0,j=0,k=0,k1=0,k2=0;
  int back;
  int switch_num=0,case_num[100],if_else_num=0,else_if_num=0; 
  int w;
  int size=100;
  char filename[size];
  string receive;
  string test="switch case else if auto break char const continue default do double enum extern float for goto int long register return short signed sizeof	static struct typedef union unsigned void volatile while";  
  string search[5]={"else if","else ","else{","if(","if "};
  fstream infile,myfile;
  cout <<cout<<" 请输入文件的路径:"; 
  cin.getline(filename, size);
  cout << "1.Total查询" << endl;
  cout << "2.switch&case查询" << endl;
  cout << "3.if_else查询" << endl;
  cout << "4.if_elseif_if查询"<< endl;
  cout << "请输入查询等级：" << endl;
  cin >> find_type;
  infile.open(filename);
  myfile.open(filename); 
  if (!infile.is_open()) {
        exit(EXIT_FAILURE);
    }
    infile >> receive;
   for (;!infile.eof();) 
    {
      if (infile.good()) {
      	for(j=2;j<9;j++){
      	  back=test.find(receive.substr(0, j));
      	  if(back<test.size()&&(receive[j]==NULL||receive[j]=='('
			                    ||receive[j]=='{'||receive[j]==';'
								||receive[j]==':')){
      	  	t++;  
      	  	if(back==0) kkk.push_back('1');
      	  	else if(back==7) kkk.push_back('2');
      	  	break;
			}
		  }
        infile >> receive;
        }
    }
    cout <<"total num: " << t << endl;
    for(j=0;j<kkk.size();j++){
 	  if(kkk[j]=='1'&&kkk[j+1]=='2') {
 	  	switch_num++;
 	  	case_num[k]=0;
	   }
	   else if(kkk[j]=='2'&&kkk[j+1]=='1'){
	   	 case_num[k]++;
	   	 k++;
	   }
	   else {
	   	 case_num[k]++;
	   }
	}
	if(find_type>=2){
	  cout<<"switch num: "<<switch_num<<endl<< "case num:" ;
      for(j=0;j<=k;j++)
      {
           cout<<' '<<case_num[j];
      }
      if(find_type>=3){
      	cout<<endl;		  
	    kkk.erase(kkk.begin(),kkk.end()); 
	    for(;getline(myfile,receive);)
		{ 
          for(j=0;j<5;j++){
          	w=receive.find(search[j]);
          	if(w!=-1){
          	  if(j==0) {
          	  	kkk.push_back('3');
          	  	break;
				}
          	  else if(j==1||j==2){
          	  	kkk.push_back('2');
          	  	break;
				} 
          	  else {
          	  	kkk.push_back('1');
          	  	break;
				}
			  }
		  } 
	    }
	    for(j=0;j<kkk.size();j++){
	      if(kkk[j]=='1') 
	        k1++;
	      else if(kkk[j]=='2'){
	      	if(k2==0&&k1>0) {
              if_else_num++;
	      	  k1--;
			  }
			  else if(k2>0){
			  	k2--;
			  	else_if_num++;
			  }
		    }
		else {
			if(kkk[j-1]!='3'){
				k1--;
				if(k1<0)
                {
                    k1=0;
                } 
				k2++;	
			  }
		    }
		  }
      if(find_type==3) 
      {
          cout<<"if-else num: "<<if_else_num;
      }
      else
      {
          cout<<"if-else num: "<<if_else_num<<endl<<"if-elseif-else num: "<<else_if_num;
      } 	
	    }
	  }
  return 0;
}
