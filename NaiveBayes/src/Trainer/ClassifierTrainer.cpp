//
//  ClassifierTrainer.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "ClassifierTrainer.hpp"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& trainingData) {
    
    unsigned long numWithImageClass = trainingData.count(imageClass);
    unsigned long numImages = trainingData.size();
    
    return (double) numWithImageClass / numImages;
    
}

double ProbabilityOfFeatureGivenClass(int imageClass, int pixelArrayX, int pixelArrayY,
                                      std::multimap<int, ImageData>& trainingData) {
    
    int numOccurenceClassWithFeature = 0;
    int numClassOccurence = 0;
    
    auto lowerBoundItr = trainingData.lower_bound(imageClass);
    auto upperBoundItr = trainingData.upper_bound(imageClass);
    
    //Iterates through the pixel in all instances of class in training data
    for (auto itr = lowerBoundItr; itr != upperBoundItr; ++itr) {
        if (itr -> second.pixelArray[pixelArrayX][pixelArrayY] == 1) {
            numOccurenceClassWithFeature++;
        }
        numClassOccurence++;
    }
    
    double probablityOfFeatureGivenClass = (kLaplaceSmoothing + numOccurenceClassWithFeature)
                                         / (2 * kLaplaceSmoothing + numClassOccurence);
    
    return probablityOfFeatureGivenClass;
    
}

ImageClassProbabilityData GetPixelProbabilitiesForClass(int imageClass, std::multimap<int, ImageData>& trainingData) {
    
    ImageClassProbabilityData probabilitesForClass;
    for (int i = 0; i < kImageSideLength; i++) {
        for (int j = 0; j < kImageSideLength; j++) {
            probabilitesForClass.pixelsProbability[i][j] = ProbabilityOfFeatureGivenClass(imageClass, i, j, trainingData);
        }
    }
    
    return probabilitesForClass;
    
}

std::array<ImageClassProbabilityData, kNumClasses> GetPixelProbabilitiesAllClasses(std::multimap<int, ImageData>& trainingData) {
    
    std::array<ImageClassProbabilityData, kNumClasses> allProbabilities;

    //for each class, calculate probability of a feature
    for (int i = 0; i < kNumClasses; i++) {
        allProbabilities[i] = GetPixelProbabilitiesForClass(i, trainingData);
    }
    
    return allProbabilities;
    
}

void SaveTrainingModels(std::string file, std::multimap<int, ImageData>& trainingData) {
    
    std::array<ImageClassProbabilityData, kNumClasses> allFeatureProbabilities = GetPixelProbabilitiesAllClasses(trainingData);
    
    std::ofstream myFile;
    myFile.open("file");

    if (myFile.good()) {
        
        myFile << "TRAINING DATA\n\n\n";
        
        for (int i = 0; i < allFeatureProbabilities.size(); i++) {
            myFile << "PROBABILITIES FOR CLASS '" << std::to_string(i) << "':\n";
            for (int j = 0; j < allFeatureProbabilities[i].pixelsProbability.size(); j++) {
                myFile << "\nPROBABILITES FOR LINE " << std::to_string(j) << "\n\n";
                for (int k = 0; k < allFeatureProbabilities[i].pixelsProbability[j].size(); k++) {
                    myFile << "PIXEL NUMBER " << std::to_string(k) << ": "
                           << std::to_string(allFeatureProbabilities[i].pixelsProbability[j][k]) << "\n";
                }
            }
        }
        
    } else {
        std::cout << "File doesn't exist, sorry." << std::endl;
    }
    
    myFile.close();
    
}
