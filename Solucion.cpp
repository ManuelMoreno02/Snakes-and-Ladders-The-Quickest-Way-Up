#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int mayor=0;
int valorfin;
vector<vector<int>> global;
int valor_global;
void ami(vector<vector<int>> ladders,vector<int> actual,int valor,int j,vector<vector<int>> totl){
  valorfin+=valor;
  totl[j]=actual;
  j++;

  for(int i=0;i<ladders.size();i++){
      if(ladders[i][0]>actual[1]){
          int valor2=ladders[i][1]-ladders[i][0];
          ami(ladders, ladders[i],valor2,j,totl);
      }
      if(i==ladders.size()-1){
          if (mayor<valorfin){
              mayor=valorfin;
              global=totl;
              valor_global=j-1;
          }
      }
  }
  valorfin-=valor;
}
/*
* Complete the 'quickestWayUp' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
*  1. 2D_INTEGER_ARRAY ladders
*  2. 2D_INTEGER_ARRAY snakes
*/

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    valorfin=0;
  int dado=6;     
vector<vector<int>> ladders_con(ladders.size());
vector<int> snakes_tem(snakes.size());
int posicion_ladders=0,posicion=1;
int mayor=0;

    for(int i=0;i<ladders.size();i++){
        ami(ladders,ladders[i],ladders[i][1]-ladders[i][0],0,ladders_con);}
  
    for(int i=0;i<snakes.size();i++){
        snakes_tem[i]=snakes[i][0];
    }
    for(int i=0;i<snakes_tem.size();i++){
        for(int j=0;j<snakes_tem.size();j++){
           if(snakes_tem[i]<snakes_tem[j]) {
                          
              mayor=snakes_tem[j];
              snakes_tem[j]=snakes_tem[i];
              snakes_tem[i]=mayor;
            }
        }
   }
    for (int i=0;i<global.size();i++){
       if(valor_global<i){
           global[i]={100,100};}}
    global.push_back({100,100});
    int contador=0;
    while(posicion<100&&posicion>0){
        int as=posicion+6;
        contador+=1;
        int b=global[posicion_ladders][0];
        vector<vector<int>> g=global;
        if(posicion+dado>=global[posicion_ladders][0]){
            posicion=global[posicion_ladders][1];
            posicion_ladders+=1;
        }else{
            bool pase=false;
          for(int a=posicion+dado;a>posicion;a--){
               for(int b=0;b<snakes_tem.size();b++){
                   if(a==snakes_tem[b]){
                       if(a==posicion+1){
                           pase=true;
                           posicion=-1;
                           contador=-1;
                      }
                      break;
                   }
                   if(b==snakes_tem.size()-1){
                       posicion=a;
                      pase=true;}
               }
            if(pase==true)break;   
            }
        }
        
    }
    
  return contador;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }
mayor=0;
valorfin=0;
global.resize(0);
valor_global=0;
        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
       // std::cout<<result;
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}