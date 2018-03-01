//
//  main.cpp
//  CPPCore
//
//  Created by 刁展鹏 on 2/3/18.
//  Copyright © 2018 ZhanpengDiao. All rights reserved.
//

// copy the file by lines
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in("/Users/ZhanpengDiao/Documents/CPP/CPPCore/Preface/Scopy.cpp");
    ofstream out("/Users/ZhanpengDiao/Documents/CPP/CPPCore/Preface/Scopy.out");
    
    string s;
    while(getline(in, s)) {
        out << s << "\n";
    }
    
    return 0;
}
