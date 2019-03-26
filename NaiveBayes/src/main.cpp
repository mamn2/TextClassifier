//
//  main.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/19/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//



#include <iostream>
#include "ClassifierEvaluator.hpp"

int main(int argc, const char * argv[]) {
    
    std::string trainingLabels = "/Users/mohamedamn/Downloads/digitdata/traininglabels";
    std::string trainingImages = "/Users/mohamedamn/Downloads/digitdata/trainingimages";
    
    std::multimap<int, ImageData> data = LoadData(trainingImages, trainingLabels);
    
    std::array<std::array<std::array<double, 28>, 28>, 10> allProbabilities = GetPixelProbabilitiesAllClasses(data);
    
    int numCorrect = 0;
    int numWrong = 0;
    
    for (std::multimap<int, ImageData>::iterator it = data.begin(); it != data.end(); ++it) {
        if (HighestProbableClassOfImage((*it).second, data, allProbabilities) == (*it).first) {
            numCorrect++;
        } else {
            numWrong++;
        }
    }
    //long highestProb = HighestProbableClassOfImage((*data.end()).second, data, allProbabilities);
    
    std::cout << numCorrect << "     " << numWrong;
    
}
