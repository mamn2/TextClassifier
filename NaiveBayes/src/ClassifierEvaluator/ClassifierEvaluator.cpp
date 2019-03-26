//
//  ClassifierEvaluator.cpp
//  NaiveBayes
//
//  Created by Mohamed Amn on 3/26/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "ClassifierEvaluator.hpp"
#include <cmath>


double ProbabilityImageBelongsToClass(int imageClass, ImageData image, std::array<std::array<double, 28>, 28>& probabilities, double probOfClass) {
    
    double probability = log(probOfClass);
    
    for (int i = 0; i < image.pixelArray.size(); i++) {
        for (int j = 0; j < image.pixelArray.size(); j++) {
            if (image.pixelArray[i][j] == 1) {
                probability += log(probabilities[i][j]);
            } else {
                probability += log(1.0 - probabilities[i][j]);
            }
        }
    }
    
    return probability;
    
}

int HighestProbableClassOfImage(ImageData image, std::multimap<int, ImageData>& data, std::array<std::array<std::array<double, 28>, 28>, 10>& probabilites) {
    
    double highestProbability = ProbabilityImageBelongsToClass(0, image, probabilites[0], ProbabilityOfClass(0, data));
    int currentMostLikelyCandidate = 0;
    
    for (int i = 1; i < 10; i++) {
        long currentProb = ProbabilityImageBelongsToClass(i, image, probabilites[i], ProbabilityOfClass(i, data));
        if (currentProb > highestProbability) {
            highestProbability = currentProb;
            currentMostLikelyCandidate = i;
        }
    }
    
    return currentMostLikelyCandidate;
    
}
