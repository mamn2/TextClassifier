//
//  ClassifierTrainer.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "ClassifierTrainer.hpp"
#include <cmath>

double ProbabilityOfClass(int imageClass, std::multimap<int, ImageData>& data) {
    
    unsigned long numWithImageClass = data.count(imageClass);
    unsigned long numImages = data.size();
    
    return (double) numWithImageClass / numImages;
    
}

double ProbabilityOfFeatureGivenClass(int imageClass, int pixelArrayX, int pixelArrayY, std::multimap<int, ImageData>& data) {
    
    auto lowerBoundItr = data.lower_bound(imageClass);
    auto upperBoundItr = data.upper_bound(imageClass);
    
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
    
    double probablityOfFeatureGivenClass = (kLaplaceSmoothing + numOccurenceClassWithFeature) / (2 * kLaplaceSmoothing + numClassOccurence);
    
    return probablityOfFeatureGivenClass;
    
}

std::array<std::array<double, 28>, 28> GetPixelProbabilitiesForClass(int imageClass, std::multimap<int, ImageData>& data) {
    
    std::array<std::array<double, 28>, 28> probabilitesForClass;
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            probabilitesForClass[i][j] = ProbabilityOfFeatureGivenClass(imageClass, i, j, data);
        }
    }
    
    return probabilitesForClass;
    
}

std::array<std::array<std::array<double, 28>, 28>, 10> GetPixelProbabilitiesAllClasses(std::multimap<int, ImageData>& data) {
    
    std::array<std::array<std::array<double, 28>, 28>, 10> allProbabilities;

    //for each class, calculate probability of a feature
    for (int i = 0; i < 10; i++) {
        allProbabilities[i] = GetPixelProbabilitiesForClass(i, data);
    }
    
    return allProbabilities;
    
}

//double ProbabilityImageBelongsToClass(int imageClass, ImageData image, std::multimap<int, ImageData>& data) {
//
//    double probabilityImageBelongsToClass = log(ProbabilityOfClass(imageClass, data));
//
//    for (int i = 0; i < image.pixelArray.size(); i++) {
//        for (int j = 0; j < image.pixelArray[i].size(); j++) {
//            probabilityImageBelongsToClass += log(ProbabilityOfFeatureGivenClass(imageClass, image.pixelArray[i][j], i, j, data));
//        }
//    }
//
//    return probabilityImageBelongsToClass;
//
//}

//long HighestProbableClassOfImage(ImageData image, std::multimap<int, ImageData>& data) {
//    
//    std::array<double, 9> probabilitiesOfClasses;
//    
//    for (int i = 0; i <= 9; i++) {
//        probabilitiesOfClasses[i] = ProbabilityImageBelongsToClass(i, image, data);
//    }
//    
//    long maxElementIndex = std::max_element(probabilitiesOfClasses.begin(), probabilitiesOfClasses.end()) - probabilitiesOfClasses.begin();
//    
//    return maxElementIndex;
//    
//}


