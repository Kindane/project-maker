#include<iostream>
#include<string>
#include<vector>
using namespace std;



size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();
 
    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
 
        pos = txt.find( ch, initialPos );
    }
 
    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
 
    return strs.size();
}




int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        cout << "You must specify what file you need to compile\n";
        return 1;
    }
    vector<string> v;
    string file = argv[1];
    split(file, v, '.');
    string filename = v[0];
    string query = "g++ " + file + " -o "  + filename;
    cout << "Compiling...\n";
    system(query.c_str());
    cout << "Compiling successfull\n";
    string call = "./" + filename;
    cout << "Start program:\n\n";
    system(call.c_str());
    return 0;
}
