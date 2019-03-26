//
//  ClassifierTrainer.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "ClassifierTrainer.hpp"
#include <cmath>

double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& trainingData) {
    
    unsigned long numWithImageClass = trainingData.count(imageClass);
    unsigned long numImages = trainingData.size();
    
    return (double) numWithImageClass / numImages;
    
}

double ProbabilityOfFeatureGivenClass(int imageClass, int pixelArrayX, int pixelArrayY,
                                      std::multimap<int, ImageData>& trainingData) {
    
    auto lowerBoundItr = trainingData.lower_bound(imageClass);
    auto upperBoundItr = trainingData.upper_bound(imageClass);
    
    int numOccurenceClassWithFeature = 0;
    int numClassOccurence = 0;
    
    while (lowerBoundItr != upperBoundItr) {
        if (lowerBoundItr -> first == imageClass) {
            if (lowerBoundItr -> second.pixelArray[pixelArrayX][pixelArrayY] == 1) {
                numOccurenceClassWithFeature++;
            }
            numClassOccurence++;
        }
        lowerBoundItr++;
    }
    
    double probablityOfFeatureGivenClass = (kLaplaceSmoothing + numOccurenceClassWithFeature)
                                         / (2 * kLaplaceSmoothing + numClassOccurence);
    
    return probablityOfFeatureGivenClass;
    
}

std::array<std::array<double, kImageSideLength>, kImageSideLength> GetPixelProbabilitiesForClass(int imageClass, std::multimap<int, ImageData>& trainingData) {
    
    std::array<std::array<double, kImageSideLength>, kImageSideLength> probabilitesForClass;
    for (int i = 0; i < kImageSideLength; i++) {
        for (int j = 0; j < kImageSideLength; j++) {
            probabilitesForClass[i][j] = ProbabilityOfFeatureGivenClass(imageClass, i, j, trainingData);
        }
    }
    
    return probabilitesForClass;
    
}

std::array<std::array<std::array<double, kImageSideLength>, kImageSideLength>, kNumClasses> GetPixelProbabilitiesAllClasses(std::multimap<int, ImageData>& data) {
    
    std::array<std::array<std::array<double, kImageSideLength>, kImageSideLength>, kNumClasses> allProbabilities;

    //for each class, calculate probability of a feature
    for (int i = 0; i < kNumClasses; i++) {
        allProbabilities[i] = GetPixelProbabilitiesForClass(i, data);
    }
    
    return allProbabilities;
    
}

