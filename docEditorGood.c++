#include<iostream>
#include<vector>
#include<string>
#include<fstream> // Needed for ofstream
using namespace std;
class DocElement{
  public:
    virtual string render() const = 0; // Pure virtual function for rendering
};

class TextElement : public DocElement {
  private:

    string text;
  public:
  TextElement(string text){
this->text = text;
  }
    string render() const override {
        return "Text: " + text + "\n"; // Render text with a label
    }
  };

class ImageElement : public DocElement {
  private:
    string imgPath;
  public:
  ImageElement(string imgPath){
  this->imgPath = imgPath;
  }
    string render() const override {
        return "Image: " + imgPath + "\n"; // Render image with a label
    }
  
};
//adding new element as it supports ocp
class newline:public DocElement {
  public:
    string render() const override {
        return "\n"; 
    }

};
//document class=> used as collection of elements
class Document {
private:
vector<DocElement*>elements; // Collection of document elements
public:
    void addele(DocElement* element) {
        elements.push_back(element); // Add a new element to the document
    }
string render()
{
  string result;
  for(auto element: elements) {
    result += element->render(); // Render each element
  }
  return result; // Return the complete rendered document
}
};
class Persistance{
public:
virtual void save(string data)=0;


};
// Concrete implementation of persistence
class fileSave:public Persistance {

public:
void save(string data) override {
    ofstream file("document.txt"); // Open a file for writing
    if (file.is_open()) {
        file << data; // Write the rendered document to the file
        file.close(); // Close the file
    } else {
        cout << "Error opening file for writing." << endl; // Error handling
    }
}

};
class DBstore:public Persistance {
public:
void save(string data) override {
    // Simulate saving to a database
    cout << "Saving to database: " << data << endl; // Placeholder for database logic
}
};
class DocEditor {
Document* doc;
Persistance* p;
string renderedDoc;
public:
DocEditor(Document* doc, Persistance* p){
this->doc= doc;
this->p = p;

}
void addText(const string& text) {
    doc->addele(new TextElement(text)); // Add a text element to the document
  
}
void addImg(const string& imgPath) {
    doc->addele(new ImageElement(imgPath)); // Add an image element to the document

}
void addNewLine() {
    doc->addele(new newline()); // Add a new line element to the document
}
string renderDoc() {
    if (renderedDoc.empty()) {
        renderedDoc = doc->render(); // Render the document if not already done
    }
    return renderedDoc; // Return the rendered document

  }
  void saveDoc(){

    p->save(renderDoc()); // Save the rendered document using the persistence strategy
  }


  };
int main(){
  Document* doc=new Document(); // Create a document instance
  Persistance* p = new fileSave(); // Create a persistence strategy instance
  DocEditor* editor=new DocEditor(doc, p);
editor->addText("Hello, World!"); // Add text to the document
editor->addImg("path/to/image.jpg"); // Add an image to the document
editor->addNewLine(); // Add a new line to the document
cout << editor->renderDoc() << endl; // Display the rendered document
editor->saveDoc(); // Save the document to a file
return 0; // Exit the program
}