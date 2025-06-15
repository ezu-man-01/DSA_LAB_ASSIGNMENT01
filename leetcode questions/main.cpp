#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Movie
{
    int id;
    string title;
    int year;

};


int main(){
    ifstream file;
    file.open("data.csv");
    if (file.is_open()){
        string str;
        getline(file, str);

        while(!file.eof()){

            getline(file,str, ',');
            if(str.empty()) continue;

            Movie movie;
            movie.id = stoi(str);

            getline(file,str,',');
            movie.title = str;

            getline(file,str);
            movie.year = stoi(str);

            cout<<movie.id<<endl;
        }

        file.close();
    }
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.