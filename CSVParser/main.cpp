#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
    ifstream myfile("/home/senthil/Desktop/test.csv");
    string line;
    string item_array[3] = {"", "", ""};
    if(myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line <<endl;
            int item_array_counter = 0;
            for(int i = 0; i < line.length(); ++i)
            {
                char c =  line.at(i);
                if(c  != ',' ){
                    
                    item_array[item_array_counter].append(1, c);
                }
                else{
                    cout << "Splitted" << item_array[item_array_counter] <<endl;
                    item_array_counter++;
                }
                
                
            }
        }
        myfile.close();
    }
	printf("hello world\n");
    getchar();
	return 0;
}
