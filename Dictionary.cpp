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
	  dict.push_back( make_pair(key,value) );
	}     

	void del(string key){//removes the pair corresponding to the string
		 for(int i = 0;i<dict.size();i++){
      if(dict[i].first == key){
        //dict.erase(i); 
      } 
    }
      
    
	}     

  int size(){ //returns number of pairs in dictionary
    return static_cast<int>(dict.size());
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

  int get(string key){ //returns value corresponding to the key
    return 0;
  }     

  void operator +(){//overloading + operator for two dictionaries

  }
       
};

int main(){
    
    Dictionary d;
    d.add("tom",22);
    d.add("joe",18);
    d.add("ciera",23);
    d.add("mitch",21);
    d.add("nathan",21);
    d.keys();
    d.values();
    d.items();
    cout << d.in("mitch");
    return 0;
}
