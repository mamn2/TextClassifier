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
    
    std::string testImages = "/Users/mohamedamn/Downloads/digitdata/testimages";
    std::string testLabels = "/Users/mohamedamn/Downloads/digitdata/testlabels";
    
    std::multimap<int, ImageData> testData = LoadData(testImages, testLabels);
    
    std::array<std::array<std::array<double, 28>, 28>, 10> allProbabilities = GetPixelProbabilitiesAllClasses(data);
    
    int numCorrect = 0;
    int numWrong = 0;
    
    for (std::multimap<int, ImageData>::iterator it = testData.begin(); it != testData.end(); ++it) {
        if (HighestProbableClassOfImage((*it).second, testData, allProbabilities) == (*it).first) {
            numCorrect++;
        } else {
            numWrong++;
        }
    }
    
    std::cout << numCorrect << "     " << numWrong;
    
}
