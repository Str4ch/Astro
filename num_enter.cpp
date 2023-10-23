//
//  num_enter.cpp
//  Astro
//
//  Created by Алексей Шмаков on 10.02.2023.
//  Copyright © 2023 Алексей Шмаков. All rights reserved.
//

#include "num_enter.hpp"
#include <iostream>
#include <string>
#include <fstream>

double get_nums(int n){
    std::ifstream file("num_enter.txt");
    std::string str;
    double d = 0;
    for (int i = 0; i < n; i++) {
        file >> str >>d;
    }
    std::cout << d<< std::endl;
    file.close();
    return d;
}
