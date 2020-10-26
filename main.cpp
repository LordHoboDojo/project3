#include <iostream>
#include <fstream>
#include <sstream>
#include "BSTree.h"
#include "DVD.h"

using namespace std;
int main() {
    BSTree<DVD> tree = BSTree<DVD>();
    string inventoryFile;
    cin >> inventoryFile;
    string transactionLog;
    cin >> transactionLog;
    ifstream inventory(inventoryFile);
    string line;
    while(getline(inventory,line)){
        stringstream ss(line);
        DVD *toAdd = new DVD();
        toAdd->title = "";
        toAdd->rented =0;
        toAdd->available=0;
        string substr;
        getline(ss,substr,',');
        toAdd->setTitle((substr));
        getline(ss,substr,',');
        toAdd->setAvailable(stoi(substr));
        getline(ss,substr,',');
        toAdd->setRented(stoi(substr));
        if(tree.getRoot() == nullptr) {
            tree.setRoot(tree.insert(tree.getRoot(),toAdd));
        }
        else{
            tree.insert(tree.getRoot(),toAdd);
        }
    }
    ifstream transactions(transactionLog);
    ofstream error;
    error.open("error.log");

    while(getline(transactions,line)){
        stringstream ss(line);
        string substr;
        if(getline(ss,substr,',')){
            stringstream ss1(substr);
            string firstWord;
            ss1 >> firstWord;
            if (firstWord != "rent" && firstWord !="add" &&firstWord !="remove"&&firstWord!="return"){
                //add to error log
                error << line << endl;
                continue;
            }
            else{
                string movieName = substr.substr(firstWord.length()+1);
                if (firstWord == "rent"){
                    if (tree.search(tree.getRoot(),movieName) != nullptr){
                        Node<DVD> *temp =tree.search(tree.getRoot(),movieName);
                        DVD t = temp->getPayload();
                        t.setAvailable(t.getAvailable()-1);
                        t.setRented(t.getRented()+1);
                        temp->setPayload(t);
                    }
                    else{
                        //error
                        error << line << endl;
                    }
                }
                else if (firstWord == "add"){
                    if (tree.search(tree.getRoot(),movieName) == nullptr){
                        if (getline(ss,substr,',')){
                            if (stoi(substr)){
                                DVD toAdd = new DVD();
                                toAdd.title = "";
                                toAdd.rented =0;
                                toAdd.available=0;
                                toAdd.setAvailable(stoi(substr));
                                toAdd.setRented(0);
                                toAdd.setTitle(movieName);
                                tree.insert(tree.getRoot(),toAdd);
                            }
                            else{
                                //bad
                                error << line << endl;
                            }
                        }
                        else{
                            //bad
                            error << line << endl;
                        }
                    }
                    else{
                        if (getline(ss,substr,',') && stoi(substr)) {
                            Node<DVD> *temp = tree.search(tree.getRoot(), movieName);
                            DVD t = temp->getPayload();
                            t.setAvailable(t.getAvailable() + stoi(substr));
                            temp->setPayload(t);
                        }
                        else{
                            //bad
                            error << line << endl;
                        }
                    }
                }
                else if (firstWord == "remove"){
                    if (tree.search(tree.getRoot(),movieName) != nullptr){
                        Node<DVD> *temp =tree.search(tree.getRoot(),movieName);
                        DVD t = temp->getPayload();
                        if (getline(ss,substr,',') && stoi(substr)) {
                            t.setAvailable(t.getAvailable() - stoi(substr));
                            temp->setPayload(t);
                            if (temp->getPayload().getAvailable() ==0 && temp->getPayload().getRented()==0){
                            }
                        }
                        else{
                            error << line << endl;
                        }
                    }
                    else{
                        //error
                        error << line << endl;
                    }
                }
                else if (firstWord == "return"){
                    if (tree.search(tree.getRoot(),movieName) != nullptr){
                        Node<DVD> *temp =tree.search(tree.getRoot(),movieName);
                        DVD t = temp->getPayload();
                        t.setAvailable(t.getAvailable()+1);
                        t.setRented(t.getRented()-1);
                        temp->setPayload(t);
                    }
                    else{
                        //error
                        error << line << endl;
                    }
                }
                else{
                    //error
                    error << line << endl;
                }
            }
        }
    }
    tree.printTree();

    return 0;
}
