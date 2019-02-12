#include <iostream>
#include <iterator>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

class Dictionary{
  public:
  vector< pair <string,int> > dict;   //vector to store pairs
    
  void keys(){//prints list of keys
    cout << "Keys: [";
    for(int i = 0;i<dict.size()-1;i++){
      cout << dict[i].first << ", "; 
    }
    cout << dict[dict.size()-1].first << "]" << endl;
	}    

  void values(){//prints list of values
    cout << "Values: [";
    for(int i = 0;i<dict.size()-1;i++){
      cout << dict[i].second << ", "; 
    }
    cout << dict[dict.size()-1].second << "]" << endl;
    
	}  

  void items(){//prints list of key/value pairs
    cout << "Items: [";
    for(int i = 0;i<dict.size()-1;i++){
      cout << "(" << dict[i].first << "," << dict[i].second << "),"; 
    }
    cout << "(" << dict[dict.size()-1].first << "," << dict[dict.size()-1].second << ")]" << endl;

  }  

  void add(string key, int value){//adds a pair to the dictionary
	  if(in(key)==0){
      dict.push_back( make_pair(key,value) );
    }else{
      cout << "Failed to add item: ("<<key<<","<<value <<") key already exists." << endl;
    }
    
	}     

	void del(string key){//removes the pair corresponding to the string
		 for(int i = 0;i<dict.size();i++){
      if(dict[i].first == key){
        //dict.erase(i); 
      } 
    }
      
    
	}     

  bool in(string key){//outputs true(1) if the key is in the dictionary, false(0) if not
    bool ret = false;
    for(int i = 0;i<dict.size();i++){
      if(dict[i].first == key){
        ret = true;
      }
    }
    return ret;
  }      

  int get(string key){ //returns value corresponding to the key, -1 if it doesn't exist
    int val = -1;
    for(int i = 0;i<dict.size();i++){
      if(dict[i].first==key){
        val = dict[i].second;
      }
    }
    return val;
  }     

  Dictionary operator +(Dictionary other){//overloading + operator for two dictionaries
    Dictionary newDict;
      
    for(int i = 0;i<dict.size();i++){
      string tempKey = dict[i].first;
      int tempVal = dict[i].second;
      newDict.add(tempKey,tempVal);
    }

    for(int j = 0;j<other.dict.size();j++){
      string tempKey = other.dict[j].first;
      int tempVal = other.dict[j].second;
      newDict.add(tempKey,tempVal);
    }
    
    return newDict;

  }
       
};

int main(){
    
  Dictionary d;
  d.add("tom",22);
  d.add("joe",18);
  d.add("ciera",23);
  //d.add("mitch",21);
  d.add("mitch",25);
  d.add("nathan",21);
  //d.keys();
  //d.values();
  d.items();
  //cout << d.in("mitch") << endl;
  //cout << d.get("tom")<< endl;
  //cout << d.get("nathan")<< endl;
  //cout << d.get("poop")<< endl;

  Dictionary d2;
  d2.add("tom",22);
  d2.add("mom",57);
  d2.add("ciera",23);
  d2.add("dad",58);
  d2.add("nathan",21);
  d2.items();

  Dictionary d3 = d+(d2);
  d3.items();
    
  return 0;
}
