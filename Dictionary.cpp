#include <iostream>
#include <iterator>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

//Thomas Martinson
/*This program replicates Python's Dictionary class and
it's main functions.*/


class Dictionary{
  public:
  vector< pair <string,int> > dict;   //vector to store pairs
    
  void keys(){//prints list of keys
    if(dict.size()>0){
      cout << "Keys: [";
      for(int i = 0;i<dict.size()-1;i++){
        cout << dict[i].first << ", "; 
      }
      cout << dict[dict.size()-1].first << "]" << endl;
    }else{
      cout << "Keys: []"<< endl;
    }
	}    

  void values(){//prints list of values
    if(dict.size()>0){
      cout << "Values: [";
      for(int i = 0;i<dict.size()-1;i++){
        cout << dict[i].second << ", "; 
      }
      cout << dict[dict.size()-1].second << "]" << endl;
    }else{
      cout << "Values: []" << endl;
    }
	}  

  void items(){//prints list of key/value pairs
    if(dict.size()>0){
      cout << "Items: [";
      for(int i = 0;i<dict.size()-1;i++){
        cout << "(" << dict[i].first << "," << dict[i].second << "),"; 
      }
      cout << "(" << dict[dict.size()-1].first << "," << dict[dict.size()-1].second << ")]" << endl;
    }else{
      cout << "Items: []" << endl;
    }

  }  

  void add(string key, int value){//adds a pair to the dictionary
	  if(in(key)==0){
      dict.push_back( make_pair(key,value) );
    }else{
      cout << "Key: '" << key << "' is already in the dictionary."<<endl;
    }
	}     

	void del(string key){//removes the pair corresponding to the string
		for(int i = 0;i<dict.size();i++){
      if(dict[i].first == key){
        dict.erase (dict.begin()+i); 
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

//Driver
int main(){
  cout << "Let's create a dictionary and add some items to it." << endl;
  Dictionary d;
  d.add("tom",22);
  d.add("joe",18);
  d.add("randy",27);
  d.add("mitch",25);
  d.add("nathan",21);
  
  cout <<"Let's look at a list of the items we added." << endl;
  d.items();

  cout << endl << "Let's look at just the keys." << endl;
  d.keys();

  cout << endl<<"Now just the values." << endl;
  d.values();
  
  cout <<endl << "What happens if we try to add an item with a key that is already in the dictionary?" << endl;
  d.add("mitch",25);

  cout <<endl << "Let's test if there is a key in the dictionary. 1 means yes, 0 means no." << endl;
  cout << d.in("mitch") << endl;
  cout << d.in("marge") << endl;

  cout << endl << "Let's see what value matches a certain key. -1 means the key doesn't exist." << endl;
  cout << "The value is: " << d.get("tom")<< endl;
  cout << "The value is: " << d.get("nathan")<< endl;
  cout << "The value is: " << d.get("larry")<< endl;

  cout << endl << "Now let's create another Dictionary and add items to it." << endl;
  Dictionary d2;
  d2.add("billy",76);
  d2.add("mom",57);
  d2.add("fred",99);
  d2.add("randy",27);
  d2.add("dad",58);
  d2.add("nathan",21);
  d2.items();

  cout <<endl<< "Let's try deleting an item." << endl;
  d2.del("fred");
  d2.items();

  cout << endl <<"Now let's test the + operator by doing a union operation on the two dictionaries we created." << endl;
  Dictionary d3 = d+(d2);
  d3.items();
  
  cout << endl <<"Let's create an empty dictionary and look at it's contents." << endl;
  Dictionary d4;
  d4.items();
  d4.keys();
  d4.values();
    
  return 0;
}
