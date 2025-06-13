// #include<iostream>

// using namespace std;
// //abstract
// class Ireports{
// virtual void getJSONData(const string data)=0;
// };
// class XMLDataprovider{
// public:
//     string getXMLData(const string& data){

//       // cout<<"XML Data"<<endl;
//       size_t sep=data.find(":");
//       string name=data.substr(0, sep);
//       string id=data.substr(sep+1);
//       return "<user>"
//       "<name>"+name+"</name>"
//       "<id>"+id+"</id>"
//       "</user>";
//     }
// };
// class XmlAdapter: public Ireports{
//   private:
//     XMLDataprovider *xdp;
// public:
//  XmlAdapter(XMLDataprovider *xdp){
//         this->xdp=xdp;
//     }
// string getJSONData(const string& data) override {
//      string xml=   xdp->getXMLData(data);
//         cout<<"Converted to JSON Data"<<endl;
//         size_t sep = xml.find("<name>");
//         string name = xml.substr(sep + 6, xml.find("</name>") - sep - 6);
//         sep = xml.find("<id>");
//         string id = xml.substr(sep + 4, xml.find("</id>") - sep - 4);

//     }

// };
// class Client{
//   public:
//     void getData(Ireports *report, const string& data){
//         report->getJSONData(data);
//         cout << "Data processed successfully." << endl;
//     }
// };
// int main(){
//     XMLDataprovider *xdp = new XMLDataprovider();
//     XmlAdapter *adapter = new XmlAdapter(xdp);
//     Client *client = new Client();

//     string data = "John:12345";
//     client->getData(adapter, data);

//     delete xdp;
//     delete adapter;
//     delete client;
//   return 0;
// }

#include <iostream>
#include <string>

using namespace std;

// Abstract interface
class Ireports
{
public:
  virtual void getJSONData(const string &data) = 0;
  virtual ~Ireports() = default;
};

// XML data provider
class XMLDataprovider
{
public:
  string getXMLData(const string &data)
  {
    size_t sep = data.find(":");
    string name = data.substr(0, sep);
    string id = data.substr(sep + 1);
    return "<user>"
           "<name>" +
           name + "</name>"
                  "<id>" +
           id + "</id>"
                "</user>";
  }
};

// Adapter class converting XML to JSON
class XmlAdapter : public Ireports
{
private:
  XMLDataprovider *xdp;

public:
  XmlAdapter(XMLDataprovider *xdp)
  {
    this->xdp = xdp;
  }

  void getJSONData(const string &data) override
  {
    string xml = xdp->getXMLData(data);
    cout << "Converted to JSON Data:" << endl;

    size_t nameStart = xml.find("<name>") + 6;
    size_t nameEnd = xml.find("</name>");
    string name = xml.substr(nameStart, nameEnd - nameStart);

    size_t idStart = xml.find("<id>") + 4;
    size_t idEnd = xml.find("</id>");
    string id = xml.substr(idStart, idEnd - idStart);

    // Print as JSON
    cout << "{ \"name\": \"" << name << "\", \"id\": \"" << id << "\" }" << endl;
  }
};

// Client code using the interface
class Client
{
public:
  void getData(Ireports *report, const string &data)
  {
    report->getJSONData(data);
    cout << "Data processed successfully." << endl;
  }
};

int main()
{
  XMLDataprovider *xdp = new XMLDataprovider();
  XmlAdapter *adapter = new XmlAdapter(xdp);
  Client *client = new Client();

  string data = "John:12345";
  client->getData(adapter, data);

  delete xdp;
  delete adapter;
  delete client;

  return 0;
}
