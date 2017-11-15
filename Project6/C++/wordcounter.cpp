#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>

typedef std::map<std::string, int> WordsMap;

bool filter(char c){
  return isalpha(c)==0;
}

void toLowerCase(std::string &str)
{
	const int length = str.length();
	for(int i=0; i < length; ++i)
	{
		str[i] = std::tolower(str[i]);
	}
}

void countWords(std::istream& in, WordsMap& words){
  std::string s;
  std::string c;
  while (in >> s){
    s.resize(remove_if(s.begin(), s.end(),filter)-s.begin());    // get rid of unwanted chars
    toLowerCase(s);
    ++words[s];
  }
}

int main(int argc, char** argv){
  if (argc<2){
    std::cout<<"Please enter a valid file name!";
    return 0;
  }

  std::ifstream in(argv[1]);
  std::string tmp;

  if (in>>tmp==0){
    std::cout<<"The file cannot be opened!";
    return 0;
  }



  WordsMap map;
  countWords(in, map);

  std::multimap<int, std::string > mymap;

  for (WordsMap::iterator p = map.begin(); p != map.end(); ++p){
    //std::cout << p->first << " occurred "<< p->second << " times.\n";
    mymap.insert(make_pair(p->second, p->first));
  }
  std::multimap<int,std::string> :: iterator it;
  it=mymap.end();
  it--;
  for (it;it!=mymap.begin();it--){
    std::cout<< it->second << " "<<it->first <<"\n";
  }
}
