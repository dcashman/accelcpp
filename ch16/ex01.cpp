#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    v.push_back("#include <iostream>");
    v.push_back("#include <string>");
    v.push_back("#include <vector>");
    v.push_back("using namespace std;");
    v.push_back("");
    v.push_back("int main() {");
    v.push_back("    vector<string> v;");
    v.push_back("    for (int i = 0; i < 7; i++)");
    v.push_back("        cout << v[i] << endl;");
    v.push_back("    for (int i = 0; i < v.size(); i++) {");
    v.push_back("        cout << \"    v.push_back(\\\"\";");
    v.push_back("        for (int j = 0; j < v[i].size(); j++) {");
    v.push_back("            switch (v[i][j]) {");
    v.push_back("            case '\\\"':");
    v.push_back("            case '\\\\':");
    v.push_back("                cout << \"\\\\\";");
    v.push_back("            default:");
    v.push_back("                cout << v[i][j];");
    v.push_back("            }");
    v.push_back("        }");
    v.push_back("        cout << \"\\\");\" << endl;");
    v.push_back("    }");
    v.push_back("    for (int i = 7; i < v.size(); i++)");
    v.push_back("        cout << v[i] << endl;");
    v.push_back("    return 0;");
    v.push_back("}");
    for (int i = 0; i < 7; i++)
        cout << v[i] << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << "    v.push_back(\"";
        for (int j = 0; j < v[i].size(); j++) {
            switch (v[i][j]) {
            case '\"':
            case '\\':
                cout << "\\";
            default:
                cout << v[i][j];
            }
        }
        cout << "\");" << endl;
    }
    for (int i = 7; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}
