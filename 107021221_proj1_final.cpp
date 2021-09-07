#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class matrix{
    public:
    int row,col;
    int top;
     matrix(int row=0,int col=0):
        row(row),col(col),top(0) {
        arr.resize(16);
        for(int i=0;i<16;i++){
            arr[i].resize(41);
        }
    }
    vector<vector<int>> arr;
};

int main(int argc,char *argv[]){
    ifstream fin(argv[1]);
    if(!fin){
        cout<<"Error in reading files"<<endl;
    }

    ofstream fout("107021221_proj1.final");
    if(!fout){
        cout<<"Error in output results"<<endl;
    }
    /*fstream file;
    file.open("1.data",ios::in);
    if(!file){
        perror("cannot open");
        return EXIT_FAILURE;
    }else cout<<"開啟"<<endl;*/

    int ref,move,col,row;
    bool valid=true;
    char num[5];
    string a,b;

    fin>>row>>col;
    //file>>row>>col;
    //fout<<"col="<<col<<endl;
    //fout<<"row="<<row<<endl;
    fin>>num;
    //file>>num;
    matrix temp(row,col);

    while(num[0]!='E'&&valid){

        matrix drop(4,3);
        //file>>a>>b;
        fin>>a>>b;
        ref=stoi(a);
        move=stoi(b);
        int num_=num[1]-'0';
            if(num[0]=='T'){
                if(num_==1){
                    drop.arr[1][0]=2;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[2][2]=3;
                }else if(num_==2){
                    drop.arr[1][0]=2;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[3][0]=2;
                 }else if(num_==3){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[1][2]=3;
                    drop.arr[2][0]=2;
                }else if(num_==4){
                    drop.arr[1][0]=1;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[3][0]=1;
                 }
            }else if(num[0]=='L'){
                if(num_==1){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[2][0]=1;
                    drop.arr[3][0]=1;
                }else if(num_==2){
                    drop.arr[1][0]=1;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[2][2]=3;
                 }else if(num_==3){
                    drop.arr[1][0]=2;
                    drop.arr[2][0]=2;
                    drop.arr[3][0]=1;
                    drop.arr[3][1]=2;
                }else if(num_==4){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[1][2]=3;
                    drop.arr[2][0]=3;
                 }
            }else if(num[0]=='J'){
                if(num_==1){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[2][0]=2;
                    drop.arr[3][0]=2;
                }else if(num_==2){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[1][2]=3;
                    drop.arr[2][0]=1;
                 }else if(num_==3){
                    drop.arr[1][0]=1;
                    drop.arr[2][0]=1;
                    drop.arr[3][0]=1;
                    drop.arr[3][1]=2;
                }else if(num_==4){
                    drop.arr[1][0]=3;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[2][2]=3;
                 }
            }else if(num[0]=='S'){
                if(num_==1){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[2][0]=2;
                    drop.arr[2][1]=3;
                }else if(num_==2){
                    drop.arr[1][0]=2;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[3][0]=1;
                }
            }else if(num[0]=='Z'){
                if(num_==1){
                    drop.arr[1][0]=2;
                    drop.arr[1][1]=3;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                }else if(num_==2){
                    drop.arr[1][0]=1;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
                    drop.arr[3][0]=2;
                }
            }else if(num[0]=='I'){
                if(num_==1){
                    drop.arr[1][0]=1;
                    drop.arr[2][0]=1;
                    drop.arr[3][0]=1;
                    drop.arr[4][0]=1;
                }else if(num_==2){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[1][2]=3;
                    drop.arr[1][3]=4;
                }
            }else if(num[0]=='O'){
                    drop.arr[1][0]=1;
                    drop.arr[1][1]=2;
                    drop.arr[2][0]=1;
                    drop.arr[2][1]=2;
            }

            //初始化掉落起點
            for(int i=1;i<=4;i++){
                for(auto it=drop.arr[i].begin();*it!=0;it++){
                    (*it)+=(ref-1);
                    if((*it)>temp.col||(*it)==0){
                        valid=false;
                        break;
                    }
                }
            }

            if(!valid){
                fout<<"invalid\n";
                break;
            }

            if(valid){
                //判斷掉落位置
                int min_d=500,each_d;
                for(int i=1;i<=4;i++){
                    int this_row=temp.top+i;
                    for(auto j=drop.arr[i].begin();*j!=0;j++){
                        int k;
                        for(k=temp.top;k>0;k--){
                            auto it=find(temp.arr[k].begin(),temp.arr[k].end(),*j);
                            if(it!=temp.arr[k].end()){
                                each_d=this_row-k;
                                break;
                            }
                        }
                        if(k==0){
                            each_d=this_row;
                        }
                        if(min_d>each_d) min_d=each_d;
                    }
                }

                //進行橫移
                for(int i=1;i<=4;i++){
                    for(int j=0;drop.arr[i][j]!=0;j++){
                        drop.arr[i][j]+=move;
                        int now_row=temp.top-min_d+1+i;
                        if(drop.arr[i][j]==0||drop.arr[i][j]==temp.col+1){
                            valid=false;
                        }else if(find(temp.arr[now_row].begin(),temp.arr[now_row].end(),drop.arr[i][j])!=temp.arr[now_row].end()){
                            valid=false;
                        }
                    }
                }

                if(!valid){
                    fout<<"invalid\n";
                    break;
                }

                //判斷是否能繼續降落
                int this_min=500;
                for(int i=1;i<=4;i++){
                    if(drop.arr[i][0]!=0){
                        for(int j=0;drop.arr[i][j]!=0;j++){
                            int now_row=temp.top-min_d+i;
                            int dist_row=0;
                            bool found=false;
                            while(!found&&now_row>=1){
                                auto it=find(temp.arr[now_row].begin(),temp.arr[now_row].end(),drop.arr[i][j]);
                                if(it!=temp.arr[now_row].end()){
                                    found=true;
                                    break;
                                }else{
                                    dist_row++;
                                    now_row--;
                                }
                            }
                            if(this_min>dist_row) this_min=dist_row;
                        }
                    }
                }


                int left_row=this_min;
                //把方塊放入主陣列
                //cout<<"temp.top= "<<temp.top<<endl;
                //cout<<"min_d= "<<min_d<<endl;
                //cout<<"left_row= "<<left_row<<endl;
                int addrow=temp.top-min_d+1-left_row;
                for(int i=1;i<=4;i++){
                    if(drop.arr[i][0]!=0){
                        int add_row=addrow+i;
                        //cout<<"addrow= "<<add_row<<endl;
                        auto it=temp.arr[add_row].begin();
                        while(*it!=0) it++;
                        for(int j=0;drop.arr[i][j]!=0;j++){
                            //cout<<"i= "<<i<<" j= "<<j<<endl;
                            *it=drop.arr[i][j];
                            //cout<<"*it= "<<*it<<endl;
                            it++;
                        }
                        if(add_row>temp.top) temp.top=add_row;
                    }
                }


                //判斷是否可以消除
                int idx=temp.top;
                while(idx>0){
                    int nonzero=0;
                    for(auto it=temp.arr[idx].begin();it!=temp.arr[idx].end();it++){
                        if(*it!=0) nonzero++;
                    }
                    if(nonzero==temp.col){
                        for(int i=idx;i<temp.top;i++){
                            temp.arr[i].clear();
                            temp.arr[i].resize(41);
                            temp.arr[i].insert(temp.arr[i].begin(),temp.arr[i+1].begin(),temp.arr[i+1].end());
                        }
                        temp.arr[temp.top].clear();
                        temp.arr[temp.top].resize(41);
                        temp.top--;
                    }
                    idx--;
                    //fout<<"hi"<<endl;
                }
               // fout<<"idx= "<<idx<<endl;
                if(temp.top>temp.row) {
                    valid=false;  //判斷是否超出陣列外了
                    fout<<"invalid\n";
                }

            }else{  //輸出
                break;
            }
            //file>>num;
            fin>>num;
    }
    for(int i=row;i>=1;i--){
        int j;
        for(j=1;j<col;j++){
            if(find(temp.arr[i].begin(),temp.arr[i].end(),j)!=temp.arr[i].end()) fout<<"1 ";
            else fout<<"0 ";
        }
        if(find(temp.arr[i].begin(),temp.arr[i].end(),j)!=temp.arr[i].end()) fout<<"1";
        else fout<<"0";
            fout<<endl;
    }
}




