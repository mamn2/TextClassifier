//
//  NaiveBayesTest.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "InputHandler.hpp"

TEST_CASE("Maps Input") {
    std::string trainingLabels = "/Users/mohamedamn/Downloads/digitdata/traininglabels";
    std::string trainingImages = "/Users/mohamedamn/Downloads/digitdata/trainingimages";
    
    std::multimap<int, std::array<std::array<int, 28>, 28>> data = LoadData(trainingImages, trainingLabels);
    
    
}

