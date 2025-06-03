// #include<iostream>
// #include <vector>
// #include <string>
// #include <fstream>
// using namespace std;
// class DocEditor{
// private:
// vector<string>elements;
// string renderedDoc;
// public:
// void addText(string text)
// {
//   elements.push_back(text);
// }
// void addImg(string imgPath)
// {
//   elements.push_back(imgPath);
// }

// string renderDoc() //busssiness logic
// {
// if(renderedDoc.empty()){
//   string result;
//   for(auto element: elements)
//   {
//     result += "img:" element + "\n"; // Assuming each element is on a new line
//   }
//   renderedDoc = result;
// }
// return renderedDoc;
// }
//  void savefile(){
//   ofstream file("document.txt");
//   if(file.is_open()){
//     file << renderdoc;
//     file.close();
//   } else {
//     cout << "Error opening file for writing." << endl;
//   }
//  }


// };
// int main(){
//     DocEditor editor;
//     editor.addText("Hello, World!");
//     editor.addImg("path/to/image.jpg");
//     cout << editor.renderDoc() << endl; // Display the rendered document
//     editor.savefile(); // Save the document to a file
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Needed for ofstream

using namespace std;

class DocEditor {
private:
    vector<string> elements;
    string renderedDoc; // renamed to avoid conflict with function name

public:
    void addText(string text) {
        elements.push_back("text: " + text);
    }

    void addImg(string imgPath) {
        elements.push_back("img: " + imgPath);
    }

    string renderDoc() { // Renamed to avoid conflict with variable
        if (renderedDoc.empty()) {
            string result;
            for (auto element : elements) {
                result += element + "\n";
            }
            renderedDoc = result;
        }
        return renderedDoc;
    }

    void saveFile() {
        ofstream file("document.txt");
        if (file.is_open()) {
            file << renderedDoc;
            file.close();
        } else {
            cout << "Error opening file for writing." << endl;
        }
    }
};

int main() {
    DocEditor editor;
    editor.addText("Hello, World!");
    editor.addImg("path/to/image.jpg");

    cout << editor.renderDoc() << endl; // Display the rendered document
    editor.saveFile(); // Save the document to a file

    return 0;
}
